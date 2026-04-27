# Guia de Uso - KitCode

## Bem-vindo ao KitCode! 🎉

KitCode é uma linguagem de programação moderna e eficiente, combinando a potência do C com a facilidade de uso de linguagens de alto nível.

---

## 📋 Índice

1. [Primeiros Passos](#primeiros-passos)
2. [Sintaxe Básica](#sintaxe-básica)
3. [Variáveis e Tipos](#variáveis-e-tipos)
4. [Operadores](#operadores)
5. [Controle de Fluxo](#controle-de-fluxo)
6. [Funções](#funções)
7. [Exemplos Práticos](#exemplos-práticos)
8. [Funções Nativas](#funções-nativas)
9. [Dicas e Boas Práticas](#dicas-e-boas-práticas)
10. [Troubleshooting](#troubleshooting)

---

## Primeiros Passos

### Instalação

Veja [INSTALL.md](INSTALL.md) para instruções completas de instalação em seu S.O.

### Executar seu primeiro programa

```bash
# Criar arquivo
echo 'print("Olá, KitCode!")' > hello.kit

# Compilar e executar
kitcode hello.kit

# Ou direto
./hello.kit
```

---

## Sintaxe Básica

### Estrutura básica de um programa

```kitcode
// Comentário de uma linha

/* 
   Comentário de
   múltiplas linhas
*/

print("Olá, Mundo!")
```

### Pontos importantes

- **Ponto e vírgula**: Opcional no final de linhas
- **Espaçamento**: Espaços e tabs são ignorados (exceto em strings)
- **Case-sensitive**: `var` é diferente de `Var`

---

## Variáveis e Tipos

### Declaração de variáveis

```kitcode
// Declaração explícita com tipo
int idade = 25
string nome = "João"
float altura = 1.75
bool ativo = true

// Declaração implícita (tipo inferido)
count = 10              // int
mensagem = "Teste"      // string
valor = 3.14           // float
```

### Tipos de dados

| Tipo | Descrição | Exemplo |
|------|-----------|---------|
| `int` | Números inteiros | `42`, `-10` |
| `float` | Números decimais | `3.14`, `-2.5` |
| `string` | Texto | `"Olá"`, `'Teste'` |
| `bool` | Verdadeiro/Falso | `true`, `false` |
| `array` | Lista de valores | `[1, 2, 3]` |
| `object` | Objeto com propriedades | `{nome: "João"}` |

### Conversão de tipos

```kitcode
// Conversão explícita
numero = int("42")
texto = string(100)
decimal = float("3.14")

// Conversão implícita
resultado = "Idade: " + 25      // Concatenação automática
total = 10 + 5.5                // Resultado: 15.5
```

---

## Operadores

### Aritméticos

```kitcode
a = 10
b = 3

soma = a + b              // 13
diferenca = a - b         // 7
multiplicacao = a * b     // 30
divisao = a / b           // 3.33...
modulo = a % b            // 1
potencia = a ** b         // 1000
```

### Comparação

```kitcode
5 == 5              // true (igual)
5 != 3              // true (diferente)
5 > 3               // true (maior)
5 < 3               // false (menor)
5 >= 5              // true (maior ou igual)
3 <= 5              // true (menor ou igual)
```

### Lógicos

```kitcode
true && true        // true (AND)
true || false       // true (OR)
!true               // false (NOT)
(5 > 3) && (2 < 4)  // true
```

### Atribuição

```kitcode
x = 10              // Atribuição simples
x += 5              // x = x + 5   (15)
x -= 3              // x = x - 3   (12)
x *= 2              // x = x * 2   (24)
x /= 4              // x = x / 4   (6)
x %= 5              // x = x % 5   (1)
```

---

## Controle de Fluxo

### Condicionais (if/else)

```kitcode
idade = 20

if (idade >= 18) {
    print("Você é maior de idade")
} else if (idade >= 13) {
    print("Você é adolescente")
} else {
    print("Você é criança")
}

// Ternário
status = idade >= 18 ? "Adulto" : "Menor"
```

### Switch

```kitcode
dia = 3

switch (dia) {
    case 1:
        print("Segunda")
        break
    case 2:
        print("Terça")
        break
    case 3:
        print("Quarta")
        break
    default:
        print("Outro dia")
}
```

### Loops

#### While
```kitcode
contador = 0
while (contador < 5) {
    print(contador)
    contador += 1
}
```

#### For
```kitcode
// Loop tradicional
for (i = 0; i < 5; i += 1) {
    print(i)
}

// For...in (para arrays/objetos)
numeros = [10, 20, 30]
for (num in numeros) {
    print(num)
}

// For...of (com índice)
for (i, num of numeros) {
    print("Índice: " + i + ", Valor: " + num)
}
```

#### Do...While
```kitcode
contador = 0
do {
    print(contador)
    contador += 1
} while (contador < 5)
```

### Break e Continue

```kitcode
for (i = 0; i < 10; i += 1) {
    if (i == 3) {
        continue        // Pula esta iteração
    }
    if (i == 7) {
        break           // Sai do loop
    }
    print(i)            // Imprime: 0, 1, 2, 4, 5, 6
}
```

---

## Funções

### Declaração básica

```kitcode
function saudacao(nome) {
    print("Olá, " + nome)
}

saudacao("Maria")       // Olá, Maria
```

### Com tipo de retorno

```kitcode
function somar(a, b) -> int {
    return a + b
}

resultado = somar(5, 3)
print(resultado)        // 8
```

### Com tipos de parâmetros

```kitcode
function multiplicar(x -> int, y -> int) -> int {
    return x * y
}

print(multiplicar(4, 5))    // 20
```

### Parâmetros padrão

```kitcode
function cumprimento(nome, titulo = "Sr.") {
    print(titulo + " " + nome)
}

cumprimento("Silva")            // Sr. Silva
cumprimento("Silva", "Dr.")     // Dr. Silva
```

### Funções anônimas (Lambda)

```kitcode
quadrado = (x) -> x ** 2

print(quadrado(5))              // 25
```

---

## Exemplos Práticos

### Exemplo 1: Calculadora Simples

```kitcode
function calculadora(a, b, operacao) {
    switch (operacao) {
        case "+":
            return a + b
        case "-":
            return a - b
        case "*":
            return a * b
        case "/":
            if (b == 0) {
                print("Erro: Divisão por zero!")
                return 0
            }
            return a / b
        default:
            print("Operação inválida")
            return 0
    }
}

print(calculadora(10, 5, "+"))      // 15
print(calculadora(10, 5, "*"))      // 50
print(calculadora(10, 0, "/"))      // Erro: Divisão por zero!
```

### Exemplo 2: Série de Fibonacci

```kitcode
function fibonacci(n) {
    if (n <= 1) return n
    return fibonacci(n - 1) + fibonacci(n - 2)
}

for (i = 0; i < 10; i += 1) {
    print(fibonacci(i))
}

// Saída: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34
```

### Exemplo 3: Trabalhando com Arrays

```kitcode
numeros = [1, 2, 3, 4, 5]

// Iterar
for (num in numeros) {
    print(num * 2)
}

// Adicionar
numeros.push(6)
numeros.push(7)

// Acessar
print(numeros[0])       // 1
print(numeros.length)   // 7

// Remover
numeros.pop()           // Remove o último
```

### Exemplo 4: Objetos

```kitcode
pessoa = {
    nome: "João",
    idade: 30,
    profissao: "Desenvolvedor"
}

// Acessar propriedades
print(pessoa.nome)              // João
print(pessoa["idade"])          // 30

// Modificar
pessoa.idade = 31

// Adicionar propriedade
pessoa.email = "joao@example.com"

// Iterar
for (chave in pessoa) {
    print(chave + ": " + pessoa[chave])
}
```

---

## Funções Nativas

### I/O (Entrada/Saída)

```kitcode
// Saída
print("Texto aqui")
println("Com quebra de linha")

// Entrada
entrada = input("Digite algo: ")
```

### String

```kitcode
texto = "Olá Mundo"

texto.length              // 9
texto.toUpperCase()       // "OLÁ MUNDO"
texto.toLowerCase()       // "olá mundo"
texto.charAt(0)           // "O"
texto.substring(0, 3)     // "Olá"
texto.replace("Mundo", "KitCode")    // "Olá KitCode"
texto.split(" ")          // ["Olá", "Mundo"]
```

### Math

```kitcode
Math.abs(-5)              // 5
Math.sqrt(16)             // 4
Math.pow(2, 3)            // 8
Math.max(5, 10, 3)        // 10
Math.min(5, 10, 3)        // 3
Math.floor(3.7)           // 3
Math.ceil(3.2)            // 4
Math.round(3.5)           // 4
Math.random()             // Número entre 0 e 1
Math.PI                   // 3.14159...
```

### Array

```kitcode
arr = [1, 2, 3]

arr.length                // 3
arr.push(4)               // Adiciona no final
arr.pop()                 // Remove do final
arr.shift()               // Remove do início
arr.unshift(0)            // Adiciona no início
arr.indexOf(2)            // 1
arr.includes(3)           // true
arr.join("-")             // "1-2-3"
arr.reverse()             // Reverte a ordem
arr.sort()                // Ordena
```

---

## Dicas e Boas Práticas

### 1. Nomenclatura

```kitcode
// ✅ Bom
usuario_nome = "João"
verificarIdade = true
LIMITE_MAXIMO = 100

// ❌ Evitar
n = "João"
x = true
temp = 100
```

### 2. Comentários

```kitcode
// ✅ Bom - Explica o porquê
if (idade >= 18) {  // Verifica maioridade legal
    print("Pode votar")
}

// ❌ Ruim - Óbvio
x = x + 1  // Incrementa x
```

### 3. Funções

```kitcode
// ✅ Bom - Função específica e com nome claro
function calcularIdadeAno(anoNascimento) {
    anoAtual = 2026
    return anoAtual - anoNascimento
}

// ❌ Ruim - Muito genérica
function calc(a, b) {
    return 2026 - a
}
```

### 4. Evitar repetição

```kitcode
// ❌ Ruim - Repetição de código
print(5 + 10)
print(10 + 20)
print(15 + 25)

// ✅ Bom - Usando função
function mostrarSoma(a, b) {
    print(a + b)
}

mostrarSoma(5, 10)
mostrarSoma(10, 20)
mostrarSoma(15, 25)
```

---

## Troubleshooting

### Erro: "Syntax Error"
**Causa**: Erro de sintaxe no código
**Solução**: Verifique parênteses, chaves e ponto e vírgula

```kitcode
// ❌ Errado
if (x > 5 {
    print("Maior")
}

// ✅ Correto
if (x > 5) {
    print("Maior")
}
```

### Erro: "Undefined variable"
**Causa**: Variável não foi declarada
**Solução**: Declare a variável antes de usar

```kitcode
// ❌ Errado
print(x)
x = 5

// ✅ Correto
x = 5
print(x)
```

### Erro: "Type mismatch"
**Causa**: Tipos de dados incompatíveis
**Solução**: Converta o tipo ou use o tipo correto

```kitcode
// ❌ Errado
x = "5"
resultado = x + 10      // Concatena, não soma

// ✅ Correto
x = 5
resultado = x + 10      // 15
```

### Erro: "Division by zero"
**Causa**: Tentativa de dividir por zero
**Solução**: Verifique antes de dividir

```kitcode
if (divisor != 0) {
    resultado = dividendo / divisor
} else {
    print("Divisor não pode ser zero")
}
```

---

## Recursos Adicionais

- 📖 [INSTALL.md](INSTALL.md) - Guia de instalação
- 🔄 [AUTO_SYNC.md](AUTO_SYNC.md) - Configurar sincronização automática
- 🐛 Encontrou um bug? [Abra uma issue](https://github.com/mihqe/kitcode/issues)
- 💡 Tem uma sugestão? [Crie uma discussão](https://github.com/mihqe/kitcode/discussions)

---

**Versão:** 1.0  
**Última atualização:** 2026-04-27  
**Desenvolvedor:** mihqe
