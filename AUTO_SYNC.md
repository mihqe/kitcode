# Guia de Sincronização Automática - KitCode

## O que é Sincronização Automática?

A sincronização automática mantém seus arquivos locais sempre atualizados com as mudanças feitas no repositório GitHub. Quando alguém no seu time faz mudanças e push no GitHub, o script automaticamente faz `git pull` a cada 5 minutos, sincronizando todos os arquivos.

---

## 📋 Pré-requisitos

- ✅ Git instalado (veja [INSTALL.md](INSTALL.md))
- ✅ KitCode clonado localmente
- ✅ Acesso à internet
- ✅ Permissões no repositório

---

## 🐧 Linux/macOS

### Opção 1: Execução Manual (Mais Simples)

```bash
# 1. Ir para o diretório do KitCode
cd ~/kitcode

# 2. Dar permissão de execução
chmod +x SYNC.sh

# 3. Executar o script
./SYNC.sh
```

O script vai rodar continuamente, sincronizando a cada 5 minutos. Pressione `Ctrl+C` para parar.

---

### Opção 2: Rodar em Background (Mais Prático)

```bash
# Executar em background
cd ~/kitcode && ./SYNC.sh &

# Ver processos rodando
jobs

# Parar o script
kill %1
```

---

### Opção 3: Executar na Inicialização (Automático)

#### Linux (Systemd)

1. **Criar arquivo de serviço:**
```bash
sudo nano /etc/systemd/system/kitcode-sync.service
```

2. **Adicionar conteúdo:**
```ini
[Unit]
Description=KitCode Auto Sync
After=network-online.target
Wants=network-online.target

[Service]
Type=simple
User=seu_usuario
WorkingDirectory=/home/seu_usuario/kitcode
ExecStart=/home/seu_usuario/kitcode/SYNC.sh
Restart=always
RestartSec=10

[Install]
WantedBy=multi-user.target
```

3. **Salvar e ativar:**
```bash
sudo systemctl daemon-reload
sudo systemctl enable kitcode-sync.service
sudo systemctl start kitcode-sync.service

# Verificar status
sudo systemctl status kitcode-sync.service

# Ver logs
sudo journalctl -u kitcode-sync.service -f
```

---

#### macOS (LaunchAgent)

1. **Criar arquivo plist:**
```bash
nano ~/Library/LaunchAgents/com.kitcode.sync.plist
```

2. **Adicionar conteúdo:**
```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>Label</key>
    <string>com.kitcode.sync</string>
    <key>ProgramArguments</key>
    <array>
        <string>/Users/seu_usuario/kitcode/SYNC.sh</string>
    </array>
    <key>StartInterval</key>
    <integer>300</integer>
    <key>StandardOutPath</key>
    <string>/var/log/kitcode-sync.log</string>
    <key>StandardErrorPath</key>
    <string>/var/log/kitcode-sync-error.log</string>
    <key>KeepAlive</key>
    <true/>
</dict>
</plist>
```

3. **Ativar:**
```bash
# Carregar
launchctl load ~/Library/LaunchAgents/com.kitcode.sync.plist

# Descarregar
launchctl unload ~/Library/LaunchAgents/com.kitcode.sync.plist

# Ver status
launchctl list | grep kitcode

# Ver logs
tail -f /var/log/kitcode-sync.log
```

---

## 🪟 Windows

### Opção 1: Execução Manual

```cmd
# 1. Abrir PowerShell ou CMD
# 2. Ir para o diretório
cd C:\Users\seu_usuario\kitcode

# 3. Executar
sync.bat
```

O script vai rodar continuamente. Pressione `Ctrl+C` para parar.

---

### Opção 2: Rodar em Background (PowerShell)

```powershell
# Iniciar em background
Start-Process -NoNewWindow -FilePath "C:\Users\seu_usuario\kitcode\sync.bat"

# Ver processos
Get-Process cmd

# Parar o processo
Stop-Process -Name cmd -Force
```

---

### Opção 3: Task Scheduler (Executar na Inicialização)

#### Passo 1: Criar um script wrapper

Criar arquivo `C:\Users\seu_usuario\kitcode\run-sync.vbs`:
```vbs
Set objShell = CreateObject("WScript.Shell")
objShell.Run "C:\Users\seu_usuario\kitcode\sync.bat", 0, False
```

#### Passo 2: Abrir Task Scheduler

