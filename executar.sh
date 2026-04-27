#!/bin/bash

# Configurações - Substitua pelo seu link RAW do GitHub
GITHUB_URL="https://raw.githubusercontent.com/mihqe/kitcode/main/motor11.c"

echo "--- 🔄 Sincronizando Motor com GitHub ---"

# 1. Baixa a versão mais recente do GitHub e substitui a local
curl -s -O $GITHUB_URL

# 2. Compila o motor baixado (O -lm é essencial para a matemática)
gcc motor11.c -o kitcode -lm

# 3. Verifica se a compilação deu certo
if [ $? -eq 0 ]; then
    echo "--- ✅ Motor atualizado e compilado ---"
    echo "--- 🚀 Rodando script: $1 ---"
    echo ""
    ./kitcode "$1"
else
    echo "--- ❌ ERRO: Falha na compilação do motor do GitHub ---"
fi
