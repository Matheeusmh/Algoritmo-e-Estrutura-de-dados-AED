#include<stdio.h>
#include<stdlib.h>

typedef struct fila {
    int valor;
    struct fila *prox;
} Fila;

typedef struct pilha {
    int valor;
    struct pilha *prox;
} Pilha;

void inciarPilha(Pilha **pilha) {
    *pilha = NULL;
}

void iniciarFila(Fila **ff) {
    (*ff) = NULL;
}

void adicionarElemento(Fila **ff, int x) {
    Fila *novo;
    novo = (Fila *)malloc(sizeof(Fila));

    novo->valor = x;
    novo->prox = NULL;

    if(*ff == NULL) {
        *ff = novo;
    }
    else {
        Fila *aux = *ff;

        while(aux->prox != NULL) {
            aux = aux->prox;
        }

        aux->prox = novo;
    }
}
void push(Pilha **pp, int x) {
    Pilha *novo;
    novo = (Pilha *)malloc(sizeof(Pilha));

    novo->valor = x;
    novo->prox = NULL;

    if(*pp != NULL) {
        novo->prox = *pp;
    }

    *pp = novo;
}

int pop(Pilha **pp) {
    Pilha *temp = *pp;
    int x = (*pp)->valor;

    *pp = (*pp)->prox;

    free(temp);

    return x;
}

int desenfilera(Fila **ff) {
    int x = (*ff)->valor;
    Fila *temp = (*ff);

    *ff = (*ff)->prox;

    free(temp);

    return x;
}

void inverterFila(Fila **ff, Pilha **pp) {
    while(*ff != NULL) {
        push(pp, desenfilera(ff));
    }

    while(*pp != NULL) {
        adicionarElemento(ff, pop(pp));
    }
}

int main(void) {
    Fila *ff;
    iniciarFila(&ff);

    Pilha *pp;
    inciarPilha(&pp);

    for(int i = 1; i <= 10; i++) {
        adicionarElemento(&ff, i);
    }

    inverterFila(&ff, &pp);

    for(int i = 1; i <= 10; i++) {
        printf("%d\n", desenfilera(&ff));
    }

    return 0;
}