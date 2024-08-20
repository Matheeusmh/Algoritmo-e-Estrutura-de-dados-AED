/*Escreva um programa que contenha duas variaveis inteiras. Leia essas vari ´ aveis do ´
teclado. Em seguida, compare seus enderec¸os e exiba o conteudo do maior enderec¸o.*/
#include<stdio.h>

int main(void) {
    int a, b, *ptrA, *ptrB;
    ptrA = &a;
    ptrB = &b;

    scanf("%d", &a);
    scanf("%d", &b);

    if(ptrA > ptrB) {
        printf("O conteudo do maior endreco eh: %d\n", *ptrA);
    }
    else {
        printf("O conteudo do maior endreco eh: %d\n", *ptrB);
    }
    
    return 0;
}
