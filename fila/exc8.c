#include<stdio.h>
#include<stdlib.h>

typedef struct fila {
    int x;
    struct fila *prox;
} Fila;

void iniciarFila(Fila **ff) {
    *ff = NULL;
}

void enfileira(Fila **ff, int x) {
    Fila *novo;
    novo = (Fila *)malloc(sizeof(Fila));

    novo->x = x;
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

int desenfileira(Fila **ff) {
    Fila *temp = *ff;
    int aux = (*ff)->x;

    (*ff) = (*ff)->prox;

    free(temp);

    return aux;
}

void novaFila(Fila **f1, Fila **f2, Fila **f3) {
    if(*f1 == NULL && *f2 == NULL) return;

    while(*f1 != NULL || *f2 != NULL) {
        if(*f1 != NULL && (*f2 == NULL || (*f1)->x < (*f2)->x)) {
            enfileira(f3, desenfileira(f1));
        }
        else {
            enfileira(f3, desenfileira(f2));
        }
    }
}

int main(void) {
    Fila *f1, *f2, *f3;
    iniciarFila(&f1);
    iniciarFila(&f2);
    iniciarFila(&f3);

    for(int i = 0; i < 10; i++) {
        enfileira(&f1, i);
        enfileira(&f2, (i * 2) - 3);
    }

    novaFila(&f1, &f2, &f3);

    while(f3 != NULL) {
        printf("%d\n", desenfileira(&f3));
    }

    return 0;
}