#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    char c;
    struct pilha *prox;
} Pilha;

Pilha *iniciarPilha(char c, Pilha *topo) {
    topo = (Pilha *)malloc(sizeof(Pilha));
    if(topo == NULL) {
        printf("ERROR!");
        return topo;
    }

    topo->c = c;
    topo->prox = NULL;

    return topo;
}

Pilha *push_back(char c, Pilha *topo) {
    if(topo == NULL) {
        topo = iniciarPilha(c, topo);
        return topo;
    }

    Pilha *aux;
    aux = (Pilha *)malloc(sizeof(Pilha));
    if(aux == NULL) {
        printf("ERROR!");
        return topo;
    }

    aux->c = c;
    aux->prox = topo;
    topo = aux;

    return topo;
}

char auxilio(Pilha **stack) {
    Pilha *aux = *stack;
    char valor;

    valor = aux->c;
    *stack = (*stack)->prox;
    free(aux);

    return valor;
}

Pilha *pop(Pilha *stack) {
    Pilha *aux = stack;

    stack = stack->prox;
    free(aux);

    return stack;
}

int palindromo(Pilha *stack1, Pilha *stack2) {
    while(stack1 != NULL && stack2 != NULL) {
        if(stack1->c != stack2->c) {
            return 0;
        }

        stack1 = pop(stack1);
        stack2 = pop(stack2);
    }

    return 1;
}
int main(void) {
    Pilha *topo = NULL;
    Pilha *aux = NULL;
    Pilha *reverso = NULL;

    char c;

    do {
        scanf("%c", &c);
        if(c != '\n' && c != ' ') {
            topo = push_back(c, topo);
            aux = push_back(c, aux);
        }
    } while (c != '\n');

    while(aux != NULL) {
        reverso = push_back(auxilio(&aux), reverso);
    }

    if(palindromo(reverso, topo)) {
        printf("A string eh um palindromo!\n");
    }
    else {
        printf("A string NAO eh um palindromo!\n");
    }
    

    return 0;
}
