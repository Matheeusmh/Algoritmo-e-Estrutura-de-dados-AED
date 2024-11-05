#include<stdio.h>
#include<stdlib.h>

typedef struct fila {
    int x;
    struct fila *prox;
} Fila;

void iniciar(Fila **ff) {
    *ff = NULL;
}

void adicionar(Fila **ff, int x) {
    Fila *novo;
    novo = (Fila *)malloc(sizeof(Fila));

    novo->x = x;
    novo->prox = NULL;

    if(*ff == NULL) {
        *ff = novo;
    }
    else {
        Fila *aux = (*ff);

        while(aux->prox != NULL) {
            aux = aux->prox;
        }

        aux->prox = novo;
    }
}

int desenfileira(Fila **ff) {
    Fila *temp = *ff;
    int x = (*ff)->x;

    *ff = (*ff)->prox;

    free(temp);

    return x;
}
void semNeg(Fila **ff1, Fila **ff2) {
    while(*ff1 != NULL) {
        int x = desenfileira(ff1);

        if(x >= 0 ) {
            adicionar(ff2, x);
        }
    }
}

int main(void) {
    Fila *ff, *ffNneg;
    iniciar(&ff);
    iniciar(&ffNneg);

    for(int i = 0; i < 10; i++) {
        int a = i;
        
        if(i % 2 != 0) a = i * -1;

        adicionar(&ff, a);
    }

    semNeg(&ff, &ffNneg);

    while(ffNneg != NULL) {
        printf("%d\n", desenfileira(&ffNneg));
    }

    return 0;
}