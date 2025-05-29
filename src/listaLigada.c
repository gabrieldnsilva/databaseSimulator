#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/listaLigada.h"

struct LLno *LLregInicio = NULL;   /**< Ponteiro para o início da lista */
struct LLno *LLregFim = NULL;      /**< Ponteiro para o fim da lista */
struct LLno *LLaux = NULL;         /**< Ponteiro auxiliar para operações temporárias */
struct LLno *LLregAnterior = NULL; /**< Ponteiro para o nó anterior em operações */
struct LLno *LLnovo = NULL;        /**< Ponteiro para o novo nó sendo criado/adicionado */
struct LLno *LLregAtual = NULL;    /**< Ponteiro para o nó atual durante navegação */

/**
 * @brief Função de inicialização da lista ligada.
 *
 * Inicializa os ponteiros da lista, configurando todos como NULL. Deve ser chamada
 * antes de usar qualquer outra função que manipule a lista.
 */
void LLinicializar()
{
    LLregInicio = NULL;
    LLregFim = NULL;
    LLregAtual = NULL;
    LLaux = NULL;
    LLregAnterior = NULL;
    LLnovo = NULL;
}

/**
 * @brief Função de finalização da lista ligada.
 *
 * Libera toda a memória alocada para os nós da lista e reseta os ponteiros globais.
 */
void LLfinalizar()
{
    if (LLregInicio != NULL)
    {
        LLfinalizarElemento(LLregInicio);
        LLregInicio = NULL;
        LLregFim = NULL;
        LLregAtual = NULL;
    }
}

/**
 * @brief Função recursiva para liberar memória de cada elemento da lista.
 *
 * @param elemento Ponteiro para o nó a ser liberado.
 */
void LLfinalizarElemento(struct LLno *elemento)
{
    if (elemento == NULL)
        return;
    if (elemento->proximo != NULL)
    {
        LLfinalizarElemento(elemento->proximo);
    }
    free(elemento);
}

/**
 * @brief Função para criar um novo nó.
 *
 * Aloca memória para um novo nó, inicializa os dados do nó com o nome e registro fornecidos
 * e configura os ponteiros para NULL.
 *
 * @param nome Nome do cliente a ser armazenado no nó.
 * @param registro Número do registro do cliente.
 *
 * @return Ponteiro para o novo nó criado.
 */
struct LLno *LLnovoNo(char *nome, int registro)
{
    struct LLno *p;
    p = (struct LLno *)malloc(sizeof(struct LLno));
    if (!p)
    {
        perror("Erro fatal! Nao existe memoria disponivel para LLnovoNo");
        exit(EXIT_FAILURE);
    }

    strcpy(p->nome, nome);
    p->registro = registro;
    p->proximo = NULL;
    p->anterior = NULL;

    return p;
}

/**
 * @brief Função interna para adicionar um nó no início da lista.
 *
 * Atualiza os ponteiros da lista para adicionar o nó no início da lista.
 */
static void LLadicionarNoInicio_internal()
{
    LLnovo->proximo = LLregInicio;
    if (LLregInicio != NULL)
    {
        LLregInicio->anterior = LLnovo;
    }
    LLregInicio = LLnovo;
    if (LLregFim == NULL)
    {
        LLregFim = LLnovo;
    }
}

/**
 * @brief Função interna para adicionar um nó no meio da lista.
 *
 * Atualiza os ponteiros da lista para inserir um nó entre dois existentes, mantendo a ordem.
 */
static void LLadicionarNoMeio_internal()
{
    LLregAnterior = LLaux->anterior;

    LLregAnterior->proximo = LLnovo;
    LLnovo->anterior = LLregAnterior;

    LLnovo->proximo = LLaux;
    LLaux->anterior = LLnovo;
}

/**
 * @brief Função para adicionar um novo nó na lista.
 *
 * Esta função garante que a lista seja ordenada alfabeticamente por nome ao inserir um novo nó.
 * Se a lista estiver vazia, o nó será o único elemento da lista.
 *
 * @param nome Nome do cliente a ser inserido no nó.
 * @param registro Número de registro do cliente.
 */
