#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdlib.h>

/**
 * @brief Estrutura que representa um nó da árvore binária.
 * 
 * Cada nó contém um cpf, um número de registro e ponteiros para os filhos à direita e à esquerda.
*/


struct noAB {
    char cpf[12];
    int registro; //n° Registro
    struct noAB *direita;
    struct noAB *esquerda;
};


/**
 * @brief Ponteiro para o nó inicial da árvore binária.
 * 
 * Esse ponteiro representa o primeiro nó da árvore, também conhecido como raiz.
*/
extern struct noAB *ABinicio;

/**
 * @brief Ponteiro para o nó anterior durante a navegação ou operações na árvore binária.
 * 
 * Este ponteiro é utilizado durante operações de manipulação ou busca.
 */
extern struct noAB *ABanterior;

/**
 * @brief Cria um novo nó na árvore binária.
 * 
 * Essa função aloca e inicializa um novo nó com o cpf e número de registro fornecidos.
 * 
 * @param cpf O cpf a ser associado ao nó.
 * @param registro O número de registro a ser associado ao nó.
 * 
 * @return Retorna um ponteiro para o novo nó criado.
*/
struct noAB *ABnovoNo(char *cpf, int registro);

/**
 * @brief Inicializa a árvore binária.
 * 
 * Essa função configura a árvore binária inicializando os ponteiros necessários.
*/
void ABinicializar();

/**
 * @brief Finaliza a árvore binária, desalocando os nós.
 * 
 * Essa função é responsável por desalocar toda a memória usada pela árvore binária.
 * 
 * @param elemento O nó a ser finalizado (desalocado).
*/
void ABfinalizar(struct noAB *elemento);

/**
 * @brief Adiciona um novo nó na árvore binária.
 * 
 * Essa função insere um novo nó na árvore, vinculando-o corretamente como filho de um nó especificado.
 * 
 * @param aonde O nó onde o novo nó será inserido.
 * @param novo O novo nó a ser inserido.
*/
void ABadicionar(struct noAB *aonde, struct noAB *novo);

/**
 * @brief Localiza um nó na árvore binária pelo cpf.
 * 
 * Essa função busca um nó na árvore a partir da raiz (ou de um nó específico) e retorna o nó encontrado, caso exista.
 * 
 * @param aonde O nó onde a busca deve começar (pode ser a raiz ou qualquer outro nó).
 * @param cpf O cpf do nó a ser encontrado.
 * 
 * @return Retorna o nó correspondente ao cpf, ou NULL caso o nó não seja encontrado.
*/
struct noAB *ABlocalizar(struct noAB *aonde, char *cpf);

/**
 * @brief Exclui um nó da árvore binária.
 * 
 * Essa função remove um nó da árvore binária, desalocando sua memória e ajustando os ponteiros dos pais e filhos.
 * 
 * @param cpf O cpf do nó a ser excluído.
*/
void ABexcluir(char *cpf);

#endif //BINARYTREE_H