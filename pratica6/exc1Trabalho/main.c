#include <stdio.h>
#include <stdlib.h>
#include "palavras.h"

int main(void)
{
    FILE *ptr_arquivo;
    char palavra[18];

    ptr_arquivo = fopen("nomes.txt", "r");

    if (ptr_arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!");
        return 1;
    }
    else
    {
        while (fscanf(ptr_arquivo, "%17s", palavra) != EOF)
        {
            insercao(&lista, palavra);
        }
    }

    fclose(ptr_arquivo);

    int tamanhoRec = countRec(lista);

    printf("Tamanho da lista com recursao: %d\n", tamanhoRec);
    printf("Tamanho da lista sem recursao: %d\n", countNoRec(lista));

    tamanhoPrimo(lista, &listaPrimo);
    imprimeLista(lista);
    printf("\n");
    imprimeLista(listaPrimo);

    char exemploRemove[] = "Relampago";
    removeLista(&lista, exemploRemove);
    printf("\n");
    imprimeLista(lista);

    char exemploBusca[] = "Saturno";
    printf("\n");
    busca(&lista, exemploBusca);
    printf(" %s!\n", exemploBusca);
    

    No *aux;
    while (lista != NULL)
    {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }

    return 0;
}
