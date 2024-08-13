#include <stdio.h>
#include "media.h"

int main(void) {
 // Declaração das variáveis
 float num1, num2, num3, media;
 // Entrada de dados
 printf("Digite o primeiro numero: ");
 scanf("%f", &num1);

 printf("Digite o segundo numero: ");
 scanf("%f", &num2);

 printf("Digite o terceiro numero: ");
 scanf("%f", &num3);
 // Saida do resultado
 media = calcularMedia(num1, num2, num3);
 printf("A media dos tres numeros eh: %.2f\n", media);
 return 0;
}
