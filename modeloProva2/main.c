#include <stdio.h>
#include "fila.h"

int main(void) {
    Fila *softwares;

    iniciarFila(&softwares);

    adicionarSoftware(&softwares, "Teste1", "Matheus","Java", 2005);
    adicionarSoftware(&softwares, "Teste2", "Gabriel","Python", 2009);
    adicionarSoftware(&softwares, "Teste3", "Laura","C", 2015);
    adicionarSoftware(&softwares, "Teste4", "Maria Adriana","JS", 2023);
    adicionarSoftware(&softwares, "Teste5", "Joao","C++", 2019);

    imprimirSoftwares(&softwares);

    printf("\t___APOS REMOCAO:___\n\n");

    removerElemento(&softwares);

    imprimirSoftwares(&softwares);

    return 0;
}