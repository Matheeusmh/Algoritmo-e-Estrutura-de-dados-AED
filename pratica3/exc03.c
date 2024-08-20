#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float vet[10], *ptrVet;
    ptrVet = vet;

    for (int i = 0; i < 10; i++)
    {
        printf("%p\n", vet + i);
    }

    return 0;
}