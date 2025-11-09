# Makefile para o Sistema de Atendimento em Clínica
# Trabalho Semestral - Estrutura de Dados

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

# Nome do executável
TARGET = clinica

# Arquivos objeto
OBJS = main.o lista.o fila.o pilha.o auxiliares.o

# Regra padrão: compila o programa
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
	@echo "Compilacao concluida! Execute com: ./$(TARGET)"

# Regras para compilar cada arquivo objeto
main.o: main.c clinica.h
	$(CC) $(CFLAGS) -c main.c

lista.o: lista.c clinica.h
	$(CC) $(CFLAGS) -c lista.c

fila.o: fila.c clinica.h
	$(CC) $(CFLAGS) -c fila.c

pilha.o: pilha.c clinica.h
	$(CC) $(CFLAGS) -c pilha.c

auxiliares.o: auxiliares.c clinica.h
	$(CC) $(CFLAGS) -c auxiliares.c

# Limpa os arquivos compilados
clean:
	rm -f $(OBJS) $(TARGET)
	@echo "Arquivos de compilacao removidos."

# Recompila tudo do zero
rebuild: clean all

# Executa o programa
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean rebuild run
