/*Crie uma func¸ao que receba como par ˜ ametro um array e o imprima. N ˆ ao utilize ˜ ´ındices
para percorrer o array, apenas aritmetica de ponteiros.*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    double vet[10];

    for(int i = 0; i < 10; i++){
        scanf("%lf", (vet + i));
    }

    for(int i = 0; i < 10; i++) {
        printf("%.2lf ", *(vet + i));
    }

    return 0;
}