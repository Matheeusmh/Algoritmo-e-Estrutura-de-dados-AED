#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
} No;

typedef struct fila{
    No *inicio, *fim;
    int quantidade;
} Fila;

void iniciarFila(Fila **ff) {
    *ff = (Fila *)malloc(sizeof(Fila));
    if(*ff == NULL) {
        printf("erro\n");
        return;
    }

    (*ff)->fim = NULL;
    (*ff)->inicio = NULL;
    (*ff)->quantidade = 0;
}

void enfileira(Fila *ff, int x) {
    No *novo;
    novo = (No *)malloc(sizeof(No));
    if(novo == NULL) {
        printf("Erro!\n");
        return;
    }

    novo->valor = x;
    novo->prox = NULL;

    if(ff->inicio == NULL) {
        ff->inicio = novo;
        ff->fim = novo;
    }
    else {
        ff->fim->prox = novo;
        ff->fim = novo;
    }

    ff->quantidade++;
}

int desenfileira(Fila *ff) {
    if(ff->inicio == NULL) return 0;

    No *temp = ff->inicio;
    int x = temp->valor;

    ff->inicio = temp->prox;

    free(temp);

    ff->quantidade--;

    return x;
} 

int dados(Fila *ff) {
    float media = 0, maior = (float)ff->inicio->valor, menor = (float)ff->inicio->valor;

    No *aux = ff->inicio;

    while(aux != NULL) {
        media += (float)aux->valor;

        if(aux->valor > maior) maior = aux->valor;
        if(aux->valor < menor) menor = aux->valor;

        aux = aux->prox;
    }

    printf("Media: %.2f\nMaior: %.2f\nMenor: %.2f\n", media / ff->quantidade, maior, menor);
}

int main(void) {
    Fila *ff;

    iniciarFila(&ff);

    for(int i = 1; i < 11;i++) {
        enfileira(ff, i);
    }

    dados(ff);

    return 0;
}