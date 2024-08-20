/*1. Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char. Associe as variaveis aos ponteiros (use &). Modifique os valores de ´
cada variavel usando os ponteiros. Imprima os valores das vari ´ aveis antes e ap ´ os a ´
modificac¸ao.*/
#include<stdio.h>

int main(void) {
    int inteiro, *ptrInteiro;
    double real, *ptrReal;
    char caractere, *ptrCaractere;

    ptrInteiro = &inteiro;
    ptrReal = &real;
    ptrCaractere = &caractere;

    printf("Digite um inteiro: ");
    scanf("%d", &inteiro);
    printf("Digite um real: ");
    scanf("%lf", &real);
    printf("Digite um caractere: ");
    scanf(" %c", &caractere);

    printf("\nAntes: %d %.2lf %c", inteiro, real, caractere);

    *ptrInteiro = 1;
    *ptrReal = 2.0;
    *ptrCaractere = 'A';

    printf("\nDepois: %d %.2lf %c", *ptrInteiro, *ptrReal, *ptrCaractere);

    return 0;
}