#include<stdio.h>
#include<stdlib.h>

typedef struct pilha {
    int topo;
    struct pilha *prox;
} Pilha;

void iniciarPilha(Pilha **pp) {
    *pp = NULL;
}

void push(Pilha **pp, int v) {
    Pilha *novo;
    novo = (Pilha *)malloc(sizeof(Pilha));
    if(novo == NULL) {
        printf("Erro!\n");
        return;
    }

    novo->topo = v;
    novo->prox = *pp;
    *pp = novo;
} 

int pop(Pilha **pp) {
    if(*pp == NULL) {
        printf("Vazia!\n");
        return -1;
    }

    int v = (*pp)->topo;
    Pilha *temp = *pp;

    *pp = (*pp)->prox;

    free(temp);

    return v;
}

void fibonacci(int n, Pilha **pp) {
    int a = 0, b = 1, fib;

    push(pp, a); 
    if (n > 0) {
        push(pp, b); 
    }

    for (int i = 2; i <= n; i++) {
        fib = a + b;
        push(pp, fib); 
        a = b;
        b = fib;
    }
}

int main(void) {
    Pilha *p;
    iniciarPilha(&p);

    int n; scanf("%d", &n);

    fibonacci(n, &p);

    while(p != NULL) {
        printf("%d\n", pop(&p));
    }

    return 0;
}