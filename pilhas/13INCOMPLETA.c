#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int topo;
    struct pilha *prox;
} Pilha;

typedef Pilha *novaPilha;

novaPilha p1 = NULL;
novaPilha p2 = NULL;

void iniciarPilha(int x, Pilha **Topo) {
    novaPilha novo;
    novo = (Pilha *)malloc(sizeof(Pilha));
    if(novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    novo->topo = x;
    novo->prox = NULL;
    (*Topo) = novo;
}

void push(int x, Pilha **Topo) {
    if(Topo == NULL) {
        iniciarPilha(x, Topo);
        return;
    }

    novaPilha novo;
    novo = (Pilha *)malloc(sizeof(Pilha));
    if(novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    novo->topo = x;
    novo->prox = *Topo;
    *Topo = novo;
}

int compare() {
    while (p1 != NULL || p2 != NULL) {
        if(p1->topo != p2->topo) return 0;

        novaPilha aux = p1;
        p1 = p1->prox;
        free(p1);

        aux = p2;
        p2 = p2->prox;
        free(aux);
    }

    if(p1 != NULL && p2 != NULL) return 1;

    return 0;
}

int main(void) {
    int n;

    printf("Digite o tamanho de p1: ");
    scanf("%d", &n);

    printf("Digite os elementos de p1: ");
    while(n--) {
        int x;

        scanf("%d", &x);

        push(x, &p1);
    }

    printf("\nDigite o tamanho de p2: ");
    scanf("%d", &n);

    printf("Digite os elementos de p2: ");
    while(n--) {
        int x;

        scanf("%d", &x);

        push(x, &p2);
    }

    if(compare()) {
        printf("As pilhas sao iguais!!\n");
    }
    else {
        printf("As pilhas sao diferentes!!\n");
    }

    return 0;
}
