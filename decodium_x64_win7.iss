#define MyAppName "Decodium 3.0 ASYMX x64 (Win7+)"
#define MyAppVersion "3.0"
#define MyAppPublisher "IU8LMC"
#define MyAppExeName "decodium.exe"
#define MyBuildTag "2603140700"
#define DistDir "dist_64bit"

[Setup]
AppId={{E8A7C3F1-4B2D-4E6F-9A1B-3C5D7E8F0A2B}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
AppVerName={#MyAppName} {#MyBuildTag}
AppPublisher={#MyAppPublisher}
AppPublisherURL=https://www.qrz.com/db/IU8LMC
DefaultDirName={pf}\Decodium_3.0_ASYMX_x64
DefaultGroupName=Decodium 3.0 ASYMX
DisableDirPage=no
DisableProgramGroupPage=no
OutputDir=.
OutputBaseFilename=Decodium_3.0_{#MyBuildTag}_ASYMX_x64_Win7_Setup
SetupIconFile=icons\windows-icons\decodium.ico
Compression=lzma2/ultra64
SolidCompression=yes
WizardStyle=modern
ArchitecturesAllowed=x64
ArchitecturesInstallIn64BitMode=x64
UninstallDisplayIcon={app}\decodium.exe
PrivilegesRequired=lowest
CloseApplications=force
CloseApplicationsFilter=decodium.exe,jt9.exe,message_aggregator.exe,udp_daemon.exe,wsprd.exe
MinVersion=6.1

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"
Name: "italian"; MessagesFile: "compiler:Languages\Italian.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"

[Files]
; Main executables
Source: "{#DistDir}\decodium.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "{#DistDir}\jt9.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "{#DistDir}\message_aggregator.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "{#DistDir}\wsprd.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "{#DistDir}\rigctl-decodium.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "{#DistDir}\rigctld-decodium.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "{#DistDir}\rigctlcom-decodium.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "{#DistDir}\udp_daemon.exe"; DestDir: "{app}"; Flags: ignoreversion

; DLLs (includes api-ms-win-core-synch-l1-2-0.dll stub for Win7)
Source: "{#DistDir}\*.dll"; DestDir: "{app}"; Flags: ignoreversion

; Data files
Source: "{#DistDir}\cty.dat"; DestDir: "{app}"; Flags: ignoreversion
Source: "{#DistDir}\ALLCALL7.TXT"; DestDir: "{app}"; Flags: onlyifdoesntexist
Source: "{#DistDir}\ft2logo.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "{#DistDir}\JPLEPH"; DestDir: "{app}"; Flags: ignoreversion

; Qt plugins
Source: "{#DistDir}\platforms\*"; DestDir: "{app}\platforms"; Flags: ignoreversion recursesubdirs
Source: "{#DistDir}\audio\*"; DestDir: "{app}\audio"; Flags: ignoreversion recursesubdirs
Source: "{#DistDir}\imageformats\*"; DestDir: "{app}\imageformats"; Flags: ignoreversion recursesubdirs
Source: "{#DistDir}\sqldrivers\*"; DestDir: "{app}\sqldrivers"; Flags: ignoreversion recursesubdirs
Source: "{#DistDir}\bearer\*"; DestDir: "{app}\bearer"; Flags: ignoreversion recursesubdirs
Source: "{#DistDir}\styles\*"; DestDir: "{app}\styles"; Flags: ignoreversion recursesubdirs
Source: "{#DistDir}\mediaservice\*"; DestDir: "{app}\mediaservice"; Flags: ignoreversion recursesubdirs
Source: "{#DistDir}\printsupport\*"; DestDir: "{app}\printsupport"; Flags: ignoreversion recursesubdirs

; Sounds and palettes
Source: "{#DistDir}\sounds\*"; DestDir: "{app}\sounds"; Flags: ignoreversion recursesubdirs
Source: "{#DistDir}\Palettes\*"; DestDir: "{app}\Palettes"; Flags: ignoreversion recursesubdirs

[Icons]
Name: "{group}\Decodium 3.0 ASYMX"; Filename: "{app}\{#MyAppExeName}"; IconFilename: "{app}\{#MyAppExeName}"
Name: "{group}\{cm:UninstallProgram,Decodium 3.0 ASYMX}"; Filename: "{uninstallexe}"
Name: "{autodesktop}\Decodium 3.0 ASYMX x64"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{sys}\netsh.exe"; Parameters: "advfirewall firewall delete rule name=""Decodium UDP Inbound"""; Flags: runhidden
Filename: "{sys}\netsh.exe"; Parameters: "advfirewall firewall add rule name=""Decodium UDP Inbound"" dir=in action=allow protocol=UDP program=""{app}\{#MyAppExeName}"" enable=yes profile=any"; Flags: runhidden; StatusMsg: "Configurazione regola firewall UDP..."
Filename: "{sys}\netsh.exe"; Parameters: "advfirewall firewall delete rule name=""Decodium UDP 2237"""; Flags: runhidden
Filename: "{sys}\netsh.exe"; Parameters: "advfirewall firewall add rule name=""Decodium UDP 2237"" dir=in action=allow protocol=UDP localport=2237 enable=yes profile=any"; Flags: runhidden
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,Decodium 3.0 ASYMX}"; Flags: nowait postinstall skipifsilent

[Code]
procedure KillProcess(Name: String);
var
  ResultCode: Integer;
begin
  Exec('taskkill.exe', '/F /IM ' + Name, '', SW_HIDE, ewWaitUntilTerminated, ResultCode);
end;

function InitializeSetup(): Boolean;
begin
  KillProcess('decodium.exe');
  KillProcess('jt9.exe');
  KillProcess('message_aggregator.exe');
  KillProcess('udp_daemon.exe');
  KillProcess('wsprd.exe');
  KillProcess('rigctl-decodium.exe');
  KillProcess('rigctld-decodium.exe');
  KillProcess('rigctlcom-decodium.exe');
  Sleep(500);
  Result := True;
end;
