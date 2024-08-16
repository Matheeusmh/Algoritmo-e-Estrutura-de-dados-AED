#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int somaElementos(int N, int** matriz) {
    int soma = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            soma += matriz[i][j];
        }
    }

    return soma;
}

int somaPrincipal(int N, int** matriz) {
    int soma = 0; 

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == j) soma += matriz[i][j];
        }
    }

    return soma;
}

int somaSecundaria(int N, int** matriz) {
    int soma = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(j == N - i - 1) {
                soma += matriz[i][j];
            }
        }
    }

    return soma;
}

int isQuadradoMagico(int N, int** matriz) {
    int soma = somaPrincipal(N, matriz);
    int somaAux = somaSecundaria(N, matriz);

    if(soma != somaAux) return 0;

    somaAux = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            somaAux += matriz[i][j];
        }

        if(somaAux != soma) return 0;

        somaAux = 0;

        for(int j = 0; j < N; j++) {
            somaAux += matriz[j][i];
        }

        if(somaAux != soma) return 0;

        somaAux = 0;
    }

    return 1;
}
