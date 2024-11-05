#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

void iniciarFila(Fila **softwares) {
    *softwares = NULL;
} 

void adicionarSoftware(Fila **softwares, char *titulo, char *autor, char *linguagem, int ano) {
    Nova novoElemento;
    novoElemento = (Fila *)malloc(sizeof(Fila));
    if(novoElemento == NULL) {
        return;
    } 

    strcpy(novoElemento->dados.titulo, titulo);
    strcpy(novoElemento->dados.autor, autor);
    strcpy(novoElemento->dados.linguagem, linguagem);
    novoElemento->dados.ano = ano;
    novoElemento->prox = NULL;

    if(*softwares == NULL) {
        novoElemento->prox = novoElemento;
    }
    else {
        novoElemento->prox = (*softwares)->prox;
        (*softwares)->prox = novoElemento;
    }

    *softwares = novoElemento;
}

void removerElemento(Fila **fila) {
    if(*fila == NULL) {
        printf("Fila Vazia!\n");
        return;
    }

    if((*fila)->prox == *fila) {
        free(*fila);
        iniciarFila(fila);
        return;
    }

    Nova aux = (*fila)->prox;

    (*fila)->prox = (*fila)->prox->prox;

    free(aux);
}

void imprimirSoftwares(Fila **fila) {
    if(*fila == NULL) {
        printf("Fila Vazia!\n");
        return;
    }

    Nova aux = (*fila)->prox;

    do {
        printf("Titulo: %s\nAutor: %s\nLinguagem: %s\nAno: %d\n\n", aux->dados.titulo , aux->dados.autor, aux->dados.linguagem, aux->dados.ano);
        aux = aux->prox;
    } while(aux != (*fila)->prox);
}
