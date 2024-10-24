#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct no {
    char c;
    struct no *prox;
} Pilha;

typedef struct lista {
    char c;
    struct lista *prox;
} No;

No *cabeca = NULL;
Pilha *topo = NULL;


Pilha* iniciaPilha(char c) {
    topo = (Pilha *)malloc(sizeof(Pilha));
    if(topo == NULL) {
        printf("Nao foi possivel alocar memoria!\n");
        return topo;
    }

    topo->c = c;
    topo->prox = NULL;

    return topo;
}

Pilha *push_back(char c) {
    if(c == '\n') return topo;

    if(topo == NULL) {
        topo = iniciaPilha(c);
        return topo;
    }
    Pilha *aux;
    aux = (Pilha *)malloc(sizeof(Pilha));
    if(aux == NULL) {
        printf("Nao foi possivel alocar memoria!\n");
        return topo;
    }

    aux->prox = topo;
    aux->c = c;
    topo = aux;

    return topo;
}

void pop() {
    if(topo == NULL) {
        printf("Pilha Vazia!\n");
        return;
    }
    Pilha *aux = topo;

    topo = topo->prox;

    free(aux);
}

void top() {
    if(topo == NULL) {
        printf("Pilha Vazia!\n");
    }
    printf("%c\n", topo->c);
}

void iniciarLista(char c) {
    cabeca = (No *)malloc(sizeof(No));
    if(cabeca == NULL) {
        printf("Erro ao alocar memoria!");
    }

    cabeca->prox = NULL;
    cabeca->c = c;
}

void adicionarLista(char c) {
    if(c == '\n') return;
    if(cabeca == NULL) {
        iniciarLista(c);
        return;
    }

    No *aux;
    aux = (No *)malloc(sizeof(No));
    if(aux == NULL) {
        printf("Erro ao alocar memoria!");
    }

    aux->c = c;
    aux->prox = NULL;
    No *temp = cabeca;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    temp->prox = aux;
}

int reverso() {
    int i = 0;
    while(topo != NULL && cabeca != NULL) {
        if(topo->c != cabeca->c) {
            return 0;
        }
        else {
            pop();
            cabeca = cabeca->prox;
        }
    }

    return 1;
}

int main() {
    char c; 
    
    printf("Digite a lista X: ");
    do {
        scanf("%c", &c);
        adicionarLista(c);
    } while(c != '\n');

    printf("Digite a pilha Y: ");
    do {
        scanf("%c", &c);
        topo = push_back(c);
    } while(c != '\n');

    if(reverso()) {
        printf("Y eh o reverso de X!");
    }
    else {
        printf("Y NAO eh o reverso de X!");
    }


    return 0;
}