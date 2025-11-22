#include <stdio.h>
#include "clinica.h"

/* ========================================
   FUNCOES AUXILIARES
   ======================================== */

/**
 * Limpa o buffer de entrada (stdin)
 * Util apos usar scanf para evitar problemas com fgets
 */
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * Pausa a execucao ate o usuario pressionar Enter
 */
void pausar() {
    printf("\nPressione ENTER para continuar...");
    getchar();
}

/**
 * Limpa a tela do terminal
 * Usa codigos ANSI compativeis com a maioria dos terminais
 */
void limparTela() {
    printf("\033[2J\033[H");
}

/**
 * Converte o enum Prioridade para texto
 * Parametro:
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

