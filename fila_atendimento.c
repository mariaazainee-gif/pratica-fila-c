#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 50

typedef struct {
    char nome[50];
    int senha;
    bool prioritario;
} Pessoa;

typedef struct {
    Pessoa pessoas[MAX];
    int inicio;
    int fim;
    int tamanho;
} FilaAtendimento;

void inicializarFila(FilaAtendimento *fila) {
    fila->inicio = 0;
    fila->fim = -1;
    fila->tamanho = 0;
}

void inserirPessoa(FilaAtendimento *fila) {
    if (fila->tamanho == MAX) {
        printf("Fila cheia!\n");
        return;
    }
    Pessoa p;
    int prioridade;
    printf("Digite o nome: ");
    scanf(" %[^\n]", p.nome);
    printf("É prioridade? (1 - Sim / 0 - Nao): ");
    scanf("%d", &prioridade);
    p.prioritario = (prioridade == 1);
    p.senha = fila->tamanho + 1;

    if (p.prioritario) {
        for (int i = fila->fim; i >= fila->inicio; i--) {
            fila->pessoas[i + 1] = fila->pessoas[i];
        }
        fila->fim++;
        fila->pessoas[fila->inicio] = p;
    } else {
        fila->fim++;
        fila->pessoas[fila->fim] = p;
    }

    fila->tamanho++;
    printf("Pessoa '%s' adicionada com senha %d (%s).\n\n", p.nome, p.senha, p.prioritario ? "PRIORIDADE" : "NORMAL");
}

void atenderPessoa(FilaAtendimento *fila) {
    if (fila->tamanho == 0) {
        printf("Fila vazia!\n\n");
        return;
    }
    Pessoa atendida = fila->pessoas[fila->inicio];
    printf("Atendendo: %s (Senha: %d - %s)\n\n", atendida.nome, atendida.senha, atendida.prioritario ? "PRIORIDADE" : "NORMAL");

    for (int i = 0; i < fila->fim; i++) {
        fila->pessoas[i] = fila->pessoas[i + 1];
    }
    fila->fim--;
    fila->tamanho--;
}

void mostrarFila(FilaAtendimento *fila) {
    if (fila->tamanho == 0) {
        printf("Fila vazia!\n\n");
        return;
    }
    printf("\nFila de Atendimento:\n");
    for (int i = fila->inicio; i <= fila->fim; i++) {
        printf("Senha %d - %s (%s)\n", fila->pessoas[i].senha, fila->pessoas[i].nome, fila->pessoas[i].prioritario ? "PRIORIDADE" : "NORMAL");
    }
    printf("\n");
}

int main() {
    FilaAtendimento fila;
    inicializarFila(&fila);
    int opcao;

    do {
        printf("\n== MENU ===\n");
        printf("1 - Adicionar pessoa à fila\n");
        printf("2 - Atender (remover da fila)\n");
        printf("3 - Mostrar fila\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirPessoa(&fila);
                break;
            case 2:
                atenderPessoa(&fila);
                break;
            case 3:
                mostrarFila(&fila);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
