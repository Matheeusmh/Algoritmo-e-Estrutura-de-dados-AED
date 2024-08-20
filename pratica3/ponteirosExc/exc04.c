/*Fac¸a um programa que leia 2 valores inteiros e chame uma func¸ao que receba estas ˜
2 variaveis e troque o seu conte ´ udo, ou seja, esta func¸ ´ ao˜ e chamada passando duas ´
variaveis A e B por exemplo e, ap ´ os a execuc¸ ´ ao da func¸ ˜ ao, A conter ˜ a o valor de B e B ´
tera o valor de A. */
#include<stdio.h>

void swap(int *a, int *b);

int main(void) {
    int a, b;

    scanf("%d", &a);
    scanf("%d", &b);

    printf("\nA = %d\nB = %d\n", a, b);
    swap(&a, &b);
    printf("\nA = %d\nB = %d\n", a, b);

    return 0;
}

void swap(int *a, int*b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}