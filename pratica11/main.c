#include <stdio.h>
#include "verbetes.h"

int main()
{
    Descritor *dadosDicionario;
    
    iniciarLista(&dadosDicionario);
    iniciarPilha();
    leituraArquivos(&dadosDicionario);

    menu(&dadosDicionario);

    return 0;
}
