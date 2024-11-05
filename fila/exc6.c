#include<stdio.h>
#include<stdlib.h>

typedef struct fila{
    int valor;
    struct fila *prox;
} Fila;

void iniciarFila(Fila **f) {
    *f = NULL;
}

void enfileira(Fila **f, int x) {
    Fila *novo;
    novo = (Fila *)malloc(sizeof(Fila));
    if(novo == NULL) {
        printf("Erro!\n");
        return;
    }

    novo->valor = x;
    novo->prox = NULL;

    if(*f == NULL) {
        novo->prox = novo;
        *f = novo;
    }
    else {
        novo->prox = (*f)->prox;
        (*f)->prox = novo;
        *f = novo;
    }
}

int desenfileira(Fila **f) {
    if(*f == NULL) {
        return 0;
    }

    Fila *temp = (*f)->prox;
    int x = temp->valor;

    if(*f == temp) {
        *f = NULL;
        return x;
    }
    
    (*f)->prox = temp->prox;

    free(temp);

    return x;
}

int countElementos(Fila **f) {
    int count = 0;
    Fila *aux;
    aux = (Fila *)malloc(sizeof(Fila));
    iniciarFila(&aux);

    while(*f != NULL) {
        count++;
        enfileira(&aux, desenfileira(f));
    }

    *f = aux;

    return count;
}

int maior(Fila **f1, Fila **f2) {
    if(countElementos(f1) > countElementos(f2)) {
        return 1;
    }
    else if(countElementos(f1) < countElementos(f2)) {
        return -1;
    }
    else {
        return 0;
    }

    return -123;
}

int main(void) {
    Fila *f1, *f2;

    iniciarFila(&f1);
    iniciarFila(&f2);

    for(int i = 0; i < 20; i++) {
        enfileira(&f1, i);
    }

    for(int i = 0; i < 20; i++) {
        enfileira(&f2, i);
    }

    if(maior(&f1, &f2) == -1) {
        printf("A segunda fila eh a maior!\n");
    }
    else if(maior(&f1, &f2)) {
        printf("A primeira fila eh a maior!\n");
    }
    else {
        printf("As filas possuem o mesmo tamanho!\n");
    }

    return 0;
}
