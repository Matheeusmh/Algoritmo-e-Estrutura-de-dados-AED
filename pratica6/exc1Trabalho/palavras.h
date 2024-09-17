#ifndef PALAVRAS_H
#define PALAVRAS_H

typedef struct no
{
    char palavra[18];
    struct no *prox;
} No;

extern No *lista;
extern No *listaPrimo;

void criarLista(No **lista, char palavra[]);
void insercao(No **lista, char palavra[]);
void removeLista(No **lista, char palavra[]);
void busca(No **lista, char palavra[]);
void imprimeLista(No *lista);
int countRec(No *lista);
int countNoRec(No *lista);
int isPrimo(char palavra[]);
void tamanhoPrimo(No *lista, No **listaPrimo);
void removeRepetidos(No **lista);

#endif