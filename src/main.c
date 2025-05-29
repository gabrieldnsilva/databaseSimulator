#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/dynamicList.h"
#include "../include/binaryTree.h"
#include "../include/listaLigada.h"
#include "../include/aux.h"

// Enumeração para opções do menu
enum
{
    OP_SAIR = 0,
    OP_ADICIONAR,
    OP_ALTERAR,
    OP_EXCLUIR,
    OP_PROCURAR,
    OP_RELATORIO
};

// Declaração de funções do menu
void exibirMenu();
void adicionarCliente();
void alterarCliente();
void excluirCliente();
void procurarCliente();
void gerarRelatorio();

// Variáveis globais para as estruturas de dados
DynamicList listaDinamica;

int main()
{
    int opcao = -1;

    // Inicializar estruturas de dados
    LDinicializarLista(&listaDinamica);
    ABinicializar();
    LLinicializar();

    printf("=== SIMULADOR DE CADASTRO DE CLIENTES ===\n\n");

    while (opcao != OP_SAIR)
    {
        exibirMenu();
        scanf("%d", &opcao);
        limparBuffer(); // Limpa o buffer após scanf

        switch (opcao)
        {
        case OP_ADICIONAR:
            adicionarCliente();
            break;
        case OP_ALTERAR:
            alterarCliente();
            break;
        case OP_EXCLUIR:
            excluirCliente();
            break;
        case OP_PROCURAR:
            procurarCliente();
            break;
        case OP_RELATORIO:
            gerarRelatorio();
            break;
        case OP_SAIR:
            printf("Encerrando o programa...\n");
            break;
        default:
            printf("Opção inválida!\n");
        }

        if (opcao != OP_SAIR)
        {
            pausar();
        }
    }

    // Liberar memória das estruturas de dados
    LDfinalizarLista(&listaDinamica);
    ABfinalizar(ABinicio);
    LLfinalizar();

    return 0;
}

/**
 * Exibe o menu principal.
 */
void exibirMenu()
{
    printf("\n=== MENU PRINCIPAL ===\n");
    printf("[1] Adicionar Cliente\n");
    printf("[2] Alterar Cliente\n");
    printf("[3] Excluir Cliente\n");
    printf("[4] Procurar Cliente\n");
    printf("[5] Relatório\n");
    printf("[0] Sair\n");
    printf("Escolha uma opção: ");
}

void adicionarCliente()
{
    char cpf[12];

    printf("\n=== ADICIONAR CLIENTE ===\n");
    lerCPF(cpf);

    if (ABinicio != NULL)
    {
        struct noAB *resultado = ABlocalizar(ABinicio, cpf);
        if (resultado != NULL)
        {
            printf("CPF já cadastrado!\n");
            return;
        }
    }

    // Ler dados do cliente
    Cliente novoCliente;
    printf("\nDigite os dados do cliente:\n");
    lerDadosCliente(&novoCliente, cpf);

    // Adicionar na Lista Dinâmica
    int registro = LDadicionarCliente(&listaDinamica, novoCliente);

    if (registro == -1)
    {
        printf("Erro ao adicionar cliente na lista dinâmica!\n");
        return;
    }

    // Adicionar na Árvore Binária
    struct noAB *novoNo = ABnovoNo(cpf, registro);
    ABadicionar(ABinicio, novoNo);

    // Adicionar na Lista Duplamente Ligada (ordenado por nome)
    LLadicionar(novoCliente.nome, registro);

    printf("Cliente cadastrado com sucesso!\n");
}

void alterarCliente()
{
    char cpf[12];

    printf("\n=== ALTERAR CLIENTE ===\n");
    lerCPF(cpf);

    // Buscar o cliente na árvore binária
    struct noAB *resultado = ABlocalizar(ABinicio, cpf);

    if (resultado == NULL)
    {
        printf("CPF não cadastrado!\n");
        return;
    }

    // Obter dados atuais do cliente
    Cliente clienteAtual = LDobterCliente(&listaDinamica, resultado->registro);

    printf("\nDados atuais do cliente:\n");
    exibirCliente(&clienteAtual);

    // Ler novos dados
    Cliente novosDados;
    printf("\nDigite os novos dados (CPF não pode ser alterado):\n");
    lerDadosCliente(&novosDados, cpf);

    // Verificar se o nome foi alterado
    bool nomeAlterado = strcmp(clienteAtual.nome, novosDados.nome) != 0;

    // Atualizar na lista dinâmica
    if (LDatualizarCliente(&listaDinamica, resultado->registro, novosDados))
    {
        // Se o nome foi alterado, atualizar na lista duplamente ligada
        if (nomeAlterado)
        {
            LLexcluir(clienteAtual.nome);
            LLadicionar(novosDados.nome, resultado->registro);
        }

        printf("Cliente atualizado com sucesso!\n");
    }
    else
    {
        printf("Erro ao atualizar cliente!\n");
    }
}

void excluirCliente()
{
    char cpf[12];

    printf("\n=== EXCLUIR CLIENTE ===\n");
    lerCPF(cpf);

    // Buscar o cliente na árvore binária
    struct noAB *resultado = ABlocalizar(ABinicio, cpf);

    if (resultado == NULL)
    {
        printf("CPF não cadastrado!\n");
        return;
    }

    // Obter dados do cliente para remover da lista duplamente ligada
    Cliente cliente = LDobterCliente(&listaDinamica, resultado->registro);

    // Remover da árvore binária
    ABexcluir(cpf);

    // Remover da lista duplamente ligada
    LLexcluir(cliente.nome);

    printf("Cliente excluído com sucesso!\n");
    printf("Nota: Os dados permanecem na lista dinâmica mas ficam inacessíveis.\n");
}

void procurarCliente()
{
    char cpf[12];

    printf("\n=== PROCURAR CLIENTE ===\n");
    lerCPF(cpf);

    // Buscar o cliente na árvore binária
    struct noAB *resultado = ABlocalizar(ABinicio, cpf);

    if (resultado == NULL)
    {
        printf("CPF não cadastrado!\n");
        return;
    }

    // Obter e exibir dados do cliente
    Cliente cliente = LDobterCliente(&listaDinamica, resultado->registro);
    exibirCliente(&cliente);
}

void gerarRelatorio()
{
    printf("\n=== RELATÓRIO DE CLIENTES ===\n");

    if (LLregInicio == NULL)
    {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    printf("Clientes ordenados por nome:\n\n");

    // Percorrer a lista duplamente ligada (já ordenada por nome)
    LLprimeiro(); // Inicia a iteração no primeiro nó
    struct LLno *atual = LLregistroAtual();
    int contador = 1;

    if (atual == NULL)
    {
        printf("Erro: Não foi possível acessar o primeiro registro.\n");
        return;
    }

    while (atual != NULL)
    {
        Cliente cliente = LDobterCliente(&listaDinamica, atual->registro);

        printf("=== CLIENTE %d ===\n", contador);
        printf("CPF: %s\n", cliente.cpf);
        printf("Nome: %s\n", cliente.nome);
        printf("Endereço: %s\n", cliente.endereco);
        printf("Telefone: %s\n", cliente.telefone);
        printf("Email: %s\n", cliente.email);
        printf("================\n\n");

        if (!LLproximo())
        {
            break;
        }
        atual = LLregistroAtual();
        contador++;
    }

    printf("Total de clientes: %d\n", contador);
}