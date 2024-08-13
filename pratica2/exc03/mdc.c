#include "mdc.h"

int calcularMDC(int num1, int num2) {
    int i = 2, acumulado = 1;

    while(1) {
        while(num1 % i == 0 && num2 % i == 0) {
            acumulado *= i;
            num1 /= i;
            num2 /= i;
        }

        while(num1 % i == 0) {
            num1 /= i;
        }
        
        while(num2 % i == 0) {
            num2 /= i;
        }

        if(num1 == 1 && num2 == 1) {
            break;
        }

        i++;
    }

    return acumulado;
}
