# Diagrama de Módulos - Simulador de Cadastro de Clientes

Este diagrama apresenta a estrutura modular do sistema e como os diferentes componentes se relacionam.

## Diagrama de Componentes

```mermaid
classDiagram
    class main {
        +int main()
        -void menu()
        -void adicionarCliente()
        -void alterarCliente()
        -void excluirCliente()
        -void procurarCliente()
        -void gerarRelatorio()
    }

    class DynamicList {
        -Cliente* lista
        -int tamanho
        -int capacidade
        +int adicionarCliente(Cliente cliente)
        +Cliente obterCliente(int registro)
        +bool atualizarCliente(int registro, Cliente novosDados)
        +void inicializar()
        +void finalizar()
    }

    class Cliente {
        +char cpf[12]
        +char nome[100]
        +char endereco[200]
        +char telefone[20]
        +char email[100]
    }

    class DoubleLinkedList {
        -Node* inicio
        -Node* fim
        +void adicionar(char* nome, int registro)
        +bool remover(char* nome)
        +Node* buscar(char* nome)
        +void listarTodos()
        +void inicializar()
        +void finalizar()
    }

    class Node {
        +char nome[100]
        +int registro
        +Node* anterior
        +Node* proximo
    }

    class BinaryTree {
        -TreeNode* raiz
        +void adicionar(char* cpf, int registro)
        +bool remover(char* cpf)
        +TreeNode* buscar(char* cpf)
        +void inicializar()
        +void finalizar()
    }

    class TreeNode {
        +char cpf[12]
        +int registro
        +TreeNode* esquerda
        +TreeNode* direita
    }

    main --> DynamicList : usa
    main --> BinaryTree : usa
    main --> DoubleLinkedList : usa
    DynamicList --> Cliente : contém
    DoubleLinkedList --> Node : contém
    BinaryTree --> TreeNode : contém
```

## Fluxo de Dados Principais

```mermaid
flowchart LR
    A[Cliente] --> B[main.c]
    B --> C{Operação?}
    C -->|Adicionar| D[adicionarCliente]
    C -->|Alterar| E[alterarCliente]
    C -->|Excluir| F[excluirCliente]
    C -->|Procurar| G[procurarCliente]
    C -->|Relatório| H[gerarRelatorio]

    D --> I[BinaryTree\nverificar CPF]
    I --> J[DynamicList\nadicionar dados]
    J --> K[BinaryTree\nadicionar índice]
    K --> L[DoubleLinkedList\nadicionar nome]

    E --> M[BinaryTree\nbuscar CPF]
    M --> N[DynamicList\natualizar dados]
    N --> O{Nome alterado?}
    O -->|Sim| P[DoubleLinkedList\natualizar]

    F --> Q[BinaryTree\nbuscar CPF]
    Q --> R[BinaryTree\nremover]
    R --> S[DoubleLinkedList\nremover]

    G --> T[BinaryTree\nbuscar CPF]
    T --> U[DynamicList\nbuscar dados]

    H --> V[DoubleLinkedList\npercorrer]
    V --> W[DynamicList\nbuscar dados]

```

## Descrição dos Módulos

### 1. Módulo Principal (main.c)

Responsável pela interface com o usuário, menu e coordenação entre os módulos.

### 2. Módulo de Lista Dinâmica (dynamicList)

Gerencia o armazenamento dos dados completos dos clientes.

### 3. Módulo de Lista Duplamente Ligada (doubleLinkedList)

Mantém um índice ordenado por nome para facilitar a geração de relatórios.

### 4. Módulo de Árvore Binária (binaryTree)

Implementa a indexação por CPF para acesso rápido aos registros.
