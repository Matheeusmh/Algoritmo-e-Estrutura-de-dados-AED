/*
Suponha um algoritmo A e um algoritmo B com funções de complexidade de tempo a(n) = n2 + n + 549 e b(n) = 49n + 49, respectivamente. Determine quais são os valores de n pertencentes ao conjunto dos números naturais para os quais A leva menos tempo para executar do que B.
*/

#include <stdio.h>
#define MAX 100000

int main(void)
{
    long int i;
    long int algoA, algoB;

    for (i = 0; i < MAX; i++)
    {
        algoA = i * i + i + 549;
        algoB = i * 49 + 49;
        if (algoA < algoB)
            printf("%ld ", i);
    }
    return 0;
}
