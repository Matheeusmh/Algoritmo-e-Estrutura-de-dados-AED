#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "verbetes.h"

Pilha *Topo;

char* my_strupr(char *str) {
    int len = strlen(str), i;

    for(i = 0; i < len; i++) {
        str[i] = toupper(str[i]);
    }

    return str;
}

char* strFormat(char *str) {
    int len = strlen(str), i;

    for(i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }

    str[0] = toupper(str[0]);

    return str;
} 

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
    Novo novo;
    novo = (No *)malloc(sizeof(No));
    if(novo == NULL) {
        printf("Nao foi possivel alocar memoria!\n");
        return;
    }

    strcpy(novo->verbete, my_strupr(verbete));
    strcpy(novo->classificacao, classificacao);
    strcpy(novo->significado, significado);
    novo->prox = NULL;

    if((*dadosDicionario)->inicio == NULL) {
        (*dadosDicionario)->inicio = novo;
        (*dadosDicionario)->fim = novo;
    }
    else {
        if(strcmp(novo->verbete, (*dadosDicionario)->inicio->verbete) < 0) {
            novo->prox = (*dadosDicionario)->inicio;
            (*dadosDicionario)->inicio = novo;
        }
        else if(strcmp(novo->verbete, (*dadosDicionario)->fim->verbete) > 0) {
            (*dadosDicionario)->fim->prox = novo;
            (*dadosDicionario)->fim = novo;
        }
        else {
            Novo aux = (*dadosDicionario)->inicio;
            Novo ant = NULL;

            while(strcmp(novo->verbete, aux->verbete) >= 0) {
                if(strcmp(novo->verbete, aux->verbete) == 0) {
                    printf("O verbete ja esta no dicionario!");
                    return;
                }
                ant = aux;
                aux = aux->prox;
            }

                ant->prox = novo;
                novo->prox = aux;
        }
    }

    (*dadosDicionario)->quant++;
}


void leituraArquivos(Descritor **dadosDicionario) {
    FILE *arquivo;
    char verbete[20], classificacao[20], significado[100];
    
    arquivo = fopen("verbetes.txt", "r");
    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo!");
        return;
    }
    
    while(fscanf(arquivo, "%19s %19s %99[^\n]", verbete, classificacao, significado) != EOF) {
        adicionarLista(dadosDicionario, verbete, classificacao, significado);
    }

    fclose(arquivo);
}

void encontreVerbete(Descritor **dadosDicionario, char *palavra) {
    if(*dadosDicionario == NULL) {
        printf("Nenhum verbete foi introduzido!\n");
        return;
    }

    Novo aux = (*dadosDicionario)->inicio;

    while(strcmp(aux->verbete, my_strupr(palavra)) != 0) {
        aux = aux->prox;
        if(aux == NULL) {
            printf("\nVerbete nao encontrado (%s)!\n\n", strFormat(palavra)); my_strupr(palavra);
            return;
        }
    }

    printf("\nVerbete: %s\n", strFormat(aux->verbete)); my_strupr(aux->verbete);
    printf("Classificacao: %s\n", aux->classificacao);
    printf("Significado: %s\n\n", aux->significado);
}

void iniciarPilha() {
    Topo = (Pilha *)malloc(sizeof(Pilha));
    if(Topo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    Topo->prox = NULL;
}

void push(char *palavra) {
    Pilha *novo;
    novo = (Pilha *)malloc(sizeof(Pilha));
    if(novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    strcpy(novo->topo, palavra);
    novo->prox = Topo;
    Topo = novo;
}

void popComSignificado(Descritor **dadosDicionario) {
        if(Topo == NULL) {
            printf("Erro. Pilha Vazia!\n");
            return;
        }
        
        Pilha *aux = Topo;
        
        encontreVerbete(dadosDicionario, aux->topo);

        Topo = Topo->prox;

        free(aux);
}

void pilhaSignificados(Descritor **dadosDicionario, char *frase) {
    char palavra[20];
    int aux = 0, i = 0;

    for(i = 0; frase[i] !=  '\0'; i++) {
        if(frase[i] == ' ') {
            if(aux > 2) {
                palavra[aux] = '\0';
                my_strupr(palavra);
                push(palavra);
            }

            aux = 0;
        }
        else {
            if(isalpha(frase[i])) {
                palavra[aux] = frase[i];
                aux++;
            }
            else {
                palavra[aux] = '\0';
                my_strupr(palavra);
                push(palavra);
                aux = 0; 
            }
        }
    }

    if(aux > 2) {
        palavra[aux] = '\0';
        push(palavra);
    }
}

void lerFrases(Descritor **dadosDicionario) {
    FILE *ponteiroArquivo;
    char frase[100];

    ponteiroArquivo = fopen("frases.txt", "r");
    if(ponteiroArquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo!\n");
        return;
    }

    while(fgets(frase, 99, ponteiroArquivo) != NULL) {
        frase[strcspn(frase, "\n")] = '\0';
        pilhaSignificados(dadosDicionario, frase);
        while(Topo != NULL) {
            popComSignificado(dadosDicionario);
        }
    }
}

void imprimeVerbetes(Descritor **desc) {
    if((*desc)->inicio == NULL) {
        printf("Lista Vazia!\n");
        return;
    }

    No *aux = (*desc)->inicio;

    while(aux != NULL) {
        printf("Verbete: %s\n", strFormat(aux->verbete)); my_strupr(aux->verbete);
        printf("Classificacao: %s\n", aux->classificacao);
        printf("Significado: %s\n\n", aux->significado);

        aux = aux->prox;
    }
}

void menu(Descritor **dadosDicionario) {
    while(1) {
        int op = 0;

        printf("Escolha uma opcao...\n");
        printf("[1] Encontrar um verbete\n");
        printf("[2] Letra c\n");
        printf("[3] Imprimir lista de verbetes\n");
        printf("[0] Encerrar programa\n");
        printf(" OPCAO: ");
        scanf("%d", &op);
        while (getchar() != '\n');

        switch(op) {
            case 1:
                char palavra[20];
                printf("Digite o verbete: ");
                fgets(palavra, 19, stdin);
                palavra[strcspn(palavra, "\n")] = '\0';
                
                encontreVerbete(dadosDicionario, palavra);
                
                break;
            case 2:
                lerFrases(dadosDicionario);

                break;
            case 3:
                printf("\n");
                imprimeVerbetes(dadosDicionario);

                break;
            case 0:
                return;
            default:
                printf("\nOPCAO INVALIDA!\n\n");
                break;
        }
    }
}
