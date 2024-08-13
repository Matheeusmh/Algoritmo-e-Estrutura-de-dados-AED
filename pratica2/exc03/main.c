#include <stdio.h>
#include "mdc.h"

int main(void) {
    int a, b, mdc; 

    printf("Digite o primeiro valor: ");
    scanf("%d", &a);
    printf("Digite o segundo valor: ");
    scanf("%d", &b);

    mdc = calcularMDC(a, b);

    printf("./O MDC entre %d e %d eh: %d\n", a, b, mdc);

    return 0;
}

