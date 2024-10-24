#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    char valor;
    struct pilha *prox;
} Pilha;

Pilha *topo = NULL;

void iniciarPilha(char c) {
    topo = (Pilha *)malloc(sizeof(Pilha));
    if(topo == NULL) {
        printf("ERRO!");
        return;
    }

    topo->valor = c;
    topo->prox = NULL;
}

void push_back(char c) {
    if(topo == NULL) {
        iniciarPilha(c);
        return;
    }

    Pilha *aux;
    aux = (Pilha *)malloc(sizeof(Pilha));
    if(aux == NULL) {
        printf("ERROR!");
        return;
    }

    aux->valor = c;
    aux->prox = topo;
    topo = aux;
}

void pop() {
    Pilha *aux = topo;
    topo = topo->prox;
    free(aux);
}

int empty() {
    if(topo == NULL) return 1;
    return 0;
}
int main(void) {
    char c;

    do {
        scanf("%c", &c);
        if(c == '(') {
            push_back(c);
        }
        else if(c == ')') {
            if(topo == NULL) {
                push_back(c);
                break;
            }
            pop();
        }
    } while (c != '\n');

    if(empty()) {
        printf("Numero certo de parenteses!\n");
    }
    else {
        printf("Numero errado de parenteses!\n");
    }

    return 0;
}
