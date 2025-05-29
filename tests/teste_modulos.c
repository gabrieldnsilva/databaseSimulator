#include <stdio.h>
#include <string.h>
#include "../include/dynamicList.h"
#include "../include/aux.h"

int main()
{
    printf("=== TESTE DOS MÓDULOS ===\n\n");

    // Teste do módulo dynamicList
    printf("1. Testando Lista Dinâmica...\n");

    DynamicList lista;
    LDinicializarLista(&lista);

    // Criar clientes de teste
    Cliente c1 = {"12345678901", "João Silva", "Rua A, 123", "1234-5678", "joao@email.com"};
    Cliente c2 = {"98765432109", "Maria Santos", "Rua B, 456", "8765-4321", "maria@email.com"};
    Cliente c3 = {"11122233344", "Pedro Oliveira", "Rua C, 789", "9999-8888", "pedro@email.com"};

    // Teste de adição
    int reg1 = LDadicionarCliente(&lista, c1);
    int reg2 = LDadicionarCliente(&lista, c2);
    int reg3 = LDadicionarCliente(&lista, c3);

    printf("Registros adicionados: %d, %d, %d\n", reg1, reg2, reg3);

    // Teste de recuperação
    Cliente cliente = LDobterCliente(&lista, reg1);
    printf("Cliente recuperado (reg %d): %s, %s\n", reg1, cliente.cpf, cliente.nome);

    // Teste de atualização
    strcpy(cliente.telefone, "9999-9999");
    bool sucesso = LDatualizarCliente(&lista, reg1, cliente);
    printf("Atualização: %s\n", sucesso ? "Sucesso" : "Falha");

    // Verificar cliente atualizado
    cliente = LDobterCliente(&lista, reg1);
    printf("Telefone atualizado: %s\n", cliente.telefone);

    // Teste de validação de CPF
    printf("\n2. Testando validação de CPF...\n");
    printf("CPF '12345678901' válido: %s\n", validarCPF("12345678901") ? "Sim" : "Não");
    printf("CPF '123456789' válido: %s\n", validarCPF("123456789") ? "Sim" : "Não");
    printf("CPF '1234567890a' válido: %s\n", validarCPF("1234567890a") ? "Sim" : "Não");

    // Liberar memória
    LDfinalizarLista(&lista);

    printf("\n=== TESTES CONCLUÍDOS ===\n");

    return 0;
}