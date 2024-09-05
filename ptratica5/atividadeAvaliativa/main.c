#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct aluno{
    char nome[50];
    float notaPratica;
    float notaTeorica;
    struct aluno *prox;
} Aluno;

Aluno* criarListaVazia() {
    return NULL;
}



Aluno* inserirAluno(char nome[], float notaPratica, float notaTeorica, Aluno *lAluno) { 
    Aluno* novo;
    novo = (Aluno *)malloc(sizeof(Aluno));

    if(novo == NULL) {
        printf("\nNAO foi possivel alocar memoria!!\n");
        return lAluno;
    }

    strcpy(novo->nome, nome);
    novo->notaPratica = notaPratica;
    novo->notaTeorica = notaTeorica;
    novo->prox = lAluno;

    return novo;
}

void encontrarNotas(Aluno *lAluno, char *nome) {
    Aluno *ptr;
    ptr = lAluno;

    while(ptr != NULL) {
        if(strcmp(ptr->nome, nome) == 0) {
            printf("Nota pratica: %.2f\n", ptr->notaPratica);
            printf("Nota teorica: %.2f\n", ptr->notaTeorica);
            break;
        }
        ptr = ptr->prox;
    }

    printf("Aluno nao encontrado!!\n");
}

void menuAluno( Aluno *lAluno) {
    char nome[50];
    int op = 10;
    float notaPratica, notaTeorica;


    while(op != 0) {
        printf("[1] Inserir um aluno\n");
        printf("[2] Encontrar notas de um aluno\n");
        printf("[3] Lista de alunos com media superior a 70\n");
        printf("[4] Remover um aluno\n");
        printf("[0] Sair do programa\n Escolha: ");
        scanf("%d", &op);
        getchar(); 

        switch (op)
        {
        case 1:
            printf("Digite o nome do aluno: ");
            getchar();
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = '\0';
            printf("Digite a nota pratica do aluno: ");
            scanf("%f", &notaPratica);
            printf("Digite a nota teorica do aluno: ");
            scanf("%f", &notaTeorica);
            lAluno = inserirAluno(nome, notaPratica, notaTeorica, lAluno);
            break;
        case 2:
            printf("Digite o nome do aluno que deseja encontrar: ");
            fgets(nome, 50, stdin);
            getchar();
            nome[strcspn(nome, "\n")] = '\0';
            encontrarNotas(lAluno, nome);
            break;
        default:
            break;
        }

    }
}


int main(void) {
    Aluno *lAluno;
    lAluno = criarListaVazia();

    menuAluno(lAluno);

    return 0;
}