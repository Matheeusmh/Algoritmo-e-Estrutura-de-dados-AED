/*Crie uma func¸ao para somar dois arrays. Esta func¸ ˜ ao deve receber dois arrays e retornar ˜
a soma em um terceiro array. Caso o tamanho do primeiro e segundo array seja diferente
entao a func¸ ˜ ao retornar ˜ a ZERO (0). Caso a func¸ ´ ao seja conclu ˜ ´ıda com sucesso a mesma
deve retornar o valor UM (1). Utilize aritmetica de ponteiros para manipulac¸ ´ ao do array. */
#include <stdio.h>
#include <stdlib.h>

int somaVetores(int *vet1, int *vet2, int *vet3, int size1, int size2); 

int main(void) {
    int *vet1, *vet2, *vet3, size1, size2;

    printf("Digite o tamanho do primeiro vetor: ");
    scanf("%d", &size1);
    printf("Digite o tamanho do segundo vetor: ");
    scanf("%d", &size2);

    vet1 = (int *)malloc(size1 * sizeof(int));

    vet3 = (int *)malloc(size1 * sizeof(int));

    printf("\nDigite os elementos do primeiro vetor: ");
    for(int i = 0; i < size1; i++) {
        scanf("%d", (vet1 + i));
    }

    vet2 = (int *)malloc(size2 *sizeof(int));
    

    printf("Digite os elementos do segundo vetor: ");
    for(int i = 0; i < size2; i++) {
        scanf("%d", (vet2 + i));
    }

    if(somaVetores(vet1, vet2, vet3, size1, size2)) {
        printf("\nA soma dos vetores eh: ");
        for(int i = 0; i < size1; i++) {
            printf("%d ", *(vet3 + i));
        }
        printf("\n");
    }
    else {
        printf("\nOs vetores nao podem ser somados pois sao de tamanhos diferentes.\n");
    }

    free(vet1);
    free(vet2);
    free(vet3);

    return 0;
}

int somaVetores(int *vet1, int *vet2, int *vet3, int size1, int size2) {
    if(size1 != size2) {
        return 0;
    }
    else {
        for(int i = 0; i < size1; i++) {
            *(vet3 + i) = *(vet2 + i) + *(vet1 + i);
        }
    }
    return 1;
}

