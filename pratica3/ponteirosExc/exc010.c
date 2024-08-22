/*Crie um programa que contenha uma matriz de float contendo 3 linhas e 3 colunas.
Imprima o enderec¸o de cada posic¸ao dessa matriz.*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float vet[3][3];

    for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                printf("[%d][%d] = %p\n", i, j, &vet[i][j]);
            }
    }

    return 0;
}