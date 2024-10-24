#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    char c;
    struct pilha *prox;
} Pilha;

Pilha *topo = NULL;

Pilha *iniciarPilha(char c) {
    topo = (Pilha *)malloc(sizeof(Pilha));
    if(topo == NULL) {
        printf("Error!\n");
        return topo;
    }

    topo->c = c;
    topo->prox = NULL;

    return topo;
}

Pilha *push_back(char c) {
    if(topo == NULL) {
        topo = iniciarPilha(c);
        return topo;
    }

    Pilha *aux;
    aux = (Pilha *)malloc(sizeof(Pilha));
    if(aux == NULL) {
        printf("Error!\n");
        return topo;
    }

    aux->c = c;
    aux->prox = topo;
    
    return aux;
}

Pilha *pop() {
    while(topo != NULL) {
        printf("%c", topo->c);
        Pilha *aux = topo;
        topo = topo->prox;
        free(aux);
    }

    return topo;
}
int main(void) {
    char c;

    push_back(' ');

    do {
        scanf("%c", &c);
        if(c == '.') break;
        if(c == ' ') {
            topo = pop();
        }
        topo = push_back(c);
    } while(c != '.');

    pop();

    return 0;
}