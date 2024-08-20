#include<math.h>
#include<stdio.h>
#include "esfera.h"

double calcVolume(double r) {
    double pi = 3.14;

    return (4  * pi * (pow(r, 3))) / 3;
}