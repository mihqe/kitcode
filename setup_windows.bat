@echo off
title Setup KitCode 1.1 - Windows
echo ------------------------------------------
echo 🚀 Compilando KitCode 1.1 para Windows...
echo ------------------------------------------

:: Compila gerando um .exe
gcc motor11.c -o kitcode.exe -lm

if %errorlevel% equ 0 (
    echo ✅ Sucesso! O kitcode.exe foi gerado.
    echo 👉 Use: kitcode.exe seu_script.kit
) else (
    echo ❌ Erro! Verifique se o GCC (MinGW) está instalado.
)

echo ------------------------------------------
pause
