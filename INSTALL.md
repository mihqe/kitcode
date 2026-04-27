# Guia de Instalação - KitCode

## Pré-requisitos

Antes de instalar o KitCode, certifique-se de que você tem os seguintes programas instalados:

- **Git** (versão 2.0 ou superior)
- **C Compiler** (GCC ou Clang)
- **Shell** (Bash ou similar)

---

## Windows

### 1. Instalar Git
- Acesse [git-scm.com](https://git-scm.com) e baixe o instalador
- Execute o instalador e siga os passos padrão

### 2. Instalar Compilador C
- **Opção A (MinGW)**: Baixe em [mingw-w64.org](https://www.mingw-w64.org)
- **Opção B (MSVC)**: Instale Visual Studio Community (gratuito)

### 3. Clonar Repositório KitCode
```bash
git clone https://github.com/mihqe/kitcode.git
cd kitcode
```

### 4. Compilar (se necessário)
```bash
gcc -o kitcode main.c
```

---

## Linux (Ubuntu/Debian)

### 1. Instalar dependências
```bash
sudo apt update
sudo apt install -y git build-essential
```

### 2. Clonar Repositório
```bash
git clone https://github.com/mihqe/kitcode.git
cd kitcode
```

### 3. Compilar
```bash
gcc -o kitcode main.c
```

### 4. (Opcional) Instalar globalmente
```bash
sudo cp kitcode /usr/local/bin/
```

---

## macOS

### 1. Instalar Xcode Command Line Tools
```bash
xcode-select --install
```

### 2. Instalar Git (se não tiver)
```bash
brew install git
```

### 3. Clonar Repositório
```bash
git clone https://github.com/mihqe/kitcode.git
cd kitcode
```

### 4. Compilar
```bash
gcc -o kitcode main.c
```

---

## Verificar Instalação

Após instalar, verifique se tudo está funcionando:

```bash
./kitcode --version
```

Se vir o número da versão, a instalação foi bem-sucedida! ✅

---

## Solução de Problemas

**Erro: "gcc: command not found"**
- Instale o compilador C conforme instruções acima

**Erro: "git: command not found"**
- Instale Git do site oficial

**Permissão negada ao executar**
```bash
chmod +x kitcode
```

Para mais ajuda, abra uma [issue no GitHub](https://github.com/mihqe/kitcode/issues)
