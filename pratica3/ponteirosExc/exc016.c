/*Considere a seguinte declarac¸ao: int A, *B, **C, ***D; Escreva um programa que leia a ˜
variavel a e calcule e exiba o dobro, o triplo e o qu ´ adruplo desse valor utilizando apenas ´
os ponteiros B, C e D. O ponteiro B deve ser usada para calcular o dobro, C o triplo e D
o quadruplo. */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, *b, **c, ***d;
    b = &a;
    c = &b;
    d = &c;

    scanf("%d", &a);

    printf("\nEntrada: %d\nDobro: %d\nTriplo: %d\nQuadruplo: %d\n", a, *b * 2, **c * 3, ***d * 4);

    return 0;
}