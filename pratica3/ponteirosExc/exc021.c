/*Escreva um programa que declare um array de inteiros e um ponteiro para inteiros. Associe o ponteiro ao array. Agora, some mais um (+1) a cada posic¸ao do array usando o ˜
ponteiro (use *).*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int vet[10], *ptrVet;

    ptrVet = vet;

    for(int i = 0; i < 10; i++) {
        printf("%p == %p\n", &vet[i], (ptrVet + i));
    }

    return 0;
}
