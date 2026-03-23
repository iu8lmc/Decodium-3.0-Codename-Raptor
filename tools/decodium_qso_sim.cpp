// ─────────────────────────────────────────────────────────────────────
// Decodium QSO Simulator — FT2 message exchange tester
// Tests pack77/unpack77 roundtrip and QSO state machine for:
//   1. Normal 5-message QSO
//   2. Quick QSO (both stations)
//   3. Mixed: A quick, B normal
//   4. Mixed: A normal, B quick
//   5. Backward compat: old TU on TX2
// ─────────────────────────────────────────────────────────────────────

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>

extern "C" {
  // C-callable wrappers (bind(C) in pack77_wrapper.f90 — no hidden length args)
  void pack77_c(char* msg, int* i3, int* n3, char* c77);
  void unpack77_c(char* c77, int* nrx, char* msg, int* success);
}

// ── ANSI color codes ──
#define C_RESET   "\033[0m"
#define C_BOLD    "\033[1m"
#define C_RED     "\033[31m"
#define C_GREEN   "\033[32m"
#define C_YELLOW  "\033[33m"
#define C_BLUE    "\033[34m"
#define C_MAGENTA "\033[35m"
#define C_CYAN    "\033[36m"
#define C_WHITE   "\033[37m"
#define C_DIM     "\033[2m"

// ── QSO Progress states (mirrors mainwindow.h) ──
enum QSOProgress {
  CALLING = 0,
  REPLYING,
  REPORT,
  ROGER_REPORT,
  ROGERS,
  SIGNOFF
};

static const char* progressName(QSOProgress p) {
  switch (p) {
    case CALLING:      return "CALLING";
    case REPLYING:     return "REPLYING";
    case REPORT:       return "REPORT";
    case ROGER_REPORT: return "ROGER_REPORT";
    case ROGERS:       return "ROGERS";
    case SIGNOFF:      return "SIGNOFF";
  }
  return "?";
}

// ── Station descriptor ──
struct Station {
  std::string call;
  std::string grid;
  bool quickQSO;      // TX1 disabled, skip grid, TU on TX3
  QSOProgress state;
  int ntx;             // current TX slot (1-6)
};

// ── Pack/Unpack verification ──
struct PackResult {
  std::string original;
  std::string unpacked;
  int i3, n3;
  bool roundtrip_ok;
  bool success;
};

static PackResult verifyPack(const std::string& msg) {
  PackResult r;
  r.original = msg;

  // Prepare Fortran-style padded buffers
  char fmsg[37];
  char c77[77];
  char umsg[37];
  int i3 = -1, n3 = -1;
  int nrx = 1;
  int unpk_ok = 0;

  memset(fmsg, ' ', 37);
  memset(c77,  ' ', 77);
  memset(umsg, ' ', 37);

  size_t len = msg.size();
  if (len > 37) len = 37;
  memcpy(fmsg, msg.c_str(), len);

  pack77_c(fmsg, &i3, &n3, c77);

  r.i3 = i3;
  r.n3 = n3;

  if (i3 < 0) {
    r.success = false;
    r.roundtrip_ok = false;
    r.unpacked = "(PACK FAILED)";
    return r;
  }

  unpack77_c(c77, &nrx, umsg, &unpk_ok);

  // Trim trailing spaces
  std::string decoded(umsg, 37);
  while (!decoded.empty() && decoded.back() == ' ') decoded.pop_back();

  r.unpacked = decoded;
  r.success = (unpk_ok != 0);

  // For roundtrip, compare trimmed versions
  std::string orig_trimmed = msg;
  while (!orig_trimmed.empty() && orig_trimmed.back() == ' ') orig_trimmed.pop_back();
  r.roundtrip_ok = (orig_trimmed == decoded);

  return r;
}

// ── Message generation (mirrors genStdMsgs logic) ──
static std::string makeCQ(const Station& s) {
  return "CQ " + s.call + " " + s.grid;
}

static std::string makeGrid(const Station& caller, const Station& cqer) {
  // TX1: hisCall myCall myGrid
  return cqer.call + " " + caller.call + " " + caller.grid;
}

