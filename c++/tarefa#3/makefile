# Nome do executável
EXECUTABLE = tarefa3

# Diretórios
SRC_DIR = .
INC_DIRS = Veiculo Veiculo/Carro Veiculo/Caminhao Cliente Ordem Roteirizacao GerenciadorVeiculo

# Arquivos fonte
SOURCES := $(wildcard $(SRC_DIR)/*.cpp) $(foreach dir,$(INC_DIRS),$(wildcard $(dir)/*.cpp))

# Arquivos objeto gerados a partir dos arquivos fonte
OBJECTS := $(SOURCES:.cpp=.o)

# Compilador
CC = g++

# Flags de compilação
CFLAGS = -Wall -std=c++11

# Instruções de compilação
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
	find . -name "*.o" -type f -delete
	clear
	@echo "Executável $@ criado com sucesso!"

# Regra para compilar cada arquivo fonte
%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

# Define a regra "all" que compila o executável
all: $(EXECUTABLE)

# Define a regra padrão que depende da regra "all"
.DEFAULT_GOAL := all

# Define as regras que não são arquivos
.PHONY: all clean
