#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char verbete[20];
    char classificacao[20];
    char significado[20];
    struct no *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int quant;
} Descritor;

typedef No *Novo;

void iniciarLista(Descritor **dadosDicionario) {
    *dadosDicionario = (Descritor *)malloc(sizeof(Descritor));
    if(*dadosDicionario == NULL) {
        printf("Nao foi possicel alocar memoria!\n");
        return;
    }
    (*dadosDicionario)->inicio = NULL;
    (*dadosDicionario)->fim = NULL;
    (*dadosDicionario)->quant = 0;
}

void adicionarLista(Descritor **dadosDicionario, char *verbete, char *classificacao, char *significado) {
    if(*dadosDicionario == NULL) {
        iniciarLista(dadosDicionario);
    }

    Novo novo;
    novo = (No *)malloc(sizeof(No));
    if(novo == NULL) {
        printf("Nao foi possivel alocar memoria!\n");
        return;
    }

    strcpy(novo->verbete, verbete);
    strcpy(novo->classificacao, classificacao);
    strcpy(novo->significado, significado);
    novo->prox = NULL;

    if((*dadosDicionario)->fim == (*dadosDicionario)->inicio && (*dadosDicionario)->inicio == NULL) {
        (*dadosDicionario)->inicio = novo;
        (*dadosDicionario)->fim = novo;

    }
    else {
        if(strcmp(novo->verbete, (*dadosDicionario)->inicio->verbete) < 0) {
            novo->prox = (*dadosDicionario)->inicio;
            (*dadosDicionario)->inicio = novo;
        }
        else if(strcmp(novo->verbete, (*dadosDicionario)->fim) > 0) {
            (*dadosDicionario)->fim->prox = novo;
            (*dadosDicionario)->fim = novo;
        }
        else {
            Novo aux = (*dadosDicionario)->inicio;

            while(strcmp(novo->verbete, aux->verbete) >= 0) {
                if(strcmp(novo->verbete, aux->prox->verbete) == 0) {
                    printf("O verbete ja esta no dicionario!");
                    return;
                }

                aux = aux->prox;
            }
        }

    }

    (*dadosDicionario)->quant++;
}

void leituraArquivos(Descritor **dadosDicionario) {
    FILE *arquivo;
    char verbete[20], classificacao[20], significado[20];
    
    arquivo = fopen("path/to/your/file.txt", "r");
    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo!");
        return;
    }
    
    while(fscanf(arquivo, "%19s", verbete) == 1) {
        fscanf(arquivo, "%19s", classificacao);
        fscanf(arquivo, " %99[^\n]", significado);
        adicionarLista(dadosDicionario, verbete, classificacao, significado);
        fscanf(arquivo, "\n"); 
    }

    fclose(arquivo);
}

void imprime(Descritor **ll) {
Novo aux = (*ll)->inicio;

    while(aux != NULL) {   
        printf("%s\n", aux->verbete);
        printf("%s\n", aux->classificacao);
        printf("%s\n", aux->significado);
        aux = aux->prox;
    }
}


int main()
{
    Descritor *dadosDicionario = NULL;

    leituraArquivos(&dadosDicionario);

    imprime(&dadosDicionario);

    return 0;
}