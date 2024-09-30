#include<stdio.h>
#include<stdlib.h>

struct no {
    int capacidadeMax, quantCombustivel;
    struct no *prox;
};

typedef struct no No;

No *lista = NULL;

No *iniciarLista(No *ll, int capacidadeMax,int quantInicial) {
    ll->capacidadeMax = capacidadeMax;
    ll->quantCombustivel = quantInicial;
    ll->prox = ll;
}

void adicionarElemento(double capacidadeMax, double quantInicial, No *ll) {
    if(ll == NULL) {
        iniciarLista(ll, capacidadeMax, quantInicial);
    }

    No *novo = (No *)malloc(sizeof(No));

    if(novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    novo->capacidadeMax = capacidadeMax;
    novo->quantCombustivel = quantInicial;

    if(ll == NULL) {
        ll = novo; 
        novo->prox = ll;

        return;
    }

    No *aux = ll->prox;

    while(aux->prox != ll) {
        aux = aux->prox;
    }

    aux->prox = novo;
    novo->prox = ll;
}

void imprimeCiclo(No *ll) {
    No *aux = ll->prox;

    while(aux != ll) {
        printf("Capacidade maxima: %d\n", aux->capacidadeMax);
        printf("Quantidade de combustivel: %d\n", aux->quantCombustivel);
        if(aux->capacidadeMax == aux->quantCombustivel) {
            printf("NAVE CHEIA!\n\n");
        }
    }
}

void menu(void) {
    while(1) {
        int op, capacidadeMax, quantInic;
        printf("[1] Adicionar no inicio\n");
        printf("[0] Nao adicionar\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &op);

        switch(op) {
            case 1:
                printf("Digite a capacidade maxima de combustivel da nave: ");
                scanf("%d", &capacidadeMax);
                printf("Digite a quantidade inicial de combustivel: ");
                scanf("%d", &quantInic);
                adicionarElemento(capacidadeMax, quantInic, lista);     
                break;
            case 0: 
                return;
            default:
                printf("Opcao invalida!\n");
                break;      
        }
    }
} 

int main(void) {

    menu();

    return 0;
}