#ifndef CLINICA_H
#define CLINICA_H

/* ========================================
   TRABALHO SEMESTRAL - ESTRUTURA DE DADOS
   Sistema de Atendimento em uma Clínica
   ======================================== */

/* Definição de constantes */
#define MAX_NOME 100
#define MAX_CPF 15

/* Enumeração para prioridade do paciente */
typedef enum {
    NORMAL = 0,
    URGENTE = 1
} Prioridade;

/* ========================================
   ESTRUTURA 1: LISTA ENCADEADA
   Cadastro de Pacientes
   ======================================== */

/* Estrutura para representar um paciente */
typedef struct Paciente {
    char nome[MAX_NOME];
    int idade;
    char cpf[MAX_CPF];
    Prioridade prioridade;
    struct Paciente *proximo;  // Ponteiro para o próximo paciente na lista
} Paciente;

/* Estrutura para a lista encadeada de pacientes */
typedef struct {
    Paciente *inicio;  // Ponteiro para o primeiro paciente
    int total;         // Total de pacientes cadastrados
} ListaPacientes;

/* ========================================
   ESTRUTURA 2: FILA
   Fila de Atendimento
   ======================================== */

/* Nó da fila de atendimento */
typedef struct NoFila {
    Paciente *paciente;      // Ponteiro para o paciente
    struct NoFila *proximo;  // Próximo na fila
} NoFila;

/* Estrutura da fila de atendimento */
typedef struct {
    NoFila *inicio;  // Primeiro da fila
    NoFila *fim;     // Último da fila
    int tamanho;     // Quantidade de pacientes na fila
} FilaAtendimento;

/* ========================================
   ESTRUTURA 3: PILHA
   Histórico de Atendimentos
   ======================================== */

/* Nó da pilha de histórico */
typedef struct NoPilha {
    Paciente *paciente;      // Ponteiro para o paciente atendido
    struct NoPilha *proximo; // Próximo na pilha
} NoPilha;

/* Estrutura da pilha de histórico */
typedef struct {
    NoPilha *topo;   // Topo da pilha
    int tamanho;     // Quantidade de atendimentos no histórico
} PilhaHistorico;

/* ========================================
   PROTÓTIPOS DAS FUNÇÕES
   ======================================== */

/* Funções da Lista Encadeada (Cadastro) */
ListaPacientes* criarListaPacientes();
void inserirPaciente(ListaPacientes *lista, char *nome, int idade, char *cpf, Prioridade prioridade);
void listarPacientes(ListaPacientes *lista);
Paciente* buscarPacientePorCPF(ListaPacientes *lista, char *cpf);
void liberarListaPacientes(ListaPacientes *lista);

/* Funções da Fila de Atendimento */
FilaAtendimento* criarFilaAtendimento();
void adicionarNaFila(FilaAtendimento *fila, Paciente *paciente);
Paciente* chamarProximoPaciente(FilaAtendimento *fila);
void visualizarFila(FilaAtendimento *fila);
void liberarFila(FilaAtendimento *fila);

/* Funções da Pilha de Histórico */
PilhaHistorico* criarPilhaHistorico();
void adicionarNoHistorico(PilhaHistorico *pilha, Paciente *paciente);
void visualizarHistorico(PilhaHistorico *pilha);
Paciente* desfazerUltimoAtendimento(PilhaHistorico *pilha);
void liberarPilha(PilhaHistorico *pilha);

/* Funções auxiliares */
void limparBuffer();
void pausar();
void limparTela();
char* obterPrioridadeTexto(Prioridade p);

#endif
