cat << 'EOF' > executar.sh
#!/bin/bash
# KitCode 1.1 - Auto-Updater & Runner

echo "--- Verificando atualizações ---"
git pull origin main --quiet

echo "--- Compilando Motor 1.1 ---"
gcc motor11.c -o kitcode -lm

if [ $? -eq 0 ]; then
    echo "--- Iniciando Script ---"
    ./kitcode "$1"
else
    echo "Erro: O motor não conseguiu compilar. Verifique o código C."
fi
EOF
