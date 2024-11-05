#ifndef FILA_H
#define FILA_H

typedef struct{
    char titulo[20];
    char autor[35];
    char linguagem[10];
    int ano;
    struct fila *prox;
} registroSoftwares;

typedef struct fila {
    registroSoftwares dados;
    struct fila *prox;
} Fila;

typedef Fila *Nova;

void iniciarFila(Fila **softwares); 
void adicionarSoftware(Fila **softwares, char *titulo, char *autor, char *linguagem, int ano); 
void removerElemento(Fila **fila); 
void imprimirSoftwares(Fila **fila); 

#endif