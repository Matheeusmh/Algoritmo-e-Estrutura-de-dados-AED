/* Dois algoritmos A e B possuem complexidade n5 e 2n respectivamente. Você utilizaria
o algoritmo B ao invés do A? Em qual caso? Explique.*/

#include <stdio.h>
#define MAX 10000
#include <math.h>

int main(void) {
    double A, B;

    for(int i = 0; i < MAX; i++) {
        A = pow(i, 5);
        B = pow(2, i);
        if(B < A) {
            printf("%d ", i);
        }
    }

    return 0;
}