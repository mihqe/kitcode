# KitCode 🎨

Uma **linguagem de programação didática em português** que permite criar scripts simples e interativos com suporte a comandos em linguagem natural, corretor ortográfico automático e um ambiente shell interativo!

## ✨ Features

- 🎯 **Linguagem em Português**: Comandos como `diga`, `repetir`, `cor`, `pot`
- 🤖 **Corretor Ortográfico Inteligente**: Sugestões automáticas para comandos digitados incorretamente
- 💻 **Modo Shell Interativo**: Execute comandos em tempo real
- 📄 **Modo Arquivo**: Crie e execute scripts `.kit`
- 🎨 **Sistema de Cores**: 8 cores diferentes para personalizar a saída
- 🔢 **Operações Matemáticas**: Cálculo de potências e outras operações
- 🔁 **Loops e Desvios**: Controle de fluxo com `repetir/fim` e `ir`
- 📦 **Variáveis e Arrays**: Armazene e manipule dados

## 🚀 Quick Start

### Compilar

```bash
gcc -o kitcode motor_v3.c -lm
```

### Modo Shell Interativo

```bash
./kitcode
```

```
=== KITCODE SHELL 3.0 ===
Digite comandos ao vivo ou 'sair'.

Kit> diga "Olá, Mundo!"
Olá, Mundo!
Kit> sair
Fechando KitCode...
```

### Executar um Script

```bash
./kitcode exemplos/hello.kit
```

## 📚 Exemplos

### Olá Mundo

```
diga "Olá, Mundo!"
```

### Operações Matemáticas

```
pot resultado 2 8
diga "2 elevado a 8 =" resultado
```

### Loop

```
repetir 3
  diga "Olá!"
fim
```

### Cores

```
cor 2
diga "Texto em verde!"
```

## 📖 Documentação

Consulte o **[MANUAL.md](MANUAL.md)** para uma documentação completa com:
- Lista de todos os comandos
- Exemplos detalhados
- Dicas e truques
- Solução de problemas
- Referência rápida

## 📁 Estrutura

```
kitcode/
├── motor_v3.c          # Código-fonte principal
├── MANUAL.md           # Manual completo em PT-BR
├── README.md           # Este arquivo
├── exemplos/           # Scripts de exemplo
│   ├── hello.kit
│   ├── matematica.kit
│   ├── cores.kit
│   ├── loops.kit
│   └── avancado.kit
└── LICENSE
```

## 🎮 Comandos Principais

| Comando | Descrição |
|---------|-----------|
| `diga` | Imprime texto ou variáveis |
| `cor N` | Define cor (0-7) |
| `pot` | Calcula potência |
| `repetir/fim` | Loop |
| `limpar` | Limpa tela |
| `espera` | Aguarda (ms) |
| `sair` | Encerra |

## 🤖 Corretor Ortográfico

Digite um comando errado e o KitCode sugere:

```
Kit> dig "oi"
[ERRO] Comando 'dig' desconhecido.
[DICA] Voce quis dizer 'diga'?
```

## 💡 Features Destacadas

✅ **Compilação rápida e leve**  
✅ **Sem dependências externas**  
✅ **Multiplataforma** (Windows, Linux, macOS)  
✅ **Suporte a comentários** (`#`)  
✅ **Modo interativo responsivo**  

## 🛠️ Compilação com Debug

```bash
gcc -g -o kitcode motor_v3.c -lm
```

## 📝 Exemplos Rápidos

### Teste de Cores

```bash
./kitcode exemplos/cores.kit
```

### Demonstração Matemática

```bash
./kitcode exemplos/matematica.kit
```

### Programa Avançado

```bash
./kitcode exemplos/avancado.kit
```

## 🐛 Problemas Conhecidos

- Windows antigo pode não suportar cores ANSI (use Windows Terminal)
- O compilador precisa da flag `-lm` para funções matemáticas

## 🤝 Contribuições

Contribuições são bem-vindas! Abra uma **Issue** ou **Pull Request** para melhorias.

## 📄 Licença

MIT License - Veja [LICENSE](LICENSE) para detalhes

## 👨‍💻 Autor

Desenvolvido com ❤️ por **mihqe**

---

**Divirta-se codificando em KitCode!** 🎨✨
