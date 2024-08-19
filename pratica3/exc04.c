#include <stdio.h>
#include <stdlib.h>

int ordena(int *a, int *b, int *c);

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

int ordena(int *a, int *b, int *c)
{
    int aux;

    if (*a > *b && *a > *c)
    {
        aux = *a;
        *a = *c;
        *c = aux;

        if (*a > *b)
        {
            aux = *b;
            *b = *a;
            *a = aux;
        }
    }

    else if (*b > *c)
    {
        aux = *b;
        *b = *c;
        *c = aux;
    }

    if (*a == *b && *b == *c)
    {
        return 0;
    }

    return 1;
}