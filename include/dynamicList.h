#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include <stdbool.h>

// Prototipos
typedef struct
{
    char cpf[12];
    char nome[100];
    char endereco[100];
    char telefone[20];
    char email[100];
} Cliente;

typedef struct
{
    Cliente *lista;
    int tamanho;
    int capacidade;
} DynamicList;

/**
 * Cria uma lista dinâmica com a capacidade inicial especificada.
 * @return Um ponteiro para a lista dinâmica criada.
 */
void inicializarLista(DynamicList *lista);

/**
 * Adiciona um cliente à lista dinâmica.
 * @param lista Ponteiro para a lista dinâmica.
 * @param cliente Cliente a ser adicionado.
 * @return true se o cliente foi adicionado com sucesso, false caso contrário.
 */
int adicionarCliente(DynamicList *lista, Cliente cliente);

/**
 * Remove um cliente da lista dinâmica com base no registro.
 * @param lista Ponteiro para a lista dinâmica.
 * @param registro Registro do cliente a ser removido.
 * @return true se o cliente foi removido com sucesso, false caso contrário.
 */
Cliente obterCliente(DynamicList *lista, int registro);

/**
 * Imprime todos os clientes na lista dinâmica.
 * @param lista Ponteiro para a lista dinâmica.
 */
bool atualizarCliente(DynamicList *lista, int registro, Cliente novosDados);

/**
 * Imprime todos os clientes na lista dinâmica.
 * @param lista Ponteiro para a lista dinâmica.
 */
void finalizarLista(DynamicList *lista);

#endif // DYNAMIC_LIST_H