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
    if(*circulo == NULL) {
        printf("Nao foi possivel alocar memoria!\n");
        return;
    }

    strcpy((*circulo)->pessoa.nome, nome);
    (*circulo)->pessoa.posicao = 1;
    (*circulo)->ant = *circulo;
    (*circulo)->prox = *circulo;

}

void inserirInicio(No **circulo, char *nome) {
    if(*circulo == NULL) {
        iniciarLista(circulo, nome);
        printf("Adicionando a lista!\n\n");
        return;
    }

    Novo novo;
    novo = (No *)malloc(sizeof(No));
    if(novo == NULL) {
        printf("Nao foi possivel alocar memoria!\n");
        return;
    }

    strcpy(novo->pessoa.nome, nome);
    novo->pessoa.posicao = 0;

    (*circulo)->ant->prox = novo;
    novo->prox = *circulo;
    novo->ant = (*circulo)->ant;
    (*circulo)->ant = novo;

    *circulo = novo;

    Novo aux = *circulo;

    do {
        aux->pessoa.posicao++;
        aux = aux->prox;
    } while(aux != *circulo);
    
    printf("Adicionando a lista!\n\n");
}

void percursoFrente(No **circulo) {
    if(*circulo == NULL) {
        printf("Lista Vazia!\n");
        return;
    }

    Novo aux = *circulo;

    do {
        printf("[%dth] %s -> ", aux->pessoa.posicao, aux->pessoa.nome);
        aux = aux->prox;
    } while(aux != *circulo);

    printf("[%dth] %s\n\n", (*circulo)->pessoa.posicao, (*circulo)->pessoa.nome);
}

void percursoTras(No **circulo) {
    if(*circulo == NULL) {
        printf("Lista Vazia!\n");
        return;
    }

    Novo aux = *circulo;

    do {
        printf("[%dth] %s -> ", aux->pessoa.posicao, aux->pessoa.nome);
        aux = aux->ant;
    } while(aux != *circulo);

    printf("[%dth] %s\n\n", (*circulo)->pessoa.posicao, (*circulo)->pessoa.nome);
}

void removerElemento(No **circulo, int posicao) {
    if(*circulo == NULL) {
        printf("Lista Vazia!\n");
        return;
    }

    if((*circulo) -> ant == *circulo) {
        free(*circulo);
        *circulo = NULL;
        printf("Elemento removido com sucesso!\n\n");
        return;
    }

    Novo aux = *circulo;

    if(posicao == 1) {
        (*circulo)->ant->prox = (*circulo)->prox;
        (*circulo)->prox->ant = (*circulo)->ant;
        *circulo = (*circulo)->prox;
    }
    else {
        do {
            aux = aux->prox;
        } while(aux->pessoa.posicao != posicao);

        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
    }

    free(aux);

    aux = *circulo;

    do {
        aux = aux->prox;
        if(aux->pessoa.posicao > posicao) aux->pessoa.posicao--;
    } while(aux != *circulo);

    printf("Elemento removido com sucesso!\n\n");
}

void menu(No **circulo) {
    int op, posicao;
    char nome[50];

    while(1) {
        printf("[1] Inserir nó no início\n"); //Feito!
        printf("[2] Remover um nó a partir de um ponteiro\n");
        printf("[3] Percurso para frente\n"); // Feito!
        printf("[4] Percurso para trás\n"); // Feito
        printf("[5] Escolha do líder (percurso + remoção)\n");
        printf("[0] Finalizar programa\n"); // Feito
        printf(" OPCAO: ");
        scanf("%d", &op);
        getchar();
        printf("\n");

        switch(op) {
            case 1:
                printf("Digite o nome: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                inserirInicio(circulo, nome);

                break;
            
            case 2:
                printf("Digite a posicao atual do elemento que deseja remover: ");
                scanf("%d", &posicao);
                removerElemento(circulo, posicao);

                break;

            case 3:
                percursoFrente(circulo);
                break;
            
            case 4:
                percursoTras(circulo);
                break;

            case 0:
                return;
            
            default:
                printf("Opcao INVALIDA!\n");
                break;
        }
    }
}

int main(void) {
    No *circulo = NULL;

    menu(&circulo);

    return 0;
}