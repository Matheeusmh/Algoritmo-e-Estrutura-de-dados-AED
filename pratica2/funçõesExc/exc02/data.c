#include "data.h"
#include <stdio.h>

void data(int dia, int mes, int ano) {
    printf("%d de ", dia);

    switch (mes)
    {
    case 1:
        printf("janeiro de %d\n", ano);
        break;
    case 2:
        printf("fevereiro de %d\n", ano);
        break;
    case 3:
        printf("marco de %d\n", ano);
        break;
    case 4:
        printf("abril de %d\n", ano);
        break;
    case 5:
        printf("maio de %d\n", ano);
        break;
    case 6:
        printf("junho de %d\n", ano);
        break;
    case 7:
        printf("julho de %d\n", ano);
        break;
    case 8:
        printf("agosto de %d\n", ano);
        break;
    case 9:
        printf("setembro de %d\n", ano);
        break;
    case 10:
        printf("outubro de %d\n", ano);
        break;
    case 11:
        printf("novembro de %d\n", ano);
        break;
    case 12:
        printf("dezembro de %d\n", ano);
        break;
    
    default:
        break;
    }
}
