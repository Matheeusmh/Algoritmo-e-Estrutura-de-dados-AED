#include <stdio.h>
#include "aluno.h"

const int quant = 3;

int main(void)
{
    float nota1, nota2, notaParticip;
    tipoAluno alunos[20];

    for (int i = 0; i < quant; i++)
    {
        dados(alunos + i, &nota1, &nota2, &notaParticip);
        calcMedia(nota1, nota2, notaParticip, alunos + i);
        fNota(alunos + i);
    }

    return 0;
}