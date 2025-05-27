#ifndef LISTALIGADA_H
#define LISTALIGADA_H

#include <stdlib.h> // Para NULL
#include <stdbool.h> 

/** 
 * @struct LLno
 * @brief Estrutura de um nó da lista ligada.
 *
 * Esta estrutura contém os dados de um cliente (nome e registro) e ponteiros
 * para o próximo e anterior nó na lista.
 */
struct LLno {
    char nome[101]; /**< Nome do cliente (para ordenação e relatório) */
    int registro; /**< Número do registro na DynamicList */
    struct LLno *proximo; /**< Ponteiro para o próximo nó */
    struct LLno *anterior; /**< Ponteiro para o nó anterior */
};

/** 
 * @brief Ponteiro para o início da lista.
 */
extern struct LLno *LLregInicio; 

/** 
 * @brief Ponteiro para o fim da lista.
 */
extern struct LLno *LLregFim;    

/** 
 * @brief Ponteiro auxiliar usado em operações da lista.
 */
extern struct LLno *LLaux;       

/** 
 * @brief Ponteiro para o nó anterior em operações de navegação.
 */
extern struct LLno *LLregAnterior; 

/** 
 * @brief Ponteiro para um novo nó sendo criado ou adicionado.
 */
extern struct LLno *LLnovo;      

/** 
 * @brief Ponteiro para o nó atual durante a navegação na lista.
 */
extern struct LLno *LLregAtual;  

/** 
 * @brief Função para inicializar a lista.
 *
 * Esta função prepara a lista para uso, inicializando os ponteiros e alocando
 * a memória necessária.
 */
void LLinicializar(); 

/** 
 * @brief Função para liberar toda a memória alocada pela lista.
 *
 * Esta função irá percorrer todos os nós da lista e liberar a memória de
 * cada um.
 */
void LLfinalizar();   

/** 
 * @brief Função auxiliar recursiva para finalizar um elemento da lista.
 * 
 * @param elemento O nó que será finalizado.
 */
void LLfinalizarElemento(struct LLno *elemento); 

/** 
 * @brief Função para criar um novo nó.
 *
 * @param nome Nome do cliente a ser adicionado no nó.
 * @param registro Número do registro do cliente.
 * 
 * @return Um ponteiro para o novo nó criado.
 */
struct LLno *LLnovoNo(char *nome, int registro); 

/** 
 * @brief Função para adicionar um nó à lista, mantendo a ordem alfabética.
 *
 * @param nome Nome do cliente a ser adicionado.
 * @param registro Número de registro do cliente.
 */
void LLadicionar(char *nome, int registro); 

/** 
 * @brief Função que adiciona um nó no início da lista.
 *
 * Este nó será o menor nome entre todos os elementos na lista.
 */
void LLadicionarNoInicio();            

/** 
 * @brief Função que adiciona um nó no meio da lista, mantendo a ordem alfabética.
 */
void LLadicionarNoMeio();              

/** 
 * @brief Função que adiciona um nó no fim da lista.
 *
 * Este nó será o maior nome ou a última inserção de uma sub-rotina.
 */
void LLadicionarNoFim();               

/** 
 * @brief Função para excluir um nó da lista, baseado no nome do cliente.
 *
 * @param nome Nome do cliente a ser removido.
 */
void LLexcluir(char *nome);     

/** 
 * @brief Função que remove o primeiro nó da lista.
 */
void LLexcluirNoInicio();       

/** 
 * @brief Função que remove um nó do meio da lista.
 */
void LLexcluirNoMeio();         

/** 
 * @brief Função que remove o último nó da lista.
 */
void LLexcluirNoFim();          

/** 
 * @brief Função que move o ponteiro para o primeiro nó da lista.
 */
void LLprimeiro();              

/** 
 * @brief Função que move o ponteiro para o último nó da lista.
 */
void LLultimo();                

/** 
 * @brief Função que retorna o nó atualmente apontado pelo ponteiro LLregAtual.
 *
 * @return O nó atualmente apontado por LLregAtual.
 */
struct LLno *LLregistroAtual(); 

/** 
 * @brief Função que avança o ponteiro LLregAtual para o próximo nó.
 *
 * @return Retorna true se o ponteiro foi movido para o próximo nó, 
 *         e false caso não haja próximo nó.
 */
bool LLproximo();            

/** 
 * @brief Função que retrocede o ponteiro LLregAtual para o nó anterior.
 *
 * @return Retorna true se o ponteiro foi movido para o nó anterior, 
 *         e false caso não haja nó anterior.
 */
bool LLanterior();           

#endif //LISTALIGADA_H
