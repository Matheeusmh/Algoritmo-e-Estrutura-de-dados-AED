#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H
struct no {
    int capacidadeMax, quantCombustivel;
    struct no *prox;
};

typedef struct no No;
typedef struct{
    No *head;
    No *tail;
} Descritor;

void iniciarLista(No **ll, int capacidadeMax,int quantInicial, Descritor **info);
void adicionarElemento(int capacidadeMax, int quantInicial, No **ll, Descritor **info);
void abastecerNaves(Descritor **info, int unidCombustivel);
void removeNave(No **ll, Descritor **info, int *count);
void imprimeCiclo(Descritor **info, int *count);
void menu(No **ll, Descritor *info);


#endif