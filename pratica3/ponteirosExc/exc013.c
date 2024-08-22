/*Fac¸a um programa que leia tres valores inteiros e chame uma func¸ ˆ ao que receba estes 3 ˜
valores de entrada e retorne eles ordenados, ou seja, o menor valor na primeira variavel, ´
o segundo menor valor na variavel do meio, e o maior valor na ´ ultima vari ´ avel. A func¸ ´ ao˜
deve retornar o valor 1 se os tres valores forem iguais e 0 se existirem valores diferentes. ˆ
Exibir os valores ordenados na tela.*/
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int sort(int *a, int *b, int *c);

int main()
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    if(sort(&a, &b, &c)) {
        printf("\nOs valores sao iguais: %d %d %d\n", a, b, c);
    }
    else {
        printf("\nValores ordenados: %d %d %d\n", a, b, c);
    }

    return 0;
}

void swap(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int sort(int *a, int *b, int *c) {
    if(*a == *b && *b == *c) {
        return 1;
    }
    else {
        if(*a > *c) {
            swap(a, c);
        }
        if(*b > *c) {
            swap(b, c);
        }
        if(*a > *b) {
            swap(a, b);
        }
    }

    return 0;
}
