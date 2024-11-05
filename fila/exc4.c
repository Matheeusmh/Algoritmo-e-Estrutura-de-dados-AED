#include<stdio.h>
#include<stdlib.h>

typedef struct fila {
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
        printf("ERRO!\n");
        return;
    }

    novo->valor = x;
    novo->prox = NULL;

    if(*f == NULL) {
        novo->prox = novo;
    }
    else {
        novo->prox = (*f)->prox;
        (*f)->prox = novo;
    }

    *f = novo;
}

int desenfileira(Fila **f) {
    if(*f == NULL) {
        printf("Vazia!\n");
        return -1;
    }

    int x = (*f)->prox->valor;

    if((*f)->prox == *f) {
        free(*f);
        *f = NULL;
        return x;
    }

    Fila *temp = (*f)->prox;

    (*f)->prox = temp->prox;

    free(temp);

    return x;
}

void sort(Fila **f) {
    if(*f == NULL) {
        printf("Vazia!\n");
        return;
    }

    int count = 0;
    Fila *aux = *f;

    do{
        count++;
        aux = aux->prox;
    } while(aux != *f);

    int *vet;
    vet = (int *)malloc(sizeof(int) * count);
    if(vet == NULL) {
        return;
    }

    for(int i = 0; i < count; i++) {
        vet[i] = desenfileira(f);
    }

    for(int i = 0; i < count; i++) {
        for(int j = 0; j < count - i - 1; j++) {
            if(vet[j] > vet[j + 1]) {
                int aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }

    for(int i = 0;  i < count ; i++) {
        enfileira(f, vet[i]);
    }
}

int main(void) {
    Fila *f;iniciarFila(&f);

    for(int i = 10; i >=0; i--) {
        enfileira(&f, i);
    }

    sort(&f);

    while(f != NULL) {
        printf("%d\n", desenfileira(&f));
    }

    return 0;
}