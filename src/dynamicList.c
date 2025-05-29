#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamicList.h"

// Define uma capacidade inicial para a lista.
#define INITIAL_CAPACITY 5
#define EXPANSION_FACTOR 2 // Fator pelo qual a lista será expandida
/**
 * Inicializa a lista dinâmica.
 * Aloca memória para a capacidade inicial e define tamanho como 0.
 * @param lista Ponteiro para a lista dinâmica a ser inicializada.
 */
void LDinicializarLista(DynamicList *lista)
{
    if (lista == NULL)
    {
        fprintf(stderr, "Erro: Ponteiro de lista nulo fornecido para inicializarLista.\n");
        return;
    }
    lista->lista = (Cliente *)malloc(INITIAL_CAPACITY * sizeof(Cliente));
    if (lista->lista == NULL)
    {
        perror("Erro ao alocar memória para a lista de clientes");
        exit(1); // Encerra o programa em caso de falha crítica de alocação
    }
    lista->tamanho = 0;
    lista->capacidade = INITIAL_CAPACITY;
}

/**
 * Adiciona um cliente à lista dinâmica.
 * Se a lista estiver cheia, ela tentará expandir sua capacidade.
 * @param lista Ponteiro para a lista dinâmica.
 * @param cliente Cliente a ser adicionado.
 * @return O índice (número de registro) onde o cliente foi adicionado, ou -1 em caso de falha na expansão.
 */
int LDadicionarCliente(DynamicList *lista, Cliente cliente)
{
    if (lista == NULL)
    {
        fprintf(stderr, "Erro: Ponteiro de lista nulo fornecido para adicionarCliente.\n");
        return -1;
    }

    // Verifica se é necessário expandir a lista
    if (lista->tamanho == lista->capacidade)
    {
        int novaCapacidade = lista->capacidade * EXPANSION_FACTOR;
        Cliente *temp = (Cliente *)realloc(lista->lista, novaCapacidade * sizeof(Cliente));

        if (temp == NULL)
        {
            perror("Erro ao realocar memória para expandir a lista de clientes");
            return -1;
        }

        lista->lista = temp;
        lista->capacidade = novaCapacidade;
    }

    // Adiciona o cliente e atualiza o tamanho
    lista->lista[lista->tamanho] = cliente;
    int novoRegistro = lista->tamanho;
    lista->tamanho++;

    return novoRegistro;
}

/**
 * Obtém um cliente da lista dinâmica com base no registro (índice).
 * @param lista Ponteiro para a lista dinâmica.
 * @param registro O índice do cliente a ser obtido.
 * @return O Cliente encontrado. Se o registro for inválido, uma mensagem de erro é impressa
 * e um Cliente "vazio" (campos zerados) é retornado.
 */
Cliente LDobterCliente(DynamicList *lista, int registro)
{
    Cliente clienteNulo = {0}; // Inicializa um cliente vazio para caso de erro

    if (lista == NULL)
    {
        fprintf(stderr, "Erro: Ponteiro de lista nulo fornecido para obterCliente.\n");
        return clienteNulo;
    }
    if (registro < 0 || registro >= lista->tamanho)
    {
        fprintf(stderr, "Erro: Registro %d inválido para obterCliente. Tamanho da lista: %d.\n", registro, lista->tamanho);
        return clienteNulo;
    }
    return lista->lista[registro]; // Retorna uma cópia do Cliente
}

/**
 * Atualiza os dados de um cliente existente na lista dinâmica.
 * @param lista Ponteiro para a lista dinâmica.
 * @param registro O índice do cliente a ser atualizado.
 * @param novosDados Os novos dados do cliente.
 * @return true se o cliente foi atualizado com sucesso, false caso contrário
 */
bool LDatualizarCliente(DynamicList *lista, int registro, Cliente novosDados)
{
    if (lista == NULL)
    {
        fprintf(stderr, "Erro: Ponteiro de lista nulo fornecido para atualizarCliente.\n");
        return false;
    }
    if (registro < 0 || registro >= lista->tamanho)
    {
        fprintf(stderr, "Erro: Registro %d inválido para atualizarCliente. Tamanho da lista: %d.\n", registro, lista->tamanho);
        return false;
    }

    // Preserva o CPF original (chave primária não pode ser alterada)
    char cpfOriginal[12];
    strcpy(cpfOriginal, lista->lista[registro].cpf);

    lista->lista[registro] = novosDados;             // Atualiza os dados do cliente
    strcpy(lista->lista[registro].cpf, cpfOriginal); // Restaura o CPF original

    return true;
}

/**
 * Libera a memória alocada para a lista de clientes.
 * Zera o tamanho e a capacidade da lista.
 * @param lista Ponteiro para a lista dinâmica a ser finalizada.
 */
void LDfinalizarLista(DynamicList *lista)
{
    if (lista == NULL)
    {
        fprintf(stderr, "Erro: Ponteiro de lista nulo fornecido para finalizarLista.\n");
        return;
    }
    if (lista->lista != NULL)
    {
        free(lista->lista);
        lista->lista = NULL;
    }
    lista->tamanho = 0;
    lista->capacidade = 0;
}