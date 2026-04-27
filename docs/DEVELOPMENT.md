# Guia de Desenvolvimento KitCode

## Overview

Este guia é destinado a desenvolvedores que desejam contribuir com o projeto KitCode, entender sua arquitetura interna ou criar extensões.

## Arquitetura do Sistema

### Estrutura Principal

```
KitCode (Linguagem)
├── Motor C (src/motor_v4.c)
│   ├── Interpretador de comandos
│   ├── Sistema de memória
│   ├── Renderização gráfica
│   └── Interface de sistema
├── Compilador (GCC/Clang)
└── Runtime (Executável)
```

### Componentes do Motor

#### 1. Sistema de Memória
```c
typedef struct { 
    char n[50];  // Nome da variável
    double v;    // Valor numérico
} Var;

Var mem[10000];           // Array de variáveis
int total_vars = 0;       // Contador de variáveis
```

#### 2. Sistema de Arrays
```c
double vetores[200][200]; // Arrays bidimensionais
```

#### 3. Sistema de Controle
```c
int loop_inicio[200];     // Início dos loops
int loop_conta[200];      // Contador de repetições
int lvl_loop = 0;         // Nível de aninhamento

int stack_se[200];        // Stack de condições
int lvl_se = 0;           // Nível de aninhamento
```

## Compilação e Build

### Requisitos
- GCC 4.0+ ou Clang 3.0+
- Biblioteca matemática (-lm)
- Git

### Processo de Compilação
```bash
# Compilação padrão
gcc -o kitcode src/motor_v4.c -lm

# Compilação com otimizações
gcc -O3 -o kitcode src/motor_v4.c -lm

# Debug
gcc -g -DDEBUG -o kitcode src/motor_v4.c -lm

# Release
gcc -O3 -DNDEBUG -o kitcode src/motor_v4.c -lm
```

### Flags de Compilação
- `-O3`: Otimização máxima
- `-g`: Informações de debug
- `-DDEBUG`: Ativa modo debug
- `-DNDEBUG`: Desativa asserts
- `-Wall`: Todos os warnings
- `-Wextra`: Warnings extras

## Estrutura do Código

### Funções Principais

#### `executar_linha(char *ln)`
Função principal que interpreta cada linha de código.

**Parâmetros:**
- `ln`: Linha de código a ser executada

**Processo:**
1. Parse da linha em tokens
2. Identificação do comando
3. Execução da função correspondente
4. Atualização de estado

#### `set_n(char *n, double v)`
Define ou atualiza valor de variável.

**Parâmetros:**
- `n`: Nome da variável
- `v`: Valor a ser atribuído

#### `get_n(char *n)`
Recupera valor de variável.

**Parâmetros:**
- `n`: Nome da variável

**Retorno:** Valor da variável ou conversão do nome para número

### Sistema de Comandos

#### Categorias de Comandos
1. **Texto e Interface**: `diga`, `pergunta`, `cor`, `limpar`
2. **Lógica e Controle**: `se`, `repetir`, `fim`
3. **Matemática**: `calc`, `pot`, `raiz`, `hipo`
4. **Gráficos**: `ponto`, `linha`, `bloco`, `janela`
5. **Sistema**: `var`, `tecla`, `espera`, `sair`

#### Adicionando Novos Comandos

1. **Identificar a categoria** do novo comando
2. **Adicionar case** na função `executar_linha()`
3. **Implementar função específica** (se necessário)
4. **Adicionar documentação** em `docs/API.md`
5. **Criar testes** em `examples/`

**Exemplo - Novo Comando:**
```c
// Na função executar_linha()
else if(strcmp(p1, "novo_comando") == 0) {
    // Implementação do comando
    printf("Executando novo comando\n");
}
```

## Sistema Gráfico

### Cores ANSI
```c
printf("\033[1;3%dm", cor);  // Define cor
```

**Cores disponíveis:**
- 0: Reset/Padrão
- 1: Vermelho
- 2: Verde
- 3: Amarelo
- 4: Azul
- 5: Magenta
- 6: Ciano
- 7: Branco

### Posicionamento
```c
printf("\033[%d;%dH", y, x);  // Move cursor para (x,y)
```

