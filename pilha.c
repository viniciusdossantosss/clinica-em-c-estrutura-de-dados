#include <stdio.h>
#include <stdlib.h>
#include "clinica.h"

/* ========================================
   IMPLEMENTACAO: PILHA
   Historico de Atendimentos
   ======================================== */

/**
 * Cria e inicializa uma nova pilha de historico
 * Retorna: ponteiro para a pilha criada
 */
PilhaHistorico* criarPilhaHistorico() {
    PilhaHistorico *pilha = (PilhaHistorico*)malloc(sizeof(PilhaHistorico));
    
    if (pilha == NULL) {
        printf("Erro ao alocar memoria para a pilha!\n");
        return NULL;
    }
    
    pilha->topo = NULL;
    pilha->tamanho = 0;
    
    return pilha;
}

/**
 * Adiciona um paciente no historico de atendimentos (topo da pilha)
 * A pilha segue o principio LIFO (Last In First Out)
 * Parametros:
 *   - pilha: ponteiro para a pilha de historico
 *   - paciente: ponteiro para o paciente atendido
 */
void adicionarNoHistorico(PilhaHistorico *pilha, Paciente *paciente) {
    if (pilha == NULL) {
        printf("Pilha nao inicializada!\n");
        return;
    }
    
    if (paciente == NULL) {
        printf("Paciente invalido!\n");
        return;
    }
    
    // Aloca memoria para o novo no da pilha
    NoPilha *novo = (NoPilha*)malloc(sizeof(NoPilha));
    
    if (novo == NULL) {
        printf("Erro ao alocar memoria para o no da pilha!\n");
        return;
    }
    
    novo->paciente = paciente;
    novo->proximo = pilha->topo;  // O novo no aponta para o antigo topo
    
    pilha->topo = novo;  // O novo no se torna o topo
    pilha->tamanho++;
    
    printf("Atendimento de %s registrado no historico.\n", paciente->nome);
}

/**
 * Visualiza os ultimos atendimentos do historico
 * Parametro:
 *   - pilha: ponteiro para a pilha de historico
 */
void visualizarHistorico(PilhaHistorico *pilha) {
    if (pilha == NULL) {
        printf("Pilha nao inicializada!\n");
        return;
    }
    
    if (pilha->topo == NULL) {
        printf("\nHistorico vazio. Nenhum atendimento realizado.\n");
        return;
    }
    
    printf("\n========== HISTORICO DE ATENDIMENTOS ==========\n");
    printf("Total de atendimentos: %d\n\n", pilha->tamanho);
    
    NoPilha *atual = pilha->topo;
    int contador = 1;
    
    // Percorre a pilha do topo para baixo
    printf("(Ordem: mais recente para mais antigo)\n\n");
    
    while (atual != NULL) {
        printf("--- Atendimento %d ---\n", contador);
        printf("Nome: %s\n", atual->paciente->nome);
        printf("CPF: %s\n", atual->paciente->cpf);
        printf("Idade: %d anos\n", atual->paciente->idade);
        printf("Prioridade: %s\n", obterPrioridadeTexto(atual->paciente->prioridade));
        printf("\n");
        
        atual = atual->proximo;
        contador++;
    }
    
    printf("===============================================\n");
}

/**
 * Desfaz o ultimo atendimento (remove do topo da pilha)
 * Parametro:
 *   - pilha: ponteiro para a pilha de historico
 * Retorna: ponteiro para o paciente removido ou NULL se a pilha estiver vazia
 */
Paciente* desfazerUltimoAtendimento(PilhaHistorico *pilha) {
    if (pilha == NULL) {
        printf("Pilha nao inicializada!\n");
        return NULL;
    }
    
    if (pilha->topo == NULL) {
        printf("Historico vazio! Nenhum atendimento para desfazer.\n");
        return NULL;
    }
    
    // Remove o no do topo
    NoPilha *removido = pilha->topo;
    Paciente *paciente = removido->paciente;
    
    pilha->topo = pilha->topo->proximo;  // O proximo se torna o novo topo
    pilha->tamanho--;
    
    // Libera o no (mas nao o paciente, pois ele pode ser reutilizado)
    free(removido);
    
    printf("\nUltimo atendimento desfeito:\n");
    printf("Paciente: %s (CPF: %s)\n", paciente->nome, paciente->cpf);
    
    return paciente;
}

/**
 * Libera toda a memoria alocada para a pilha
 * Parametro:
 *   - pilha: ponteiro para a pilha de historico
 */
void liberarPilha(PilhaHistorico *pilha) {
    if (pilha == NULL) {
        return;
    }
    
    NoPilha *atual = pilha->topo;
    NoPilha *proximo;
    
    // Percorre a pilha liberando cada no
    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    
    free(pilha);
}

