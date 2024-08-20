/*Fac¸a uma func¸ao para verificar se um n ˜ umero ´ e positivo ou negativo. Sendo que o valor ´
de retorno sera 1 se positivo, -1 se negativo e 0 se for igual a 0.*/
#include<stdio.h>
#include "verificador.h"

int main(void) {
    int n;

    scanf("%d", &n);

    if(verifica(n) == 1) {
        printf("O valor %d eh positivo!\n", n);
    }
    else if(verifica(n) == 0) {
        printf("O valor eh %d!\n", n);
    }
    else {
        printf("O valor %d eh negativo!\n", n);
    }

    return 0;
}
