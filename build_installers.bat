@echo off
setlocal enabledelayedexpansion

set SIGNTOOL="C:\Program Files (x86)\Windows Kits\10\bin\10.0.22621.0\x64\signtool.exe"
set ISCC="C:\Program Files (x86)\Inno Setup 6\ISCC.exe"
set PFX=C:\Users\IU8LMC\decodium_codesign.pfx
set PASS=Dec2026sign
set SRC=C:\Users\IU8LMC\Downloads\WSJTX_3.0_Source
set BUILD=2603160728

echo ============================================
echo  Decodium Fast Track 2 %BUILD% - Build Installers
echo ============================================
echo.

echo === Step 0: Copy build output to dist ===
if exist "%SRC%\build-w2\decodium.exe" (
    copy /Y "%SRC%\build-w2\decodium.exe" "%SRC%\dist_64bit\decodium.exe"
    echo   Copied decodium.exe to dist_64bit
)
if exist "%SRC%\build-w2\jt9.exe" (
    copy /Y "%SRC%\build-w2\jt9.exe" "%SRC%\dist_64bit\jt9.exe"
    echo   Copied jt9.exe to dist_64bit
)
echo.

echo === Step 1: Signing x64 executables ===
for %%f in (decodium.exe jt9.exe message_aggregator.exe wsprd.exe udp_daemon.exe rigctl-decodium.exe rigctld-decodium.exe rigctlcom-decodium.exe) do (
    if exist "%SRC%\dist_64bit\%%f" (
        echo   Signing x64\%%f...
        %SIGNTOOL% sign /f %PFX% /p %PASS% /fd SHA256 /d "Decodium Fast Track 2" /tr http://timestamp.digicert.com /td SHA256 "%SRC%\dist_64bit\%%f"
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
        %SIGNTOOL% sign /f %PFX% /p %PASS% /fd SHA256 /d "Decodium Fast Track 2" /tr http://timestamp.digicert.com /td SHA256 "%SRC%\dist_32bit\%%f"
        if errorlevel 1 echo   WARNING: Failed to sign %%f
    ) else (
        echo   SKIP: %%f not found
    )
)
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

echo === Step 5: Signing installers ===
for %%f in (Decodium_FT2_%BUILD%_x64_Setup.exe Decodium_FT2_%BUILD%_x86_Setup.exe) do (
    if exist "%SRC%\%%f" (
        echo   Signing %%f...
        %SIGNTOOL% sign /f %PFX% /p %PASS% /fd SHA256 /d "Decodium Fast Track 2 Installer" /tr http://timestamp.digicert.com /td SHA256 "%SRC%\%%f"
        if errorlevel 1 echo   WARNING: Failed to sign %%f
    ) else (
        echo   ERROR: %%f not found!
    )
)
echo.

echo ============================================
echo  BUILD COMPLETE!
echo  Installers:
echo    %SRC%\Decodium_FT2_%BUILD%_x64_Setup.exe
echo    %SRC%\Decodium_FT2_%BUILD%_x86_Setup.exe
echo ============================================
goto :end

:error
echo.
echo BUILD FAILED - check errors above
exit /b 1

:end
endlocal
