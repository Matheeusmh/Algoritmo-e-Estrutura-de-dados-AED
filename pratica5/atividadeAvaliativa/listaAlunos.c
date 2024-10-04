#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listaAlunos.h"

Aluno *cabecaMedia = NULL;
Aluno *cabeca = NULL;

Aluno *criarListaVazia()
{
    return NULL;
}

Aluno *inserirAluno(char nome[], float notaPratica, float notaTeorica)
{
    Aluno *novo;
    novo = (Aluno *)malloc(sizeof(Aluno));
    float media;

    if (novo == NULL)
    {
        printf("\nNAO foi possivel alocar memoria!!\n");
        return cabeca;
    }

    strcpy(novo->nome, nome);
    novo->notaPratica = notaPratica;
    novo->notaTeorica = notaTeorica;

    media = (notaPratica + notaTeorica) / 2;

    if (media > 70)
    {
        Aluno *mediaMaior;
        mediaMaior = (Aluno *)malloc(sizeof(Aluno));

        if (mediaMaior == NULL)
        {
            printf("\nNAO foi possivel alocar memoria!!\n");
            return cabeca;
        }
        else
        {
            mediaMaior->notaPratica = notaPratica;
            mediaMaior->notaTeorica = notaTeorica;
            strcpy(mediaMaior->nome, nome);
            mediaMaior->prox = cabecaMedia;
            cabecaMedia = mediaMaior;
        }
    }

    novo->prox = cabeca;
    cabeca = novo;

    return novo;
}

Aluno *encontrarNotas(char *nome)
{
    Aluno *ptr;
    ptr = cabeca;

    while (ptr != NULL)
    {
        if (strcmp(ptr->nome, nome) == 0)
        {
            printf("Nota pratica: %.2f\n", ptr->notaPratica);
            printf("Nota teorica: %.2f\n", ptr->notaTeorica);
            return ptr;
        }
        ptr = ptr->prox;
    }

    printf("Aluno nao encontrado!!\n");

    return ptr;
}

Aluno *mediaSuperior()
{
    Aluno *media;
    media = cabecaMedia;

    while (media != NULL)
    {
        printf("Nome: %s\n", media->nome);
        printf("Nota pratica: %.2f\n", media->notaPratica);
        printf("Nota teorica: %.2f\n\n", media->notaTeorica);

        media = media->prox;
    }

    return media;
}

Aluno *removerAluno(char *nome)
{
    Aluno *ptr, *ant, *ptrMedia, *antMedia;
    ptr = cabeca;
    ant = cabeca;
    ptrMedia = cabecaMedia;
    antMedia = cabecaMedia;

    while (ptrMedia != NULL)
    {
        if (strcmp(ptrMedia->nome, nome) == 0)
        {
            antMedia->prox = ptrMedia->prox;
            if (ptrMedia == cabecaMedia)
                cabecaMedia = cabecaMedia->prox;
            break;
        }

        antMedia = ptrMedia;
        ptrMedia = ptrMedia->prox;
    }

    while (ptr != NULL)
    {
        if (strcmp(ptr->nome, nome) == 0)
        {
            ant->prox = ptr->prox;
            if (ptr == cabeca)
                cabeca = cabeca->prox;
            printf("Aluno removido com sucesso!!\n");
            return ant;
        }

        ant = ptr;
        ptr = ptr->prox;
    }

    printf("Aluno nao encontrado!!\n");

    return ptr;
}

void menuAluno()
{
    char nome[50];
    int op = 10;
    float notaPratica, notaTeorica;

    while (op != 0)
    {
        printf("\n[1] Inserir um aluno\n");
        printf("[2] Encontrar notas de um aluno\n");
        printf("[3] Lista de alunos com media superior a 70\n");
        printf("[4] Remover um aluno\n");
        printf("[0] Sair do programa\n Escolha: ");
        scanf("%d", &op);
        getchar();

        switch (op)
        {
        case 1:
            printf("\nDigite o nome do aluno: ");
            scanf(" %[^\n]", nome);
            printf("Digite a nota pratica do aluno: ");
            scanf("%f", &notaPratica);
            printf("Digite a nota teorica do aluno: ");
            scanf("%f", &notaTeorica);
            inserirAluno(nome, notaPratica, notaTeorica);
            break;
        case 2:
            printf("\nDigite o nome do aluno que deseja encontrar: ");
            scanf(" %[^\n]", nome);
            encontrarNotas(nome);
            break;
        case 3:
            printf("\n");
            mediaSuperior();
            break;
        case 4:
            printf("\nDigite o aluno a ser removido: ");
            scanf("  %[^\n]", nome);
            removerAluno(nome);
            break;
        case 0:
            break;
        default:
            printf("OPCAO INVALIDA!!");
            break;
        }
    }
}