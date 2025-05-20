# Projeto Estrutura de Dados - Simulador de Banco de Dados

# Integrantes:

-   Gabriel Danilo do Nascimento e Silva
-   Kaique
-   Rogério Rodrigues

# Descrição

Simulador de banco de dados em C, utilizando 3 das estruturas de dados estudadas na disciplina.

-   Árvore Binária
-   Listas Dinâmicas
-   Listas Encadeadas

# Requisitos

## Lista Dinâmica:

    A lista dinâmica será utilizada para simular um banco de dados em disco

    - CPF
    - Nome
    - Endereço
    - Telefone
    - Email

## Lista Duplamente Ligada:

    A lista duplamente ligada será utilizada para o índice de ordenação de dados

    - Nome
    - Número de Registro

## Árvore Binária:

    A árvore binária será utilizada como índice de chave primária

    - CPF
    - Número de Registro

# Menu

## 1 - Adicionar

Quando a opção **[adicionar**] for selecionada, o programa deverá pedir por CPF;
Depois **[Buscar]** o CPF, na **Árvore Binária** em condicional:

-   Sim: "CPF já cadastrado"
-   Não: Pedir os dados do cliente, adicionar na **Lista dinâmica** pegando os números de registro, adicionar na **Árvore Binária** e na **Lista duplamente ligada**.

## 2 - Alterar

Quando a opção **[alterar]** for selecionada, pedir o CPF do cliente e **[Buscar]** na **Árvore Binária** para condicional:

-   Sim: Pedir os outros dados do cliente e alterar a **Lista dinâmica**, se o [Nome] for alterado, excluir da **Lista duplamente ligada** o anterior e adicionar o novo nome.
-   Não: "CPF não cadastrado"

Obs: O CPF não pode ser alterado por ser a chave primária.

## 3 - Excluir

Quando a opção **[excluir]** for selecionada, pedir o CPF do cliente e **[Buscar]** na **Árvore Binária** para condicional:

-   Sim: Excluir o cliente da **Lista dinâmica** e da **Árvore Binária**. Não será necessário excluir da **Lista dinâmica** pois os dados agora estarão inacessíveis.
-   Não: "CPF não cadastrado"

## 4 - Procurar

Quando a opção **[procurar]** for selecionada, pedir o CPF do cliente e **[Buscar]** na **Árvore Binária** para condicional:

-   Sim: Exibir os dados do cliente contidos na **Lista dinâmica**.
-   Não: "CPF não cadastrado"

## 5 - Relatório

Quando a opção **[relatório]** for selecionada, usar a **Lista duplamente ligada** para imprimir todos os registros ordenados por nome.

## 6 - Sair
