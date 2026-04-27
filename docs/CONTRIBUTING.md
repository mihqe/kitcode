# Guia de Contribuição - KitCode

Obrigado pelo seu interesse em contribuir com o KitCode! Este guia irá ajudá-lo a começar.

## 🚀 Como Contribuir

### Reportando Bugs

1. Verifique se o bug já foi [reportado](https://github.com/mihqe/kitcode/issues)
2. Se não encontrado, [abra uma nova issue](https://github.com/mihqe/kitcode/issues/new)
3. Use o template de bug report
4. Forneça informações detalhadas:
   - SO e versão
   - Versão do KitCode
   - Passos para reproduzir
   - Comportamento esperado vs. atual
   - Logs ou screenshots

### Sugerindo Funcionalidades

1. Verifique se a sugestão já existe
2. [Abra uma issue](https://github.com/mihqe/kitcode/issues/new) com template de feature request
3. Descreva a funcionalidade claramente
4. Explique o caso de uso
5. Considere implementar você mesmo!

### Contribuindo Código

#### 1. Fork e Clone
```bash
git clone https://github.com/SEU_USERNAME/kitcode.git
cd kitcode
```

#### 2. Crie Branch
```bash
git checkout -b feature/nova-funcionalidade
# ou
git checkout -b fix/correcao-de-bug
```

#### 3. Desenvolva
- Siga as [diretrizes de código](#diretrizes-de-código)
- Adicione testes
- Atualize documentação
- Teste em múltiplos SOs

#### 4. Commit
```bash
git add .
git commit -m "feat: adiciona nova funcionalidade X"
```

#### 5. Push e Pull Request
```bash
git push origin feature/nova-funcionalidade
```

Abra um Pull Request com:
- Título descritivo
- Descrição detalhada
- Screenshots (se aplicável)
- Issue relacionada

## 📋 Diretrizes de Código

### Estilo de Código

#### C (Motor Principal)
```c
// Use nomes descritivos
void executar_comando_texto(char *linha, char *parametros[]) {
    // Implementação clara
}

// Comentários explicativos
// Verifica se variável existe antes de usar
for(int i = 0; i < total_vars; i++) {
    if(strcmp(mem[i].nome, nome_busca) == 0) {
        return mem[i].valor;
    }
}
```

#### KitCode (Scripts)
```kitcode
# Use nomes descritivos
var idade_usuario 25

# Comente lógica complexa
# Verifica se usuário pode votar
se idade_usuario >= 18
    diga "Pode votar"
fim
```

### Convenções

#### Nomenclatura
- **Variáveis**: `snake_case` (ex: `idade_usuario`)
- **Funções**: `snake_case` (ex: `executar_comando`)
- **Constantes**: `UPPER_CASE` (ex: `MAX_VARIAVEIS`)
- **Comandos**: `lowercase` (ex: `diga`, `calc`)

#### Formatação
- Indentação: 4 espaços
- Linhas: máximo 80 caracteres
- Comentários: acima ou ao lado do código

### Boas Práticas

#### Performance
- Evite loops aninhados desnecessários
- Use arrays de acesso direto quando possível
- Valide entradas antes de processar
- Libere recursos quando não usar mais

#### Segurança
- Use `fgets()` em vez de `scanf()`
- Valide bounds de arrays
- Verifique ponteiros nulos
- Limpe buffers sensíveis

#### Manutenibilidade
- Funções pequenas e focadas
- Nomes descritivos
- Comente código complexo
- Documente APIs públicas

## 🧪 Testes

### Tipos de Testes

#### Unitários
```c
// test/test_math.c
#include "../src/motor_v4.c"

void test_calc_soma() {
    set_n("a", 10);
    set_n("b", 5);
    executar_linha("calc resultado a + b");
    assert(get_n("resultado") == 15);
}
```

#### Integração
```kitcode
# examples/test_integration.kit
# Testa sistema completo
var a 10
var b 20
calc resultado a + b
diga "Resultado: " resultado
```

#### Performance
```bash
# Benchmark
time ./kitcode examples/benchmark.kit
```

### Executando Testes
```bash
# Compilar com debug
gcc -g -DDEBUG -o kitcode src/motor_v4.c -lm

# Valgrind (memory leaks)
valgrind --leak-check=full ./kitcode test_script.kit

# Coverage (se disponível)
gcov src/motor_v4.c
```

## 📖 Documentação

### Tipos de Documentação

#### API Reference
- Atualize `docs/API.md` para novos comandos
- Inclua sintaxe, parâmetros e exemplos
- Mantenha tabela de comandos atualizada

#### Guia de Usuário
- Atualize `docs/USAGE.md` para novas funcionalidades
- Adicione exemplos práticos
- Mantenha seção de troubleshooting

#### Guia de Desenvolvedor
- Atualize `docs/DEVELOPMENT.md` para mudanças arquiteturais
- Documente novas APIs internas
- Mantenha roadmap atualizado

### Escrevendo Documentação

#### Markdown
- Use headings (`#`, `##`, `###`)
- Use código formatado
- Inclua exemplos funcionais
- Adicione links internos

#### Exemplos
```markdown
### `novo_comando`
Descrição breve do comando.

**Sintaxe:**
```kitcode
novo_comando parametro1 parametro2
```

**Exemplo:**
```kitcode
novo_comando "texto" 42
```
```

## 🏗️ Arquitetura

### Estrutura do Projeto
```
kitcode/
├── src/           # Código-fonte C
├── docs/          # Documentação
├── examples/      # Exemplos KitCode
├── scripts/       # Scripts auxiliares
├── tests/         # Testes
└── bin/           # Executáveis
```

### Adicionando Comandos

#### 1. Implementação (C)
```c
// Em executar_linha()
else if(strcmp(p1, "novo_comando") == 0) {
    // Implementação
    printf("Executando novo comando\n");
}
```

#### 2. Documentação
- Adicione a `docs/API.md`
- Adicione exemplo a `examples/`
- Atualize `CHANGELOG.md`

#### 3. Testes
- Crie teste unitário
- Crie exemplo prático
- Teste em múltiplos SOs

## 🔄 Processo de Review

### Checklist de Pull Request

#### Código
- [ ] Compila sem warnings
- [ ] Passa em todos os testes
- [ ] Segue estilo de código
- [ ] Não introduz regressões

#### Documentação
- [ ] API.md atualizado
- [ ] Exemplos funcionais
- [ ] Changelog atualizado
- [ ] Comentários explicativos

#### Qualidade
- [ ] Performance aceitável
- [ ] Sem memory leaks
- [ ] Tratamento de erros
- [ ] Multiplataforma

### Review Process
1. **Automated Checks**: CI/CD, linting, tests
2. **Peer Review**: Revisão por outro mantenedor
3. **Testing**: Testes manuais em diferentes SOs
4. **Approval**: Aprovação necessária para merge

## 🚀 Release Process

### Versionamento
- **Major**: Mudanças que quebram compatibilidade
- **Minor**: Novas funcionalidades (backward compatible)
- **Patch**: Correções de bugs

### Preparação de Release
1. [ ] Todos os testes passando
2. [ ] Documentação atualizada
3. [ ] CHANGELOG.md atualizado
4. [ ] Versão incrementada
5. [ ] Tag criada
6. [ ] Release notes preparadas

### Publicação
```bash
# Create tag
git tag v5.1.0

# Push tag
git push origin v5.1.0

# Create GitHub release
# (via interface web)
```

## 🤝 Comunidade

### Canais de Comunicação
- **GitHub Issues**: Bugs e feature requests
- **GitHub Discussions**: Discussões gerais
- **Pull Requests**: Contribuições de código

### Código de Conduta
- Seja respeitoso e inclusivo
- Ajude novos contribuidores
- Foque no que é melhor para a comunidade
- Respeite opiniões diferentes

### Reconhecimento
- Contribuidores são listados no README
- Destaque em releases notes
- Agradecimentos em changelog

## 🛠️ Ferramentas

### Desenvolvimento
- **Editor**: VS Code, Vim, Emacs
- **Compiler**: GCC, Clang
- **Debugger**: GDB
- **Profiler**: Valgrind

### Documentação
- **Editor**: Markdown
- **Preview**: GitHub, VS Code
- **Linter**: markdownlint

### CI/CD
- **Actions**: GitHub Actions
- **Testing**: Automatizado
- **Deployment**: Automatizado

## 📚 Recursos

### Aprendizado
- [C Programming Guide](https://github.com/awesome-c)
- [Git Handbook](https://guides.github.com/introduction/git-flow/)
- [Markdown Guide](https://www.markdownguide.org/)

### Ferramentas
- [GitHub Desktop](https://desktop.github.com/)
- [Git CLI](https://git-scm.com/)
- [VS Code](https://code.visualstudio.com/)

### Referências
- [Semantic Versioning](https://semver.org/)
- [Conventional Commits](https://conventionalcommits.org/)
- [Keep a Changelog](https://keepachangelog.com/)

---

## 🎉 Obrigado!

Sua contribuição ajuda o KitCode a crescer e melhorar. Todas as contribuições são valorizadas, não importa o tamanho.

**Para dúvidas, entre em contato através das [issues](https://github.com/mihqe/kitcode/issues).**
