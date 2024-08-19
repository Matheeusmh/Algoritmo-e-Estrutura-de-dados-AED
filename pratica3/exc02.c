#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int inteiro, *ptrInt;
    ptrInt = &inteiro;
    double real, *ptrReal;
    ptrReal = &real;
    char caracter, *ptrCaracter;
    ptrCaracter = &caracter;

    printf("Digite um inteiro: ");
    scanf("%d", &inteiro);
    printf("Digite um valor real: ");
    scanf("%lf", &real);
    fflush(stdin);
    printf("Digite um caracter: ");
    scanf("%c", &caracter);

    printf("\nInteiro antes: %d\nReal antes: %.2lf\nCaracter antes: %c\n\n", inteiro, real, caracter);
    *ptrInt = 1;
    *ptrReal = 1.1;
    *ptrCaracter = 'm';
    printf("Inteiro modificado: %d\nReal modificado: %.2lf\nCaracter modificado: %c\n", *ptrInt, *ptrReal, *ptrCaracter);

    return 0;
}