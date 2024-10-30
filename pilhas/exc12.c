#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    int topo;
    struct pilha *prox;
} Pilha;

Pilha *Topo = NULL;

void iniciarPilha(int x) {
    Pilha *novo;
    novo = (Pilha *)malloc(sizeof(Pilha));
    if(novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    novo->prox = NULL;
    novo->topo = x;
    
    Topo = novo;
}

void push(int x) {
    if(Topo == NULL) {
        iniciarPilha(x);
        return;
    }

    Pilha *novo;
    novo = (Pilha *)malloc(sizeof(Pilha));
    if(novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    novo->topo = x;
    novo->prox = Topo;

    Topo = novo;
}

void pop() {
    if(Topo == NULL) return;

    Pilha *aux = Topo;

    Topo = Topo->prox;

    free(aux);
}

int main(void) {
    int x, size1 = 0, size2 = 0;

    printf("Digite os elementos inteiros de P1 (digite um -1111 para finalizar): ");
    do {
        scanf("%d", &x);
        if(x == -1111) break;
        push(x);
    } while(x != -1111);

    while(Topo != NULL) {
        pop();
        size1++;
    }

    printf("Digite os elementos inteiros de P2 (digite um -1111 para finalizar): ");
    do {
        scanf("%d", &x);
        if(x == -1111) break;
        push(x);
    } while(x != -1111);

    while(Topo != NULL) {
        pop();
        size2++;
    }

    if(size1 > size2) {
        printf("A pilha 1 eh maior!\n");
    }
    else if(size2 > size1) {
        printf("A pilha 2 eh maior!\n");
    }
    else {
        printf("As pilhas possuem o mesmo tamanho!\n");
    }

    return 0;
}