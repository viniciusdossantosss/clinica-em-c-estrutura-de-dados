#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clinica.h"

/* ========================================
   PROGRAMA PRINCIPAL
   Sistema de Atendimento em Clínica
   ======================================== */

/**
 * Exibe o menu principal do sistema
 */
void exibirMenu() {
    printf("\n");
    printf("╔════════════════════════════════════════════════╗\n");
    printf("║   SISTEMA DE ATENDIMENTO - CLINICA MEDICA      ║\n");
    printf("╚════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("┌─ CADASTRO DE PACIENTES ────────────────────────┐\n");
    printf("│ 1. Cadastrar novo paciente                     │\n");
    printf("│ 2. Listar todos os pacientes                   │\n");
    printf("│ 3. Buscar paciente por CPF                     │\n");
    printf("└─────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("┌─ FILA DE ATENDIMENTO ──────────────────────────┐\n");
    printf("│ 4. Adicionar paciente na fila                  │\n");
    printf("│ 5. Chamar proximo paciente                     │\n");
    printf("│ 6. Visualizar fila de atendimento              │\n");
    printf("└─────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("┌─ HISTORICO DE ATENDIMENTOS ────────────────────┐\n");
    printf("│ 7. Visualizar historico                        │\n");
    printf("│ 8. Desfazer ultimo atendimento                 │\n");
    printf("└─────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("┌─ SISTEMA ──────────────────────────────────────┐\n");
    printf("│ 0. Sair                                        │\n");
    printf("└─────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Escolha uma opcao: ");
}

/**
 * Função principal do programa
 */
int main() {
    // Inicializa as estruturas de dados
    ListaPacientes *listaPacientes = criarListaPacientes();
    FilaAtendimento *filaAtendimento = criarFilaAtendimento();
    PilhaHistorico *pilhaHistorico = criarPilhaHistorico();
    
    if (listaPacientes == NULL || filaAtendimento == NULL || pilhaHistorico == NULL) {
        printf("Erro ao inicializar o sistema!\n");
        return 1;
    }
    
    int opcao;
    char nome[MAX_NOME];
    int idade;
    char cpf[MAX_CPF];
    int prioridadeInt;
    Prioridade prioridade;
    Paciente *pacienteEncontrado;
    
    // Loop principal do programa
    while (1) {
        limparTela();
        exibirMenu();
        
        if (scanf("%d", &opcao) != 1) {
            limparBuffer();
            printf("\nOpcao invalida! Digite um numero.\n");
            pausar();
            continue;
        }
        limparBuffer();
        
        switch (opcao) {
            case 1:  // Cadastrar novo paciente
                printf("\n=== CADASTRAR NOVO PACIENTE ===\n");
                
                printf("Nome: ");
                fgets(nome, MAX_NOME, stdin);
                nome[strcspn(nome, "\n")] = '\0';  // Remove o \n do final
                
                printf("Idade: ");
                if (scanf("%d", &idade) != 1 || idade < 0 || idade > 150) {
                    limparBuffer();
                    printf("Idade invalida!\n");
                    pausar();
                    break;
                }
                limparBuffer();
                
                printf("CPF (apenas numeros): ");
                fgets(cpf, MAX_CPF, stdin);
                cpf[strcspn(cpf, "\n")] = '\0';
                
                printf("Prioridade (0-Normal / 1-Urgente): ");
                if (scanf("%d", &prioridadeInt) != 1 || (prioridadeInt != 0 && prioridadeInt != 1)) {
                    limparBuffer();
                    printf("Prioridade invalida!\n");
                    pausar();
                    break;
                }
                limparBuffer();
                
                prioridade = (prioridadeInt == 1) ? URGENTE : NORMAL;
                
                inserirPaciente(listaPacientes, nome, idade, cpf, prioridade);
                pausar();
                break;
                
            case 2:  // Listar todos os pacientes
                listarPacientes(listaPacientes);
                pausar();
                break;
                
            case 3:  // Buscar paciente por CPF
                printf("\n=== BUSCAR PACIENTE ===\n");
                printf("Digite o CPF: ");
                fgets(cpf, MAX_CPF, stdin);
                cpf[strcspn(cpf, "\n")] = '\0';
                
                pacienteEncontrado = buscarPacientePorCPF(listaPacientes, cpf);
                
                if (pacienteEncontrado != NULL) {
                    printf("\n--- PACIENTE ENCONTRADO ---\n");
                    printf("Nome: %s\n", pacienteEncontrado->nome);
                    printf("Idade: %d anos\n", pacienteEncontrado->idade);
                    printf("CPF: %s\n", pacienteEncontrado->cpf);
                    printf("Prioridade: %s\n", obterPrioridadeTexto(pacienteEncontrado->prioridade));
                } else {
                    printf("\nPaciente nao encontrado!\n");
                }
                pausar();
                break;
                
            case 4:  // Adicionar paciente na fila
                printf("\n=== ADICIONAR PACIENTE NA FILA ===\n");
                printf("Digite o CPF do paciente: ");
                fgets(cpf, MAX_CPF, stdin);
                cpf[strcspn(cpf, "\n")] = '\0';
                
                pacienteEncontrado = buscarPacientePorCPF(listaPacientes, cpf);
                
                if (pacienteEncontrado != NULL) {
                    adicionarNaFila(filaAtendimento, pacienteEncontrado);
                } else {
                    printf("Paciente nao encontrado! Cadastre o paciente primeiro.\n");
                }
                pausar();
                break;
                
            case 5:  // Chamar próximo paciente
                printf("\n=== CHAMAR PROXIMO PACIENTE ===\n");
                pacienteEncontrado = chamarProximoPaciente(filaAtendimento);
                
                if (pacienteEncontrado != NULL) {
                    // Adiciona o paciente atendido no histórico
                    adicionarNoHistorico(pilhaHistorico, pacienteEncontrado);
                    printf("\nAtendimento concluido!\n");
                }
                pausar();
                break;
                
            case 6:  // Visualizar fila
                visualizarFila(filaAtendimento);
                pausar();
                break;
                
            case 7:  // Visualizar histórico
                visualizarHistorico(pilhaHistorico);
                pausar();
                break;
                
            case 8:  // Desfazer último atendimento
                printf("\n=== DESFAZER ULTIMO ATENDIMENTO ===\n");
                pacienteEncontrado = desfazerUltimoAtendimento(pilhaHistorico);
                
                if (pacienteEncontrado != NULL) {
                    // Retorna o paciente para a fila
                    printf("Deseja retornar o paciente para a fila? (1-Sim / 0-Nao): ");
                    int retornar;
                    if (scanf("%d", &retornar) == 1 && retornar == 1) {
                        adicionarNaFila(filaAtendimento, pacienteEncontrado);
                    }
                    limparBuffer();
                }
                pausar();
                break;
                
            case 0:  // Sair
                printf("\n=== ENCERRANDO SISTEMA ===\n");
                printf("Liberando recursos...\n");
                
                // Libera toda a memória alocada
                liberarListaPacientes(listaPacientes);
                liberarFila(filaAtendimento);
                liberarPilha(pilhaHistorico);
                
                printf("Sistema encerrado com sucesso!\n");
                return 0;
                
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                pausar();
                break;
        }
    }
    
    return 0;
}
