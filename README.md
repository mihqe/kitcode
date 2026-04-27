# KitCode - Linguagem de Programação Brasileira

<div align="center">

![KitCode Logo](https://img.shields.io/badge/KitCode-v5.0-blue?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-Português-red?style=for-the-badge)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-orange?style=for-the-badge)

**Linguagem de programação poderosa e intuitiva desenvolvida no Brasil**

[Documentação](docs/) • [Exemplos](examples/) • [Instalação](docs/INSTALL.md) • [Contribuir](#contribuição)

</div>

## 🚀 Sobre o KitCode

KitCode é uma linguagem de programação brasileira que combina a simplicidade de linguagens modernas com o desempenho do C. Desenvolvida para ser acessível a iniciantes enquanto oferece recursos avançados para desenvolvedores experientes.

### ✨ Características Principais

- 🇧🇷 **Sintaxe em Português**: Comandos intuitivos como `diga`, `se`, `repetir`
- 🎨 **Gráficos 2D**: Sistema avançado de renderização no terminal
- 🌐 **Multiplataforma**: Windows, Linux e macOS
- ⚡ **Alta Performance**: Compilado em C com otimizações
- 💾 **Memória Expandida**: Suporte para até 10.000 variáveis
- 🔒 **Segurança**: Validação segura de entrada de dados
- 📚 **Documentação Completa**: Guias detalhados e exemplos práticos

## 🛠️ Instalação Rápida

### Pré-requisitos
- Git
- Compilador C (GCC/Clang)
- Shell (Bash ou similar)

### Linux/macOS
```bash
git clone https://github.com/mihqe/kitcode.git
cd kitcode
gcc -o kitcode src/motor_v4.c -lm
sudo cp bin/kitcode /usr/local/bin/
```

### Windows
```bash
git clone https://github.com/mihqe/kitcode.git
cd kitcode
gcc -o kitcode.exe src/motor_v4.c -lm
# Adicione kitcode.exe ao PATH do sistema
```

### Verificação
```bash
kitcode --version
```

## 📖 Guia Rápido

### Olá Mundo
```kitcode
diga "Olá, KitCode!"
```

### Variáveis e Operações
```kitcode
var numero 42
diga "O número é: " numero

calc resultado numero + 8
diga "Resultado: " resultado
```

### Estruturas de Controle
```kitcode
var idade 18
se idade >= 18
    diga "Maior de idade"
senao
    diga "Menor de idade"
fim
```

### Loops
```kitcode
var contador 0
repetir 5
    diga "Contagem: " contador
    calc contador contador + 1
fim
```

### Gráficos
```kitcode
limpar
cor 2
ponto 10 10 1 "█"
linha 5 5 20 20 3 "─"
bloco 15 15 10 5 4 "■"
```

## 📁 Estrutura do Projeto

```
kitcode/
├── src/                    # Código-fonte principal
│   └── motor_v4.c         # Motor da linguagem v5.0
├── bin/                    # Executáveis compilados
│   └── kitcode            # Executável principal
├── docs/                   # Documentação completa
│   ├── README.md          # Este arquivo
│   ├── INSTALL.md         # Guia de instalação detalhado
│   ├── USAGE.md           # Manual de uso completo
│   ├── MANUAL.md          # Manual de referência
│   ├── SHORTCUTS.md       # Atalhos e comandos
│   └── LICENSE           # Licença MIT
├── examples/               # Exemplos práticos
│   └── calculadora.kit    # Calculadora simples
├── scripts/               # Scripts auxiliares
│   ├── instalar.sh       # Instalação automática Linux
│   ├── setup_windows.bat # Instalação Windows
│   └── SYNC.sh           # Sincronização
└── .vscode/              # Configuração VS Code
```

## 🎨 Referência de Comandos

### Texto e Interface
| Comando | Descrição | Exemplo |
|---------|-----------|---------|
| `diga "texto"` | Exibe mensagem | `diga "Olá Mundo"` |
| `pergunta "prompt" var` | Solicita entrada | `pergunta "Idade: " idade` |
| `cor [0-9]` | Muda cor do texto | `cor 2` |
| `limpar` | Limpa tela | `limpar` |
| `espera N` | Pausa N segundos | `espera 2` |

### Lógica e Controle
| Comando | Descrição | Exemplo |
|---------|-----------|---------|
| `se condicao` | Estrutura condicional | `se idade >= 18` |
| `senao` | Alternativa do se | `senao` |
| `repetir N` | Loop N vezes | `repetir 5` |
| `fim` | Fecha blocos | `fim` |

### Matemática
| Comando | Descrição | Exemplo |
|---------|-----------|---------|
| `calc var op` | Calcula (+, -, *, /) | `calc resultado a + b` |
| `pot base exp` | Potência | `pot resultado 2 3` |
| `raiz numero` | Raiz quadrada | `raiz resultado 16` |
| `sorteia min max` | Número aleatório | `sorteia numero 1 100` |

### Gráficos
| Comando | Descrição | Exemplo |
|---------|-----------|---------|
| `ponto x y cor char` | Desenha ponto | `ponto 10 10 1 "█"` |
| `linha x1 y1 x2 y2 cor char` | Desenha linha | `linha 0 0 20 20 2 "─"` |
| `bloco x y larg alt cor char` | Desenha retângulo | `bloco 5 5 10 3 3 "■"` |

## 🚀 Versão 5.0 - Melhorias

- ✅ **Segurança**: Validação segura com `fgets()`
- ✅ **Capacidade**: 10.000 variáveis (2x mais)
- ✅ **Performance**: Arrays 200×200
- ✅ **Estabilidade**: Tratamento melhorado de erros
- ✅ **Organização**: Estrutura profissional de projeto
- ✅ **Documentação**: Guias completos e detalhados

## 🤝 Contribuição

Contribuições são bem-vindas! Por favor:

1. Fork este repositório
2. Crie sua feature branch (`git checkout -b feature/nova-funcionalidade`)
3. Commit suas mudanças (`git commit -m 'Adiciona nova funcionalidade'`)
4. Push para o branch (`git push origin feature/nova-funcionalidade`)
5. Abra um Pull Request

### Diretrizes de Contribuição
- Mantenha o código limpo e comentado
- Siga o estilo de código existente
- Adicione testes para novas funcionalidades
- Atualize a documentação quando necessário

## 📄 Licença

Este projeto está licenciado sob a Licença MIT - veja o arquivo [LICENSE](docs/LICENSE) para detalhes.

## 🐛 Reportar Bugs

Encontrou um bug? [Abra uma issue](https://github.com/mihqe/kitcode/issues) com:

- Descrição detalhada do problema
- Passos para reproduzir
- Ambiente (SO, versão do KitCode)
- Logs ou screenshots (se aplicável)

## 💬 Discussões

Dúvidas, sugestões ou ideias? [Participe das discussões](https://github.com/mihqe/kitcode/discussions)

## 📞 Suporte

- 📖 [Documentação Completa](docs/)
- 💬 [GitHub Discussions](https://github.com/mihqe/kitcode/discussions)
- 🐛 [Reportar Issues](https://github.com/mihqe/kitcode/issues)
- 📧 [Contato via GitHub Issues](https://github.com/mihqe/kitcode/issues)

## 🏆 Créditos

- Desenvolvido com ❤️ no Brasil
- Mantido pela comunidade open source
- Contribuidores: [Veja no GitHub](https://github.com/mihqe/kitcode/graphs/contributors)

## ⚖️ Avisos Importantes

### 🛡️ Segurança e Responsabilidade
- **Use por conta e risco**: Sem garantias de qualquer tipo
- **Responsabilidade do usuário**: Pela segurança e uso adequado
- **Revisão necessária**: Teste antes de usar em produção
- [Política de Segurança Completa](docs/SECURITY.md)

### ⚠️ Termos Legais
- **Isenção de responsabilidade**: Não nos responsabilizamos por danos
- **Uso de IA**: Parte do desenvolvimento assistida por IA, revisada por humanos
- **Direitos autorais**: Licenciado sob MIT com atribuição obrigatória
- [Termos Legais Completos](docs/LEGAL.md)

### 🚫 Usos Proibidos
- Desenvolvimento de malware ou atividades ilegais
- Ataques cibernéticos ou hacking não autorizado
- Violação de privacidade ou fraude eletrônica

---

<div align="center">

**[⬆️ Voltar ao Topo](#kitcode---linguagem-de-programação-brasileira)**

Made with ❤️ in Brazil • Use com responsabilidade

</div>
