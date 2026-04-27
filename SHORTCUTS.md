# Manual de Atalhos - KitCode

## 📌 O que é um Atalho?

Um atalho permite executar o KitCode de qualquer lugar do seu computador sem precisar estar no diretório do repositório. É muito mais prático!

---

## 🪟 Windows

### Opção 1: Atalho na Inicialização (Sync Automático)

#### Passo 1: Localizar a pasta de Startup

1. Pressione `Windows + R`
2. Digite: `shell:startup`
3. Pressione Enter

Uma pasta se abrirá automaticamente. Deixe-a aberta.

#### Passo 2: Criar o Atalho

1. Clique com botão direito na pasta vazia
2. Selecione: **"Novo"** → **"Atalho"**
3. Na janela que abrir, cole o caminho:
```
C:\Users\SEU_USUARIO\kitcode\sync.bat
```
(Substitua `SEU_USUARIO` pelo seu nome de usuário)

4. Clique em **"Avançar"**
5. Digite o nome: `KitCode Auto Sync`
6. Clique em **"Concluir"**

Pronto! Agora o script sincroniza automaticamente quando você inicia o Windows! ✅

---

### Opção 2: Atalho na Área de Trabalho

#### Passo 1: Criar o Atalho

1. Clique com botão direito na **Área de Trabalho**
2. Selecione: **"Novo"** → **"Atalho"**
3. Cole o caminho:
```
C:\Users\SEU_USUARIO\kitcode\sync.bat
```

4. Clique em **"Avançar"**
5. Digite o nome: `KitCode Sync`
6. Clique em **"Concluir"**

#### Passo 2: Personalizar o Atalho (Opcional)

1. Clique com botão direito no atalho
2. Selecione **"Propriedades"**
3. Na aba "Atalho":
   - **Iniciar em**: `C:\Users\SEU_USUARIO\kitcode`
   - **Executar**: Selecione "Minimizado" para rodar em background
4. Clique em "Aplicar" → "OK"

Agora você pode clicar no atalho da área de trabalho para sincronizar! ✅

---

### Opção 3: Adicionar ao Menu Iniciar

1. Pressione `Windows`
2. Digite: `KitCode`
3. Clique com botão direito no resultado
4. Selecione: **"Fixar ao menu Iniciar"**

Agora você encontra KitCode direto no Menu Iniciar! ✅

---

### Opção 4: Atalho de Teclado Global

1. Crie um atalho na área de trabalho (Opção 2)
2. Clique com botão direito nele → **"Propriedades"**
3. Na aba "Atalho", clique em **"Tecla de Atalho"**
4. Pressione uma combinação (Ex: `Ctrl + Alt + K`)
5. Clique "Aplicar" → "OK"

Agora você pode pressionar `Ctrl + Alt + K` para sincronizar de qualquer lugar! ✅

---

## 🐧 Linux

### Opção 1: Atalho no Menu de Aplicações

#### Passo 1: Criar arquivo .desktop

Abra o terminal e execute:

```bash
nano ~/.local/share/applications/kitcode-sync.desktop
```

#### Passo 2: Adicionar Conteúdo

Cole o seguinte:

```ini
[Desktop Entry]
Type=Application
Name=KitCode Auto Sync
Comment=Sincroniza automaticamente o repositório KitCode
Exec=/home/SEU_USUARIO/kitcode/SYNC.sh
Icon=system-software-update
Categories=Utility;Development;
Terminal=true
```

(Substitua `SEU_USUARIO` pelo seu nome de usuário)

#### Passo 3: Salvar

Pressione `Ctrl + X`, depois `Y`, depois `Enter`

Agora o KitCode aparece no seu menu de aplicações! ✅

---

### Opção 2: Alias no Terminal

#### Passo 1: Editar .bashrc

```bash
nano ~/.bashrc
```

#### Passo 2: Adicionar Alias

Vá para o final do arquivo e adicione:

```bash
# KitCode Aliases
alias kitcode-sync='/home/SEU_USUARIO/kitcode/SYNC.sh'
alias kitcode='cd /home/SEU_USUARIO/kitcode'
alias kit-help='cat /home/SEU_USUARIO/kitcode/USAGE.md'
```

#### Passo 3: Salvar

Pressione `Ctrl + X`, depois `Y`, depois `Enter`

#### Passo 4: Aplicar Mudanças

```bash
source ~/.bashrc
```

Agora você pode usar:
- `kitcode-sync` - Inicia sincronização
- `kitcode` - Entra no diretório
- `kit-help` - Vê o manual

✅

---

### Opção 3: Atalho na Área de Trabalho

#### Passo 1: Criar arquivo .desktop na Área de Trabalho

```bash
nano ~/Desktop/KitCode-Sync.desktop
```

#### Passo 2: Adicionar Conteúdo

```ini
[Desktop Entry]
Type=Application
Name=KitCode Sync
Exec=/home/SEU_USUARIO/kitcode/SYNC.sh
Terminal=true
Icon=system-software-update
```

#### Passo 3: Dar Permissão

```bash
chmod +x ~/Desktop/KitCode-Sync.desktop
```

Agora tem um atalho na Área de Trabalho! ✅

---

### Opção 4: Atalho de Teclado Global

#### Para GNOME (Ubuntu):

