#include <stdio.h>
#include <stdlib.h>
#include "listaCircular.h"

int main(void)
{
    Descritor info;
    No *lista = NULL;
    info.head = NULL;
    info.tail = NULL;

    menu(&lista, &info);

    return 0;
}
