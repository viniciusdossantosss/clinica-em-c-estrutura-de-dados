# Demonstração do Sistema de Atendimento em Clínica

Este documento apresenta exemplos práticos de uso do sistema e demonstra todas as funcionalidades implementadas.

## Exemplo de Uso Completo

### Passo 1: Cadastrar Pacientes

Primeiro, cadastramos alguns pacientes no sistema usando a opção **1**:

**Paciente 1:**
- Nome: Maria Silva
- Idade: 45
- CPF: 12345678901
- Prioridade: Normal (0)

**Paciente 2:**
- Nome: João Santos
- Idade: 32
- CPF: 98765432100
- Prioridade: Urgente (1)

**Paciente 3:**
- Nome: Ana Costa
- Idade: 28
- CPF: 11122233344
- Prioridade: Normal (0)

### Passo 2: Listar Pacientes Cadastrados

Usando a opção **2**, podemos visualizar todos os pacientes cadastrados:

```
========== PACIENTES CADASTRADOS ==========
Total: 3 paciente(s)

--- Paciente 1 ---
Nome: Ana Costa
Idade: 28 anos
CPF: 11122233344
Prioridade: NORMAL

--- Paciente 2 ---
Nome: João Santos
Idade: 32 anos
CPF: 98765432100
Prioridade: URGENTE

--- Paciente 3 ---
Nome: Maria Silva
Idade: 45 anos
CPF: 12345678901
Prioridade: NORMAL

===========================================
```

### Passo 3: Buscar Paciente por CPF

Usando a opção **3**, podemos buscar um paciente específico:

```
=== BUSCAR PACIENTE ===
Digite o CPF: 12345678901

--- PACIENTE ENCONTRADO ---
Nome: Maria Silva
Idade: 45 anos
CPF: 12345678901
Prioridade: NORMAL
```

### Passo 4: Adicionar Pacientes na Fila

Usando a opção **4**, adicionamos pacientes na fila de atendimento:

```
=== ADICIONAR PACIENTE NA FILA ===
Digite o CPF do paciente: 12345678901
Paciente Maria Silva adicionado na fila de atendimento.

=== ADICIONAR PACIENTE NA FILA ===
Digite o CPF do paciente: 98765432100
Paciente João Santos adicionado na fila de atendimento.

=== ADICIONAR PACIENTE NA FILA ===
Digite o CPF do paciente: 11122233344
Paciente Ana Costa adicionado na fila de atendimento.
```

### Passo 5: Visualizar Fila de Atendimento

Usando a opção **6**, visualizamos a fila:

```
========== FILA DE ATENDIMENTO ==========
Total na fila: 3 paciente(s)

Posicao 1:
  Nome: Maria Silva
  CPF: 12345678901
  Idade: 45 anos
  Prioridade: NORMAL

Posicao 2:
  Nome: João Santos
  CPF: 98765432100
  Idade: 32 anos
  Prioridade: URGENTE

Posicao 3:
  Nome: Ana Costa
  CPF: 11122233344
  Idade: 28 anos
  Prioridade: NORMAL

=========================================
```

### Passo 6: Chamar Próximo Paciente

Usando a opção **5**, chamamos o próximo paciente (primeiro da fila):

```
=== CHAMAR PROXIMO PACIENTE ===

Chamando paciente: Maria Silva
CPF: 12345678901
Prioridade: NORMAL
Atendimento de Maria Silva registrado no historico.

Atendimento concluido!
```

O paciente é automaticamente removido da fila e adicionado ao histórico.

### Passo 7: Chamar Mais Pacientes

Chamamos o segundo paciente:

```
=== CHAMAR PROXIMO PACIENTE ===

Chamando paciente: João Santos
CPF: 98765432100
Prioridade: URGENTE
Atendimento de João Santos registrado no historico.

Atendimento concluido!
```

### Passo 8: Visualizar Histórico de Atendimentos

Usando a opção **7**, visualizamos o histórico:

