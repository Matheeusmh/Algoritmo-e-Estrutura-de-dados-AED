#include <stdio.h>
#include <stdlib.h>

int ordena(int *a, int *b, int *c);
void swap(int *a, int *b);

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
    if (*a > *b && *a > *c)
        swap(a, c);

    if (*b > *c && *b > *a)
        swap(b, c);

    if(*a > *b) 
        swap(a, b);

    if (*a == *b && *b == *c)
        return 0;

    return 1;
}

void swap(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}