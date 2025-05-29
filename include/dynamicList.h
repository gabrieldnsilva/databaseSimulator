#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include <stdbool.h>

// Estrutura do Cliente
typedef struct
{
    char cpf[12];
    char nome[100];
    char endereco[100];
    char telefone[20];
    char email[100];
} Cliente;

// Estrutura da Lista Dinâmica
typedef struct
{
    Cliente *lista;
    int tamanho;
    int capacidade;
} DynamicList;

/**
 * Inicializa a lista dinâmica com a capacidade inicial.
 * @param lista Ponteiro para a lista dinâmica.
 */
void LDinicializarLista(DynamicList *lista);

/**
 * Adiciona um cliente à lista dinâmica.
 * @param lista Ponteiro para a lista dinâmica.
 * @param cliente Cliente a ser adicionado.
 * @return O registro (índice) do cliente adicionado ou -1 em caso de erro.
 */
int LDadicionarCliente(DynamicList *lista, Cliente cliente);

/**
 * Obtém um cliente da lista dinâmica com base no registro.
 * @param lista Ponteiro para a lista dinâmica.
 * @param registro Registro do cliente a ser obtido.
 * @return O Cliente encontrado.
 */
Cliente LDobterCliente(DynamicList *lista, int registro);

/**
 * Atualiza os dados de um cliente existente na lista dinâmica.
 * @param lista Ponteiro para a lista dinâmica.
 * @param registro O índice do cliente a ser atualizado.
 * @param novosDados Os novos dados do cliente.
 * @return true se o cliente foi atualizado com sucesso, false caso contrário.
 */
bool LDatualizarCliente(DynamicList *lista, int registro, Cliente novosDados);

/**
 * Libera a memória alocada para a lista de clientes.
 * @param lista Ponteiro para a lista dinâmica a ser finalizada.
 */
void LDfinalizarLista(DynamicList *lista);

#endif // DYNAMIC_LIST_H