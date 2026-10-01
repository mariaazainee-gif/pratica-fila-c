#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
    int capacidade;
} Fila;

void inicializarFila(Fila *fila, int capacidade) {
    fila->inicio = 0;
    fila->fim = -1;
    fila->capacidade = capacidade;
}

int filaVazia(Fila *fila) {
    return fila->fim < fila->inicio;
}

int filaCheia(Fila *fila) {
    return (fila->fim - fila->inicio + 1) == fila->capacidade;
}

void adicionarFila(Fila *fila, int valor) {
    if (filaCheia(fila)) {
        printf("Fila cheia! Não é possível adicionar.\n");
        return;
    }
    fila->dados[++fila->fim] = valor;
}

int removerFila(Fila *fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia! Não é possível remover.\n");
        return -1;
    }
    return fila->dados[fila->inicio++];
}

void mostrarFila(Fila *fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia!\n");
        return;
    }
    printf("Fila: ");
    for (int i = fila->inicio; i <= fila->fim; i++) {
        printf("%d ", fila->dados[i]);
    }
    printf("\n");
}

void esvaziarFila(Fila *fila) {
    fila->inicio = 0;
    fila->fim = -1;
    printf("Fila esvaziada!\n");
}

void reverso(Fila *fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia! Não é possível inverter.\n");
        return;
    }
    int i = fila->inicio;
    int j = fila->fim;
    while (i < j) {
        int temp = fila->dados[i];
        fila->dados[i] = fila->dados[j];
        fila->dados[j] = temp;
        i++;
        j--;
    }
    printf("Fila invertida!\n");
}

void imprimirPares(Fila *fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia! Não há elementos para verificar.\n");
        return;
    }
    printf("Números pares na fila: ");
    for (int i = fila->inicio; i <= fila->fim; i++) {
        if (fila->dados[i] % 2 == 0) {
            printf("%d ", fila->dados[i]);
        }
    }
    printf("\n");
}

int somarElementos(Fila *fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia! Soma = 0\n");
        return 0;
    }
    int soma = 0;
    for (int i = fila->inicio; i <= fila->fim; i++) {
        soma += fila->dados[i];
    }
    printf("Soma dos elementos: %d\n", soma);
    return soma;
}

void multiplicarElementos(Fila *fila, int multiplicador) {
    if (filaVazia(fila)) {
        printf("Fila vazia! Não há elementos para multiplicar.\n");
        return;
    }
    for (int i = fila->inicio; i <= fila->fim; i++) {
        fila->dados[i] *= multiplicador;
    }
    printf("Elementos multiplicados por %d!\n", multiplicador);
}

void substituirPrimeiroUltimo(Fila *fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia! Não é possível substituir.\n");
        return;
    }
    if (fila->inicio == fila->fim) {
        printf("A fila tem apenas um elemento. Nada a substituir.\n");
        return;
    }
    int temp = fila->dados[fila->inicio];
    fila->dados[fila->inicio] = fila->dados[fila->fim];
    fila->dados[fila->fim] = temp;
    printf("Primeiro e último elementos trocados!\n");
}

int main() {
    Fila fila;
    int capacidade, opcao, valor, multiplicador;

    printf("Digite a capacidade da fila: ");
    scanf("%d", &capacidade);

    if (capacidade <= 0 || capacidade > MAX) {
        printf("Capacidade inválida. Usando valor padrão %d.\n", MAX);
        capacidade = MAX;
    }

    inicializarFila(&fila, capacidade);

    do {
        printf("\n=== Menu ===\n");
        printf("1. Adicionar Fila\n");
        printf("2. Remover Fila\n");
        printf("3. Mostrar Fila\n");
        printf("4. Esvaziar Fila\n");
        printf("5. Reverso\n");
        printf("6. Imprimir números pares da fila\n");
        printf("7. Somar elementos da fila (todos)\n");
        printf("8. Multiplicar elementos da fila (por um número escolhido)\n");
        printf("9. Substituir primeiro pelo último\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser adicionado: ");
                scanf("%d", &valor);
                adicionarFila(&fila, valor);
                break;
            case 2:
                valor = removerFila(&fila);
                if (valor != -1) {
                    printf("Elemento removido: %d\n", valor);
                }
                break;
            case 3:
                mostrarFila(&fila);
                break;
            case 4:
                esvaziarFila(&fila);
                break;
            case 5:
                reverso(&fila);
                break;
            case 6:
                imprimirPares(&fila);
                break;
            case 7:
                somarElementos(&fila);
                break;
            case 8:
                printf("Digite o multiplicador: ");
                scanf("%d", &multiplicador);
                multiplicarElementos(&fila, multiplicador);
                break;
            case 9:
                substituirPrimeiroUltimo(&fila);
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