### Algoritmo de Bresenham
Para desenhar linhas perfeitas:
```c
void desenhar_linha(int x0, int y0, int x1, int y1, int cor, char *c) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;
    
    printf("\033[1;3%dm", cor);
    while(1) {
        printf("\033[%d;%dH%s", y0, x0, c);
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
    fflush(stdout);
}
```

## Sistema de Entrada/Saída

### Leitura Segura
```c
void pergunta_seguro(char *prompt, char *variavel) {
    printf("%s ", prompt);
    char in[100];
    if(fgets(in, sizeof(in), stdin)) {
        in[strcspn(in, "\n")] = '\0';
        set_n(variavel, atof(in));
    }
}
```

### Leitura de Teclas
```c
int ler_tecla() {
    struct termios oldt, newt; int ch;
    tcgetattr(STDIN_FILENO, &oldt); 
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
    int oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if(ch < 0) return 0; 
    return ch;
}
```

## Debug e Testes

### Modo Debug
Compile com `-DDEBUG` para ativar informações de depuração.

### Testes Unitários
Crie testes na pasta `tests/`:

```c
// tests/test_math.c
#include "../src/motor_v4.c"

void test_calc() {
    set_n("a", 10);
    set_n("b", 5);
    executar_linha("calc resultado a + b");
    assert(get_n("resultado") == 15);
}
```

### Validação de Memória
```bash
# Valgrind para detectar leaks
valgrind --leak-check=full ./kitcode script.kit
```

## Performance

### Otimizações Atuais
- Busca linear em variáveis (O(n))
- Arrays de acesso direto (O(1))
- Renderização otimizada com ANSI

### Possíveis Melhorias
1. **Hash table** para variáveis
2. **Cache** de comandos frequentes
3. **Buffer** de saída
4. **JIT compilation** para loops

### Benchmarks
```bash
# Teste de performance
time ./kitcode examples/benchmark.kit
```

## Extensões e Plugins

### Sistema de Plugins (Futuro)
```c
typedef struct {
    char nome[50];
    void (*executar)(char *parametros);
} Plugin;

Plugin plugins[100];
int total_plugins = 0;
```

### Comandos Customizados
```c
void registrar_comando(char *nome, void (*func)(char *)) {
    // Registrar novo comando
}
```

## Boas Práticas de Desenvolvimento

### Código
- Mantenha funções pequenas e focadas
- Use nomes descritivos
- Comente lógica complexa
- Valide entradas e saídas

### Commits
- Mensagens claras e descritivas
- Commits atômicos
- Referencie issues quando aplicável

### Documentação
- Mantenha API.md atualizado
- Adicione exemplos para novos comandos
- Documente mudanças significativas

## Release Process

### Versionamento Semântico
- **MAJOR**: Mudanças que quebram compatibilidade
- **MINOR**: Novas funcionalidades (backward compatible)
- **PATCH**: Correções de bugs

### Checklist de Release
1. [ ] Todos os testes passando
2. [ ] Documentação atualizada
3. [ ] Changelog atualizado
4. [ ] Versão incrementada
5. [ ] Tag criada
6. [ ] Release publicado

## Contribuição

### Fluxo de Trabalho
1. Fork do repositório
2. Branch para feature/bugfix
3. Desenvolvimento com testes
4. Pull request com descrição
5. Code review
6. Merge

### Code Review
- Verificar funcionalidade
- Testar em múltiplos SOs
- Validar performance
- Revisar documentação

## Troubleshooting

### Problemas Comuns

#### Compilação
```bash
# Erro: undefined reference to math functions
# Solução: adicionar -lm
gcc -o kitcode src/motor_v4.c -lm
```

#### Runtime
```bash
# Erro: segmentation fault
# Solução: verificar bounds de arrays
```

#### Performance
```bash
# Erro: execução lenta
# Solução: reduzir número de variáveis ou loops
```

### Debug Avançado
```bash
# GDB para debug interativo
gdb ./kitcode
(gdb) run script.kit
(gdb) bt
```

## Roadmap Futuro

### v5.1
- [ ] Sistema de strings nativo
- [ ] Funções de manipulação de texto
- [ ] Melhor tratamento de erros

### v5.2
- [ ] Sistema de arquivos
- [ ] Networking básico
- [ ] Plugin system

### v6.0
- [ ] Compilador JIT
- [ ] Orientação a objetos
- [ ] Garbage collector

---

**Para dúvidas, abra uma issue ou contate a equipe de desenvolvimento.**