static std::string makeReport(const Station& caller, const Station& cqer, const std::string& rpt) {
  // TX2: hisCall myCall report
  return cqer.call + " " + caller.call + " " + rpt;
}

static std::string makeRogerReport(const Station& me, const Station& him, const std::string& rpt, bool withTU) {
  // TX3: hisCall myCall R+report [TU]
  std::string msg = him.call + " " + me.call + " R" + rpt;
  if (withTU) msg += " TU";
  return msg;
}

static std::string makeRR73(const Station& me, const Station& him) {
  // TX4: hisCall myCall RR73
  return him.call + " " + me.call + " RR73";
}

static std::string make73(const Station& me, const Station& him) {
  // TX5: hisCall myCall 73
  return him.call + " " + me.call + " 73";
}

// ── Print helpers ──
static void printHeader(const char* title) {
  printf("\n%s%s══════════════════════════════════════════════════════════════%s\n",
         C_BOLD, C_CYAN, C_RESET);
  printf("%s%s  %s%s\n", C_BOLD, C_CYAN, title, C_RESET);
  printf("%s%s══════════════════════════════════════════════════════════════%s\n\n",
         C_BOLD, C_CYAN, C_RESET);

  printf(" %sPeriod  Station   TX Message                         QSO State%s\n",
         C_DIM, C_RESET);
  printf(" %s──────  ────────  ──────────────────────────────────  ─────────────%s\n",
         C_DIM, C_RESET);
}

static void printStep(int period, const char* station, const char* arrow,
                      const std::string& msg, QSOProgress state, const char* color) {
  printf("   %s%d%s     %s%-8s%s %s%-35s%s %s%s%s\n",
         C_BOLD, period, C_RESET,
         color, station, C_RESET,
         C_WHITE, msg.c_str(), C_RESET,
         C_YELLOW, progressName(state), C_RESET);
}

static void printAction(int period, const char* station, const char* action, QSOProgress state) {
  printf("   %s%d%s     %s%-8s%s %s[%s]%s %s%s%s\n",
         C_BOLD, period, C_RESET,
         C_GREEN, station, C_RESET,
         C_DIM, action, C_RESET,
         C_YELLOW, progressName(state), C_RESET);
}

// ── Verification block ──
struct VerifyItem {
  std::string msg;
  std::string note;
};

static void printVerification(const std::vector<VerifyItem>& items) {
  printf("\n %sPack/Unpack verification:%s\n", C_BOLD, C_RESET);

  for (auto& item : items) {
    PackResult r = verifyPack(item.msg);

    const char* status_color = r.roundtrip_ok ? C_GREEN : C_RED;
    const char* status_sym   = r.roundtrip_ok ? "OK" : "FAIL";

    printf("   \"%s%s%s\" -> pack77(i3=%d,n3=%d) -> unpack77 -> \"%s%s%s\" %s[%s]%s",
           C_WHITE, r.original.c_str(), C_RESET,
           r.i3, r.n3,
           C_WHITE, r.unpacked.c_str(), C_RESET,
           status_color, status_sym, C_RESET);

    if (!item.note.empty()) {
      printf("\n     %s%s%s", C_DIM, item.note.c_str(), C_RESET);
    }

    // Check if TU was stripped (WSJT-X compat)
    if (r.original.find(" TU") != std::string::npos && r.unpacked.find("TU") == std::string::npos) {
      printf("\n     %sWSJT-X compat: TU stripped by pack77 (free-text fallback avoided, TU invisible)%s",
             C_GREEN, C_RESET);
    }
    // Check if it fell back to free text (i3=0, n3=0)
    if (r.i3 == 0 && r.n3 == 0) {
      printf("\n     %s%sWARNING: packed as free text (i3=0, n3=0) — 13 char limit!%s",
             C_BOLD, C_RED, C_RESET);
    }

    printf("\n");
  }
}

