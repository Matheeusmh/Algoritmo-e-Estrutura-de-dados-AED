#ifndef LISTA_H
#define LISTA_H

typedef struct
{
    struct no *inicio;
    struct no *final;
    int quantElement;
} Descritor;

struct no
{
    int num;
    struct no *prox;
};

typedef struct no No;

void inicializarLista(Descritor *lista);
void adicionarNoInicio(Descritor *lista, int valor);
void adicionarNoFinal(Descritor *lista, int valor);
void removerDoInicio(Descritor *lista);
void removerDoFinal(Descritor *lista);
void removerElemento(Descritor *lista, int elemento);
void exibirLista(Descritor *lista);
void menu();

#endif