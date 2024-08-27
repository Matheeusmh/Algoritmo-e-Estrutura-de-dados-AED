/*Implemente uma func¸ao que calcule a ˜ area da superf ´ ´ıcie e o volume de uma esfera de
raio R. Essa func¸ao deve obedecer ao prot ˜ otipo: ´
void calc_esfera(float R, float *area, float *volume)
A area da superf ´ ´ıcie e o volume sao dados, respectivamente, por: ˜
A = 4 ∗ p ∗ R2
V = 4/3 ∗ p ∗ R3*/
#include <stdio.h>
#include <stdlib.h>

void calc_esfera(float R, float *area, float *volume);

const double pi = 3.14;

int main()
{
    float raio, area, volume;

    scanf("%f", &raio);

    calc_esfera(raio, &area, &volume);

    printf("Area = %f\n", area);
    printf("Volume = %f", volume);

    return 0;
}

void calc_esfera(float R, float *area, float *volume) {
    *area = 4 * pi * (R * R);
    *volume = 4 / 3 * pi * (R * R * R);
}
