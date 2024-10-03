#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct no {
    int capacidadeMax, quantCombustivel;
    struct no *prox;
};

typedef struct no No;
typedef struct{
    No *head;
    No *tail;
} Descritor;

void iniciarLista(No **ll, int capacidadeMax,int quantInicial, Descritor **info) {
    *ll = (No *)malloc(sizeof(No));
    if (*ll == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }
    (*ll)->capacidadeMax = capacidadeMax;
    (*ll)->quantCombustivel = quantInicial;
    (*ll)->prox = *ll;
    (*info)->head = *ll;
    (*info)->tail = *ll;
}

void adicionarElemento(int capacidadeMax, int quantInicial, No **ll, Descritor **info) {
    if(*ll == NULL) {
        iniciarLista(ll, capacidadeMax, quantInicial, info);
        return;
    }

    No *novo = (No *)malloc(sizeof(No));

    if(novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    novo->capacidadeMax = capacidadeMax;
    novo->quantCombustivel = quantInicial;
    novo->prox = (*info)->head;

    (*info)->tail->prox = novo;
    (*info)->tail = novo;
}

void abastecerNaves(Descritor **info, int unidCombustivel) {
    if((*info)->head == (*info)->head->prox) {
        (*info)->head->quantCombustivel += unidCombustivel;
        return;
    }

    No *aux = (*info)->head->prox;

    do {
        aux->quantCombustivel += unidCombustivel;
        aux = aux->prox; 
    } while(aux != (*info)->head);
}

void removeNave(No **nave, Descritor **info) {
    if((*info)->head == (*info)->tail) {
        free(*nave);
        (*info)->head = NULL;
        (*info)->tail = NULL;
        return;
    }
    
    No *aux = (*info)->head;

    while(aux->prox != *nave) aux = aux->prox;
    
    if(aux->prox == (*info)->tail) {
        free((*info)->tail);
        (*info)->tail->prox = (*info)->head;
        (*info)->tail = aux;
        return;
    }

    if(aux->prox == (*info)->head) {
        (*info)->tail->prox = (*info)->head->prox;
        (*info)->head = (*nave)->prox;
        free(nave);
        return;
    }

    aux->prox = (*nave)->prox;
    free(nave);    
}

void imprimeCiclo(Descritor **info) {
    if((*info)->head->prox == (*info)->head) {
        if((*info)->head == NULL) {
            printf("NENHUMA NAVE NO CICLO!!");
            return;
        }
        printf("\nCapacidade maxima: %d\n", (*info)->head->capacidadeMax);
        printf("Quantidade atual de combustivel: %d\n", (*info)->head->quantCombustivel);
        if((*info)->head->capacidadeMax == (*info)->head->quantCombustivel) {
            printf("NAVE CHEIA!\n\n");
        }
        return;
    }

    No *aux = (*info)->head;


    do {
        printf("\nCapacidade maxima: %d\n", aux->capacidadeMax);
        printf("Quantidade de combustivel: %d\n", aux->quantCombustivel);
        if(aux->capacidadeMax == aux->quantCombustivel) {
            printf("NAVE CHEIA! REMOVENDO NAVE DOS PROXIMOS CICLOS...\n\n");
            removeNave(&aux, info);
        }
        aux = aux->prox;
    }while(aux != (*info)->head);
}

void menu(No **ll, Descritor *info) {
    while(1) {
        int op = 0, capacidadeMax = 0, quantInic = 0, unidCombustivel = 0;
        printf("[1] Adicionar no inicio\n");
        printf("[2] Nao adicionar\n");
        printf("[0] Encerrar programa\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &op);

        printf("\n");

        switch(op) {
            case 1:
                printf("Digite a capacidade maxima de combustivel da nave: ");
                scanf("%d", &capacidadeMax);
                printf("Digite a quantidade inicial de combustivel: ");
                scanf("%d", &quantInic);
                printf("\n\nDigite a quantidade de combustivel a ser inserido nesse ciclo: ");
                scanf("%d", &unidCombustivel);

                adicionarElemento(capacidadeMax, quantInic, ll, &info);  
                abastecerNaves(&info, unidCombustivel);

                imprimeCiclo(&info);
                break;
            case 2: 
                printf("\n\nDigite a quantidade de combustivel a ser inserido nesse ciclo: ");
                scanf("%d", &unidCombustivel);

                abastecerNaves(&info, unidCombustivel);

                imprimeCiclo(&info);
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
    Descritor info;
    No *lista = NULL;
    info.head = NULL;
    info.tail = NULL;

    menu(&lista, &info);

    return 0;
}
