/*Elaborar um programa que leia dois valores inteiros (A e B). Em seguida fac¸a uma func¸ao˜
que retorne a soma do dobro dos dois numeros lidos. A func¸ ´ ao dever ˜ a armazenar o dobro ´
de A na propria vari ´ avel A e o dobro de B na pr ´ opria vari ´ avel B. */
#include<stdio.h>

int calc(int *a, int *b);

int main(void) {
    int a, b;

    scanf("%d", &a);
    scanf("%d", &b);

    printf("\n%d + %d = %d\n", a, b, calc(&a, &b));

    return 0;
}

int calc(int *a, int *b) {
    *a *= 2;
    *b *= 2;

    return *a + *b;
}
