#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    struct elemento *inicio;
    struct elemento *final;
    int quant;
} Descritor;

struct elemento
{
    int dados;
    struct elemento *ant;
    struct elemento *prox;
};

typedef struct elemento Elem;

typedef struct elemento *Lista;

void iniciarLista(Descritor **lista, Elem **novo)
{
    Descritor *novoDescritor;
    novoDescritor = (Descritor *)malloc(sizeof(Descritor));
    if (novoDescritor == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    novoDescritor->inicio = (*novo);
    novoDescritor->final = (*novo);
    novoDescritor->quant = 1;

    (*lista) = novoDescritor;
}

void inserirNaLista(Descritor **lista, int elemento)
{
    Lista novo;
    novo = (Lista)malloc(sizeof(Elem));

    if (novo == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    novo->dados = elemento;
    novo->ant = NULL;
    novo->prox = NULL;

    if ((*lista) == NULL)
    {
        iniciarLista(lista, &novo);
    }
    else
    {
        novo->ant = (*lista)->final;
        (*lista)->final->prox = novo;
        (*lista)->final = novo;
        (*lista)->quant++;
    }
}

void imprimirLista(Descritor **lista)
{
    if ((*lista) == NULL)
    {
        printf("Lista vazia!\n");
        return;
    }

    Lista aux = (*lista)->inicio;

    while (aux != NULL)
    {
        printf("%d ", aux->dados);
        aux = aux->prox;
    }
}

void insereInicioRepetidos(Descritor **lista1, Descritor **lista2)
{
    if ((*lista1) == NULL)
    {
        printf("Lista A Vazia!");
        return;
    }

    if ((*lista2) == NULL)
    {
        *lista2 = *lista1;
        *lista1 = NULL;
        return;
    }

    Lista aux2 = (*lista2)->inicio;
    Lista aux1 = (*lista1)->inicio;

    while (aux1 != NULL)
    {
        aux2->ant = aux1;
        aux1 = aux1->prox;
        (*lista1)->quant--;
        (*lista2)->quant++;
        aux2 = aux2->ant;
    }

    aux2->ant = NULL;

    aux2 = (*lista2)->inicio;

    while (aux2->ant != NULL)
    {
        aux2->ant->prox = aux2;
        aux2 = aux2->ant;
    }

    (*lista2)->inicio = aux2;

    *lista1 = NULL;

    printf("Listas fundidas com sucesso!\n");
}

void insereInicioNrepetidos(Descritor **lista1, Descritor **lista2)
{
    if ((*lista1) == NULL && (*lista1) == (*lista2))
    {
        printf("As duas listas estao vazias!");
        return;
    }

    if ((*lista1) == NULL)
        return;

    if ((*lista2) == NULL)
    {
        *lista2 = *lista1;
        *lista1 = NULL;
        return;
    }

    Lista aux1 = (*lista1)->inicio;

    while (aux1 != NULL)
    {
        Lista aux2 = (*lista2)->inicio;
        int found = 0;

        while (aux2 != NULL)
        {
            if (aux2->dados == aux1->dados)
            {
                found = 1;
                break;
            }
            aux2 = aux2->prox;
        }

        if (!found)
        {
            Lista novo = (Lista)malloc(sizeof(Elem));
            if (novo == NULL)
            {
                printf("Erro ao alocar memoria!\n");
                return;
            }

            novo->dados = aux1->dados;
            novo->prox = (*lista2)->inicio;
            novo->ant = NULL;

            if ((*lista2)->inicio != NULL)
                (*lista2)->inicio->ant = novo;

            (*lista2)->inicio = novo;

            if ((*lista2)->final == NULL)
                (*lista2)->final = novo;

            (*lista2)->quant++;
        }

        aux1 = aux1->prox;
    }

    *lista1 = NULL;

    printf("Listas fundidas com sucesso!\n");
}

void insereFinal(Descritor **lista1, Descritor **lista2) {
    if(*lista1 == NULL && *lista1 == *lista2) {
        printf("As listas estao vazias!!\n");
        return;
    }

    if(*lista1 == NULL) return;

    if(*lista2 == NULL) {
        *lista2 = *lista1;
        *lista1 = NULL;
        return;
    }

    Lista aux2 = (*lista2)->final;
    Lista aux1 = (*lista1)->inicio;

    while(aux1 != NULL) {
        aux2->prox = aux1;
        aux1->ant = aux2;
        aux1 = aux1->prox;
        (*lista1)->quant--;
        (*lista2)->quant++;
        aux2 = aux2->prox;
    }

    aux2->prox = NULL;

    (*lista2)->final = aux2;

    *lista1 = NULL;

    printf("Listas fundidas com sucesso!\n");
}

void removerElemento (Descritor **ll, int elemento) {
    if(*ll == NULL) {
        printf("Lista Vazia!");
        return;
    }
    else {
        Lista aux = (*ll)->inicio;

        if((*ll)->inicio->dados == elemento) {
            (*ll)->quant--;

            if((*ll)->inicio == (*ll)->final) {
                free(*ll);
                *ll = NULL;
                return;
            }

            (*ll)->inicio = (*ll)->inicio->prox;
            (*ll)->inicio->ant = NULL;
            free(aux);
        }
        else if((*ll)->final->dados == elemento) {
            aux = (*ll)->final;
            (*ll)->final = (*ll)->final->ant;
            (*ll)->final->prox = NULL;
            (*ll)->quant--;
            free(aux);
        }
        else {
            while(aux->prox->dados != elemento) {
                aux = aux->prox;
            }

            if(aux->prox == NULL) {
                printf("Elemento NAO encontrado na lista!\n");
                return;
            }

            Lista temp = aux->prox;

            aux->prox = temp->prox;
            temp->prox->ant = aux;
            free(temp);
        }
    }
}

void menu(Descritor **lista1, Descritor **lista2)
{
    int op, elemento, tamanho;

    while (1)
    {
        printf("[1] Adicionar elemento a lista A\n");
        printf("[2] Adicionar elementos a lista B\n");
        printf("[3] Exibir listas\n");
        printf("[4] Juntar listas adicionando no INICIO (COM repeticao)\n");
        printf("[5] Juntar listas adicionando no INICIO (SEM repeticao)\n");
        printf("[6] Juntar listas adicionando no FINAL\n");
        printf("[7] Remover elemento\n");
        printf("[0] Encerrar programa\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Digite a quantidade de elementos que deseja adicionar: ");
            scanf("%d", &tamanho);
            printf("Digite os elementos: ");
            for (int i = 0; i < tamanho; i++)
            {
                scanf("%d", &elemento);
                inserirNaLista(lista1, elemento);
            }

            break;
        case 2:
            printf("Digite a quantidade de elementos que deseja adicionar: ");
            scanf("%d", &tamanho);
            printf("Digite os elementos: ");
            for (int i = 0; i < tamanho; i++)
            {
                scanf("%d", &elemento);
                inserirNaLista(lista2, elemento);
            }

            break;
        case 3:
            printf("\nLista A:\n");
            imprimirLista(lista1);

            printf("\nLista B:\n");
            imprimirLista(lista2);
            printf("\n");

            break;
        case 4:
            insereInicioRepetidos(lista1, lista2);
            break;
        case 5:
            insereInicioNrepetidos(lista1, lista2);
            break;
        case 6:
            insereFinal(lista1, lista2);
            break;
        case 7:
            printf("Listas...\n[1] Lista A\n[2] Lista B\n OPCAO: ");
            scanf("%d", &op);

            printf("Digite o elemento que deseja remover: ");
            scanf("%d", &elemento);

            if(op == 1) {
                removerElemento(lista1, elemento);
            }
            else if(op == 2) {
                removerElemento(lista2, elemento);
            }
            else {
                printf("OPCAO INVALIDA!\n");
            }
            
            break;
        case 0:
            return;
        default:
            break;
        }
    }
}

int main(void)
{
    Descritor *lista1 = NULL;
    Descritor *lista2 = NULL;

    menu(&lista1, &lista2);

    return 0;
}