#include "verificador.h"

int verifica(int n) {
    if(n < 0) {
        return -1;
    }
    else if(n > 0) {
        return 1;
    }

    return 0;
}
