# Sistema de Atendimento em Clínica

**Trabalho Semestral - Estrutura de Dados**

Este projeto implementa um sistema completo de gerenciamento de pacientes em uma clínica médica, utilizando três estruturas de dados fundamentais: **Lista Encadeada**, **Fila** e **Pilha**.

## Estruturas de Dados Implementadas

### 1. Lista Encadeada - Cadastro de Pacientes

A lista encadeada armazena todos os pacientes cadastrados no sistema. Cada paciente possui as seguintes informações:

- Nome completo
- Idade
- CPF (identificador único)
- Prioridade (Normal ou Urgente)

**Operações disponíveis:**
- Inserir novo paciente
- Listar todos os pacientes cadastrados
- Buscar paciente por CPF

### 2. Fila - Fila de Atendimento

A fila gerencia a ordem de atendimento dos pacientes, seguindo o princípio **FIFO (First In, First Out)**, ou seja, o primeiro a entrar é o primeiro a ser atendido.

**Operações disponíveis:**
- Adicionar paciente na fila
- Chamar próximo paciente (remove do início da fila)
- Visualizar todos os pacientes na fila

### 3. Pilha - Histórico de Atendimentos

A pilha mantém o histórico dos atendimentos realizados, seguindo o princípio **LIFO (Last In, First Out)**, permitindo desfazer o último atendimento.

**Operações disponíveis:**
- Visualizar histórico de atendimentos
- Desfazer último atendimento (remove do topo da pilha)

## Arquitetura do Projeto

O código está organizado de forma modular, com separação clara de responsabilidades:

```
sistema_clinica/
├── clinica.h          # Definições de estruturas e protótipos
├── lista.c            # Implementação da lista encadeada
├── fila.c             # Implementação da fila
├── pilha.c            # Implementação da pilha
├── auxiliares.c       # Funções auxiliares
├── main.c             # Programa principal com menu
├── Makefile           # Arquivo para compilação
└── README.md          # Este arquivo
```

## Compilação e Execução

### Requisitos

- Compilador GCC
- Sistema operacional Linux/Unix ou Windows com MinGW

### Como compilar

No terminal, dentro do diretório do projeto, execute:

```bash
make
```

Ou compile manualmente:

```bash
gcc -Wall -Wextra -std=c99 -o clinica main.c lista.c fila.c pilha.c auxiliares.c
```

### Como executar

```bash
./clinica
```

### Limpar arquivos de compilação

```bash
make clean
```

## Funcionalidades do Sistema

### Menu Principal

O sistema apresenta um menu interativo com as seguintes opções:

#### Cadastro de Pacientes
1. **Cadastrar novo paciente** - Adiciona um novo paciente na lista encadeada
2. **Listar todos os pacientes** - Exibe todos os pacientes cadastrados
3. **Buscar paciente por CPF** - Localiza um paciente específico

#### Fila de Atendimento
4. **Adicionar paciente na fila** - Coloca um paciente cadastrado na fila de espera
5. **Chamar próximo paciente** - Remove o primeiro da fila e registra o atendimento
6. **Visualizar fila de atendimento** - Mostra todos os pacientes aguardando

#### Histórico de Atendimentos
7. **Visualizar histórico** - Exibe todos os atendimentos realizados
8. **Desfazer último atendimento** - Remove o último atendimento e pode retornar o paciente à fila

#### Sistema
0. **Sair** - Encerra o programa e libera toda a memória alocada

## Fluxo de Uso Típico

Um fluxo comum de utilização do sistema seria:

1. Cadastrar pacientes na lista (opção 1)
2. Adicionar pacientes na fila de atendimento (opção 4)
3. Chamar pacientes para atendimento (opção 5)
   - Automaticamente move o paciente da fila para o histórico
4. Visualizar histórico de atendimentos (opção 7)
5. Se necessário, desfazer atendimento (opção 8)

## Características Técnicas

### Conformidade com os Requisitos

✅ **Linguagem:** C puro (C99)  
✅ **Sem bibliotecas externas:** Usa apenas bibliotecas padrão (stdio.h, stdlib.h, string.h)  
✅ **Código modular:** Separado em múltiplos arquivos com funções específicas  
✅ **Uso de structs:** Todas as estruturas de dados implementadas com structs  
✅ **Código comentado:** Comentários detalhados em todas as funções  

### Gerenciamento de Memória

O sistema implementa gerenciamento adequado de memória:

- Alocação dinâmica com `malloc()`
- Liberação de memória com `free()`
- Funções específicas para liberar cada estrutura de dados
- Verificação de erros em alocações

### Validações Implementadas

- Verificação de CPF duplicado no cadastro
- Validação de entrada de dados (idade, prioridade)
- Verificação de estruturas vazias antes de operações
- Tratamento de erros de alocação de memória

## Conceitos de Estrutura de Dados Demonstrados

Este projeto demonstra os seguintes conceitos fundamentais:

### Lista Encadeada
- Inserção no início (O(1))
- Busca sequencial (O(n))
- Travessia da lista
- Ponteiros para próximo elemento

### Fila (FIFO)
- Enfileirar (enqueue) no final
- Desenfileirar (dequeue) do início
- Ponteiros para início e fim
- Ordem de chegada preservada

### Pilha (LIFO)
- Empilhar (push) no topo
- Desempilhar (pop) do topo
- Último a entrar, primeiro a sair
- Útil para operações de desfazer

## Autor

Trabalho desenvolvido para a disciplina de Estrutura de Dados.

## Data de Entrega

- **Código fonte:** 25/11/2025
- **Apresentação:** 27/11/2025
