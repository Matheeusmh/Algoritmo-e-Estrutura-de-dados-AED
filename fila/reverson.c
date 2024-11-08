#include<stdio.h>
#include<stdlib.h>

typedef struct fila {
    int valor;
    struct fila *prox;
} Fila;

void iniciarFila(Fila **ff) {
    (*ff) = NULL;
}

void adicionarElemento(Fila **ff, int x) {
    Fila *novo;
    novo = (Fila *)malloc(sizeof(Fila));

    novo->valor = x;
    novo->prox = NULL;

    if(*ff == NULL) {
        *ff = novo;
    }
    else {
        Fila *aux = *ff;

        while(aux->prox != NULL) {
            aux = aux->prox;
        }

        aux->prox = novo;
    }
}

int desenfilera(Fila **ff) {
    int x = (*ff)->valor;
    Fila *temp = (*ff);

    *ff = (*ff)->prox;

    free(temp);

    return x;
}

void inverterFila(Fila **ff) {
    int x;

    if(*ff != NULL) {
        x = desenfilera(ff);
        inverterFila(ff);
        adicionarElemento(ff, x);
    }
}

int main(void) {
    Fila *ff;
    iniciarFila(&ff);

    for(int i = 1; i <= 10; i++) {
        adicionarElemento(&ff, i);
    }

    inverterFila(&ff);

    for(int i = 1; i <= 10; i++) {
        printf("%d\n", desenfilera(&ff));
    }

    return 0;
}