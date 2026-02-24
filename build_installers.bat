@echo off
set ISCC="C:\Program Files (x86)\Inno Setup 6\ISCC.exe"
set SRC=C:\Users\IU8LMC\Downloads\WSJTX_3.0_Source

echo === Building x64 installer ===
%ISCC% /Qp "%SRC%\decodium_x64.iss"
if errorlevel 1 (
    echo ERROR: x64 installer failed
) else (
    echo x64 installer built successfully
)

echo === Building x86 installer ===
%ISCC% /Qp "%SRC%\decodium_x86.iss"
if errorlevel 1 (
    echo ERROR: x86 installer failed
) else (
    echo x86 installer built successfully
)

echo === Done ===
dir /b "%SRC%\Decodium_3.0_*_Setup.exe" 2>nul
