@echo off
REM KitCode Auto Sync Script (Windows)
REM Este script sincroniza automaticamente com o repositorio GitHub
REM Sincroniza a cada 5 minutos

setlocal enabledelayedexpansion

set SYNC_INTERVAL=300
set LOG_FILE=%USERPROFILE%\.kitcode_sync.log
cd /d "%~dp0"

if not exist ".git" (
    echo [ERROR] Diretorio nao eh um repositorio Git
    echo [%date% %time%] ERROR: Diretorio nao eh um repositorio Git >> "%LOG_FILE%"
    pause
    exit /b 1
)

cls
echo.
echo ======================================
echo   KitCode Auto Sync (Windows)
echo   Sincronizando a cada 5 minutos
echo ======================================
echo.

echo [%date% %time%] KitCode Auto Sync iniciado >> "%LOG_FILE%"
echo [%date% %time%] Diretorio: %cd% >> "%LOG_FILE%"
echo [%date% %time%] Intervalo: %SYNC_INTERVAL% segundos (5 minutos) >> "%LOG_FILE%"

:loop
cls
echo.
echo ======================================
echo   KitCode Auto Sync (Windows)
echo ======================================
echo.
echo Sincronizando... [%date% %time%]
echo.

git pull origin main > nul 2>&1
if errorlevel 1 (
    echo [%date% %time%] ERROR: Falha ao sincronizar >> "%LOG_FILE%"
    echo Falha ao sincronizar. Verifique a conexao de internet.
) else (
    echo [%date% %time%] Sincronizado com sucesso >> "%LOG_FILE%"
    echo Sincronizado com sucesso!
)

echo.
echo Proxima sincronizacao em 5 minutos...
echo Pressione Ctrl+C para parar.
echo.

timeout /t %SYNC_INTERVAL% /nobreak

goto loop
