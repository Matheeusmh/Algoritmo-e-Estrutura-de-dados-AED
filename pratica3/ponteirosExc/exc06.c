/*Fac¸a um programa que leia dois valores inteiros e chame uma func¸ao que receba estes ˜
2 valores de entrada e retorne o maior valor na primeira variavel e o menor valor na ´
segunda variavel. Escreva o conte ´ udo das 2 vari ´ aveis na tela.*/
#include<stdio.h>

void sort(int *a, int *b);

int main(void) {
    int a, b;
    
    scanf("%d %d", &a, &b);

    printf("Antes: %d %d\n", a, b);
    sort(&a, &b);
    printf("Depois: %d %d\n", a, b);

    return 0;
}

void sort(int *a, int *b) {
    if(*a > *b) {
        int aux = *a;
        *a = *b;
        *b = aux;
    }
}