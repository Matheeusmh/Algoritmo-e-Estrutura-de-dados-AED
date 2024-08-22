/*Crie um programa que contenha um array de inteiros contendo 5 elementos. Utilizando
apenas aritmetica de ponteiros, leia esse array do teclado e imprima o dobro de cada ´
valor lido.*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vet[5], *ptrVet;

    *ptrVet = vet;

    for(int i = 0; i < 5; i++) {
        scanf("%d", (vet + i));
    }

    for(int i = 0; i < 5; i++) {
        printf("2 x %d = %d\n", *(vet + i), 2 * *(vet + i));
    }

    return 0;
}
