#include<stdio.h>
#include<stdlib.h>

typedef struct fila{
    int valor;
    struct fila *prox;
} Fila;

typedef struct pilha {
    int topo;
    struct pilha *prox;
} Pilha;

void iniciarFila(Fila **ff) {
    *ff = NULL;
}

void iniciarPilha(Pilha **pp) {
    *pp = NULL;
}

void push(Pilha **pp, int x) {
    Pilha *novo;
    novo = (Pilha *)malloc(sizeof(Pilha));
    if(novo == NULL) {
        printf("Vazia!\n");
        return;
    }

    novo->topo = x;
    novo->prox = *pp;
    *pp = novo;
}

void enfileira(Fila **ff, int x) {
    Fila *novo;
    novo = (Fila *)malloc(sizeof(Fila));
    if(novo == NULL) {
        printf("Vazia!\n");
        return;
    }

    novo->valor = x;
    novo->prox = NULL;

    if(*ff == NULL) {
        novo->prox = novo;
        *ff = novo;
    }
    else {
        novo->prox = (*ff)->prox;
        (*ff)->prox = novo;
        *ff = novo;
    }
}

int pop(Pilha **pp) {
    if(*pp == NULL) {
        printf("Vazia!\n");
        return -1;
    }

    Pilha *temp = *pp;
    int x = (*pp)->topo;

    *pp = (*pp)->prox;

    free(temp);

    return x;
}

int desenfileira(Fila **ff) {
    if(*ff == NULL) {
        printf("Vazia!\n");
        return -1;
    }

    int x = (*ff)->prox->valor;

    if(*ff == (*ff)->prox) {
        free(*ff);
        iniciarFila(ff);
        return x;
    }

    Fila *temp = (*ff)->prox;

    (*ff)->prox = temp->prox;

    free(temp);

    return x;
}

void inverteFila(Fila **ff, Pilha **pp) {
    if(*ff == NULL) {
        printf("Vazia!\n");
        return;
    }

    while(*ff != NULL) {
        push(pp, desenfileira(ff));
    }

    while(*pp != NULL) {
        enfileira(ff, pop(pp));
    }
}

int main(void) {
    Fila *ff;
    Pilha *pp;

    iniciarFila(&ff);
    iniciarPilha(&pp);

    for(int i = 0; i < 10; i++) {
        enfileira(&ff, i * 2);
    }

    inverteFila(&ff, &pp);

    while(ff != NULL) {
        printf("%d\n", desenfileira(&ff));
    }

    return 0;
}
