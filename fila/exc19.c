#include<stdio.h>
#include<stdlib.h>

typedef struct fila {
    int *elementos, capacidade, fim, inicio, tamanho;
} Fila;

void iniciarFila(Fila **ff, int capacidade) {
    *ff = (Fila *)malloc(sizeof(Fila));
    (*ff)->capacidade = capacidade;
    (*ff)->elementos = (int *)malloc((*ff)->capacidade * sizeof(int));

    (*ff)->inicio = 0;
    (*ff)->fim = -1;
    (*ff)->tamanho = 0;
}

int vazia(Fila **ff) {
    return (*ff)->tamanho == 0;
}

int cheia(Fila **ff) {
    return (*ff)->tamanho == (*ff)->capacidade;
}

void enfileira(Fila **ff, int x) {
    if(!cheia(ff)) {
        if((*ff)->fim == (*ff)->capacidade - 1) {
            (*ff)->fim = -1;
        }
        (*ff)->fim++;
        (*ff)->elementos[(*ff)->fim] = x;
        (*ff)->tamanho++;
    }
}

int desenfileira(Fila **ff) {
    if(!vazia(ff)) {
        int x = (*ff)->elementos[(*ff)->inicio++];

        if((*ff)->inicio == (*ff)->capacidade) {
            (*ff)->inicio = 0;
        }

        (*ff)->tamanho--;

        return x;
    }
    else {
        return -1;
    }
}

int impares(Fila **ff) {
    int count = 0;
    int tamanho = ((*ff)->fim - (*ff)->inicio + (*ff)->capacidade) % (*ff)->capacidade + 1;
    int *temp = (int *)malloc(tamanho * sizeof(int));
    int i = 0;

    while(!vazia(ff)) {
        int x = desenfileira(ff);
        if(x % 2 == 0 && x != 0) {
            count++;
        }
        temp[i++] = x;
    }

    for(int j = 0; j < i; j++) {
        enfileira(ff, temp[j]);
    }

    free(temp);
    return count;
}

int main(void) {
    Fila *fila;
    iniciarFila(&fila, 10);

    for(int i = 0; i < 10; i++) {
        enfileira(&fila, i);
    }

    printf("%d\n", impares(&fila));

    return 0;
}