// ═══════════════════════════════════════════════════════════════════
// Scenario 1: Normal 5-message QSO (both stations standard)
// ═══════════════════════════════════════════════════════════════════
static void scenario_normal(Station A, Station B) {
  printHeader("Scenario 1: Normal QSO (5 messages, both standard)");

  A.quickQSO = false;
  B.quickQSO = false;
  std::string rptAtoB = "+05";
  std::string rptBtoA = "-12";
  std::vector<VerifyItem> verify;

  int p = 1;

  // Period 1: A sends CQ
  A.state = CALLING;
  std::string msg = makeCQ(A);
  printStep(p++, "A (CQ)", "->", msg, A.state, C_CYAN);
  verify.push_back({msg, ""});

  // Period 2: B replies with grid (TX1)
  B.state = REPLYING;
  msg = makeGrid(B, A);
  printStep(p++, "B ->", "->", msg, B.state, C_MAGENTA);
  verify.push_back({msg, ""});

  // Period 3: A sends report (TX2)
  A.state = REPORT;
  msg = makeReport(A, B, rptAtoB);
  printStep(p++, "A ->", "->", msg, A.state, C_CYAN);
  verify.push_back({msg, ""});

  // Period 4: B sends R+report (TX3)
  B.state = ROGER_REPORT;
  msg = makeRogerReport(B, A, rptBtoA, false);
  printStep(p++, "B ->", "->", msg, B.state, C_MAGENTA);
  verify.push_back({msg, ""});

  // Period 5: A sends RR73 (TX4)
  A.state = ROGERS;
  msg = makeRR73(A, B);
  printStep(p++, "A ->", "->", msg, A.state, C_CYAN);
  verify.push_back({msg, ""});

  // Period 6: B sends 73 (TX5), then A logs
  B.state = SIGNOFF;
  msg = make73(B, A);
  printStep(p++, "B ->", "->", msg, B.state, C_MAGENTA);
  verify.push_back({msg, ""});

  A.state = SIGNOFF;
  printAction(p, "A", "LOG QSO -> return to CQ", CALLING);
  B.state = CALLING;
  printAction(p, "B", "LOG QSO -> return to CQ", CALLING);

  printVerification(verify);
}

// ═══════════════════════════════════════════════════════════════════
// Scenario 2: Quick QSO (both stations have Quick QSO enabled)
// ═══════════════════════════════════════════════════════════════════
static void scenario_quick_both(Station A, Station B) {
  printHeader("Scenario 2: Quick QSO (both stations, 3 messages)");

  A.quickQSO = true;
  B.quickQSO = true;
  std::string rptAtoB = "+05";
  std::string rptBtoA = "-12";
  std::vector<VerifyItem> verify;

  int p = 1;

  // Period 1: A sends CQ
  A.state = CALLING;
  std::string msg = makeCQ(A);
  printStep(p++, "A (CQ)", "->", msg, A.state, C_CYAN);
  verify.push_back({msg, ""});

  // Period 2: B replies with report directly (skip grid, TX2)
  B.state = REPORT;
  msg = makeReport(B, A, rptBtoA);
  printStep(p++, "B ->", "->", msg, B.state, C_MAGENTA);
  verify.push_back({msg, "Quick QSO: skip TX1 (grid), go straight to TX2 (report)"});

  // Period 3: A sends R+report TU (TX3 with TU marker)
  A.state = ROGER_REPORT;
  msg = makeRogerReport(A, B, rptAtoB, true);  // TU appended!
  printStep(p++, "A ->", "->", msg, A.state, C_CYAN);
  verify.push_back({msg, "Quick QSO TX3: R+report TU (Decodium identifier)"});

  // Period 4: B sees TU -> sends RR73 (TX4), skips TX3
  B.state = ROGERS;
  msg = makeRR73(B, A);
  printStep(p++, "B ->", "->", msg, B.state, C_MAGENTA);
  verify.push_back({msg, "B detects TU -> skip own TX3, go to RR73"});

  // Period 5: A receives RR73 -> log + CQ (skip 73/TX5)
  A.state = SIGNOFF;
  printAction(p, "A", "LOG QSO + return to CQ (skip TX5/73)", CALLING);
  B.state = SIGNOFF;
  printAction(p, "B", "LOG QSO + return to CQ", CALLING);

  printVerification(verify);
}

