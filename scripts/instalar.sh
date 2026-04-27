#!/bin/bash

echo "------------------------------------------"
echo "📦 INSTALADOR AUTOMÁTICO KITCODE 1.1 (11)"
echo "------------------------------------------"

# 1. Verifica se o GCC está instalado
if ! command -v gcc &> /dev/null
then
    echo "❌ Erro: GCC não encontrado. Instale o compilador C primeiro."
    exit
fi

# 2. Compila o motor oficial
echo "🛠️ Compilando motor11.c..."
gcc motor11.c -o kitcode -lm

if [ $? -eq 0 ]; then
    echo "✅ Compilação concluída com sucesso!"
    chmod +x kitcode
else
    echo "❌ Erro na compilação. Verifique o arquivo motor11.c"
    exit
fi

# 3. Cria o atalho (Alias) automático
echo "🔗 Criando atalho 'kit' no seu sistema..."

# Detecta qual arquivo de configuração o usuário usa (.bashrc ou .zshrc)
SHELL_CONFIG="$HOME/.bashrc"
[ -f "$HOME/.zshrc" ] && SHELL_CONFIG="$HOME/.zshrc"

# Adiciona o alias se ele ainda não existir
if ! grep -q "alias kit=" "$SHELL_CONFIG"; then
    echo "alias kit='$(pwd)/kitcode'" >> "$SHELL_CONFIG"
    echo "✅ Atalho 'kit' adicionado a $SHELL_CONFIG"
else
    echo "ℹ️ O atalho 'kit' já existe."
fi

echo "------------------------------------------"
echo "🎉 TUDO PRONTO!"
echo "👉 Feche e abra o terminal ou digite: source $SHELL_CONFIG"
echo "👉 Depois, basta digitar: kit seu_arquivo.kit"
echo "------------------------------------------"
