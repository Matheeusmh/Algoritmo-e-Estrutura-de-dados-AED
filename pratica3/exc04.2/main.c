#include <stdio.h>
#include <stdlib.h>
#include "ordenar.h"

int main(void)
{
    int a, b, c;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    printf("\n%d %d %d\n", a, b, c);

    if (!ordena(&a, &b, &c))
    {
        printf("\nOs valores sao iguais: ");
    }
    else
    {
        printf("\nOs valores sao diferentes: ");
    }

    printf("%d %d %d\n", a, b, c);

    return 0;
}
