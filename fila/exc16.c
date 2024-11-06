#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *elementos, inicio, fim, capacidade, quantidade;
} Fila;

void iniciarFila(Fila **ff, int c) {
    *ff = (Fila *)malloc(sizeof(Fila)); 
    if(*ff == NULL) return;

    (*ff)->capacidade = c;
    (*ff)->elementos = (int *)malloc(c * sizeof(int));
    if(*ff == NULL) return;

    (*ff)->quantidade = 0;
    (*ff)->inicio = 0;
    (*ff)->fim = -1;
}

int cheio(Fila *ff) {
    return ff->fim == ff->capacidade - 1;
}

void enfileirar(Fila *ff, int v) {
    if(cheio(ff)) {
        ff->fim = -1;
    }

    ff->fim++;
    ff->elementos[ff->fim] = v;
    ff->quantidade++;
}

int vazia(Fila *ff) {
    return ff->quantidade == 0;
}

int desenfileira(Fila *ff) {
    if(!vazia(ff)) {
        int v = ff->elementos[ff->inicio];
        
        ff->inicio++;
        ff->quantidade--;

        return v;
    }
    return -1;
}

const int maximo = 4;

int impares(Fila *ff) {
    int count = 0;

    for(int i = ff->inicio; i != ff->fim + 1; i++) {
        if(i == ff->capacidade) i = 0;
        if(ff->elementos[i] % 2 != 0) count++;
    }

    return count;
}

int main(void) {
    Fila *ff;
    iniciarFila(&ff, maximo);

    for(int i = 0; i < maximo; i++) {
        enfileirar(ff, i);
    }

    printf("%d\n", impares(ff));

    return 0;
}