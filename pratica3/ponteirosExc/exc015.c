/*Crie uma func¸ao que receba dois par ˜ ametros: um array e um valor do mesmo tipo do ˆ
array. A func¸ao dever ˜ a preencher os elementos de array com esse valor. N ´ ao utilize ˜
´ındices para percorrer o array, apenas aritmetica de ponteiros. */
#include <stdio.h>
#include <stdlib.h>

int init(int *vet, int *a);

int main()
{
    int vet[10], a;

    scanf("%d", &a);

    init(vet, &a);

    printf("\n");

    for(int i = 0; i < 10; i++) {
        printf("%d ", *(vet + i));
    }

    return 0;
}

int init(int *vet, int *a) {
    for(int i = 0; i < 10; i++) {
        *(vet + i) = *a;
    }
}
