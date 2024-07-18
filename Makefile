#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa main
# Autor		: Daniele Cássia
# Histórico	: 10-06-2024 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make run - compila tudo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC       = g++
CFLAGS   = -std=c++11 -Wall -I. -I$(INCLUDEDIR)

LINKER   = g++
LFLAGS   = -Wall -I. -I$(INCLUDEDIR) -lm

SRCDIR     = src
INCLUDEDIR = include
OBJDIR     = obj
BINDIR     = bin

DEPS = main

SRC := $(addsuffix .cpp, $(DEPS))

OBJ := $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

EXE := $(BINDIR)/tp2.out

run:  all
### caso queira rodar o arquivo de teste utilizado no relatório, "descomente" a linha abaixo
# ./script.sh
#./scriptTemplate.sh
# $(EXE) -s "0 | 1 & 2" 01e  
# $(EXE) -s "(1 | 2) & ~(1 & 2)" ee  

# Rule to compile all source files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to build the main executable
all: $(OBJ)
	mkdir -p $(BINDIR)
	$(LINKER) $(LFLAGS) $(OBJ) -o $(BINDIR)/tp1.out

.PHONY: clean
clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)/*