1. Pressione `Win + R`
2. Digite `taskschd.msc` e enter
3. Clique em "Create Task" (lado direito)

#### Passo 3: Configurar Task

**Aba "General":**
- Nome: `KitCode Auto Sync`
- Descrição: `Sincroniza KitCode automaticamente a cada 5 minutos`
- ✅ Marque: "Run with highest privileges"
- ✅ Marque: "Run whether user is logged in or not"

**Aba "Triggers":**
- Clique "New..."
- Begin the task: `At startup`
- OK

**Aba "Actions":**
- Clique "New..."
- Action: `Start a program`
- Program/script: `C:\Users\seu_usuario\kitcode\run-sync.vbs`
- OK

**Aba "Conditions":**
- ✅ "Start only if the computer is on AC power" (opcional)

**Aba "Settings":**
- ✅ "If the task fails, restart every 1 minute"
- ✅ "Stop the task if it runs longer than: 1 day"

Clique "OK" e pronto!

---

## 🔒 Autenticação Segura

### Usando SSH Key

1. **Gerar chave SSH (se não tiver):**
```bash
ssh-keygen -t ed25519 -C "seu_email@example.com"
```

2. **Adicionar chave ao GitHub:**
   - Ir para https://github.com/settings/keys
   - Clique "New SSH key"
   - Cole o conteúdo de `~/.ssh/id_ed25519.pub`

3. **Usar SSH no repositório:**
```bash
git remote set-url origin git@github.com:mihqe/kitcode.git
```

### Usando Personal Access Token (PAT)

1. **Criar token no GitHub:**
   - Ir para https://github.com/settings/tokens
   - Gerar novo token com permissão `repo`

2. **Guardar token com segurança:**
```bash
# macOS - Keychain
git config --global credential.helper osxkeychain

# Linux - Credential Store
git config --global credential.helper store

# Windows - Credential Manager
git config --global credential.helper manager-core
```

3. **Usar token:**
```bash
git clone https://seu_usuario:seu_token@github.com/mihqe/kitcode.git
```

---

## 📊 Monitorar a Sincronização

### Ver Logs

```bash
# Linux/macOS
tail -f ~/.kitcode_sync.log

# Windows
type %USERPROFILE%\.kitcode_sync.log
```

### Verificar se está rodando

```bash
# Linux/macOS
ps aux | grep SYNC.sh

# Windows
tasklist | find "cmd.exe"
```

---

## 🛠️ Troubleshooting

### "Permission denied" (Linux/macOS)
```bash
chmod +x SYNC.sh
./SYNC.sh
```

### "git: command not found"
- Instale Git conforme [INSTALL.md](INSTALL.md)
- Verifique PATH do Git

### "Authentication failed"
- Verifique credenciais do Git
- Verifique acesso ao repositório
- Tente usar SSH key (mais seguro)

### "fatal: Not a git repository"
- Verifique se está no diretório correto
- Reclone o repositório

### Script parou de funcionar
- Verifique conexão de internet
- Verifique permissões de arquivo
- Verifique logs

### Sincronização lenta
- Verifique tamanho do repositório
- Verifique conexão de internet
- Aumente intervalo para 600s (10 min)

---

## 🔧 Personalizar

### Mudar Intervalo de Sincronização

#### Linux/macOS (SYNC.sh)
Edite a linha:
```bash
SYNC_INTERVAL=300  # Mudar para 600 (10 minutos)
```

#### Windows (sync.bat)
Edite a linha:
```batch
set SYNC_INTERVAL=300
```

### Mudar Branch Padrão

Se seu repositório não usa `main`:
```bash
# Ver branches
git branch -a

# Editar script para usar outro branch
# Trocar "origin main" por "origin seu_branch"
```

---

## ⚠️ Importante!

1. **Backups**: Sempre faça backup antes de ativar sincronização automática
2. **Conflitos**: Se tiver mudanças locais não commitadas, o pull pode falhar
3. **Permissões**: Certifique-se de ter permissão de leitura no repositório
4. **Segurança**: Guarde suas credenciais com segurança (use SSH keys quando possível)

---

## 📞 Suporte

Se tiver problemas:
- 📖 Veja [INSTALL.md](INSTALL.md) para instalação
- 📖 Veja [USAGE.md](USAGE.md) para usar KitCode
- 🐛 Abra uma [issue no GitHub](https://github.com/mihqe/kitcode/issues)

---

**Versão:** 1.0  
**Última atualização:** 2026-04-27
