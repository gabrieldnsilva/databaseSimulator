#include <stdio.h>
#include <string.h>
#include "../include/binaryTree.h"

/**
 * @brief Ponteiro para o nó raiz da árvore binária.
 */
struct noAB *ABinicio;

/**
 * @brief Ponteiro para armazenar o nó pai durante buscas.
 */
struct noAB *ABanterior = NULL;

/**
 * @brief Inicializa a árvore binária.
 *
 * Define o ponteiro da raiz como NULL, indicando uma árvore vazia.
 */
void ABinicializar()
{
    ABinicio = NULL;
}

/**
 * @brief Libera recursivamente toda a memória alocada para a árvore.
 *
 * Esta função percorre a árvore e libera a memória de cada nó.
 *
 * @param elemento Ponteiro para o nó atual a ser liberado.
 */
void ABfinalizar(struct noAB *elemento)
{
    if (ABinicio != NULL)
    {
        printf("Excluindo %s\n", elemento->cpf);
        if (elemento->esquerda != NULL)
        {
            ABfinalizar(elemento->esquerda);
        }
        if (elemento->direita != NULL)
        {
            ABfinalizar(elemento->direita);
        }
        free(elemento);
    }
}

/**
 * @brief Cria e inicializa um novo nó para a árvore binária.
 *
 * @param cpf CPF a ser armazenado no nó.
 * @param registro Valor inteiro de registro associado ao CPF.
 * @return Ponteiro para o novo nó criado.
 */
struct noAB *ABnovoNo(char *cpf, int registro)
{
    struct noAB *p;

    p = malloc(sizeof(struct noAB));
    if (!p)
    {
        printf("Erro de alocação de memória !!!\n");
        exit(-1);
    }

    p->esquerda = NULL;
    p->direita = NULL;
    p->registro = registro;
    strcpy(p->cpf, cpf);

    return p;
}

/**
 * @brief Adiciona um novo nó à árvore binária.
 *
 * A inserção é feita com base na ordem do CPF.
 *
 * @param aonde Nó atual onde se deseja inserir.
 * @param novo Ponteiro para o novo nó a ser inserido.
 */
void ABadicionar(struct noAB *aonde, struct noAB *novo)
{
    if (ABinicio == NULL)
    {
        ABinicio = novo;
    }
    else
    {
        if (strcmp(novo->cpf, aonde->cpf) > 0)
        {
            // ABadicionar a direita
            if (aonde->direita == NULL)
            {
                aonde->direita = novo;
            }
            else
            {
                ABadicionar(aonde->direita, novo);
            }
        }
        else
        {
            // ABadicionar a esquerda
            if (aonde->esquerda == NULL)
            {
                aonde->esquerda = novo;
            }
            else
            {
                ABadicionar(aonde->esquerda, novo);
            }
        }
    }
}

/**
 * @brief Localiza um nó na árvore binária com base no CPF.
 *
 * Atualiza o ponteiro global ABanterior para o nó pai do nó encontrado.
 *
 * @param aonde Ponteiro para o nó atual da busca.
 * @param cpf CPF a ser localizado.
 * @return Ponteiro para o nó localizado ou NULL se não encontrado.
 */
struct noAB *ABlocalizar(struct noAB *aonde, char *cpf)
{
    if (ABinicio == NULL)
    {
        return NULL;
    }
    if (!strcmp(aonde->cpf, cpf))
    {
        return aonde;
    }
    else
    {
        ABanterior = aonde;
        if (strcmp(cpf, aonde->cpf) > 0)
        {
            // ABlocalizar à direita
            if (aonde->direita == NULL)
            {
                return NULL;
            }
            else
            {
                return ABlocalizar(aonde->direita, cpf);
            }
        }
        else
        {
            // ABlocalizar à esquerda
            if (aonde->esquerda == NULL)
            {
                return NULL;
            }
            else
            {
                return ABlocalizar(aonde->esquerda, cpf);
            }
        }
    }
}

/**
 * @brief Procura um CPF na árvore binária e exibe o resultado ao usuário.
 *
 * Esta função utiliza a função ABlocalizar() para buscar um CPF na árvore binária.
 * Se o CPF for encontrado, exibe o número de registro associado. Caso contrário,
 * informa que o CPF não está cadastrado.
 *
 * @param cpf CPF a ser procurado na árvore (string com até 11 caracteres + '\0').
 */
void ABprocurar(char *cpf)
{
    struct noAB *resultado = ABlocalizar(ABinicio, cpf);

    if (resultado == NULL)
    {
        printf("CPF não cadastrado.\n");
    }
    else
    {
        printf("CPF encontrado: %s | Registro: %d\n", resultado->cpf, resultado->registro);
    }
}

/**
 * @brief Exclui um nó da árvore binária com base no CPF.
 *
 * Remove o nó correspondente ao CPF e reinserir seus filhos na árvore.
 *
 * @param cpf CPF do nó a ser excluído.
 */
void ABexcluir(char *cpf)
{
    if (ABinicio == NULL)
    {
        printf("Vazio.\n");
        return;
    }

    struct noAB *aux = ABlocalizar(ABinicio, cpf);

    if (aux == NULL)
    {
        printf("CPF não cadastrado.\n");
        return;
    }

    printf("Localizado %s\n", aux->cpf);

    // Remove a referência ao nó excluído da árvore
    if (aux == ABinicio)
    {
        ABinicio = NULL;
    }
    else
    {
        if (strcmp(aux->cpf, ABanterior->cpf) > 0)
        {
            ABanterior->direita = NULL;
        }
        else
        {
            ABanterior->esquerda = NULL;
        }
    }

    // Reinsere os filhos do nó excluído
    if (aux->esquerda != NULL)
    {
        ABadicionar(ABinicio, aux->esquerda);
    }
    if (aux->direita != NULL)
    {
        ABadicionar(ABinicio, aux->direita);
    }

    free(aux);
}