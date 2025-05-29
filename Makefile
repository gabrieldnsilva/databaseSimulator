CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude
SRCDIR = src
INCDIR = include
TESTDIR = tests
BUILDDIR = build

# Arquivos fonte
SOURCES = $(SRCDIR)/dynamicList.c $(SRCDIR)/listaLigada.c $(SRCDIR)/binaryTree.c $(SRCDIR)/aux.c
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)

# Alvos principais
all: main test

main: $(BUILDDIR)/main

test: $(BUILDDIR)/teste_modulos

# Compilação do programa principal
$(BUILDDIR)/main: $(SRCDIR)/main.c $(OBJECTS) | $(BUILDDIR)
    $(CC) $(CFLAGS) $^ -o $@

# Compilação dos testes
$(BUILDDIR)/teste_modulos: $(TESTDIR)/teste_modulos.c $(OBJECTS) | $(BUILDDIR)
    $(CC) $(CFLAGS) $^ -o $@

# Compilação dos objetos
$(BUILDDIR)/%.o: $(SRCDIR)/%.c | $(BUILDDIR)
    $(CC) $(CFLAGS) -c $< -o $@

# Criar diretório de build
$(BUILDDIR):
    mkdir -p $(BUILDDIR)

# Limpeza
clean:
    rm -rf $(BUILDDIR)

.PHONY: all main test clean