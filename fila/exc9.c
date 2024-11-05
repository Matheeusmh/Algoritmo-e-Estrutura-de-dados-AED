#include<stdio.h>
#include<stdlib.h>

typedef struct fila{
    int *fila, inicio, fim, quant, capacidade;
} Fila;

void iniciar(Fila **ff, int c) {
    *ff = (Fila *)malloc(sizeof(Fila));
    (*ff)->capacidade = c;
    (*ff)->fila = (int *)malloc((*ff)->capacidade * sizeof(int));

    (*ff)->quant = 0;
    (*ff)->inicio = 0;
    (*ff)->fim = -1;
}

void adicionar(Fila **ff, int x) {
    if((*ff)->quant == (*ff)->capacidade) return;

    if((*ff)->fim == (*ff)->capacidade - 1) {
        (*ff)->fim = -1;
    }

    (*ff)->fim++;
    (*ff)->fila[(*ff)->fim] = x;
    (*ff)->quant++;
}

int desenfileirar(Fila **ff) {
    if((*ff)->quant == 0) return -1;

    int x = (*ff)->fila[(*ff)->inicio++];

    if((*ff)->inicio == (*ff)->capacidade) {
        (*ff)->inicio = 0;
    }

    (*ff)->quant--;

    return x;
}
int main(void) {
    Fila *ff; int c = 10;
    iniciar(&ff, c);

    for(int i = 1; i <= 10; i++) {
        adicionar(&ff, i);
    }

    while(ff->quant > 0) {
        printf("%d\n", desenfileirar(&ff));
    }

    return 0;
}