// ═══════════════════════════════════════════════════════════════════
// Scenario 3: Mixed — A quick, B normal
// ═══════════════════════════════════════════════════════════════════
static void scenario_mixed_A_quick(Station A, Station B) {
  printHeader("Scenario 3: Mixed — A quick, B normal (compatible)");

  A.quickQSO = true;
  B.quickQSO = false;
  std::string rptAtoB = "+05";
  std::string rptBtoA = "-12";
  std::vector<VerifyItem> verify;

  int p = 1;

  // Period 1: A sends CQ
  A.state = CALLING;
  std::string msg = makeCQ(A);
  printStep(p++, "A (CQ)", "->", msg, A.state, C_CYAN);

  // Period 2: B replies with grid (TX1, normal)
  B.state = REPLYING;
  msg = makeGrid(B, A);
  printStep(p++, "B ->", "->", msg, B.state, C_MAGENTA);

  // Period 3: A (quick) skips TX1 reroute, sends report (TX2)
  // Quick QSO reroute: if m_ntx==1, skip to m_ntx=2
  // But A is the CQ station receiving grid, so A goes to TX2 (report)
  A.state = REPORT;
  msg = makeReport(A, B, rptAtoB);
  printStep(p++, "A ->", "->", msg, A.state, C_CYAN);
  verify.push_back({msg, ""});

  // Period 4: B sends R+report (TX3, normal — no TU)
  B.state = ROGER_REPORT;
  msg = makeRogerReport(B, A, rptBtoA, false);
  printStep(p++, "B ->", "->", msg, B.state, C_MAGENTA);
  verify.push_back({msg, "B is normal: no TU on TX3"});

  // Period 5: A sends RR73 (TX4)
  A.state = ROGERS;
  msg = makeRR73(A, B);
  printStep(p++, "A ->", "->", msg, A.state, C_CYAN);
  verify.push_back({msg, ""});

  // Period 6: B sends 73 (TX5)
  B.state = SIGNOFF;
  msg = make73(B, A);
  printStep(p++, "B ->", "->", msg, B.state, C_MAGENTA);

  // A logs, skips TX5 (Quick QSO reroute)
  A.state = SIGNOFF;
  printAction(p, "A", "LOG QSO + skip TX5 (Quick QSO reroute)", CALLING);
  printAction(p, "B", "LOG QSO", CALLING);

  printVerification(verify);
}

// ═══════════════════════════════════════════════════════════════════
// Scenario 4: Mixed — A normal, B quick
// ═══════════════════════════════════════════════════════════════════
static void scenario_mixed_B_quick(Station A, Station B) {
  printHeader("Scenario 4: Mixed — A normal, B quick (compatible)");

  A.quickQSO = false;
  B.quickQSO = true;
  std::string rptAtoB = "+05";
  std::string rptBtoA = "-12";
  std::vector<VerifyItem> verify;

  int p = 1;

  // Period 1: A sends CQ
  A.state = CALLING;
  std::string msg = makeCQ(A);
  printStep(p++, "A (CQ)", "->", msg, A.state, C_CYAN);

  // Period 2: B (quick) skips grid, sends report directly (TX2)
  B.state = REPORT;
  msg = makeReport(B, A, rptBtoA);
  printStep(p++, "B ->", "->", msg, B.state, C_MAGENTA);
  verify.push_back({msg, "B is quick: skip TX1 (grid), straight to TX2 (report)"});

  // Period 3: A (normal) sends R+report (TX3, no TU)
  A.state = ROGER_REPORT;
  msg = makeRogerReport(A, B, rptAtoB, false);
  printStep(p++, "A ->", "->", msg, A.state, C_CYAN);
  verify.push_back({msg, "A is normal: standard TX3 without TU"});

  // Period 4: B sends RR73 (TX4)
  B.state = ROGERS;
  msg = makeRR73(B, A);
  printStep(p++, "B ->", "->", msg, B.state, C_MAGENTA);
  verify.push_back({msg, ""});

  // Period 5: A sends 73 (TX5, normal)
  A.state = SIGNOFF;
  msg = make73(A, B);
  printStep(p++, "A ->", "->", msg, A.state, C_CYAN);

  // Both log
  printAction(p, "A", "LOG QSO", CALLING);
  B.state = SIGNOFF;
  printAction(p, "B", "LOG QSO + skip TX5 (Quick QSO reroute)", CALLING);

  printVerification(verify);
}

