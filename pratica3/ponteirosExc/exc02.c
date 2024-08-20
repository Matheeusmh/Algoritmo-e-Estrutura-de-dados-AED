/*Escreva um programa que contenha duas variaveis inteiras. Compare seus enderec¸os e ´
exiba o maior enderec¸o.*/
#include<stdio.h>

int main(void) {
    int a, b, *ptrA, *ptrB;

    ptrA = &a;
    ptrB = &b;

    if(ptrA > ptrB) {
        printf("O maior endereco eh o da variavel A: %p\n", ptrA);
    }
    else {
        printf("O maior endereco eh o da variavel B: %p\n", ptrB);
    }

    return 0;
}
