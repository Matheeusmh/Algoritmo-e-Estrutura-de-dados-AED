#include<stdio.h>
#include<stdlib.h>

typedef struct fila {
    int capacidade, quantidade, inicio, fim;
    float *elementos;
} Fila;

Fila *criaFila(int c) {
    Fila *aux;
    aux = (Fila *)malloc(sizeof(Fila));
    if(aux == NULL){
        printf("Erro ao alocar memoria!\n");
        return NULL;
    }

    aux->capacidade = c;

    aux->elementos = (float *)malloc(c * sizeof(float));
    if(aux->elementos == NULL) {
        printf("Erro ao alocar memoria!\n");
        return NULL;
    }

    aux->inicio = 0;
    aux->fim = -1;

    return aux;
}

void enfileirar(Fila **f, float elemento) {
    if((*f)->fim == (*f)->capacidade - 1) {
        (*f)->fim = -1;
    }

    (*f)->fim++;
    (*f)->elementos[(*f)->fim] = elemento;
    (*f)->quantidade++;
}

float desenfila(Fila **f) {
    float aux = (*f)->elementos[(*f)->inicio++];
    if((*f)->inicio == (*f)->capacidade) (*f)->inicio = 0;
    (*f)->quantidade--;
    
    return aux;
}


int main(void) {
    Fila *fila;
    int c;

    printf("Digite a capacidade da fila: ");
    scanf("%d", &c);

    fila = criaFila(c);

    while(1) {
        int op;
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            float x;
            scanf("%f", &x);
            enfileirar(&fila, x);
            break;
        case 2:
            printf("%f\n", desenfila(&fila));
            break;
        case 3:
            reverso(&fila);
            break;

        case 0:
            return 0;
        default:
            break;
        }
    }

    return 0;
}