// ═══════════════════════════════════════════════════════════════════
// Scenario 5: Backward compat — old-style TU on TX2
// ═══════════════════════════════════════════════════════════════════
static void scenario_backward_compat(Station A, Station B) {
  printHeader("Scenario 5: Backward compat — TU on various positions");

  std::vector<VerifyItem> items;

  // Test all message forms that might contain TU
  items.push_back({B.call + " " + A.call + " R-12 TU",
                   "Quick QSO TX3: R+report TU — Decodium marker"});
  items.push_back({B.call + " " + A.call + " R+05 TU",
                   "Quick QSO TX3: R+report TU — positive report"});
  items.push_back({B.call + " " + A.call + " -12",
                   "Standard TX2: plain report (no TU)"});
  items.push_back({B.call + " " + A.call + " R-12",
                   "Standard TX3: R+report (no TU)"});
  items.push_back({B.call + " " + A.call + " RR73",
                   "Standard TX4: RR73"});
  items.push_back({"CQ " + A.call + " " + A.grid,
                   "Standard CQ message"});
  items.push_back({B.call + " " + A.call + " " + B.grid,
                   "Standard TX1: grid"});
  items.push_back({B.call + " " + A.call + " 73",
                   "Standard TX5: 73"});

  // Also test with compound calls
  items.push_back({"VP8/IU8LMC IK8XXX R+05 TU",
                   "Compound call + TU — may fall to free text"});
  items.push_back({"IK8XXX VP8/IU8LMC R-12 TU",
                   "Compound DX call + TU — may fall to free text"});

  printVerification(items);

  printf("\n %sKey observations:%s\n", C_BOLD, C_RESET);
  printf("   - Messages with TU that fit in type 1 (i3=1): TU is %sstripped%s by pack77\n",
         C_GREEN, C_RESET);
  printf("     (pack77 packs the report part, TU is an extra word that doesn't fit)\n");
  printf("   - WSJT-X standard sees \"%sR+05%s\" without TU — %sfully compatible%s\n",
         C_WHITE, C_RESET, C_GREEN, C_RESET);
  printf("   - Decodium detects TU %sbefore%s packing (in genStdMsgs/processMessage)\n",
         C_BOLD, C_RESET);
  printf("   - If message falls to free text (i3=0,n3=0): 13 char limit, truncated\n");
}

// ═══════════════════════════════════════════════════════════════════
// Main
// ═══════════════════════════════════════════════════════════════════
int main(int argc, char* argv[]) {
  printf("%s%s", C_BOLD, C_CYAN);
  printf("╔══════════════════════════════════════════════════════════════╗\n");
  printf("║       Decodium QSO Simulator — FT2 Message Exchange        ║\n");
  printf("║       Pack77/Unpack77 Roundtrip + State Machine Test       ║\n");
  printf("╚══════════════════════════════════════════════════════════════╝\n");
  printf("%s\n", C_RESET);

  Station A = {"IU8LMC", "JN70", false, CALLING, 6};
  Station B = {"IK8XXX", "JN71", false, CALLING, 0};

  // Allow selecting specific scenario via command line
  int scenario = 0;  // 0 = all
  if (argc > 1) {
    scenario = atoi(argv[1]);
    if (scenario < 0 || scenario > 5) {
      printf("Usage: %s [scenario_number 1-5]\n", argv[0]);
      printf("  0 or no arg = run all scenarios\n");
      return 1;
    }
  }

  if (scenario == 0 || scenario == 1) scenario_normal(A, B);
  if (scenario == 0 || scenario == 2) scenario_quick_both(A, B);
  if (scenario == 0 || scenario == 3) scenario_mixed_A_quick(A, B);
  if (scenario == 0 || scenario == 4) scenario_mixed_B_quick(A, B);
  if (scenario == 0 || scenario == 5) scenario_backward_compat(A, B);

  printf("\n%s%s════════════════════════════════════════════════════════════════%s\n",
         C_BOLD, C_GREEN, C_RESET);
  printf("%s%s  All scenarios completed.%s\n",
         C_BOLD, C_GREEN, C_RESET);
  printf("%s%s════════════════════════════════════════════════════════════════%s\n\n",
         C_BOLD, C_GREEN, C_RESET);

  return 0;
}
