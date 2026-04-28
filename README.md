# KitCode - Linguagem de Programação Brasileira
<div align="center">
**Interpretador de comandos e motor gráfico baseado em C com sintaxe em português**
Documentação • Exemplos • Instalação • Licença
</div>
## Sobre o Projeto
O KitCode é um projeto de linguagem de programação desenvolvido no Brasil que utiliza a sintaxe em português para facilitar a lógica de programação. O interpretador é construído sobre a linguagem C, permitindo a execução de comandos lógicos e a renderização de elementos gráficos diretamente no terminal.
### Desenvolvimento e Metodologia
O projeto encontra-se em **fase de desenvolvimento ativo**. A arquitetura do sistema e a otimização dos componentes do motor v5.0 foram elaboradas com o auxílio de ferramentas de **Inteligência Artificial**, utilizadas especificamente para a estruturação de algoritmos complexos, depuração de código e organização da lógica de memória.
## Arquitetura do Sistema
O diagrama abaixo descreve o fluxo de processamento do KitCode, desde a leitura do script até a exibição no terminal:
```text
    +-------------------------------------------------------+
    |                  ENTRADA (Script .kit)                |
    +---------------------------+---------------------------+
                                |
                                v
    +---------------------------+---------------------------+
    |            INTERPRETADOR (motor_v4.c)                 |
    |       (Análise de sintaxe e gestão de memória)        |
    +---------------------------+---------------------------+
                                |
             +------------------+------------------+
             |                  |                  |
             v                  v                  v
    +----------------+  +----------------+  +----------------+
    |     LÓGICA     |  |    MEMÓRIA     |  |    GRÁFICOS    |
    | (se / repetir) |  | (10k Variáveis)|  | (Matriz 200x200)|
    +----------------+  +----------------+  +----------------+
             |                  |                  |
             +------------------+------------------+
                                |
                                v
    +-------------------------------------------------------+
    |                  SAÍDA (Terminal)                     |
    +-------------------------------------------------------+

```
## Instalação
### Requisitos
 * Compilador C (GCC ou Clang)
 * Git
 * Ambiente de linha de comando
### Procedimento
```bash
# Clonar o repositório
git clone https://github.com/mihqe/kitcode.git
cd kitcode

# Compilação do motor v5.0
gcc -o kitcode src/motor_v4.c -lm

# Instalação (opcional para Linux/macOS)
sudo cp kitcode /usr/local/bin/

```
## Guia de Uso
### Estrutura de Pastas
```text
kitcode/
├── bin/            # Executáveis do sistema
├── docs/           # Arquivos de documentação técnica
├── examples/       # Exemplos de scripts (.kit)
├── src/            # Código-fonte em C
└── scripts/        # Utilitários de configuração

```
### Exemplo de Sintaxe
O KitCode utiliza comandos claros para facilitar o entendimento do fluxo:
```kitcode
var valor 10
se valor > 5
    diga "O valor é superior a cinco"
senao
    diga "O valor é inferior ou igual a cinco"
fim

```
## Referência de Comandos
### Interface e Sistema
| Comando | Descrição |
|---|---|
| diga | Exibe texto ou o valor de uma variável. |
| pergunta | Recebe uma entrada do usuário e armazena. |
| limpar | Limpa as informações do terminal. |
| espera | Pausa a execução por um tempo determinado. |
### Lógica e Matemática
| Comando | Descrição |
|---|---|
| var | Reserva espaço na memória para um dado. |
| calc | Executa operações aritméticas básicas. |
| pot / raiz | Funções de potência e raiz quadrada. |
| repetir | Cria um laço de repetição definido. |
### Sistema Gráfico
O motor gráfico utiliza um sistema de coordenadas para desenhar no terminal:
```text
    (0,0)  X+ --->
    Y+  +---------------------------+
    |   |                           |
    |   |     MATRIZ GRÁFICA        |
    v   |      (200 x 200)          |
        |                           |
        +---------------------------+

```
## Segurança e Implementação
A versão 5.0 do KitCode foca na estabilidade do interpretador:
 * **Entrada de Dados:** Utilização de fgets() para evitar vulnerabilidades de estouro de memória.
 * **Capacidade de Variáveis:** O sistema foi dimensionado para suportar o endereçamento de até 10.000 variáveis simultâneas.
 * **Compatibilidade:** O motor foi testado para operar de forma consistente em ambientes Windows, Linux e macOS.
## Contribuição
Para contribuir com o desenvolvimento:
 1. Realize o fork do repositório.
 2. Crie uma branch para sua alteração.
 3. Submeta um Pull Request descrevendo as mudanças técnicas aplicadas.
## Licença
Este projeto é licenciado sob a **Licença MIT**. Para mais detalhes, consulte o arquivo LICENSE.
<div align="center">
**KitCode - Linguagem de Programação Brasileira** Projeto em constante atualização.
</div>
