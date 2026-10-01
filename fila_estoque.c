#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nome[50];
    int codigo;
} Produto;

typedef struct {
    Produto dados[MAX];
    int inicio;
    int fim;
    int capacidade;
} FilaEstoque;

void inicializarFila(FilaEstoque *fila, int capacidade) {
    fila->inicio = 0;
    fila->fim = -1;
    fila->capacidade = capacidade;
}

int filaVazia(FilaEstoque *fila) {
    return fila->fim < fila->inicio;
}

int filaCheia(FilaEstoque *fila) {
    return (fila->fim - fila->inicio + 1) == fila->capacidade;
}

void mostrarFila(FilaEstoque *fila) {
    if (filaVazia(fila)) {
        printf("Estoque vazio!\n");
        return;
    }
    printf("\n=== ESTOQUE ATUAL ===\n");
    printf("Posição | Código | Nome\n");
    printf("--------|--------|------------------\n");
    for (int i = fila->inicio; i <= fila->fim; i++) {
        printf("%7d | %6d | %s\n", i - fila->inicio + 1, fila->dados[i].codigo, fila->dados[i].nome);
    }
    printf("\n");
}

void adicionarProduto(FilaEstoque *fila) {
    if (filaCheia(fila)) {
        printf("Estoque cheio! Não é possível adicionar mais produtos.\n");
        return;
    }
    Produto novoProduto;
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", novoProduto.nome);
    printf("Digite o código do produto: ");
    scanf("%d", &novoProduto.codigo);
    fila->dados[++fila->fim] = novoProduto;
    printf("Produto adicionado com sucesso!\n");
    mostrarFila(fila);
}

void removerProduto(FilaEstoque *fila) {
    if (filaVazia(fila)) {
        printf("Estoque vazio! Não há produtos para remover.\n");
        return;
    }
    Produto removido = fila->dados[fila->inicio++];
    printf("Produto removido:\n");
    printf("Nome: %s\n", removido.nome);
    printf("Código: %d\n", removido.codigo);
    mostrarFila(fila);
}

void buscarProduto(FilaEstoque *fila) {
    if (filaVazia(fila)) {
        printf("Estoque vazio! Não há produtos para buscar.\n");
        return;
    }
    int codigoBusca;
    printf("Digite o código do produto a ser buscado: ");
    scanf("%d", &codigoBusca);
    int encontrado = 0;
    for (int i = fila->inicio; i <= fila->fim; i++) {
        if (fila->dados[i].codigo == codigoBusca) {
            printf("Produto encontrado:\n");
            printf("Nome: %s\n", fila->dados[i].nome);
            printf("Código: %d\n", fila->dados[i].codigo);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Produto com código %d não encontrado no estoque.\n", codigoBusca);
    }
}

int main() {
    FilaEstoque estoque;
    int capacidade, opcao;

    printf("Digite a capacidade do estoque: ");
    scanf("%d", &capacidade);

    if (capacidade <= 0 || capacidade > MAX) {
        printf("Capacidade inválida. Usando valor padrão %d.\n", MAX);
        capacidade = MAX;
    }

    inicializarFila(&estoque, capacidade);

    do {
        printf("\n=== Menu ===\n");
        printf("1. Adicionar produto ao estoque\n");
        printf("2. Remover produto do estoque\n");
        printf("3. Buscar produto pelo código\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto(&estoque);
                break;
            case 2:
                removerProduto(&estoque);
                break;
            case 3:
                buscarProduto(&estoque);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
