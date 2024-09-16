#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palavras.h"

No *lista = NULL;
No *listaPrimo = NULL;

void criarLista(No **lista, char *palavra)
{
    *lista = (No *)malloc(sizeof(No));

    if (*lista == NULL)
    {
        printf("Erro ao alocar memoria!");
    }
    else
    {
        strcpy((*lista)->palavra, palavra);
        (*lista)->prox = NULL;
    }
}

void insercao(No **lista, char *palavra)
{
    if (*lista == NULL)
    {
        criarLista(lista, palavra);
    }
    else
    {
        No *aux = *lista;

        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }

        aux->prox = (No *)malloc(sizeof(No));

        if (aux->prox == NULL)
        {
            printf("Erro ao alocar memoria!");
        }
        else
        {
            strcpy(aux->prox->palavra, palavra);
            aux->prox->prox = NULL;
        }
    }
}

void removeLista(No **lista, char *palavra)
{
    No *ant = NULL;
    No *aux = *lista;

    while (aux != NULL)
    {
        if (strcmp(aux->palavra, palavra) == 0)
        {
            if (ant == NULL)
            {
                *lista = aux->prox;
            }
            else
            {
                ant->prox = aux->prox;
            }
            free(aux);
            return;
        }
        else
        {
            ant = aux;
            aux = aux->prox;
        }
    }
}

void busca(No **lista, char *palavra)
{
    No *aux = *lista;

    while (aux != NULL)
    {
        if (strcmp(aux->palavra, palavra) == 0)
        {
            printf("Palavra encontrada!");
            return;
        }
        aux = aux->prox;
    }

    printf("Palavra nao encontrada!");
}

void imprimeLista(No *lista)
{
    No *aux = lista;

    while (aux != NULL)
    {
        printf("%s\n", aux->palavra);
        aux = aux->prox;
    }
}

int countRec(No *lista)
{
    No *aux = lista;

    if (aux == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + countRec(aux->prox);
    }
}

int countNoRec(No *lista)
{
    No *aux = lista;
    int count = 0;

    while (aux != NULL)
    {
        count++;
        aux = aux->prox;
    }

    return count;
}
int isPrimo(char *palavra)
{
    int tamanho = strlen(palavra), count = 0;

    for (int i = 1; i <= tamanho; i++)
    {
        if (tamanho % i == 0)
        {
            count++;
        }

        if (tamanho == 1)
        {
            return 1;
        }
    }

    if (count == 2)
        return 1;

    return 0;
}
void tamanhoPrimo(No *lista, No **listaPrimo)
{
    No *aux = lista;

    while (aux != NULL)
    {
        if (isPrimo(aux->palavra))
        {
            if (*listaPrimo == NULL)
            {
                criarLista(listaPrimo, aux->palavra);
            }
            else
            {
                No *auxPrimo;

                auxPrimo = (No *)malloc(sizeof(No));

                if (auxPrimo == NULL)
                {
                    printf("Falha ao alocar memoria!");
                }
                else
                {
                    strcpy(auxPrimo->palavra, aux->palavra);
                    auxPrimo->prox = *listaPrimo;
                    *listaPrimo = auxPrimo;
                }
            }
        }
        aux = aux->prox;
    }
}
