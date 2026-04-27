# Guia de Uso - KitCode

## Introdução

KitCode é uma linguagem de programação poderosa e flexível, combinando o desempenho do C com a simplicidade de linguagens modernas.

---

## Sintaxe Básica

### Variáveis e Tipos

```kitcode
// Inteiros
int numero = 42;
long grande_numero = 999999999;

// Números decimais
float valor = 3.14;
double precisao = 3.141592653589793;

// Texto
string nome = "João";
char letra = 'A';

// Booleano
bool ativo = true;
```

### Entrada e Saída

```kitcode
// Saída (print)
print("Olá, Mundo!");
println("Com quebra de linha");

// Entrada (input)
string entrada = input("Digite algo: ");
int numero = inputInt("Digite um número: ");
float valor = inputFloat("Digite um valor: ");
```

---

## Operadores

### Aritméticos
```kitcode
int a = 10;
int b = 3;

int soma = a + b;        // 13
int subtracao = a - b;   // 7
int multiplicacao = a * b;  // 30
int divisao = a / b;     // 3
int resto = a % b;       // 1
int potencia = a ^ b;    // 1000
```

### Comparação
```kitcode
bool igual = (a == b);       // false
bool diferente = (a != b);   // true
bool maior = (a > b);        // true
bool menor = (a < b);        // false
bool maiorIgual = (a >= b);  // true
bool menorIgual = (a <= b);  // false
```

### Lógicos
```kitcode
bool e = (true && false);    // false
bool ou = (true || false);   // true
bool nao = !true;            // false
```

---

## Condicionais

### If/Else

```kitcode
int idade = 20;

if (idade >= 18) {
    println("Maior de idade");
} else if (idade >= 13) {
    println("Adolescente");
} else {
    println("Criança");
}
```

### Switch

```kitcode
int dia = 3;

switch (dia) {
    case 1:
        println("Segunda");
        break;
    case 2:
        println("Terça");
        break;
    case 3:
        println("Quarta");
        break;
    default:
        println("Outro dia");
}
```

---

## Loops

### While

```kitcode
int contador = 0;

while (contador < 5) {
    println("Contador: " + contador);
    contador = contador + 1;
}
```

### For

```kitcode
for (int i = 0; i < 10; i++) {
    println("Iteração " + i);
}
```

### Do-While

```kitcode
int x = 0;

do {
    println("Valor: " + x);
    x = x + 1;
} while (x < 5);
```

### For-Each (Arrays)

```kitcode
array numeros = [1, 2, 3, 4, 5];

for (int num in numeros) {
    println(num);
}
```

---

## Funções

### Definir Função

```kitcode
function int somar(int a, int b) {
    return a + b;
}

// Chamar função
int resultado = somar(5, 3);  // 8
```

### Função sem retorno

```kitcode
function saudacao(string nome) {
    println("Olá, " + nome + "!");
}

saudacao("Maria");  // Imprime: Olá, Maria!
```

### Funções com múltiplos parâmetros

```kitcode
function bool verificarIdade(int idade, string nome) {
    if (idade >= 18) {
        println(nome + " é maior de idade");
        return true;
    }
    return false;
}
```

---

## Arrays

### Declarar e Inicializar

```kitcode
// Array de inteiros
array numeros = [1, 2, 3, 4, 5];

// Array vazio
array vazio = [];

// Array com diferentes tipos
array misto = [1, "texto", 3.14, true];
```

### Acessar elementos

```kitcode
array cores = ["vermelho", "azul", "verde"];

string primeira = cores[0];   // "vermelho"
string ultima = cores[2];     // "verde"

// Modificar elemento
cores[1] = "amarelo";
```

### Funções de Array

```kitcode
array nums = [5, 2, 8, 1];

int tamanho = len(nums);          // 4
int maximo = max(nums);            // 8
int minimo = min(nums);            // 1

array ordenado = sort(nums);       // [1, 2, 5, 8]
bool contem = includes(nums, 5);  // true

nums = push(nums, 10);  // Adiciona 10 no final
nums = pop(nums);       // Remove o último elemento
```

---

## Strings

### Manipulação de Strings

```kitcode
string texto = "KitCode";

int comprimento = len(texto);           // 7
string maiuscula = toUpper(texto);      // "KITCODE"
string minuscula = toLower(texto);      // "kitcode"

bool contem = contains(texto, "Code"); // true
int posicao = indexOf(texto, "C");     // 3

string parte = substring(texto, 0, 3); // "Kit"
string substituida = replace(texto, "Code", "Script"); // "KitScript"

array palavras = split("um-dois-tres", "-"); // ["um", "dois", "tres"]
string juncao = join(["a", "b", "c"], ","); // "a,b,c"
```

---

## Objetos

### Criar Classe

```kitcode
class Pessoa {
    string nome;
    int idade;
    string email;
    
    function Pessoa(string n, int i, string e) {
        nome = n;
        idade = i;
        email = e;
    }
    
    function string obterInfo() {
        return nome + " (" + idade + " anos)";
    }
    
    function bool maiorDeIdade() {
        return idade >= 18;
    }
}
```

### Usar Classe

```kitcode
// Criar instância
Pessoa pessoa1 = new Pessoa("João", 25, "joao@email.com");

// Acessar propriedades
println(pessoa1.nome);    // "João"
println(pessoa1.idade);   // 25

// Chamar métodos
println(pessoa1.obterInfo());    // "João (25 anos)"
bool maior = pessoa1.maiorDeIdade(); // true

// Modificar propriedades
pessoa1.email = "joao.silva@email.com";
```

