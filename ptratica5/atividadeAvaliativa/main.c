#include<stdio.h>
#include "listaAlunos.h"

int main(void) {
    int flag = 1;
    char nome[50];
    float notaPratica, notaTeorica;
    Aluno *lAluno;
    lAluno = criarListaVazia();

    while(flag){
        printf("Digite o nome do aluno: ");
        fgets(nome, 50, stdin);
        if(nome[0] == '.') break;
        printf("Digite a nota pratica: ");
        scanf("%f", &notaPratica);
        printf("Digite a nota teorica: ");
        scanf("%f", &notaTeorica);
        printf("\n");
        lAluno = inserirAluno(nome, notaPratica, notaTeorica, lAluno);
    }

    return 0;
}