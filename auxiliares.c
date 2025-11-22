#include <stdio.h>
#include "clinica.h"

/* ========================================
   FUNCOES AUXILIARES
   ======================================== */

/* Limpa o buffer de entrada (stdin) */
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* Pausa o programa ate o usuario pressionar ENTER */
void pausar() {
    printf("\nPressione ENTER para continuar...");
    getchar();
}

/* Limpa a tela do terminal usando codigos ANSI */
void limparTela() {
    printf("\033[2J\033[H");
}

/* Converte a prioridade enum em texto */
char* obterPrioridadeTexto(Prioridade p) {
    if (p == URGENTE)
        return "URGENTE";
    return "NORMAL";
}

/* Verifica se a string esta vazia ou contem apenas espacos */
int stringVaziaOuEspacos(const char *s) {
    if (s == NULL) return 1;

    while (*s != '\0') {
        if (*s != ' ' && *s != '\t' && *s != '\n')
            return 0; /* Contem algum caractere valido */
        s++;
    }

    return 1; /* Apenas espacos */
}