void LLadicionar(char *nome, int registro)
{
    LLnovo = LLnovoNo(nome, registro);

    if (LLregInicio == NULL)
    {
        LLregInicio = LLnovo;
        LLregFim = LLnovo;
    }
    else
    {
        if (strcmp(LLnovo->nome, LLregInicio->nome) < 0)
        {
            LLadicionarNoInicio_internal();
        }
        else
        {
            LLaux = LLregInicio;
            while (LLaux->proximo != NULL && strcmp(LLnovo->nome, LLaux->proximo->nome) >= 0)
            {
                LLaux = LLaux->proximo;
            }

            if (LLaux->proximo == NULL)
            { // Inserir após LLaux (que é o último nó)
                LLaux->proximo = LLnovo;
                LLnovo->anterior = LLaux;
                LLregFim = LLnovo;
            }
            else
            { // Inserir LLnovo antes de LLaux->proximo
                LLnovo->proximo = LLaux->proximo;
                LLnovo->anterior = LLaux;
                LLaux->proximo->anterior = LLnovo;
                LLaux->proximo = LLnovo;
            }
        }
    }
}

/**
 * @brief Função interna para excluir um nó do início da lista.
 *
 * Atualiza os ponteiros da lista para remover o primeiro nó.
 */
static void LLexcluirNoInicio_internal()
{
    if (LLregInicio == NULL)
        return;
    LLaux = LLregInicio;
    LLregInicio = LLregInicio->proximo;
    if (LLregInicio != NULL)
    {
        LLregInicio->anterior = NULL;
    }
    else
    {
        LLregFim = NULL;
    }
    free(LLaux);
}

/**
 * @brief Função interna para excluir um nó do meio da lista.
 *
 * Atualiza os ponteiros da lista para remover um nó entre dois existentes.
 */
static void LLexcluirNoMeio_internal()
{
    if (LLaux == NULL || LLaux->anterior == NULL || LLaux->proximo == NULL)
        return;

    LLregAnterior = LLaux->anterior;
    struct LLno *proximoNo = LLaux->proximo;

    LLregAnterior->proximo = proximoNo;
    proximoNo->anterior = LLregAnterior;

    free(LLaux);
}

/**
 * @brief Função interna para excluir um nó do fim da lista.
 *
 * Atualiza os ponteiros da lista para remover o último nó.
 */
static void LLexcluirNoFim_internal()
{
    if (LLaux == NULL)
        return;

    if (LLaux == LLregInicio)
    {
        free(LLaux);
        LLregInicio = NULL;
        LLregFim = NULL;
        return;
    }

    LLregAnterior = LLaux->anterior;
    if (LLregAnterior != NULL)
    {
        LLregAnterior->proximo = NULL;
    }
    LLregFim = LLregAnterior;
    free(LLaux);
}

/**
 * @brief Função para excluir um nó da lista baseado no nome do cliente.
 *
 * Procura um nó com o nome fornecido e o remove da lista, atualizando os ponteiros
 * adequadamente. Se o nó não for encontrado, a função não faz nada.
 *
 * @param nome Nome do cliente a ser removido.
 */
void LLexcluir(char *nome)
{
    if (LLregInicio == NULL)
    {
        return;
    }

    LLaux = LLregInicio;
    while (LLaux != NULL && strcmp(LLaux->nome, nome) != 0)
    {
        LLaux = LLaux->proximo;
    }

    if (LLaux == NULL)
    {
        return;
    }

    if (LLaux == LLregInicio)
    {
        LLexcluirNoInicio_internal();
    }
    else if (LLaux == LLregFim)
    {
        LLexcluirNoFim_internal();
    }
    else
    {
        LLexcluirNoMeio_internal();
    }
}

/**
 * @brief Função para mover o ponteiro para o primeiro nó da lista.
 */
void LLprimeiro()
{
    LLregAtual = LLregInicio;
}

/**
 * @brief Função para mover o ponteiro para o último nó da lista.
 */
void LLultimo()
{
    LLregAtual = LLregFim;
}

/**
 * @brief Função para obter o nó atualmente apontado por LLregAtual.
 *
 * @return O ponteiro para o nó atual na lista.
 */
struct LLno *LLregistroAtual()
{
    return LLregAtual;
}

/**
 * @brief Função para mover o ponteiro LLregAtual para o próximo nó.
 *
 * @return Retorna true se o ponteiro foi movido para o próximo nó,
 *         e false se não houver próximo nó.
 */
bool LLproximo()
{
    if (LLregAtual == NULL || LLregAtual->proximo == NULL)
    {
        return false;
    }
    LLregAtual = LLregAtual->proximo;
    return true;
}

/**
 * @brief Função para mover o ponteiro LLregAtual para o nó anterior.
 *
 * @return Retorna true se o ponteiro foi movido para o nó anterior,
 *         e false se não houver nó anterior.
 */
bool LLanterior()
{
    if (LLregAtual == NULL || LLregAtual->anterior == NULL)
    {
        return false;
    }
    LLregAtual = LLregAtual->anterior;
    return true;
}
