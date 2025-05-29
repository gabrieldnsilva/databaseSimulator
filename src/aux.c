#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/aux.h"

/**
 * Lê uma string do usuário removendo a quebra de linha.
 */
void lerString(char *buffer, int tamanho, const char *prompt)
{
    printf("%s", prompt);
    if (fgets(buffer, tamanho, stdin) != NULL)
    {
        // Remove a quebra de linha se presente
        buffer[strcspn(buffer, "\n")] = 0;
    }
    else
    {
        buffer[0] = '\0'; // String vazia em caso de erro
    }
}
/**
 * Lê um CPF válido do usuário.
 */
void lerCPF(char *cpf)
{
    do
    {
        lerString(cpf, 12, "Digite o CPF (apenas números, 11 dígitos): ");
        if (!validarCPF(cpf))
        {
            printf("CPF inválido! Por favor, digite um CPF com 11 dígitos numéricos.\n");
        }
    } while (!validarCPF(cpf));
}

/**
 * Valida se um CPF tem o formato correto.
 */
bool validarCPF(const char *cpf)
{
    if (cpf == NULL || strlen(cpf) != 11)
    {
        return false;
    }

    // Verifica se todos os caracteres são dígitos
    for (int i = 0; i < 11; i++)
    {
        if (!isdigit(cpf[i]))
        {
            return false;
        }
    }

    return true;
}

/**
 * Lê os dados completos de um cliente.
 */
void lerDadosCliente(Cliente *cliente, const char *cpf)
{
    if (cpf != NULL)
    {
        strcpy(cliente->cpf, cpf);
    }
    else
    {
        lerCPF(cliente->cpf);
    }

    lerString(cliente->nome, sizeof(cliente->nome), "Nome: ");
    lerString(cliente->endereco, sizeof(cliente->endereco), "Endereço: ");
    lerString(cliente->telefone, sizeof(cliente->telefone), "Telefone: ");
    lerString(cliente->email, sizeof(cliente->email), "Email: ");
}

/**
 * Exibe os dados de um cliente.
 */
void exibirCliente(const Cliente *cliente)
{
    printf("\n=== DADOS DO CLIENTE ===\n");
    printf("CPF: %s\n", cliente->cpf);
    printf("Nome: %s\n", cliente->nome);
    printf("Endereço: %s\n", cliente->endereco);
    printf("Telefone: %s\n", cliente->telefone);
    printf("Email: %s\n", cliente->email);
    printf("========================\n");
}

/**
 * Pausa a execução até o usuário pressionar Enter.
 */
void pausar()
{
    printf("\nPressione Enter para continuar...");
    getchar();
}

/**
 * Limpa o buffer de entrada.
 */
void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}