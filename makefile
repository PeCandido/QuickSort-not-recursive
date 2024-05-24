# Variáveis
CC = gcc
CFLAGS = -Wall -g
OBJ = main.o t_stack_quicksort.o
TARGET = meu_programa

# Regra padrão (primeira regra é a padrão)
all: $(TARGET)

# Regra para compilar o executável
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Regras para compilar os arquivos objeto
main.o: main.c t_stack_quicksort.h
	$(CC) $(CFLAGS) -c main.c

t_stack_quicksort.o: t_stack_quicksort.c t_stack_quicksort.h
	$(CC) $(CFLAGS) -c t_stack_quicksort.c

# Regra para limpar arquivos compilados
clean:
	rm -f $(OBJ) $(TARGET)

# Regra para rodar o programa
run: $(TARGET)
	./$(TARGET)
