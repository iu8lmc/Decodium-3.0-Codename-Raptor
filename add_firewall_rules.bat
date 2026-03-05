@echo off
:: Esegui questo file come Amministratore (tasto destro -> Esegui come amministratore)
echo ============================================
echo  Decodium - Aggiungi regole Windows Firewall
echo ============================================
echo.

set EXE64=C:\Users\IU8LMC\AppData\Local\Programs\Decodium_3.0_FT2_x64\decodium.exe
set EXE86=C:\Users\IU8LMC\AppData\Local\Programs\Decodium_3.0_FT2_x86\decodium.exe

echo Rimuovo vecchie regole Decodium...
netsh advfirewall firewall delete rule name="Decodium UDP Inbound x64" >nul 2>&1
netsh advfirewall firewall delete rule name="Decodium UDP Inbound x86" >nul 2>&1
netsh advfirewall firewall delete rule name="Decodium UDP 2237" >nul 2>&1

echo Aggiungo regola inbound UDP per Decodium x64...
if exist "%EXE64%" (
    netsh advfirewall firewall add rule name="Decodium UDP Inbound x64" ^
        dir=in action=allow protocol=UDP ^
        program="%EXE64%" ^
        enable=yes profile=any
) else (
    echo   SKIP: %EXE64% non trovato
)

echo Aggiungo regola inbound UDP per Decodium x86...
if exist "%EXE86%" (
    netsh advfirewall firewall add rule name="Decodium UDP Inbound x86" ^
        dir=in action=allow protocol=UDP ^
        program="%EXE86%" ^
        enable=yes profile=any
) else (
    echo   SKIP: %EXE86% non trovato
)

echo Aggiungo regola generica porta 2237 UDP inbound...
netsh advfirewall firewall add rule name="Decodium UDP 2237" ^
    dir=in action=allow protocol=UDP localport=2237 ^
    enable=yes profile=any

echo.
echo Verifica:
netsh advfirewall firewall show rule name="Decodium UDP 2237" | findstr /C:"Rule Name" /C:"Enabled" /C:"Action"

echo.
echo ============================================
echo  FATTO - riavvia Decodium poi JTAlert
echo ============================================
pause
