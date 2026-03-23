#define MyAppName "Decodium Shannon x64"
#define MyAppVersion "3.0"
#define MyAppPublisher "IU8LMC"
#define MyAppExeName "decodium.exe"
#define MyBuildTag "2603232208"
#define DistDir "dist_64bit"

[Setup]
AppId={{E8A7C3F1-4B2D-4E6F-9A1B-3C5D7E8F0A2B}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
AppVerName={#MyAppName} {#MyBuildTag}
AppPublisher={#MyAppPublisher}
AppPublisherURL=https://www.qrz.com/db/IU8LMC
DefaultDirName={autopf}\Decodium
DefaultGroupName=Decodium Shannon
DisableDirPage=no
DisableProgramGroupPage=no
OutputDir=.
OutputBaseFilename=Decodium_FT2_{#MyBuildTag}_x64_Setup
SetupIconFile=icons\windows-icons\decodium.ico
Compression=lzma2/ultra64
SolidCompression=yes
WizardStyle=modern
CloseApplications=force
CloseApplicationsFilter=decodium.exe,jt9.exe
RestartApplications=no
ArchitecturesAllowed=x64compatible
ArchitecturesInstallIn64BitMode=x64compatible
UninstallDisplayIcon={app}\decodium.exe
PrivilegesRequired=admin

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

; DLLs
Source: "{#DistDir}\*.dll"; DestDir: "{app}"; Flags: ignoreversion

; Data files
Source: "{#DistDir}\cty.dat"; DestDir: "{app}"; Flags: ignoreversion
Source: "{#DistDir}\ALLCALL7.TXT"; DestDir: "{app}"; Flags: onlyifdoesntexist
Source: "{#DistDir}\ft2logo.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "{#DistDir}\JPLEPH"; DestDir: "{app}"; Flags: ignoreversion

; Qt plugins
Source: "{#DistDir}\platforms\*"; DestDir: "{app}\platforms"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#DistDir}\audio\*"; DestDir: "{app}\audio"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#DistDir}\imageformats\*"; DestDir: "{app}\imageformats"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#DistDir}\sqldrivers\*"; DestDir: "{app}\sqldrivers"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#DistDir}\bearer\*"; DestDir: "{app}\bearer"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#DistDir}\styles\*"; DestDir: "{app}\styles"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#DistDir}\mediaservice\*"; DestDir: "{app}\mediaservice"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#DistDir}\printsupport\*"; DestDir: "{app}\printsupport"; Flags: ignoreversion recursesubdirs createallsubdirs

; Sounds and palettes
Source: "{#DistDir}\sounds\*"; DestDir: "{app}\sounds"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#DistDir}\Palettes\*"; DestDir: "{app}\Palettes"; Flags: ignoreversion recursesubdirs createallsubdirs

[Dirs]
; Ensure program directory is writable for ADIF log
Name: "{app}"; Permissions: users-modify

[Icons]
Name: "{group}\Decodium Shannon"; Filename: "{app}\{#MyAppExeName}"; IconFilename: "{app}\{#MyAppExeName}"
Name: "{group}\{cm:UninstallProgram,Decodium Shannon}"; Filename: "{uninstallexe}"
Name: "{autodesktop}\Decodium Shannon x64"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
; Firewall rules (admin mode, won't fail)
Filename: "{sys}\netsh.exe"; Parameters: "advfirewall firewall delete rule name=""Decodium UDP Inbound"""; Flags: runhidden
Filename: "{sys}\netsh.exe"; Parameters: "advfirewall firewall add rule name=""Decodium UDP Inbound"" dir=in action=allow protocol=UDP program=""{app}\{#MyAppExeName}"" enable=yes profile=any"; Flags: runhidden; StatusMsg: "Configurazione firewall UDP..."
; Auto-launch after install
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,Decodium Shannon}"; Flags: nowait postinstall
