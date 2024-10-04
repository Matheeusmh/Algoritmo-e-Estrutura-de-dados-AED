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
    if((*info)->head == NULL) {
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
    if((*info)->head == NULL) {
        return;
    }

    if((*info)->head == (*info)->head->prox) {
        (*info)->head->quantCombustivel += unidCombustivel;
        return;
    }

    No *aux = (*info)->head;

    do {
        aux->quantCombustivel += unidCombustivel;
        aux = aux->prox; 
    } while(aux != (*info)->head);
}

void removeNave(No **ll, Descritor **info, int *count) {
    if ((*info)->head == NULL) {
        return;
    }

    No *aux = (*info)->head;
    No *ant = (*info)->head;

    do {
        if (aux->capacidadeMax == aux->quantCombustivel) {
            while(ant->prox != aux) ant = ant->prox;
            if (aux == (*info)->head && aux == (*info)->tail) {
                free(aux);
                (*info)->head = NULL;
                (*info)->tail = NULL;
                *ll = NULL;
                return;
            } else if (aux == (*info)->head) {
                (*info)->tail->prox = aux->prox;
                (*info)->head = aux->prox;
                free(aux);
                aux = (*info)->head;
                (*count)--;
            } else if (aux == (*info)->tail) {
                ant->prox = aux->prox;
                (*info)->tail = ant;
                free(aux);
                return;
            } else {
                ant->prox = aux->prox;
                free(aux);
                aux = (*info)->head;
                (*count)--;
            }
        } 
        else {
            aux = aux->prox;
        }
    } while ((*count) != 0);
}

void imprimeCiclo(Descritor **info, int *count) {
    printf("\n     __INFORMACOES DO CICLO__");
    if((*info)->head == NULL) {
        printf("\nNENHUMA NAVE NO CICLO!!\n\n");
        return;
    }

    No *aux = (*info)->head;


    do {
        if(aux->quantCombustivel > aux->capacidadeMax) aux->quantCombustivel = aux->capacidadeMax;
        printf("\nCapacidade maxima: %d\n", aux->capacidadeMax);
        printf("Quantidade atual de combustivel: %d\n", aux->quantCombustivel);
        if(aux->capacidadeMax == aux->quantCombustivel) {
            (*count)++;
            printf("NAVE CHEIA! REMOVENDO NAVE DOS PROXIMOS CICLOS...\n\n");
        }
        aux = aux->prox;
    }while(aux != (*info)->head);

    printf("\n\n");
}

void menu(No **ll, Descritor *info) {
    while(1) {
        int op = 0, capacidadeMax = 0, quantInic = 0, unidCombustivel = 0, count = 0;
        printf("\t__CICLO DE NAVES__\n");
        printf("[1] Adicionar uma nave ao ciclo\n");
        printf("[2] Nao adicionar uma nave nesse ciclo\n");
        printf("[0] Encerrar programa\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &op);

        printf("\n");

        switch(op) {
            case 1:
                printf("\t\t__NOVA NAVE__\n");
                printf("Digite a capacidade maxima de combustivel da nave: ");
                scanf("%d", &capacidadeMax);
                printf("Digite a quantidade inicial de combustivel: ");
                scanf("%d", &quantInic);
                printf("\n\nDigite a quantidade de combustivel a ser inserido nesse ciclo: ");
                scanf("%d", &unidCombustivel);

                adicionarElemento(capacidadeMax, quantInic, ll, &info);  
                abastecerNaves(&info, unidCombustivel);

                imprimeCiclo(&info, &count);
                break;
            case 2:        
                if(info->head == NULL) {
                    printf("\nNENHUMA NAVE NO CICLO!!\n\n");
                    break;
                }
                printf("\nDigite a quantidade de combustivel a ser inserido nesse ciclo: ");
                scanf("%d", &unidCombustivel);

                abastecerNaves(&info, unidCombustivel);

                imprimeCiclo(&info, &count);
                break;
            case 0:
                return;
            default:
                printf("Opcao invalida!\n\n");
                break;      
        }

        removeNave(ll, &info, &count);
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
