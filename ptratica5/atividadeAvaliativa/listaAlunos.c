#include "listaAlunos.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

Aluno* criarListaVazia() {
    return NULL;
}

Aluno* inserirAluno(char nome[], float notaPratica, float notaTeorica, Aluno *lAluno) { 
    Aluno* novo;

    novo = (Aluno *)malloc(sizeof(Aluno));

    if(novo == NULL) {
        printf("\nNAO foi possivel alocar memoria!!\n");
        return NULL;
    }

    strcpy(novo->nome, nome);
    novo->notaPratica = notaPratica;
    novo->notaTeorica = notaTeorica;
    novo->prox = lAluno;

    return novo;
}