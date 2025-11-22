#include <stdio.h>
#include <stdlib.h>
#include "clinica.h"

/* ========================================
   IMPLEMENTACAO: FILA
   Fila de Atendimento
   ======================================== */

/**
 * Cria e inicializa uma nova fila de atendimento
 * Retorna: ponteiro para a fila criada
 */
FilaAtendimento* criarFilaAtendimento() {
    FilaAtendimento *fila = (FilaAtendimento*)malloc(sizeof(FilaAtendimento));
    
    if (fila == NULL) {
        printf("Erro ao alocar memoria para a fila!\n");
        return NULL;
    }
    
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
    
    return fila;
}

/**
 * Adiciona um paciente na fila de atendimento
 * A fila respeita a ordem de chegada (FIFO - First In First Out)
 * Parametros:
 *   - fila: ponteiro para a fila de atendimento
 *   - paciente: ponteiro para o paciente a ser adicionado
 */
void adicionarNaFila(FilaAtendimento *fila, Paciente *paciente) {
    if (fila == NULL) {
        printf("Fila nao inicializada!\n");
        return;
    }
    
    if (paciente == NULL) {
        printf("Paciente invalido!\n");
        return;
    }
    
    // Aloca memoria para o novo no da fila
    NoFila *novo = (NoFila*)malloc(sizeof(NoFila));
    
    if (novo == NULL) {
        printf("Erro ao alocar memoria para o no da fila!\n");
        return;
    }
    
    novo->paciente = paciente;
    novo->proximo = NULL;
    
    // Se a fila esta vazia
    if (fila->fim == NULL) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        // Adiciona no final da fila
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
    
    fila->tamanho++;
    printf("Paciente %s adicionado na fila de atendimento.\n", paciente->nome);
}

/**
 * Chama o próximo paciente da fila (remove do início)
 * Parâmetro:
 *   - fila: ponteiro para a fila de atendimento
 * Retorna: ponteiro para o paciente chamado ou NULL se a fila estiver vazia
 */
Paciente* chamarProximoPaciente(FilaAtendimento *fila) {
    if (fila == NULL) {
        printf("Fila nao inicializada!\n");
        return NULL;
    }
    
    if (fila->inicio == NULL) {
        printf("Fila vazia! Nenhum paciente para atender.\n");
        return NULL;
    }
    
    // Remove o primeiro nó da fila
    NoFila *removido = fila->inicio;
    Paciente *paciente = removido->paciente;
    
    fila->inicio = fila->inicio->proximo;
    
    // Se a fila ficou vazia, atualiza o ponteiro fim
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    
    fila->tamanho--;
    
    // Libera o nó (mas não o paciente, pois ele será usado)
    free(removido);
    
    printf("\nChamando paciente: %s\n", paciente->nome);
    printf("CPF: %s\n", paciente->cpf);
    printf("Prioridade: %s\n", obterPrioridadeTexto(paciente->prioridade));
    
    return paciente;
}

/**
 * Visualiza todos os pacientes na fila de atendimento
 * Parâmetro:
 *   - fila: ponteiro para a fila de atendimento
 */
void visualizarFila(FilaAtendimento *fila) {
    if (fila == NULL) {
        printf("Fila nao inicializada!\n");
        return;
    }
    
    if (fila->inicio == NULL) {
        printf("\nFila de atendimento vazia.\n");
        return;
    }
    
    printf("\n========== FILA DE ATENDIMENTO ==========\n");
    printf("Total na fila: %d paciente(s)\n\n", fila->tamanho);
    
    NoFila *atual = fila->inicio;
    int posicao = 1;
    
    // Percorre a fila do início ao fim
    while (atual != NULL) {
        printf("Posicao %d:\n", posicao);
        printf("  Nome: %s\n", atual->paciente->nome);
        printf("  CPF: %s\n", atual->paciente->cpf);
        printf("  Idade: %d anos\n", atual->paciente->idade);
        printf("  Prioridade: %s\n", obterPrioridadeTexto(atual->paciente->prioridade));
        printf("\n");
        
        atual = atual->proximo;
        posicao++;
    }
    
    printf("=========================================\n");
}

/**
 * Libera toda a memória alocada para a fila
 * Parâmetro:
 *   - fila: ponteiro para a fila de atendimento
 */
void liberarFila(FilaAtendimento *fila) {
    if (fila == NULL) {
        return;
    }
    
    NoFila *atual = fila->inicio;
    NoFila *proximo;
    
    // Percorre a fila liberando cada nó
    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    
    free(fila);
}
