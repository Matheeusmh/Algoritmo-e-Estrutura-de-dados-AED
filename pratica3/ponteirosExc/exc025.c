/*Fac¸a um programa que possua uma func¸ao para ˜
• ler 2 notas e retorna-las por par ´ ametro (chamar uma func¸ ˆ ao dedicada a ler 2 notas ˜
validas e que devolver os 2 n ´ umeros lidos); ´
• calcular a media simples e a m ´ edia ponderada e retorn ´ a-las por par ´ ametro, onde a ˆ
segunda nota tem peso 2 media ponderada = (n1 + n2 ∗ 2)/3;*/
#include<stdio.h>
#include<stdlib.h>

float recebeNota() {
    float nota;

    printf("Digite a nota: ");
    scanf("%f", &nota);

    return nota;
}

void calcMedia(float *nota1, float *nota2) {
    float mediaN, mediaP;
    mediaN = (*nota1 + *nota2) / 2;
    mediaP = ((*nota1 + *nota2 * 2) / 3);

    *nota1 = mediaN;
    *nota2 = mediaP;
}

int main(void) {
    float nota1, nota2;

    nota1 = recebeNota();
    nota2 = recebeNota();

    calcMedia(&nota1, &nota2);

    printf("\nMEDIA SIMPLES: %.2f \nMEDIA PONDERADA: %.2f\n", nota1, nota2);

    return 0;
}
