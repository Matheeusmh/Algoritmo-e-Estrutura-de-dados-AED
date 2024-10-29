#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

typedef struct no2{
    int valor;
    struct no *ant;
    struct no *prox;
} No2;

No *pilha = NULL;

typedef struct {
    No2 *inicio;
    No2 *final;
} Descritor;

No *iniciaPilha(int valor) {
    pilha = (No *)malloc(sizeof(No));
    if(pilha == NULL) {
        printf("ERROR!\n");
        return pilha;
    }

    pilha->valor = valor;
    pilha->prox = NULL;
    
    return pilha;
}

No *push_back(int valor) {
    if(pilha == NULL) {
        pilha = iniciaPilha(valor);
        return pilha;
    }

    No *aux;
    aux = (No *)malloc(sizeof(No));
    if(aux == NULL) {
        printf("ERROR!\n");
        return pilha;
    }

    aux->valor = valor;
    aux->prox = pilha;
    pilha = aux;

    return pilha;
}

void iniciarLista(Descritor **descritor, int valor) {
    No2 *lista;
    lista = (No2 *)malloc(sizeof(No2));
    if(lista == NULL) {
        printf("ERROR!\n");
        return;
    }

    lista->valor = valor;
    lista->prox = NULL;
    lista->ant = NULL;

    (*descritor)->inicio = lista;
    (*descritor)->final = lista;
}

int pop() {
    No *aux = pilha;
    int valor = pilha->valor;

    pilha = pilha->prox;
    free(aux);
    
    return valor;
}

void insereOrdenado(Descritor **descritor) {
    int valor = pop();

    iniciarLista(descritor, valor);

    while(pilha != NULL) {
        No2 *aux; 
        aux = (No2 *)malloc(sizeof(No2));
        if(aux == NULL) {
            printf("ERROR!\n");
            return;
        }
        
        aux->valor = valor;
        aux->prox = NULL;
        aux->ant = NULL;

        while(aux->valor >= (*descritor)->final->valor) {
            aux = aux->prox;
        }

        if(aux == (*descritor)->inicio) {
            aux->prox = (*descritor)->inicio;
            (*descritor)->inicio->ant = aux;
            (*descritor)->inicio = aux;
        }
        else if(aux == (*descritor)->final) {
            aux->ant2
            (*descritor)->final = aux->prox;
        }
        else {
            aux->ant->prox = aux2;
            aux->ant = aux2;
            aux2->ant = aux->ant;
            aux2->prox = aux;
        }

        pop();
    }
}

void imprimeLista(Descritor **descritor) {
    No2 *aux = (*descritor)->inicio;
    while(aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
}
int main(void) {
    Descritor *descritor;
    descritor = (Descritor *)malloc(sizeof(Descritor));
    if(descritor == NULL) {
        printf("ERROR!\n");
        return 0;
    }

    int valor, tamanho;

    printf("Digite quantos numeros deseja armazenar: ");
    scanf("%d", &tamanho);

    for(int i = 0; i < tamanho; i++) {
        scanf("%d", &valor);
        pilha = push_back(valor);
    }

    insereOrdenado(&descritor);

    imprimeLista(&descritor);

    return 0;
}
