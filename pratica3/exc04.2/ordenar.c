#include <stdio.h>
#include <stdlib.h>
#include "ordenar.h"

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