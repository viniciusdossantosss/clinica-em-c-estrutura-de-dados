# Análise dos Requisitos - Trabalho de Estrutura de Dados

## Objetivo
Desenvolver um sistema de gerenciamento de pacientes em uma clínica utilizando:
- **Lista Encadeada** (cadastro de pacientes)
- **Fila** (fila de atendimento)
- **Pilha** (histórico de atendimentos)

## Funcionalidades Requeridas

### 1. Cadastro de Pacientes (Lista Encadeada)
- Dados do paciente: nome, idade, CPF, prioridade (normal/urgente)
- Operações:
  - Inserir novo paciente
  - Listar todos os pacientes
  - Buscar paciente por CPF

### 2. Fila de Atendimento (Fila)
- Pacientes colocados em fila respeitando ordem de chegada
- Operações:
  - Adicionar paciente à fila
  - Chamar próximo paciente (remover da fila)
  - Ver quem está na fila

### 3. Histórico de Atendimentos (Pilha)
- Após atendimento, paciente vai para pilha de histórico
- Operações:
  - Visualizar últimos atendimentos
  - Desfazer último atendimento (remover da pilha)

## Requisitos Técnicos
- Linguagem: C
- **NÃO usar bibliotecas externas**
- Separar código em funções
- Usar structs para representar dados
- Código bem comentado

## Entrega
- Data: 27/11/2025 (Apresentação)
- Código fonte até 25/11/2025 por e-mail: pedro.kislansky@gmail.com

## Avaliação
- Sistema funcionando: 30%
- Código limpo: 10%
- Código bem comentado: 10%
- Modificação individual: 50%
