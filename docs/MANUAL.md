# 📚 Manual KitCode 3.0 - Kit Shell & Corretor

Bem-vindo ao **KitCode**, uma linguagem de programação didática em português que permite criar scripts simples e interativos!

---

## 📖 Índice

1. [Instalação](#instalação)
2. [Como Usar](#como-usar)
3. [Comandos](#comandos)
4. [Exemplos](#exemplos)
5. [Dicas & Truques](#dicas--truques)
6. [Solução de Problemas](#solução-de-problemas)

---

## 🚀 Instalação

### Pré-requisitos
- Compilador C (gcc, clang ou similar)
- Sistema operacional: Windows, Linux ou macOS

### Compilar

```bash
gcc -o kitcode motor_v3.c -lm
```

**Nota:** O parâmetro `-lm` é necessário para usar funções matemáticas como `pot` (potência).

### Estrutura do Repositório

```
kitcode/
├── motor_v3.c          # Código-fonte principal
├── MANUAL.md           # Este arquivo
├── README.md           # Informações gerais
├── exemplos/           # Scripts de exemplo
│   ├── hello.kit
│   ├── matematica.kit
│   └── cores.kit
└── LICENSE             # Licença do projeto
```

---

## 💻 Como Usar

### Modo Interativo (Shell)

Execute sem argumentos para entrar no modo shell interativo:

```bash
./kitcode
```

Você verá a tela:
```
=== KITCODE SHELL 3.0 ===
Digite comandos ao vivo ou 'sair'.

Kit> 
```

Digite seus comandos diretamente e pressione **Enter**. Para sair, digite `sair`.

### Modo Arquivo

Execute um arquivo de script KitCode:

```bash
./kitcode seu_script.kit
```

KitCode lerá e executará todos os comandos do arquivo sequencialmente.

---

## 🎮 Comandos

### 1. **diga** - Imprime texto ou variáveis

**Sintaxe:**
```
diga "seu texto aqui"
diga "texto com variavel" variavel
```

**Exemplos:**
```
diga "Olá, Mundo!"
diga "O valor é:" resultado
```

**Resultado:**
```
Olá, Mundo!
O valor é: 42
```

---

### 2. **limpar** - Limpa a tela

**Sintaxe:**
```
limpar
```

Remove todo o conteúdo da tela do console.

---

### 3. **cor** - Define a cor do texto

**Sintaxe:**
```
cor N
```

Onde **N** é um número de 0 a 7:

| Número | Cor      |
|--------|----------|
| 0      | Preto    |
| 1      | Vermelho |
| 2      | Verde    |
| 3      | Amarelo  |
| 4      | Azul     |
| 5      | Magenta  |
| 6      | Ciano    |
| 7      | Branco   |

**Exemplo:**
```
cor 2
diga "Texto em verde!"
```

---

### 4. **pot** - Calcula potência

**Sintaxe:**
```
pot variavel base expoente
```

Calcula **base^expoente** e armazena o resultado em **variavel**.

**Exemplo:**
```
pot resultado 2 3
diga "2 elevado a 3 =" resultado
```

**Resultado:**
```
2 elevado a 3 = 8
```

---

### 5. **ir** - Desvio condicional

**Sintaxe:**
```
ir linha_numero
```

Salta para a linha especificada (apenas em modo arquivo).

---

### 6. **janela** - Configura tamanho da janela

**Sintaxe:**
```
janela largura altura
```

Define as dimensões da janela do console.

---

### 7. **repetir / fim** - Loop

**Sintaxe:**
```
repetir numero
  comandos aqui
fim
```

Executa os comandos entre `repetir` e `fim` **numero** vezes.

**Exemplo:**
```
repetir 3
  diga "Olá!"
fim
```

**Resultado:**
```
Olá!
Olá!
Olá!
```

---

### 8. **lista** - Cria uma lista/array

**Sintaxe:**
```
lista nome indice valor
```

Armazena um valor em uma posição de um array.

---

### 9. **pega_lista** - Acessa um valor da lista

**Sintaxe:**
```
pega_lista variavel nome indice
```

Recupera um valor da lista e armazena em **variavel**.

---

### 10. **espera** - Aguarda tempo

**Sintaxe:**
```
espera millisegundos
```

Pausa a execução pelo tempo especificado (em milissegundos).

**Exemplo:**
```
espera 1000
```

Aguarda 1 segundo.

---

### 11. **esconde** - Esconde elementos

**Sintaxe:**
```
esconde
```

---

### 12. **mostra** - Mostra elementos

**Sintaxe:**
```
mostra
```

---

### 13. **sair** - Encerra o programa

**Sintaxe:**
```
sair
```

Fecha o KitCode imediatamente.

---

## 📝 Exemplos

### Exemplo 1: Olá Mundo

**arquivo: hello.kit**
```
diga "Olá, Mundo!"
```

Executa com:
```bash
./kitcode hello.kit
```

---

### Exemplo 2: Operações Matemáticas

**arquivo: matematica.kit**
```
# Comentários começam com #
pot resultado 2 8
diga "2 elevado a 8 =" resultado

pot quadrado 5 2
diga "5 ao quadrado =" quadrado
```

---

### Exemplo 3: Usando Cores

**arquivo: cores.kit**
```
limpar

cor 2
diga "Texto em VERDE"

cor 1
diga "Texto em VERMELHO"

cor 4
diga "Texto em AZUL"

cor 6
diga "Texto em CIANO"

cor 0
```

---

### Exemplo 4: Loop com Repetição

**arquivo: contador.kit**
```
diga "Contando de 1 a 5:"
repetir 5
  diga "Número!"
fim
```

---

### Exemplo 5: Interativo no Shell

```bash
./kitcode
```

```
=== KITCODE SHELL 3.0 ===
Digite comandos ao vivo ou 'sair'.

Kit> diga "Bem vindo!"
Bem vindo!
Kit> cor 2
Kit> diga "Estou em verde!"
Estou em verde!
Kit> sair
Fechando KitCode...
```

---

## 💡 Dicas & Truques

### 1. **Use comentários**
Linhas começando com `#` são ignoradas. Use para documentar seu código!

```
# Isto é um comentário
# Este script faz X coisa
diga "Código aqui"
```

### 2. **Corretor Ortográfico Automático**
Digitou um comando errado? O KitCode vai sugerir:

```
Kit> diga "oi"
Comando 'diga' desconhecido.
[DICA] Voce quis dizer 'diga'?
```

Se as **duas primeiras letras** baterem com um comando oficial, ele sugere!

### 3. **Armazene resultados em variáveis**
```
pot dobro 5 1
diga "5 + 5 =" dobro
```

### 4. **Combine cores com textos**
```
cor 1
diga "AVISO!"
cor 7
diga "Texto normal"
```

### 5. **Limpe a tela no começo**
```
limpar
diga "Nova tela!"
```

---

## 🐛 Solução de Problemas

### Problema: "Erro ao compilar"

**Solução:**
Certifique-se de que tem o compilador C instalado:

```bash
gcc --version
```

Se não tiver, instale:
- **Linux (Ubuntu/Debian):** `sudo apt-get install build-essential`
- **macOS:** Instale Xcode Command Line Tools
- **Windows:** Instale MinGW ou TDM-GCC

---

### Problema: "Comando desconhecido"

**Solução:**
Verifique a ortografia. O KitCode é **sensível a maiúsculas e minúsculas**:

```
❌ DIGA "Oi"     (errado)
✅ diga "Oi"     (correto)
```

---

### Problema: "-lm: comando não encontrado"

**Solução:**
Use a flag `-lm` na compilação:

```bash
gcc -o kitcode motor_v3.c -lm
```

---

### Problema: Cores não aparecem no Windows

**Solução:**
Algumas versões antigas do Windows não suportam códigos ANSI. Use o Windows Terminal ou PowerShell moderno.

---

## 📚 Referência Rápida

| Comando | Uso |
|---------|-----|
| `diga` | Imprime texto/variáveis |
| `limpar` | Limpa a tela |
| `cor N` | Muda cor (0-7) |
| `pot var base exp` | Calcula potência |
| `ir linha` | Salta para linha |
| `janela L A` | Define tamanho |
| `repetir N` | Loop N vezes |
| `fim` | Fim do loop |
| `lista nome idx val` | Array |
| `pega_lista var nome idx` | Acessa array |
| `espera ms` | Aguarda (ms) |
| `sair` | Encerra |

---

## 🤝 Contribuições

Quer melhorar o KitCode? Contribuições são bem-vindas!

1. Faça um fork do repositório
2. Crie uma branch para sua feature
3. Commit suas mudanças
4. Push e abra um Pull Request

---

## 📄 Licença

Este projeto está sob a licença **MIT**. Veja o arquivo `LICENSE` para mais detalhes.

---

## 👨‍💻 Autor

Desenvolvido com ❤️ por **mihqe**

---

## ❓ Dúvidas?

Abra uma **Issue** no repositório ou consulte os exemplos fornecidos!

**Divirta-se codificando em KitCode!** 🚀
