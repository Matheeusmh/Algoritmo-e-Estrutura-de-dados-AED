#ifndef SORTEIO_H
#define SORTEIO_H

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

void iniciarLista(No **circulo, char *nome);
void inserirInicio(No **circulo, char *nome);
void percursoFrente(No **circulo, int k);
void percursoTras(No **circulo, int k);
void removerElemento(No **circulo, int posicao);
void sortear(No **circulo, int k);
void menu(No **circulo);

#endif