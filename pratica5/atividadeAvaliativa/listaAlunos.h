#ifndef LISTA_ALUNOS_H
#define LISTA_ALUNOS_H

typedef struct aluno
{
    char nome[50];
    float notaPratica;
    float notaTeorica;
    struct aluno *prox;
} Aluno;

extern Aluno *cabeca;
extern Aluno *cabecaMedia;

Aluno *criarListaVazia();
Aluno *inserirAluno(char nome[], float notaPratica, float notaTeorica);
Aluno *encontrarNotas(char *nome);
Aluno *mediaSuperior();
Aluno *removerAluno(char *nome);
void menuAluno();


#endif