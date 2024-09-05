#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct aluno{
    char nome[50];
    float notaPratica;
    float notaTeorica;
    struct aluno *prox;
} Aluno;

Aluno *cabeca, *cabecaMedia;

Aluno* criarListaVazia() {
    return NULL;
}

Aluno* inserirAluno(char nome[], float notaPratica, float notaTeorica) { 
    Aluno* novo;
    novo = (Aluno *)malloc(sizeof(Aluno));
    float = media;

    if(novo == NULL) {
        printf("\nNAO foi possivel alocar memoria!!\n");
        return cabeca;
    }

    strcpy(novo->nome, nome);
    novo->notaPratica = notaPratica;
    novo->notaTeorica = notaTeorica;

    if(nota)
    novo->prox = cabeca;
    cabeca = novo;

    return novo;
}

Aluno* encontrarNotas(char *nome) {
    Aluno *ptr;
    ptr = cabeca;

    while(ptr != NULL) {
        if(strcmp(ptr->nome, nome) == 0) {
            printf("Nota pratica: %.2f\n", ptr->notaPratica);
            printf("Nota teorica: %.2f\n", ptr->notaTeorica);
            return ptr;
        }
        ptr = ptr->prox;
    }

    printf("Aluno nao encontrado!!\n");
}

Aluno* mediaSuperior() {
    float media;
    Aluno *ptr;
    ptr = cabeca;


    while(ptr != NULL) {
        media = (ptr->notaPratica + ptr->notaTeorica) / 2;
        if(media > 70) {
            printf("Nome: %s\n", ptr->nome);
            printf("Nota pratica: %.2f\n", ptr->notaPratica);
            printf("Nota teorica: %.2f\n", ptr->notaTeorica);
        }

        ptr = ptr->prox;
    }

    return ptr;
}

Aluno* removerAluno(char *nome) {
    Aluno *ptr, *ant;
    ptr = cabeca;
    ant = cabeca;

    while(ptr != NULL) {
        if(strcmp(ptr->nome, nome) == 0) {
            ant->prox = ptr->prox;
            if(ptr == cabeca) cabeca = cabeca->prox;
            printf("Aluno removido com sucesso!!\n");
            return ant;
        }
        ant = ptr;
        ptr = ptr->prox;
    }

    return ptr;
}

void menuAluno() {
    char nome[50];
    int op = 10;
    float notaPratica, notaTeorica;

    while(op != 0) {
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
            mediaSuperior();
            break;
        case 4:
            printf("Digite o aluno a ser removido: ");
            scanf("  %[^\n]", nome);
            removerAluno(nome);
        default:
            break;
        }

    }
}


int main(void) {
    cabeca = criarListaVazia();

    menuAluno();

    return 0;
}