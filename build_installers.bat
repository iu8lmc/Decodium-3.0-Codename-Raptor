@echo off
setlocal enabledelayedexpansion

set SIGNTOOL="C:\Program Files (x86)\Windows Kits\10\bin\10.0.22621.0\x64\signtool.exe"
set ISCC="C:\Program Files (x86)\Inno Setup 6\ISCC.exe"
set PFX=C:\Users\IU8LMC\decodium_codesign.pfx
set PASS=Dec2026sign
set SRC=C:\Users\IU8LMC\Downloads\WSJTX_3.0_Source
set BUILD=2603141352

echo ============================================
echo  Decodium 3.0 ASYMX %BUILD% - Build Installers
echo ============================================
echo.

echo === Step 0: Copy build output to dist ===
if exist "%SRC%\build\decodium.exe" (
    copy /Y "%SRC%\build\decodium.exe" "%SRC%\dist_64bit\decodium.exe"
    echo   Copied decodium.exe to dist_64bit
)
if exist "%SRC%\build\jt9.exe" (
    copy /Y "%SRC%\build\jt9.exe" "%SRC%\dist_64bit\jt9.exe"
    echo   Copied jt9.exe to dist_64bit
)
echo.

echo === Step 1: Signing x64 executables ===
for %%f in (decodium.exe jt9.exe message_aggregator.exe wsprd.exe udp_daemon.exe rigctl-decodium.exe rigctld-decodium.exe rigctlcom-decodium.exe) do (
    if exist "%SRC%\dist_64bit\%%f" (
        echo   Signing x64\%%f...
        %SIGNTOOL% sign /f %PFX% /p %PASS% /fd SHA256 /d "Decodium 3.0 ASYMX" /tr http://timestamp.digicert.com /td SHA256 "%SRC%\dist_64bit\%%f"
        if errorlevel 1 echo   WARNING: Failed to sign %%f
    ) else (
        echo   SKIP: %%f not found
    )
)
echo.

echo === Step 2: Signing x86 executables ===
for %%f in (decodium.exe jt9.exe message_aggregator.exe wsprd.exe udp_daemon.exe rigctl-decodium.exe rigctld-decodium.exe rigctlcom-decodium.exe) do (
    if exist "%SRC%\dist_32bit\%%f" (
        echo   Signing x86\%%f...
        %SIGNTOOL% sign /f %PFX% /p %PASS% /fd SHA256 /d "Decodium 3.0 ASYMX" /tr http://timestamp.digicert.com /td SHA256 "%SRC%\dist_32bit\%%f"
        if errorlevel 1 echo   WARNING: Failed to sign %%f
    ) else (
        echo   SKIP: %%f not found
    )
)
echo.

echo === Step 2b: Remove Win7 synch DLL from dist (standard installers must NOT include it) ===
if exist "%SRC%\dist_64bit\api-ms-win-core-synch-l1-2-0.dll" del /Q "%SRC%\dist_64bit\api-ms-win-core-synch-l1-2-0.dll"
if exist "%SRC%\dist_32bit\api-ms-win-core-synch-l1-2-0.dll" del /Q "%SRC%\dist_32bit\api-ms-win-core-synch-l1-2-0.dll"
echo.

echo === Step 3: Building x64 installer ===
%ISCC% "%SRC%\decodium_x64.iss"
if errorlevel 1 (
    echo ERROR: x64 installer build failed!
    goto :error
)
echo.

echo === Step 4: Building x86 installer ===
%ISCC% "%SRC%\decodium_x86.iss"
if errorlevel 1 (
    echo ERROR: x86 installer build failed!
    goto :error
)
echo.

echo === Step 5: Building x64 Win7 installer ===
echo   Copying Win7 synch DLL to dist_64bit...
copy /Y "%SRC%\win7_compat\api-ms-win-core-synch-l1-2-0.dll" "%SRC%\dist_64bit\api-ms-win-core-synch-l1-2-0.dll"
echo   Patching decodium.exe for Win7 compatibility...
python "%SRC%\win7_compat\patch_precise.py" "%SRC%\dist_64bit\decodium.exe"
%ISCC% "%SRC%\decodium_x64_win7.iss"
if errorlevel 1 (
    echo ERROR: x64 Win7 installer build failed!
    goto :error
)
echo.

echo === Step 5b: Remove Win7 synch DLL from dist_64bit after Win7 installer ===
del /Q "%SRC%\dist_64bit\api-ms-win-core-synch-l1-2-0.dll" 2>nul

echo === Step 6: Building x86 Win7 installer ===
echo   Copying Win7 synch DLL to dist_32bit...
copy /Y "%SRC%\win7_compat\api-ms-win-core-synch-l1-2-0_x86.dll" "%SRC%\dist_32bit\api-ms-win-core-synch-l1-2-0.dll"
echo   Patching x86 decodium.exe for Win7 compatibility...
python "%SRC%\win7_compat\patch_precise.py" "%SRC%\dist_32bit\decodium.exe"
%ISCC% "%SRC%\decodium_x86_win7.iss"
if errorlevel 1 (
    echo ERROR: x86 Win7 installer build failed!
    goto :error
)
del /Q "%SRC%\dist_32bit\api-ms-win-core-synch-l1-2-0.dll" 2>nul
echo.

echo === Step 7: Signing installers ===
for %%f in (Decodium_3.0_%BUILD%_ASYMX_x64_Setup.exe Decodium_3.0_%BUILD%_ASYMX_x86_Setup.exe Decodium_3.0_%BUILD%_ASYMX_x64_Win7_Setup.exe Decodium_3.0_%BUILD%_ASYMX_x86_Win7_Setup.exe) do (
    if exist "%SRC%\%%f" (
        echo   Signing %%f...
        %SIGNTOOL% sign /f %PFX% /p %PASS% /fd SHA256 /d "Decodium 3.0 ASYMX Installer" /tr http://timestamp.digicert.com /td SHA256 "%SRC%\%%f"
        if errorlevel 1 echo   WARNING: Failed to sign %%f
    ) else (
        echo   ERROR: %%f not found!
    )
)
echo.

echo ============================================
echo  BUILD COMPLETE!
echo  Installers:
echo    %SRC%\Decodium_3.0_%BUILD%_ASYMX_x64_Setup.exe
echo    %SRC%\Decodium_3.0_%BUILD%_ASYMX_x86_Setup.exe
echo    %SRC%\Decodium_3.0_%BUILD%_ASYMX_x64_Win7_Setup.exe
echo    %SRC%\Decodium_3.0_%BUILD%_ASYMX_x86_Win7_Setup.exe
echo ============================================
goto :end

:error
echo.
echo BUILD FAILED - check errors above
exit /b 1

:end
endlocal
