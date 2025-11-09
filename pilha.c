#include <stdio.h>
#include <stdlib.h>
#include "clinica.h"

/* ========================================
   IMPLEMENTAÇÃO: PILHA
   Histórico de Atendimentos
   ======================================== */

/**
 * Cria e inicializa uma nova pilha de histórico
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
 * Adiciona um paciente no histórico de atendimentos (topo da pilha)
 * A pilha segue o princípio LIFO (Last In First Out)
 * Parâmetros:
 *   - pilha: ponteiro para a pilha de histórico
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
    
    // Aloca memória para o novo nó da pilha
    NoPilha *novo = (NoPilha*)malloc(sizeof(NoPilha));
    
    if (novo == NULL) {
        printf("Erro ao alocar memoria para o no da pilha!\n");
        return;
    }
    
    novo->paciente = paciente;
    novo->proximo = pilha->topo;  // O novo nó aponta para o antigo topo
    
    pilha->topo = novo;  // O novo nó se torna o topo
    pilha->tamanho++;
    
    printf("Atendimento de %s registrado no historico.\n", paciente->nome);
}

/**
 * Visualiza os últimos atendimentos do histórico
 * Parâmetro:
 *   - pilha: ponteiro para a pilha de histórico
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
 * Desfaz o último atendimento (remove do topo da pilha)
 * Parâmetro:
 *   - pilha: ponteiro para a pilha de histórico
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
    
    // Remove o nó do topo
    NoPilha *removido = pilha->topo;
    Paciente *paciente = removido->paciente;
    
    pilha->topo = pilha->topo->proximo;  // O próximo se torna o novo topo
    pilha->tamanho--;
    
    // Libera o nó (mas não o paciente, pois ele pode ser reutilizado)
    free(removido);
    
    printf("\nUltimo atendimento desfeito:\n");
    printf("Paciente: %s (CPF: %s)\n", paciente->nome, paciente->cpf);
    
    return paciente;
}

/**
 * Libera toda a memória alocada para a pilha
 * Parâmetro:
 *   - pilha: ponteiro para a pilha de histórico
 */
void liberarPilha(PilhaHistorico *pilha) {
    if (pilha == NULL) {
        return;
    }
    
    NoPilha *atual = pilha->topo;
    NoPilha *proximo;
    
    // Percorre a pilha liberando cada nó
    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    
    free(pilha);
}
