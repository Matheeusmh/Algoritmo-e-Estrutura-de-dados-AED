#include<stdio.h>
#include<stdlib.h>

void maior_menor (int *v, int tam, int *maior, int *menor) {
    for(int i = 0; i < tam; i++) {
        if(i == 0) {
            *maior = *(v + i);
            *menor = *(v + i);
        }
        else {
            if(*(v + i) > *maior) *maior = *(v + i);
            if(*(v + i) < *menor) *menor = *(v + i);
        }
    }
}

int main(void) {
    int *v, tamanho, maior = 0, menor = 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    v = (int *)malloc(tamanho * sizeof(int));

    printf("Digite os elementos do vetor: ");
    for(int i = 0; i < tamanho; i++) {
        scanf("%d", (v + i));
    }

    maior_menor(v, tamanho, &maior, &menor);

    printf("Maior: %d; Menor: %d\n", maior, menor);

    return 0;
}
