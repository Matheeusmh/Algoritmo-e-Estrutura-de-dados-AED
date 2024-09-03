#ifndef LISTA_ALUNOS_H
#define LISTA_ALUNOS_H

typedef struct aluno{
    char nome[50];
    float notaPratica;
    float notaTeorica;
    struct aluno *prox;
} Aluno;

Aluno* inserirAluno(char nome[], float notaPratica, float notaTeorica, Aluno *lAluno);
Aluno* criarListaVazia();

#endif