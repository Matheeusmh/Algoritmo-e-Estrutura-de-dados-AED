#include <stdio.h>
#include "matriz.h"
#include <stdlib.h>

const int N = 100;

int main(void) {
    int N;
    
    printf("Digite a dimensao da matriz quadrada: ");
    scanf("%d", &N);

    int matriz[N][N];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Soma de todo os elementos: ", somaElementos(N, matriz));
    printf("Soma da diagonal principal: ", somaPrincipal(N, matriz));
    printf("Soma da diagonal secundaria: ", somaSecundaria(N, matriz));

    return 0;
}