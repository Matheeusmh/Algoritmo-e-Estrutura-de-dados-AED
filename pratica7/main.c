#include<stdio.h>
#include<stdlib.h>

typedef struct {
    struct no *inicio;
    struct no *final;
    int quantElement;
} Descritor;

struct no {
    int num;
    struct no *prox;
};

typedef struct no No;

void inicializarLista(Descritor *lista) {
    lista->quantElement = 0;
    lista->inicio = NULL;
    lista->final = NULL;
}

void adicionarNoInicio(Descritor *lista, int valor) {
    No *novo;
    novo = (No *)malloc(sizeof(No));

    if(novo == NULL) {
        printf("Nao foi possivel alocar memoria!");
        return;
    }

    novo->num = valor;
    novo->prox = lista->inicio;

    if(lista->inicio == NULL) {
        lista->final = novo;
        lista->inicio = novo;
        lista->quantElement++;
        return;
    }

    lista->inicio = novo;
    lista->quantElement++;
}

void adicionarNoFinal(Descritor *lista, int valor) {
    No *novo;
    novo = (No *)malloc(sizeof(No));

    if(novo == NULL) {
        printf("Nao foi possivel alocar memoria!");
        return;
    }

    novo->num = valor;
    novo->prox = NULL;

    if(lista->final == NULL) {
        lista->final = novo;
        lista->inicio = novo;
        lista->quantElement++;
        return;
    }

    No *fim = lista->final;
    fim->prox = novo;
    
    lista->final = novo;
    lista->quantElement++;


}

void removerDoInicio(Descritor *lista) {
    if(lista->quantElement == 0) {
        printf("Lista vazia!");
        return;
    }

    No *novo = lista->inicio;

    lista->inicio = novo->prox;
    lista->quantElement--;

    if(lista->quantElement == 0) {
        lista->inicio = NULL;
        lista->final = NULL;
    }

    printf("Elemento removido do inicio!");

    free(novo);
}

void removerDoFinal(Descritor *lista) {
    if(lista->quantElement == 0) {
        printf("Lista vazia!");
        return;
    }
    No *aux = lista->inicio;
    No *anterior = NULL;

    while(aux->prox != NULL) {
        anterior = aux;
        aux = aux->prox;
    }

    if (anterior == NULL) {
        lista->inicio = NULL;
        lista->final = NULL;
    } else {
        anterior->prox = NULL;
        lista->final = anterior;
    }

    lista->quantElement--;

    if(lista->quantElement == 0) {
        lista->inicio = NULL;
        lista->final = NULL;
    }

    printf("Elemento removido do final!");

    free(aux);
}

void removerElemento(Descritor *lista, int elemento) {
    if(lista->quantElement == 0) {
        printf("Lista vazia!");
        return;
    }

    No *aux = lista->inicio;
    No *anterior = NULL;

    while(aux != NULL) {
        if(aux->num == elemento) {
            if(aux == lista->inicio) {
                lista->inicio = aux->prox;
            } else {
                anterior->prox = aux->prox;
            }

            if(aux == lista->final) {
                lista->final = anterior;
            }

            free(aux);
            lista->quantElement--;
            
            if(lista->quantElement == 0) {
                lista->inicio = NULL;
                lista->final = NULL;
            }

            printf("Elemento removido!");
            return;
        }

        anterior = aux;
        aux = aux->prox;
    }

    printf("Elemento nao encontrado!");
}

void exibirLista(Descritor *lista) {
    No *aux = lista->inicio;

    if(lista->quantElement == 0) {
        printf("Lista vazia!");
        return;
    }

    while(aux != NULL) {
        printf("%d ", aux->num);
        aux = aux->prox;
    }
}

void menu() {
    int op = 1;
    Descritor* info = (Descritor*)malloc(sizeof(Descritor));
    if (info == NULL) {
        printf("Nao foi possivel alocar memoria!\n");
        return;
    }

    inicializarLista(info);

    while(op != 0) {
        int valor;

        printf("[1] Inserir no inicio\n");
        printf("[2] Inserir no final\n");
        printf("[3] Remover do inicio\n");
        printf("[4] Remover do final\n");
        printf("[5] Remover elemento\n");
        printf("[6] Imprimir lista\n");
        printf("[0] Sair\n");
        printf("Op: ");
        scanf("%d", &op);

        printf("\n");
        
        switch (op)
        {
        case 1:
            printf("Digite o numero que deseja adicionar ao inicio da lista: ");
            scanf("%d", &valor);
            adicionarNoInicio(info, valor);
            break;
        case 2:
            printf("Digite o numero que deseja adicionar no final da lista: ");
            scanf("%d", &valor);
            adicionarNoFinal(info, valor);
            break;
        case 3:
            removerDoInicio(info);
            break;
        case 4:
            removerDoFinal(info);
            break;
        case 5:
            printf("Digite o numero que deseja remover da lista: ");
            scanf("%d", &valor);
            removerElemento(info, valor);
            break;
        case 6:
            exibirLista(info);
            break;
        default:
            break;
        }
        printf("\n\n");
    }
}

int main(void) {    

    menu();

    return 0;
}