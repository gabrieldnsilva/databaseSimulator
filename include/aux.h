#ifndef AUX_H
#define AUX_H

#include "dynamicList.h"

/**
 * Lê uma string do usuário removendo a quebra de linha.
 * @param buffer Buffer onde será armazenada a string.
 * @param tamanho Tamanho máximo do buffer.
 * @param prompt Mensagem a ser exibida ao usuário.
 */
void lerString(char *buffer, int tamanho, const char *prompt);

/**
 * Lê um CPF válido do usuário.
 * @param cpf Buffer onde será armazenado o CPF.
 */
void lerCPF(char *cpf);

/**
 * Valida se um CPF tem o formato correto (apenas números, 11 dígitos).
 * @param cpf CPF a ser validado.
 * @return true se válido, false caso contrário.
 */
bool validarCPF(const char *cpf);

/**
 * Lê os dados completos de um cliente.
 * @param cliente Ponteiro para a estrutura Cliente a ser preenchida.
 * @param cpf CPF já conhecido (pode ser NULL).
 */
void lerDadosCliente(Cliente *cliente, const char *cpf);

/**
 * Exibe os dados de um cliente.
 * @param cliente Cliente a ser exibido.
 */
void exibirCliente(const Cliente *cliente);

/**
 * Pausa a execução até o usuário pressionar Enter.
 */
void pausar();

/**
 * Limpa o buffer de entrada.
 */
void limparBuffer();

#endif // AUX_H