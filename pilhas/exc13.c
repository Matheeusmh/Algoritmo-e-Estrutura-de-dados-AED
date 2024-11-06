#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
} No;

typedef struct pilha{
    No *topo;
    int quantidade;
} Pilha;

void iniciarPilha(Pilha **pp) {
    *pp = (Pilha *)malloc(sizeof(Pilha));
    if(*pp == NULL) {
        printf("ERRO\n");
        return;
    }

    (*pp)->topo = NULL;
    (*pp)->quantidade = 0;
}

void push(Pilha **pp, int v) {
    No *novo;
    novo = (No *)malloc(sizeof(No));
    if(novo == NULL) {
        printf("Erro!\n");
    }

    novo->valor = v;
    novo->prox = (*pp)->topo;
    (*pp)->topo = novo;
    (*pp)->quantidade++;
}

int empty(Pilha **pp) {
    return (*pp)->quantidade == 0;
}

int pop(Pilha **pp) {
    if(empty(pp)) {
        printf("Vazia!\n");
        return -1;
    }

    No *temp = (*pp)->topo;
    int v = (*pp)->topo->valor;

    (*pp)->topo = temp->prox;

    free(temp);

    (*pp)->quantidade--;

    return v;
}

int ehIgual(Pilha *p1, Pilha *p2) {
    if(p1->quantidade != p2->quantidade) {
        return 0;
    }
    else {
        if(pop(&p1) != pop(&p2)) {
            return 0;
        }
    }

    return 1;
}

int main(void) {
    Pilha *p1, *p2;

    iniciarPilha(&p1);
    iniciarPilha(&p2);

    for(int i = 0; i < 10; i++) {
        push(&p1, i - 2);
        push(&p2, i - 2);
    }

    if(ehIgual(p1, p2)) {
        printf("As pilhas sao iguais!\n");
    }
    else {
        printf("As pilhas sao diferentes!\n");
    }

    return 0;
}
