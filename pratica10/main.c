#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int posicao;
} Pessoa;

typedef struct no{
    Pessoa pessoa; 
    struct no *prox;
    struct no *ant;
} No;

typedef No* Novo;

void iniciarLista(No **circulo, char *nome) {
    (*circulo) = (No *) malloc(sizeof(No));

    strcpy((*circulo)->pessoa.nome, nome);
    (*circulo)->pessoa.posicao = 1;
    (*circulo)->ant = *circulo;
    (*circulo)->prox = *circulo;

}

void inserirInicio(No **circulo, char *nome) {
    if(*circulo == NULL) {
        iniciarLista(circulo, nome);
        return;
    }

    Novo novo;
    novo = (No *)malloc(sizeof(No));

    strcpy(novo->pessoa.nome, nome);
    novo->pessoa.posicao = 0;
    
    Novo aux = *circulo;

    do {
        aux = aux->prox;
    } while(aux->prox != *circulo);

    aux->prox = novo;
    novo->ant = aux;
    novo->prox = *circulo;

    aux = *circulo;

    do {
        aux->pessoa.posicao++;
        aux = aux->prox;
    } while(aux != *circulo);
    
}

void menu(No **circulo) {
    int op;
    char nome[50];

    while(1) {
        printf("[1] Inserir nó no início\n");
        printf("[2] Remover um nó a partir de um ponteiro\n");
        printf("[3] Percurso para frente\n");
        printf("[4] Percurso para trás\n");
        printf("[5] Escolha do líder (percurso + remoção)\n");
        printf("[0] Finalizar programa\n");
        printf(" OPCAO: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                inserirInicio(circulo, nome);
                break;
        }
    }
}

int main(void) {
    No *circulo;

    main(&circulo);
    return 0;
}