# Simulador de Cadastro de Clientes

## Integrantes

-   Gabriel Danilo do Nascimento e Silva
-   Kaique
-   Rogério Rodrigues

## Descrição do Projeto

Este projeto implementa um sistema simples de cadastro de clientes utilizando três estruturas de dados fundamentais para simular aspectos básicos de um banco de dados:

-   **Lista Dinâmica**: Armazena os dados dos clientes
-   **Lista Duplamente Ligada**: Permite a ordenação dos dados por nome
-   **Árvore Binária**: Implementa um índice de acesso rápido pela chave primária (CPF)

## Estrutura do Projeto

### 1. Lista Dinâmica

Armazena os dados completos dos clientes:

-   CPF
-   Nome
-   Endereço
-   Telefone
-   Email

### 2. Lista Duplamente Ligada

Mantém um índice ordenado por nome:

-   Nome
-   Número de Registro

### 3. Árvore Binária

Mantém um índice de acesso rápido pela chave primária:

-   CPF
-   Número de Registro

## Funcionalidades (Menu)

### 1. Adicionar Cliente

-   Solicita o CPF e verifica se já existe na Árvore Binária
-   Se não existir, solicita os dados completos do cliente
-   Armazena na Lista Dinâmica, na Árvore Binária e na Lista Duplamente Ligada

### 2. Alterar Cliente

-   Busca o cliente pelo CPF na Árvore Binária
-   Permite alterar os dados na Lista Dinâmica
-   Atualiza a Lista Duplamente Ligada se o nome for alterado
-   O CPF não pode ser alterado (chave primária)

### 3. Excluir Cliente

-   Busca o cliente pelo CPF na Árvore Binária
-   Remove o cliente da Árvore Binária e da Lista Duplamente Ligada

### 4. Procurar Cliente

-   Busca o cliente pelo CPF na Árvore Binária
-   Exibe todos os dados do cliente armazenados na Lista Dinâmica

### 5. Relatório

-   Utiliza a Lista Duplamente Ligada para imprimir todos os registros ordenados por nome

### 6. Sair

-   Encerra a execução do programa

## Estrutura de Arquivos

A proposta da estrutura de arquivos do projeto é a seguinte:

```
/databaseSimulator
|-- src
|   |-- main.c
|   |-- dynamicList.c
|   |-- doubly_linkedList.c
|   |-- binaryTree.c
|   `-- aux.c
|-- include
|   |-- dynamicList.h
|   |-- doubly_linkedList.h
|   |-- binaryTree.h
|   `-- aux.h
|-- docs
|   |-- casos_de_uso.md
|   |-- diagrama_atividades.md
|   `-- diagrama_classes.md
`-- Makefile
```

## Documentações

-   [Casos de Uso](docs/casos_de_uso.md)
-   [Diagrama de Atividades](docs/diagrama_atividades.md)
-   [Diagrama de Módulos](docs/diagrama-modulos.md)

## Referências

-   Aulas do professor Nava
-   Estruturas de Dados e Algoritmos em C - Mark Allen Weiss
-   [Documentação do SQLite](https://github.com/sqlite/sqlite)
-   [Implementação de stupidDatabase em JavaScript - AkitaOnRails](https://github.com/akitaonrails/akitando_episode_0118)
