#include<stdio.h>
#include<stdlib.h>

typedef struct pilha{
    int topo;
    struct pilha *prox;
} Pilha;

void iniciarPilha(Pilha **p) {
    *p = NULL;
}

void push(Pilha **p, int v) {
    Pilha *novo;
    novo = (Pilha *)malloc(sizeof(Pilha));
    if(novo == NULL) {
        printf("Vazia!\n");
        return;
    }

    novo->topo = v;
    novo->prox = *p;
    *p = novo;
}

int pop(Pilha **p) {
    int x = (*p)->topo;
    Pilha *temp = *p;

    *p = (*p)->prox;

    free(temp);

    return x;
}

void copia(Pilha **p1, Pilha **p2) {
    if(*p1 == NULL) return;

    Pilha *aux = *p1;
    int count = 0;

    while(aux != NULL) {
        count++;
        aux = aux->prox;
    }

    int *vet;
    vet = (int *)malloc(count * sizeof(int));
    if(vet == NULL) return;

    for(int i = 0; i < count; i++) {
        vet[i] = pop(p1);
    }

    for(int i = count - 1; i >= 0; i--) {
        push(p1, vet[i]);
        push(p2, vet[i]);
    }
}

int main(void) {
    Pilha *p1, *p2;
    iniciarPilha(&p1);
    iniciarPilha(&p2);

    for(int i = 0; i < 10; i++) {
        push(&p1, i);
    }

    copia(&p1, &p2);

    while(p1 != NULL) printf("%d\n", pop(&p1));
    printf("--------------\n");
    while(p2 != NULL) printf("%d\n", pop(&p2));

    return 0;
}
