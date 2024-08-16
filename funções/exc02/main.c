#include <stdio.h>
#include "data.h"

int main(void) {
    int dia, mes, ano;

    printf("Digite o dia, o mes e o ano separados por espaco: ");
    scanf("%d %d %d", &dia, &mes, &ano);

    data(dia, mes, ano);

    return 0;
}
