#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

typedef struct fila {
    No *inicio, *fim;
    int quantidade;
} Fila;

void iniciarFila(Fila **ff) {
    *ff = (Fila *)malloc(sizeof(Fila));
    if(*ff == NULL) {
        printf("erro!");
        return;
    }

    (*ff)->fim = NULL;
    (*ff)->inicio = NULL;
    (*ff)->quantidade = 0;
}

void enfileirar(Fila *ff, int v) {
    No *novo;
    novo = (No *)malloc(sizeof(No));
    if(novo == NULL) {
        printf("Erro!\n");
        return;
    }

    novo->valor = v;
    novo->prox = NULL;

    if(ff->inicio == NULL) {
        ff->inicio = novo;
        ff->fim = novo;
    }
    else {
        ff->fim->prox = novo;
        ff->fim = novo;
    }

    ff->quantidade++;
}

int vazia(Fila *ff) {
    return ff->quantidade == 0;
}
int desenfila(Fila *ff) {
    if(vazia(ff)) {
        return -1;
    }

    No *temp = ff->inicio;
    int v = temp->valor;

    ff->inicio = temp->prox;

    free(temp);

    ff->quantidade--;

    return v;
}

int inverte(Fila *ff) {
    if(!vazia(ff)) {
        int v = desenfila(ff);

        inverte(ff);

        enfileirar(ff, v);
    }
}

int main(void) {
    Fila *ff;

    iniciarFila(&ff);

    for(int i = 0; i < 20; i++) {
        enfileirar(ff, i);
    }

    inverte(ff);

    while(!vazia(ff)) {
        printf("%d\n", desenfila(ff));
    }

    return 0;
}
