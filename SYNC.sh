#!/bin/bash

# KitCode Auto Sync Script (Linux/macOS)
# Este script sincroniza automaticamente com o repositório GitHub
# Sincroniza a cada 5 minutos

SYNC_INTERVAL=300  # 5 minutos em segundos
LOG_FILE="$HOME/.kitcode_sync.log"
REPO_PATH="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Cores para output
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Função de logging
log_message() {
    local timestamp=$(date '+%Y-%m-%d %H:%M:%S')
    echo "[$timestamp] $1" >> "$LOG_FILE"
    echo -e "${GREEN}[$timestamp]${NC} $1"
}

log_error() {
    local timestamp=$(date '+%Y-%m-%d %H:%M:%S')
    echo "[$timestamp] ERROR: $1" >> "$LOG_FILE"
    echo -e "${RED}[$timestamp] ERROR:${NC} $1"
}

# Função para sincronizar
sync_repo() {
    cd "$REPO_PATH" || {
        log_error "Não foi possível acessar o diretório do repositório: $REPO_PATH"
        return 1
    }
    
    # Verificar se é um repositório git
    if [ ! -d ".git" ]; then
        log_error "Diretório não é um repositório Git"
        return 1
    fi
    
    # Fazer pull
    if git pull origin main 2>&1 | grep -q "Already up to date"; then
        log_message "Repositório já está atualizado"
    elif git pull origin main > /dev/null 2>&1; then
        log_message "Repositório sincronizado com sucesso! ✓"
    else
        log_error "Falha ao sincronizar o repositório"
        return 1
    fi
}

# Header
echo -e "${YELLOW}"
echo "╔═══════════════════════════════════════╗"
echo "║     KitCode Auto Sync (Linux/macOS)    ║"
echo "║        Sincronizando a cada 5min       ║"
echo "╚═══════════════════════════════════════╝"
echo -e "${NC}"

log_message "KitCode Auto Sync iniciado"
log_message "Repositório: $REPO_PATH"
log_message "Intervalo de sincronização: $SYNC_INTERVAL segundos (5 minutos)"
log_message "Arquivo de log: $LOG_FILE"
echo ""

# Loop infinito de sincronização
while true; do
    sync_repo
    
    # Mostrar próxima sincronização
    next_sync=$(date -d "+${SYNC_INTERVAL} seconds" '+%H:%M:%S' 2>/dev/null || date -v+${SYNC_INTERVAL}S '+%H:%M:%S')
    echo -e "${YELLOW}Próxima sincronização em: $next_sync${NC}"
    echo ""
    
    sleep "$SYNC_INTERVAL"
done
