#include <stdio.h>
#include "clinica.h"

/* ========================================
   FUNÇÕES AUXILIARES
   ======================================== */

/**
 * Limpa o buffer de entrada (stdin)
 * Útil após usar scanf para evitar problemas com fgets
 */
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * Pausa a execução até o usuário pressionar Enter
 */
void pausar() {
    printf("\nPressione ENTER para continuar...");
    getchar();
}

/**
 * Limpa a tela do terminal
 * Usa códigos ANSI compatíveis com a maioria dos terminais
 */
void limparTela() {
    printf("\033[2J\033[H");
}

/**
 * Converte o enum Prioridade para texto
 * Parâmetro:
 *   - p: prioridade a ser convertida
 * Retorna: string com o texto da prioridade
 */
char* obterPrioridadeTexto(Prioridade p) {
    if (p == URGENTE) {
        return "URGENTE";
    } else {
        return "NORMAL";
    }
}
