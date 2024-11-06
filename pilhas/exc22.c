#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct pilha {
    int pilha[MAX];
    int topo;
} Pilha;

void iniciarPilha(Pilha **pp) {
    *pp = (Pilha *)malloc(sizeof(Pilha));
    if(*pp == NULL) {
        printf("ERRO\n");
        return;
    }

    (*pp)->topo = -1;
}

int cheia(Pilha *pp) {
    return pp->topo == MAX - 1;
}

void push(Pilha *pp, int v) {
    if(!cheia(pp)) {
        pp->topo++;
        pp->pilha[pp->topo] = v;
    }
}

int empty(Pilha *pp) {
    return pp->topo == -1;
}

int pop(Pilha *pp) {
    if(!empty(pp)) {
        int v = pp->pilha[pp->topo];
        pp->topo--;
        return v;
    }

    return -1;
}

int main(void) {
    Pilha *p;
    iniciarPilha(&p);

    push(p, 2);
    push(p, 5);
    pop(p);
    printf("%d\n", pop(p));

    return 0;
}
