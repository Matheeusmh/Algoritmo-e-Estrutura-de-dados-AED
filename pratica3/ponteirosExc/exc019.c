/*Escreva uma func¸ao que aceita como par ˜ ametro um array de inteiros com N valores, e ˆ
determina o maior elemento do array e o numero de vezes que este elemento ocorreu ´
no array. Por exemplo, para um array com os seguintes elementos: 5, 2, 15, 3, 7, 15,
8, 6, 15, a func¸ao deve retorna para o programa que a chamou o valor 15 e o n ˜ umero 3 ´
(indicando que o numero 15 ocorreu 3 vezes). A func¸ ´ ao deve ser do tipo ˜ void.*/
#include <stdio.h>
#include <stdlib.h>

void calc(int *maior, int *contagem, int *vet, int n);

int main(void) {
    int n, maior, contagem = 0, *vet;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    vet = (int *)malloc(n * sizeof(int));

    printf("Digite os %d valores: ", n);

    for(int i = 0; i < n; i++) {
        scanf("%d", (vet + i));
    }

    calc(&maior, &contagem, vet, n);

    printf("\nO maior valor digitado foi: %d\n%d se repetiu %d vezes!\n", maior, maior, contagem);
    free(vet);

    return 0;
}

void calc(int *maior, int *contagem, int *vet, int n) {
    *maior = -10000;

    for(int i = 0; i < n; i++) {
        if(*maior < *(vet + i)) {
            *maior = *(vet + i);
        }
    }

    for(int i = 0; i < n; i++) {
        if(*(vet + i) == *maior) {
            (*contagem)++;
        }
    }
}
