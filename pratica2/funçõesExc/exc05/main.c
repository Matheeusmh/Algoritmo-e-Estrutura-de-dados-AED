/*Fac¸a uma func¸ao e um programa de teste para o c ˜ alculo do volume de uma esfera. ´
Sendo que o raio e passado por par ´ ametro. ˆ
V = 4/3 ∗ π ∗ R3*/
#include <stdio.h>
#include "esfera.h"

int main(void) {
    double r; 
    
    scanf("%lf", &r);

    printf("O volume da esfera eh: %.2lf\n", calcVolume(r));

    return 0;
}
