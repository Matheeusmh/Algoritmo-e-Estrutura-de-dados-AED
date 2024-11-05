#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct pilha {
    int pilha[MAX];
    int topo;
} Pilha;

void iniciarPilha(Pilha **p) {
    (*p)->topo = -1;
}

int cheia(Pilha **p) {
    return (*p)->topo == MAX - 1;
}

void push(Pilha **p, int x) {
    if(!cheia(p)) {
        (*p)->topo++;
        (*p)->pilha[(*p)->topo] = x;
    }
}

int vazia(Pilha **p) {
    return (*p)->topo == -1;
}

int pop(Pilha **p) {
    if(!vazia(p)) {
        int x = (*p)->pilha[(*p)->topo];
        (*p)->topo--;

        return x;
    }
}

void inverterPosicoes(Pilha **p) {
    if(!vazia(p)) {
        Pilha *aux;
        aux = (Pilha *)malloc(sizeof(Pilha));

        iniciarPilha(&aux);

        while((*p)->topo != -1) {
            push(&aux, pop(p));
        }

        while(aux->topo != -1) {
            push(p, pop(&aux));
        }
    }
}

int main(void) {
    Pilha *p;

    iniciarPilha(&p);

    for(int i = 0; i < 10; i++) {
        push(&p, i + i);
    }

    inverterPosicoes(&p);

    for(int i = 0; i < 10; i++) {
        printf("%d\n", pop(&p));
    }

    return 0;
}