1. Abra **Configurações**
2. Vá em **Teclado**
3. Clique em **Atalhos Personalizados**
4. Clique em **"+"** para adicionar novo
5. Nome: `KitCode Sync`
6. Comando: `/home/SEU_USUARIO/kitcode/SYNC.sh`
7. Clique em **Definir Atalho** e pressione uma combinação (Ex: `Super + K`)

Pronto! Agora `Super + K` sincroniza! ✅

---

## 🍎 macOS

### Opção 1: Atalho na Inicialização (LaunchAgent)

#### Passo 1: Criar arquivo plist

```bash
nano ~/Library/LaunchAgents/com.kitcode.sync.plist
```

#### Passo 2: Adicionar Conteúdo

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>Label</key>
    <string>com.kitcode.sync</string>
    <key>ProgramArguments</key>
    <array>
        <string>/Users/SEU_USUARIO/kitcode/SYNC.sh</string>
    </array>
    <key>RunAtLoad</key>
    <true/>
    <key>KeepAlive</key>
    <true/>
</dict>
</plist>
```

(Substitua `SEU_USUARIO` pelo seu nome de usuário)

#### Passo 3: Salvar

Pressione `Ctrl + X`, depois `Y`, depois `Enter`

#### Passo 4: Ativar

```bash
launchctl load ~/Library/LaunchAgents/com.kitcode.sync.plist
```

Pronto! Sincroniza automaticamente na inicialização! ✅

---

### Opção 2: Alias no Terminal

#### Passo 1: Editar .zshrc ou .bash_profile

```bash
nano ~/.zshrc
```

(Se usar bash, abra `~/.bash_profile`)

#### Passo 2: Adicionar Alias

```bash
# KitCode Aliases
alias kitcode-sync='/Users/SEU_USUARIO/kitcode/SYNC.sh'
alias kitcode='cd /Users/SEU_USUARIO/kitcode'
alias kit-help='cat /Users/SEU_USUARIO/kitcode/USAGE.md'
```

#### Passo 3: Salvar

Pressione `Ctrl + X`, depois `Y`, depois `Enter`

#### Passo 4: Aplicar

```bash
source ~/.zshrc
```

Agora pode usar os comandos! ✅

---

### Opção 3: Atalho de Teclado com Automator

#### Passo 1: Abrir Automator

1. Abra **Spotlight** (Cmd + Space)
2. Digite `Automator` e pressione Enter

#### Passo 2: Criar Nova Automação

1. Clique em **"Novo"**
2. Selecione **"Aplicação Rápida"** (Quick Action)

#### Passo 3: Adicionar Script

1. Procure por **"Executar Script Shell"**
2. Arraste para o painel direito
3. Cole:
```bash
/Users/SEU_USUARIO/kitcode/SYNC.sh
```

#### Passo 4: Salvar

1. Pressione `Cmd + S`
2. Nome: `KitCode Sync`
3. Clique em "Salvar"

#### Passo 5: Configurar Atalho

1. Abra **Preferências do Sistema**
2. Vá em **Teclado** → **Atalhos** → **Serviços**
3. Procure por **"KitCode Sync"**
4. Clique e defina uma combinação de teclas

Pronto! ✅

---

## 📋 Resumo de Atalhos Recomendados

| Sistema | Tipo | Comando/Atalho |
|---------|------|---|
| **Windows** | Inicialização | Atalho em `shell:startup` |
| **Windows** | Teclado | `Ctrl + Alt + K` |
| **Linux** | Menu | Aplicativo no menu de apps |
| **Linux** | Terminal | `kitcode-sync` |
| **Linux** | Teclado | `Super + K` |
| **macOS** | Inicialização | LaunchAgent |
| **macOS** | Terminal | `kitcode-sync` |
| **macOS** | Teclado | `Cmd + K` |

---

## 🔧 Dicas Adicionais

### Executar Sem Janela do Terminal (Windows)

Crie um arquivo `run-sync-hidden.vbs`:

```vbs
Set objShell = CreateObject("WScript.Shell")
objShell.Run "C:\Users\SEU_USUARIO\kitcode\sync.bat", 0, False
```

Depois crie um atalho para este arquivo `.vbs` em vez do `.bat`

### Executar com Privilégios de Administrador (Windows)

1. Crie o atalho normalmente
2. Clique com botão direito → **Propriedades**
3. Clique em **"Avançado"**
4. Marque **"Executar como Administrador"**
5. Clique "OK"

### Executar em Segundo Plano (macOS/Linux)

Adicione `&` no final do comando:

```bash
alias kitcode-sync='/Users/SEU_USUARIO/kitcode/SYNC.sh &'
```

---

## ❓ Troubleshooting

**P: O atalho não funciona**
- Verifique se o caminho está correto
- Verifique permissões do arquivo
- Teste o comando diretamente no terminal

**P: Aparece erro de permissão**
- Use `chmod +x` no Linux/macOS
- Use "Executar como Administrador" no Windows

**P: Não consegui salvar o arquivo**
- Verifique se tem permissão na pasta
- Tente criar em outro local

**P: Atalho de teclado não funciona**
- Verifique se a combinação já está em uso
- Tente outra combinação

---

## 🎯 Próximos Passos

1. Escolha o método de atalho que preferir
2. Siga os passos conforme seu S.O.
3. Teste para verificar se funciona
4. Aproveite a conveniência! 🚀

---

**Versão:** 1.0  
**Última atualização:** 2026-04-27