```
========== HISTORICO DE ATENDIMENTOS ==========
Total de atendimentos: 2

(Ordem: mais recente para mais antigo)

--- Atendimento 1 ---
Nome: João Santos
CPF: 98765432100
Idade: 32 anos
Prioridade: URGENTE

--- Atendimento 2 ---
Nome: Maria Silva
CPF: 12345678901
Idade: 45 anos
Prioridade: NORMAL

===============================================
```

Note que o histórico mostra os atendimentos do mais recente para o mais antigo (característica da pilha LIFO).

### Passo 9: Desfazer Último Atendimento

Usando a opção **8**, podemos desfazer o último atendimento:

```
=== DESFAZER ULTIMO ATENDIMENTO ===

Ultimo atendimento desfeito:
Paciente: João Santos (CPF: 98765432100)
Deseja retornar o paciente para a fila? (1-Sim / 0-Nao): 1
Paciente João Santos adicionado na fila de atendimento.
```

O paciente João Santos foi removido do histórico e retornou para a fila.

### Passo 10: Verificar Estado Final

Visualizando a fila novamente (opção **6**):

```
========== FILA DE ATENDIMENTO ==========
Total na fila: 2 paciente(s)

Posicao 1:
  Nome: Ana Costa
  CPF: 11122233344
  Idade: 28 anos
  Prioridade: NORMAL

Posicao 2:
  Nome: João Santos
  CPF: 98765432100
  Idade: 32 anos
  Prioridade: URGENTE

=========================================
```

## Validações Implementadas

O sistema possui diversas validações para garantir a integridade dos dados:

### 1. CPF Duplicado

Ao tentar cadastrar um paciente com CPF já existente:

```
Erro: Paciente com CPF 12345678901 ja cadastrado!
```

### 2. Fila Vazia

Ao tentar chamar paciente de uma fila vazia:

```
Fila vazia! Nenhum paciente para atender.
```

### 3. Histórico Vazio

Ao tentar desfazer atendimento sem histórico:

```
Historico vazio! Nenhum atendimento para desfazer.
```

### 4. Paciente Não Cadastrado

Ao tentar adicionar na fila um CPF não cadastrado:

```
Paciente nao encontrado! Cadastre o paciente primeiro.
```

### 5. Validação de Idade

O sistema valida se a idade está em um intervalo razoável (0-150).

### 6. Validação de Prioridade

Aceita apenas 0 (Normal) ou 1 (Urgente).

## Estruturas de Dados em Ação

### Lista Encadeada (Cadastro)

A lista encadeada permite:
- **Inserção eficiente** no início (O(1))
- **Busca sequencial** por CPF (O(n))
- **Armazenamento dinâmico** sem limite pré-definido
- Cada nó aponta para o próximo, formando uma cadeia

### Fila (Atendimento)

A fila implementa o princípio **FIFO (First In, First Out)**:
- Primeiro paciente a entrar é o primeiro a ser atendido
- Inserção no final da fila
- Remoção do início da fila
- Mantém ponteiros para início e fim

### Pilha (Histórico)

A pilha implementa o princípio **LIFO (Last In, First Out)**:
- Último atendimento realizado é o primeiro a ser desfeito
- Inserção e remoção sempre no topo
- Ideal para operações de desfazer (undo)

## Gerenciamento de Memória

O sistema gerencia adequadamente a memória:

1. **Alocação dinâmica** com `malloc()` para todas as estruturas
2. **Liberação de memória** com `free()` ao sair do programa
3. **Verificação de erros** em todas as alocações
4. **Sem vazamento de memória** (memory leaks)

Ao sair do programa (opção **0**):

```
=== ENCERRANDO SISTEMA ===
Liberando recursos...
Sistema encerrado com sucesso!
```

Todas as estruturas são liberadas corretamente:
- `liberarListaPacientes()`
- `liberarFila()`
- `liberarPilha()`

## Conclusão

Este sistema demonstra de forma prática e funcional o uso de três estruturas de dados fundamentais:

- **Lista Encadeada** para armazenamento dinâmico
- **Fila** para gerenciamento de ordem de atendimento
- **Pilha** para histórico com possibilidade de desfazer

O código está bem estruturado, comentado e segue todas as boas práticas de programação em C, sem uso de bibliotecas externas além das padrões (stdio.h, stdlib.h, string.h).
