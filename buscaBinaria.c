#include <stdio.h>
#include <stdlib.h>

int pesquisa_binaria(int *vetor, int tamanho, int chave);

int main(void) {
    int tamanho, chave;

//  printf("\nDigite o valor que deseja encontrar: ");
    scanf("%d", &chave);

//  printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int *vetor = (int *)calloc(tamanho, sizeof(int));

    for(int i = 0; i < tamanho; i++) {
//      printf("Elemento %d: ", i + 1);
        scanf("%d", (vetor + i));
    }

    printf("%d\n", pesquisa_binaria(vetor, tamanho, chave));

    return 0;
}

int pesquisa_binaria(int *vetor, int tamanho, int chave) {
    int meio , ladoEsquerdo = 0, ladoDireito = tamanho - 1;

    while(ladoEsquerdo <= ladoDireito) {
        meio = (ladoEsquerdo + ladoDireito) / 2;

        if(vetor[meio] == chave) {
            return meio;
        }
        else if(vetor[meio] < chave) {
            ladoEsquerdo = meio + 1;
        }
        else {
            ladoDireito = meio - 1;
        }
    }
    return -1;
}
