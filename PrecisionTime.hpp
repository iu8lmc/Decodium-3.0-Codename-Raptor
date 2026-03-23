#ifndef PRECISION_TIME_HPP
#define PRECISION_TIME_HPP

#include <QtGlobal>
#include <QDateTime>

#ifdef Q_OS_WIN
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
// windows.h defines MessageBox as a macro, which conflicts with WSJT-X MessageBox class
#ifdef MessageBox
#undef MessageBox
#endif
#endif

// GetSystemTimePreciseAsFileTime compatibility:
// Available on Windows 8+ (0x0602). On Windows 7 use GetSystemTimeAsFileTime.
// We resolve it at runtime via GetProcAddress to avoid hard import failure.
#ifdef Q_OS_WIN
namespace PrecisionTimeImpl {
  typedef VOID (WINAPI *PFN_GetSystemTimePreciseAsFileTime)(LPFILETIME);
  inline PFN_GetSystemTimePreciseAsFileTime resolveGetSystemTimePrecise() {
    static PFN_GetSystemTimePreciseAsFileTime fn = nullptr;
    static bool resolved = false;
    if (!resolved) {
      resolved = true;
      FARPROC raw = GetProcAddress(GetModuleHandleA("kernel32.dll"),
                                   "GetSystemTimePreciseAsFileTime");
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-function-type"
      fn = reinterpret_cast<PFN_GetSystemTimePreciseAsFileTime>(raw);
#pragma GCC diagnostic pop
    }
    return fn;
  }
  inline void getSystemTimeAsFiletime(FILETIME *ft) {
    auto fn = resolveGetSystemTimePrecise();
    if (fn) fn(ft);
    else    GetSystemTimeAsFileTime(ft);   // Windows 7 fallback
  }
}
#endif

// Returns current UTC time in milliseconds since epoch with maximum precision.
// On Windows 8+ uses GetSystemTimePreciseAsFileTime (~1μs resolution).
// On Windows 7 falls back to GetSystemTimeAsFileTime (~15ms resolution).
// On other platforms falls back to QDateTime (millisecond resolution).
inline qint64 preciseCurrentMSecsSinceEpoch()
{
#ifdef Q_OS_WIN
    FILETIME ft;
    PrecisionTimeImpl::getSystemTimeAsFiletime(&ft);
    // FILETIME is 100-nanosecond intervals since 1601-01-01
    // Difference between 1601 and 1970 in 100-ns units: 116444736000000000LL
    ULARGE_INTEGER ull;
    ull.LowPart = ft.dwLowDateTime;
    ull.HighPart = ft.dwHighDateTime;
    return static_cast<qint64>((ull.QuadPart - 116444736000000000LL) / 10000);
#else
    return QDateTime::currentMSecsSinceEpoch();
#endif
}

// Returns fractional microseconds part (0-999) for sub-millisecond precision
inline int preciseCurrentMicrosecondFraction()
{
#ifdef Q_OS_WIN
    FILETIME ft;
    PrecisionTimeImpl::getSystemTimeAsFiletime(&ft);
    ULARGE_INTEGER ull;
    ull.LowPart = ft.dwLowDateTime;
    ull.HighPart = ft.dwHighDateTime;
    return static_cast<int>((ull.QuadPart / 10) % 1000);
#else
    return 0;
#endif
}

#endif // PRECISION_TIME_HPP
