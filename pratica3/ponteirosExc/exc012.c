/*Crie um programa que contenha um array contendo 5 elementos inteiros. Leia esse array
do teclado e imprima o enderec¸o das posic¸oes contendo valores pares.*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vet[5], *ptrVet;

    *ptrVet = vet;

    for(int i = 0; i < 5; i++) {
        scanf("%d", (vet + i));
    }

    printf("\n");

    for(int i = 0; i < 5; i++) {
        if(*(vet + i) % 2 == 0 && *(vet + i) != 0) {
            printf("Endereco de %d: %p\n", *(vet + i), (vet + i));
        }
    }

    return 0;
}
