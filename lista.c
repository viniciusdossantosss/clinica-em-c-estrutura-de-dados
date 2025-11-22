#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clinica.h"

/* ========================================
   IMPLEMENTACAO: LISTA ENCADEADA
   Cadastro de Pacientes
   ======================================== */

/**
 * Cria e inicializa uma nova lista de pacientes
 * Retorna: ponteiro para a lista criada
 */
ListaPacientes* criarListaPacientes() {
    ListaPacientes *lista = (ListaPacientes*)malloc(sizeof(ListaPacientes));
    
    if (lista == NULL) {
        printf("Erro ao alocar memoria para a lista!\n");
        return NULL;
    }
    
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->total = 0;
    
    return lista;
}

/**
 * Insere um novo paciente na lista encadeada
 * Parametros:
 *   - lista: ponteiro para a lista de pacientes
 *   - nome: nome do paciente
 *   - idade: idade do paciente
 *   - cpf: CPF do paciente
 *   - prioridade: prioridade do atendimento (NORMAL ou URGENTE)
 */
void inserirPaciente(ListaPacientes *lista, char *nome, int idade, char *cpf, Prioridade prioridade) {
    if (lista == NULL) {
        printf("Lista nao inicializada!\n");
        return;
    }
    
        // validacao de string vazia
    if (stringVaziaOuEspacos(nome)) {
	    printf("Erro: nome invalido!\n");
	    return;
	}
	if (stringVaziaOuEspacos(cpf)) {
	    printf("Erro: CPF invalido!\n");
	    return;
	}

    // Verifica se o CPF ja esta cadastrado
    if (buscarPacientePorCPF(lista, cpf) != NULL) {
        printf("Erro: Paciente com CPF %s ja cadastrado!\n", cpf);
        return;
    }
    
    // Aloca memoria para o novo paciente
    Paciente *novo = (Paciente*)malloc(sizeof(Paciente));
    
    if (novo == NULL) {
        printf("Erro ao alocar memoria para o paciente!\n");
        return;
    }
    
    // Copia os dados para o novo paciente
    strncpy(novo->nome, nome, MAX_NOME - 1);
    novo->nome[MAX_NOME - 1] = '\0';  // Garante terminacao da string
    
    novo->idade = idade;
    
    strncpy(novo->cpf, cpf, MAX_CPF - 1);
    novo->cpf[MAX_CPF - 1] = '\0';
    novo->prioridade = prioridade;
    
    novo->proximo = lista->inicio;
    novo->prev = NULL;
    
    // Insere no inicio da lista (insercao mais eficiente)
    if (lista->inicio == NULL) {
        // Lista vazia
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        /* insere no inicio */
        lista->inicio->prev = novo;
        lista->inicio = novo;
    }
    
    lista->total++;
    printf("Paciente cadastrado com sucesso!\n");
}

/**
 * Lista todos os pacientes cadastrados
 * Parametro:
 *   - lista: ponteiro para a lista de pacientes
 */
void listarPacientes(ListaPacientes *lista) {
    if (lista == NULL) {
        printf("Lista nao inicializada!\n");
        return;
    }
    
    if (lista->inicio == NULL) {
        printf("\nNenhum paciente cadastrado.\n");
        return;
    }
    
    printf("\n========== PACIENTES CADASTRADOS ==========\n");
    printf("Total: %d paciente(s)\n\n", lista->total);
    
    Paciente *atual = lista->inicio;
    int contador = 1;
    
    // Percorre a lista do inicio ao fim
    while (atual != NULL) {
        printf("--- Paciente %d ---\n", contador);
        printf("Nome: %s\n", atual->nome);
        printf("Idade: %d anos\n", atual->idade);
        printf("CPF: %s\n", atual->cpf);
        printf("Prioridade: %s\n", obterPrioridadeTexto(atual->prioridade));
        printf("\n");
        
        atual = atual->proximo;
        contador++;
    }
    
    printf("===========================================\n");
}

/**
 * Busca um paciente pelo CPF
 * Parametros:
 *   - lista: ponteiro para a lista de pacientes
 *   - cpf: CPF do paciente a ser buscado
 * Retorna: ponteiro para o paciente encontrado ou NULL se nao encontrado
 */
Paciente* buscarPacientePorCPF(ListaPacientes *lista, char *cpf) {
    if (lista == NULL || cpf == NULL) {
        return NULL;
    }
    
    Paciente *atual = lista->inicio;
    
    // Percorre a lista procurando pelo CPF
    while (atual != NULL) {
        if (strcmp(atual->cpf, cpf) == 0) {
            return atual;  // Encontrou o paciente
        }
        atual = atual->proximo;
    }
    
    return NULL;  // Nao encontrou
}

/**
 * Libera toda a memoria alocada para a lista de pacientes
 * Parametro:
 *   - lista: ponteiro para a lista de pacientes
 */
void liberarListaPacientes(ListaPacientes *lista) {
    if (lista == NULL) {
        return;
    }
    
    Paciente *atual = lista->inicio;
    Paciente *proximo;
    
    // Percorre a lista liberando cada no
    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    
    free(lista);
}

