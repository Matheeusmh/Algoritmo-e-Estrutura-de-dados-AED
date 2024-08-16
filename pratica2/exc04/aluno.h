#ifndef ALUNO_H
#define ALUNO_H

typedef struct
{
    char nome[50];
    float media;
} tipoAluno;

int dados(tipoAluno *alunos, float *nota1, float *nota2, float *notaParticip);
void calcMedia(int nota1, int nota2, int notaParticip, tipoAluno *alunos);
void fNota(tipoAluno *alunos);

#endif