---

## Exemplos Práticos

### 1. Calculadora Simples

```kitcode
function float calculadora(float a, float b, string operacao) {
    switch (operacao) {
        case "+":
            return a + b;
        case "-":
            return a - b;
        case "*":
            return a * b;
        case "/":
            if (b != 0) return a / b;
            else println("Erro: divisão por zero");
            break;
        default:
            println("Operação inválida");
    }
    return 0;
}

// Usar
float resultado = calculadora(10, 5, "+");
println("Resultado: " + resultado);  // 15
```

### 2. Sequência de Fibonacci

```kitcode
function array fibonacci(int n) {
    array seq = [];
    
    if (n >= 1) seq = push(seq, 0);
    if (n >= 2) seq = push(seq, 1);
    
    for (int i = 2; i < n; i++) {
        int novo = seq[i-1] + seq[i-2];
        seq = push(seq, novo);
    }
    
    return seq;
}

// Usar
array fib = fibonacci(10);
println(fib);  // [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]
```

### 3. Gerenciador de Tarefas

```kitcode
class Tarefa {
    string descricao;
    bool concluida;
    
    function Tarefa(string desc) {
        descricao = desc;
        concluida = false;
    }
    
    function string status() {
        string icone = concluida ? "✓" : "○";
        return icone + " " + descricao;
    }
}

// Usar
array tarefas = [];

tarefas = push(tarefas, new Tarefa("Estudar KitCode"));
tarefas = push(tarefas, new Tarefa("Fazer projeto"));

for (Tarefa tarefa in tarefas) {
    println(tarefa.status());
}
```

### 4. Validador de Email

```kitcode
function bool validarEmail(string email) {
    // Verificar se contém @
    if (!contains(email, "@")) return false;
    
    // Verificar se contém .
    if (!contains(email, ".")) return false;
    
    // Verificar posições
    int posArroba = indexOf(email, "@");
    int posPonto = indexOf(email, ".");
    
    // @ deve estar antes de .
    if (posArroba >= posPonto) return false;
    
    // Não pode começar ou terminar com @
    if (posArroba == 0 || posPonto == len(email) - 1) return false;
    
    return true;
}

// Usar
println(validarEmail("usuario@email.com"));      // true
println(validarEmail("usuario@email"));          // false
println(validarEmail("usuarioemail.com"));       // false
```

---

## Funções Nativas

### String
- `len(string)` - Comprimento da string
- `toUpper(string)` - Converter para maiúscula
- `toLower(string)` - Converter para minúscula
- `contains(string, substring)` - Contém substring?
- `indexOf(string, substring)` - Posição da substring
- `substring(string, inicio, fim)` - Extrair parte
- `replace(string, antigo, novo)` - Substituir
- `split(string, delimitador)` - Dividir em array
- `join(array, delimitador)` - Juntar array em string
- `trim(string)` - Remover espaços

### Math
- `abs(numero)` - Valor absoluto
- `sqrt(numero)` - Raiz quadrada
- `pow(base, expoente)` - Potência
- `ceil(numero)` - Arredondar para cima
- `floor(numero)` - Arredondar para baixo
- `round(numero)` - Arredondar
- `sin(numero)` - Seno
- `cos(numero)` - Cosseno
- `tan(numero)` - Tangente
- `random()` - Número aleatório entre 0 e 1
- `randomInt(min, max)` - Inteiro aleatório

### Array
- `len(array)` - Tamanho do array
- `push(array, elemento)` - Adicionar no final
- `pop(array)` - Remover último
- `shift(array)` - Remover primeiro
- `unshift(array, elemento)` - Adicionar no início
- `sort(array)` - Ordenar
- `reverse(array)` - Inverter
- `includes(array, elemento)` - Contém elemento?
- `indexOf(array, elemento)` - Posição do elemento
- `max(array)` - Maior valor
- `min(array)` - Menor valor
- `sum(array)` - Soma de elementos

---

## Comentários

```kitcode
// Comentário de uma linha

/*
  Comentário
  de múltiplas
  linhas
*/

# Também funciona com hash
```

---

## Tratamento de Erros

```kitcode
try {
    int resultado = 10 / 0;  // Erro!
} catch (error err) {
    println("Erro: " + err.message);
}
```

---

## Dicas e Boas Práticas

✅ **DO's:**
- Use nomes descritivos para variáveis
- Adicione comentários em lógica complexa
- Organize código em funções reutilizáveis
- Valide entrada do usuário
- Use camelCase para nomes de variáveis

❌ **DON'Ts:**
- Não use nomes muito curtos (exceto em loops)
- Não declare muitas variáveis globais
- Não ignore erros
- Não escreva funções muito longas
- Não esqueça de quebras de linha em saídas

---

## Troubleshooting

**Erro: "Undefined variable"**
- Verifique se você declarou a variável antes de usar

**Erro: "Type mismatch"**
- Verifique se os tipos são compatíveis

**Erro: "Division by zero"**
- Sempre valide antes de dividir por zero

**Script não sincroniza**
- Verifique sua conexão de internet
- Verifique credenciais do Git
- Confira permissões do repositório

---

## Recursos Adicionais

- 📖 [Documentação Completa](https://github.com/mihqe/kitcode)
- 🐛 [Reportar Bug](https://github.com/mihqe/kitcode/issues)
- 💬 [Discussões](https://github.com/mihqe/kitcode/discussions)

---

**Versão:** 1.0  
**Última atualização:** 2026-04-27
