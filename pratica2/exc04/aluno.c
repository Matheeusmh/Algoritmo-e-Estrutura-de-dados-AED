#include "aluno.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void dados(tipoAluno *alunos, float *nota1, float *nota2, float *notaParticip)
{
    printf("Digite o nome do aluno: ");
    fgets(alunos->nome, 50, stdin);
    for (int i = 0; i < 50; i++)
    {
        if (alunos->nome[i] == '\n')
        {
            alunos->nome[i] = '\0';
        }
    }
    printf("Digite a nota da primeira prova: ");
    scanf("%f", nota1);
    printf("Digite a nota da segunda prova: ");
    scanf("%f", nota2);
    printf("Digite os pontos de participacao: ");
    scanf("%f", notaParticip);
}

void calcMedia(int nota1, int nota2, int notaParticip, tipoAluno *alunos)
{
    float media = (nota1 + nota2) / 3;
    media += notaParticip;

    if (media > 10)
    {
        media = 10;
    }

    alunos->media = media;
}

void fNota(tipoAluno *alunos)
{
    printf("Nota final: %.2f", alunos->media);
}
