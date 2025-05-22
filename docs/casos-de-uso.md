# Casos de Uso - Simulador de Cadastro de Clientes

Este documento descreve os casos de uso para o sistema de cadastro de clientes.

## UC01 - Adicionar Cliente

**Descrição:** Adiciona um novo cliente ao sistema.

**Fluxo principal:**

1. Usuário seleciona a opção "Adicionar" no menu
2. Sistema solicita o CPF do cliente
3. Sistema verifica se o CPF já existe na Árvore Binária
4. Se não existir, sistema solicita:
    - Nome
    - Endereço
    - Telefone
    - Email
5. Sistema armazena os dados na Lista Dinâmica
6. Sistema adiciona o CPF e número de registro na Árvore Binária
7. Sistema adiciona o Nome e número de registro na Lista Duplamente Ligada
8. Sistema confirma a adição

**Fluxo alternativo:**

-   Se o CPF já existir, sistema exibe mensagem "CPF já cadastrado"

## UC02 - Alterar Cliente

**Descrição:** Modifica os dados de um cliente existente.

**Fluxo principal:**

1. Usuário seleciona a opção "Alterar" no menu
2. Sistema solicita o CPF do cliente
3. Sistema busca o CPF na Árvore Binária
4. Se encontrado, sistema exibe os dados atuais e solicita novos valores para:
    - Nome
    - Endereço
    - Telefone
    - Email
5. Sistema atualiza os dados na Lista Dinâmica
6. Se o Nome for alterado, sistema atualiza a Lista Duplamente Ligada
7. Sistema confirma a alteração

**Fluxo alternativo:**

-   Se o CPF não existir, sistema exibe mensagem "CPF não cadastrado"

## UC03 - Excluir Cliente

**Descrição:** Remove um cliente do sistema.

**Fluxo principal:**

1. Usuário seleciona a opção "Excluir" no menu
2. Sistema solicita o CPF do cliente
3. Sistema busca o CPF na Árvore Binária
4. Se encontrado, sistema remove o cliente da Árvore Binária e da Lista Duplamente Ligada
5. Sistema confirma a exclusão

**Fluxo alternativo:**

-   Se o CPF não existir, sistema exibe mensagem "CPF não cadastrado"

## UC04 - Procurar Cliente

**Descrição:** Busca e exibe os dados de um cliente.

**Fluxo principal:**

1. Usuário seleciona a opção "Procurar" no menu
2. Sistema solicita o CPF do cliente
3. Sistema busca o CPF na Árvore Binária
4. Se encontrado, sistema recupera e exibe todos os dados do cliente da Lista Dinâmica

**Fluxo alternativo:**

-   Se o CPF não existir, sistema exibe mensagem "CPF não cadastrado"

## UC05 - Gerar Relatório

**Descrição:** Exibe um relatório com todos os clientes ordenados por nome.

**Fluxo principal:**

1. Usuário seleciona a opção "Relatório" no menu
2. Sistema percorre a Lista Duplamente Ligada (já ordenada por nome)
3. Para cada entrada, sistema recupera dados completos da Lista Dinâmica
4. Sistema exibe os dados de todos os clientes em ordem alfabética
