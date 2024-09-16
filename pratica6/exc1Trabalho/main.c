#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct no{
    char palavra[10];
    struct no *prox;
} No;

No *lista = NULL;

void criarLista(No **lista, char palavra[10]) {
    *lista = (No *)malloc(sizeof(No));

    if(*lista == NULL) {
        printf("Erro ao alocar memoria!");
    }
    else {
        strcpy((*lista)->palavra, palavra);
        (*lista)->prox = NULL;
    }
}

void insercao(No **lista, char palavra[10]) {
    if(*lista == NULL) {
        criarLista(lista, palavra);
    }
    else {
        No *aux = *lista;

        while(aux->prox != NULL) {
            aux = aux->prox;
        }

        aux->prox = (No *)malloc(sizeof(No));

        if(aux->prox == NULL) {
            printf("Erro ao alocar memoria!");
        }
        else {
            strcpy(aux->prox->palavra, palavra);
            aux->prox->prox = NULL;
        }
    }
}

void removeLista(No **lista, char palavra[10]) {
    No *ant = NULL;
    No *aux = *lista;

    while(aux != NULL) {
        if(strcmp(aux->palavra, palavra) == 0) {
            if(ant == NULL) {
                *lista = aux->prox;
            }
            else {
                ant->prox = aux->prox;
            }
            free(aux);
            return;
        }
        else {
            ant = aux;
            aux = aux->prox;
        }
    }
}

void busca(No **lista, char palavra[10]) {
    No *aux = *lista;

    while(aux != NULL) {
        if(strcmp(aux->palavra, palavra) == 0) {
            printf("Palavra encontrada!");
            return;
        }
        aux = aux->prox;
    }

    printf("Palavra nao encontrada!");

}

void imprimeLista(No **lista) {
    No *aux = *lista;

    while(aux != NULL) {
        printf("%s\n", aux->palavra);
        aux = aux->prox;
    }
}

int countRec(No **lista) {
    No *aux = *lista;

    if(aux == NULL) {
        return 0;
    }
    else {
        return 1 + countRec(&aux->prox);
    }
}

int main(void) {
    FILE *ptr_arquivo;
    char palavra[10];

    ptr_arquivo = fopen("nomes.txt", "r");

    if(ptr_arquivo == NULL) {
        printf("Erro ao abrir o arquivo!");
        return 1; 
    }
    else {
        while(fscanf(ptr_arquivo, "%9s", palavra) != EOF) {
            insercao(&lista, palavra);
        }
    }

    fclose(ptr_arquivo);


    int tamanhoRec = countRec(&lista);
    printf("Tamanho da lista: %d\n", tamanhoRec);

    imprimeLista(&lista);

    No *aux;
    while(lista != NULL) {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }


    return 0;
}
