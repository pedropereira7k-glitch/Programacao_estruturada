#include <stdio.h>

#define CAPACIDADE 50

void inserir_ordenado(int vet[], int *tam, int valor) {
    int i = *tam - 1;
    while (i >= 0 && vet[i] > valor) {
        vet[i + 1] = vet[i];
        i--;
    }
    vet[i + 1] = valor;
    (*tam)++;
}

int busca_binaria(int vet[], int tam, int valor) {
    int esq = 0, dir = tam - 1;
    while (esq <= dir) {
        int meio = (esq + dir) / 2;
        if (vet[meio] == valor)
            return meio;
        else if (vet[meio] < valor)
            esq = meio + 1;
        else
            dir = meio - 1;
    }
    return -1;
}

void remover(int vet[], int *tam, int valor) {
    int pos = busca_binaria(vet, *tam, valor);
    if (pos == -1) {
        printf("Elemento nao encontrado. Nada foi feito.\n");
    } else {
        for (int i = pos; i < *tam - 1; i++) {
            vet[i] = vet[i + 1];
        }
        (*tam)--;
        printf("Elemento %d removido com sucesso.\n", valor);
    }
}

void imprimir(int vet[], int tam) {
    printf("Vetor [%d elementos]: ", tam);
    for (int i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int main() {
    int vet[CAPACIDADE];
    int tamanho = 0;
    int n, valor, opcao;

    // Leitura do tamanho
    do {
        printf("Digite o tamanho do vetor (entre 3 e 50): ");
        scanf("%d", &n);
    } while (n < 3 || n > 50);

    // Inserção ordenada dos elementos iniciais
    printf("Digite %d valores inteiros:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &valor);
        inserir_ordenado(vet, &tamanho, valor);
    }

    // Menu com if/else if
    do {
        printf("\n===== MENU =====\n");
        printf("1. Imprimir vetor\n");
        printf("2. Consultar elemento (busca binaria)\n");
        printf("3. Remover elemento\n");
        printf("4. Inserir elemento\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            imprimir(vet, tamanho);

        } else if (opcao == 2) {
            printf("Digite o valor a consultar: ");
            scanf("%d", &valor);
            int pos = busca_binaria(vet, tamanho, valor);
            if (pos == -1)
                printf("Elemento nao encontrado. Posicao: -1\n");
            else
                printf("Elemento %d encontrado na posicao %d.\n", valor, pos);

        } else if (opcao == 3) {
            printf("Digite o valor a remover: ");
            scanf("%d", &valor);
            remover(vet, &tamanho, valor);

        } else if (opcao == 4) {
            if (tamanho >= CAPACIDADE) {
                printf("Vetor cheio! Insercao impossivel.\n");
            } else {
                printf("Digite o valor a inserir: ");
                scanf("%d", &valor);
                inserir_ordenado(vet, &tamanho, valor);
                printf("Elemento %d inserido com sucesso.\n", valor);
            }

        } else if (opcao != 0) {
            printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    printf("Encerrando...\n");
    return 0;
}