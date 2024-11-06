#include<stdio.h>
#include<stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

typedef struct {
    No *inicio, *final;
    int quantidade;
} Fila;

void iniciarFila(Fila **ff) {
    (*ff) = (Fila *)malloc(sizeof(Fila));
    if(*ff == NULL) return;

    (*ff)->final = NULL;
    (*ff)->inicio = NULL;
    (*ff)->quantidade = 0;
}

void enfileirar(Fila *f, int v) {
    No *novo;
    novo = (No *)malloc(sizeof(No));
    if(novo == NULL) return;

    novo->valor = v;
    novo->prox = NULL;

    if(f->inicio == NULL) {
        f->inicio = novo;
        f->final = novo;
    }
    else {
        f->final->prox = novo;
        f->final = novo;
    }

    f->quantidade++;
}

int vazia(Fila *f) {
    return f->quantidade == 0;
}

int desenfileirar(Fila *f) {
    if(!vazia(f)) {
        No *temp = f->inicio;
        int v = temp->valor;

        f->inicio = temp->prox;

        free(temp); 
        f->quantidade--;

        return v;
    }

    return -1;
}

int pares(Fila *f) {
    No *aux = f->inicio;
    int count = 0;

    while(aux != NULL) {
        if(aux->valor % 2 == 0 && aux->valor != 0) count++;
        aux = aux->prox;
    }

    return count;
}

int main(void) {
    Fila *f;
    iniciarFila(&f);

    for(int i = 0; i <= 100; i++) {
        enfileirar(f, i);
    }

    printf("%d\n", pares(f));

    return 0;
}