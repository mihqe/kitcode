# KitCode API Reference

## Overview

Esta documentação descreve todos os comandos, funções e estruturas disponíveis na linguagem KitCode v5.0.

## Índice

- [Comandos Básicos](#comandos-básicos)
- [Variáveis e Tipos](#variáveis-e-tipos)
- [Operadores](#operadores)
- [Estruturas de Controle](#estruturas-de-controle)
- [Funções Matemáticas](#funções-matemáticas)
- [Comandos Gráficos](#comandos-gráficos)
- [Entrada e Saída](#entrada-e-saída)
- [Sistema e Controle](#sistema-e-controle)

## Comandos Básicos

### `diga`
Exibe uma mensagem ou variável no terminal.

**Sintaxe:**
```kitcode
diga "texto"
diga "texto " variavel
```

**Parâmetros:**
- `texto` (string): Mensagem a ser exibida
- `variavel` (opcional): Variável para concatenar

**Exemplo:**
```kitcode
diga "Olá, Mundo!"
diga "O valor é: " numero
```

### `var`
Declara ou atribui valor a uma variável.

**Sintaxe:**
```kitcode
var nome_variavel valor
```

**Parâmetros:**
- `nome_variavel` (string): Nome da variável
- `valor` (número): Valor a ser atribuído

**Exemplo:**
```kitcode
var idade 25
var pi 3.14159
```

## Variáveis e Tipos

### Tipos Suportados
- **int**: Números inteiros
- **float/double**: Números decimais
- **string**: Textos (limitado)

### Escopo de Variáveis
- Variáveis são globais por padrão
- Suporte para até 10.000 variáveis simultâneas
- Nomes de até 50 caracteres

## Operadores

### Aritméticos
| Operador | Descrição | Exemplo |
|----------|-----------|---------|
| `+` | Adição | `calc resultado a + b` |
| `-` | Subtração | `calc resultado a - b` |
| `*` | Multiplicação | `calc resultado a * b` |
| `/` | Divisão | `calc resultado a / b` |
| `^` | Potência | `calc resultado a ^ b` |

### Comparação
| Operador | Descrição | Exemplo |
|----------|-----------|---------|
| `==` | Igual | `se a == b` |
| `!=` | Diferente | `se a != b` |
| `>` | Maior | `se a > b` |
| `<` | Menor | `se a < b` |
| `>=` | Maior ou igual | `se a >= b` |
| `<=` | Menor ou igual | `se a <= b` |

### Lógicos
| Operador | Descrição | Exemplo |
|----------|-----------|---------|
| `&&` | E lógico | `se a > 0 && b > 0` |
| `||` | Ou lógico | `se a > 0 || b > 0` |
| `!` | Negação | `se !a` |

## Estruturas de Controle

### `se` / `senao` / `fim`
Estrutura condicional.

**Sintaxe:**
```kitcode
se condicao
    # código se verdadeiro
senao
    # código se falso
fim
```

**Exemplo:**
```kitcode
var idade 18
se idade >= 18
    diga "Maior de idade"
senao
    diga "Menor de idade"
fim
```

### `repetir` / `fim`
Loop controlado por contador.

**Sintaxe:**
```kitcode
repetir numero_vezes
    # código a repetir
fim
```

**Exemplo:**
```kitcode
var contador 0
repetir 10
    diga "Contagem: " contador
    calc contador contador + 1
fim
```

## Funções Matemáticas

### `calc`
Realiza cálculos matemáticos básicos.

**Sintaxe:**
```kitcode
calc resultado operando1 operador operando2
```

**Operadores suportados:** `+`, `-`, `*`, `/`

**Exemplo:**
```kitcode
calc soma 10 + 5
calc produto 8 * 3
calc quociente 20 / 4
calc diferenca 15 - 7
```

### `pot`
Calcula potência.

**Sintaxe:**
```kitcode
pot resultado base expoente
```

**Exemplo:**
```kitcode
pot resultado 2 8  # resultado = 256
pot resultado 5 3  # resultado = 125
```

### `raiz`
Calcula raiz quadrada.

**Sintaxe:**
```kitcode
raiz resultado numero
```

**Exemplo:**
```kitcode
raiz resultado 16  # resultado = 4
raiz resultado 25  # resultado = 5
```

### `hipo`
Calcula hipotenusa (teorema de Pitágoras).

**Sintaxe:**
```kitcode
hipo resultado cateto1 cateto2
```

**Exemplo:**
```kitcode
hipo resultado 3 4  # resultado = 5
hipo resultado 5 12 # resultado = 13
```

### `queda`
Calcula distância de queda livre.

**Sintaxe:**
```kitcode
queda resultado tempo
```

**Fórmula:** `d = 0.5 * 9.81 * t²`

**Exemplo:**
```kitcode
queda distancia 2  # queda por 2 segundos
```

### `forca`
Calcula força (F = m × a).

**Sintaxe:**
```kitcode
forca resultado massa aceleracao
```

**Exemplo:**
```kitcode
forca resultado 10 9.8  # 10kg * 9.8m/s²
```

### `sorteia`
Gera número aleatório em um intervalo.

**Sintaxe:**
```kitcode
sorteia resultado minimo maximo
```

**Exemplo:**
```kitcode
sorteia dado 1 6      # Simula dado de 6 faces
sorteia numero 0 100  # Número entre 0 e 100
```

## Comandos Gráficos

### Sistema de Coordenadas
- Origem (0,0) no canto superior esquerdo
- Coordenadas em caracteres do terminal
- Cores: 0-9 (preto, vermelho, verde, amarelo, azul, magenta, ciano, branco)

### `cor`
Define a cor do texto.

**Sintaxe:**
```kitcode
cor numero_cor
```

**Cores disponíveis:**
- 0: Padrão/Reset
- 1: Vermelho
- 2: Verde  
- 3: Amarelo
- 4: Azul
- 5: Magenta
- 6: Ciano
- 7: Branco

### `ponto`
Desenha um ponto na tela.

**Sintaxe:**
```kitcode
ponto x y cor caractere
```

**Exemplo:**
```kitcode
ponto 10 5 2 "█"  # Ponto verde na posição (10,5)
ponto 20 10 1 "●" # Ponto vermelho na posição (20,10)
```

### `linha`
Desenha uma linha reta.

**Sintaxe:**
```kitcode
linha x1 y1 x2 y2 cor caractere
```

**Exemplo:**
```kitcode
linha 0 0 20 10 3 "─"  # Linha amarela
linha 5 5 15 15 2 "│"  # Linha verde
```

### `bloco`
Desenha um retângulo preenchido.

**Sintaxe:**
```kitcode
bloco x y largura altura cor caractere
```

**Exemplo:**
```kitcode
bloco 5 5 10 3 4 "■"  # Retângulo azul
bloco 10 10 20 5 1 "█" # Retângulo vermelho
```

### `janela`
Desenha uma moldura de janela.

**Sintaxe:**
```kitcode
janela x y largura altura
```

**Exemplo:**
```kitcode
janela 5 5 30 10  # Janela de 30x10 começando em (5,5)
```

### `grafico`
Exibe gráfico de barras simples.

**Sintaxe:**
```kitcode
grafico valor maximo
```

**Exemplo:**
```kitcode
grafico 75 100  # Exibe barra 75% preenchida
```

## Entrada e Saída

### `pergunta`
Solicita entrada do usuário.

**Sintaxe:**
```kitcode
pergunta "prompt" variavel
```

**Exemplo:**
```kitcode
pergunta "Digite sua idade: " idade
pergunta "Qual seu nome? " nome
```

### `tecla`
Lê uma tecla do teclado.

**Sintaxe:**
```kitcode
tecla variavel
```

**Exemplo:**
```kitcode
tecla codigo_tecla
diga "Tecla pressionada: " codigo_tecla
```

## Sistema e Controle

### `limpar`
Limpa a tela do terminal.

**Sintaxe:**
```kitcode
limpar
```

### `espera`
Pausa a execução por N segundos.

**Sintaxe:**
```kitcode
espera segundos
```

**Exemplo:**
```kitcode
espera 2  # Pausa por 2 segundos
espera 0.5 # Pausa por meio segundo
```

### `ir`
Move o cursor para uma posição específica.

**Sintaxe:**
```kitcode
ir x y
```

**Exemplo:**
```kitcode
ir 10 5  # Move cursor para coluna 10, linha 5
```

### `desenha`
Desenha um caractere em uma posição específica.

**Sintaxe:**
```kitcode
desenha x y caractere
```

**Exemplo:**
```kitcode
desenha 15 8 "A"  # Desenha 'A' na posição (15,8)
```

### `esconde` / `mostra`
Controla visibilidade do cursor.

**Sintaxe:**
```kitcode
esconde  # Esconde cursor
mostra   # Mostra cursor
```

### `sair`
Encerra o programa.

**Sintaxe:**
```kitcode
sair
```

## Arrays e Listas

### `lista`
Armazena valor em array bidimensional.

**Sintaxe:**
```kitcode
lista indice_x indice_y valor
```

**Exemplo:**
```kitcode
lista 0 0 42      # matriz[0][0] = 42
lista 1 2 3.14    # matriz[1][2] = 3.14
```

### `pega_lista`
Recupera valor de array bidimensional.

**Sintaxe:**
```kitcode
pega_lista indice_x indice_y variavel_destino
```

**Exemplo:**
```kitcode
pega_lista 0 0 valor_recuperado
diga "Valor: " valor_recuperado
```

## Constantes do Sistema

### Variáveis Especiais
- `sorte`: Resultado de operações de chance (0 ou 1)

### Limites do Sistema
- Máximo de variáveis: 10.000
- Tamanho do array: 200×200
- Linhas de código: 5.000
- Comprimento de linha: 500 caracteres

## Tratamento de Erros

### Erros Comuns
- **Divisão por zero**: Retorna 0
- **Variável não encontrada**: Interpreta como número
- **Array fora dos limites**: Comportamento indefinido
- **Comando inválido**: Ignorado com mensagem de erro

### Boas Práticas
- Valide entradas do usuário
- Use nomes descritivos para variáveis
- Comente código complexo
- Teste limites e casos extremos

## Exemplos Completos

### Calculadora Científica
```kitcode
# Calculadora com funções avançadas
diga "=== CALCULADORA CIENTÍFICA ==="

pergunta "Digite um número: " num1
pergunta "Digite outro número: " num2

diga ""
diga "Resultados:"

calc soma num1 + num2
diga "Soma: " soma

calc produto num1 * num2
diga "Produto: " produto

calc quociente num1 / num2
diga "Quociente: " quociente

pot potencia num1 2
diga num1 " ao quadrado: " potencia

raiz raiz_num1 num1
diga "Raiz de " num1 ": " raiz_num1

hipo hipotenusa num1 num2
diga "Hipotenusa: " hipotenusa
```

### Jogo Simples
```kitcode
# Jogo de adivinhação
sorteia numero_secreto 1 100
var tentativas 0
var acertou 0

diga "=== JOGO DE ADIVINHAÇÃO ==="
diga "Tente adivinhar o número entre 1 e 100"

repetir 10
    pergunta "Digite seu palpite: " palpite
    calc tentativas tentativas + 1
    
    se palpite == numero_secreto
        diga "Parabéns! Você acertou em " tentativas " tentativas!"
        calc acertou 1
        fim
    senao se palpite < numero_secreto
        diga "Muito baixo!"
    senao
        diga "Muito alto!"
    fim
fim

se acertou == 0
    diga "Suas tentativas acabaram! O número era: " numero_secreto
fim
```

---

**Para mais exemplos, veja a pasta [examples/](../examples/)**
