#ifndef VERBETES_H
#define VERBETES_H

typedef struct no {
    char verbete[20];
    char classificacao[20];
    char significado[100];
    struct no *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int quant;
} Descritor;

typedef struct pilha {
    char topo[20];
    struct pilha *prox;
} Pilha;

extern Pilha *Topo;
typedef No *Novo;

char* strupr(char *str);
char* strFormat(char *str);
void iniciarLista(Descritor **dadosDicionario);
void adicionarLista(Descritor **dadosDicionario, char *verbete, char *classificacao, char *significado);
void leituraArquivos(Descritor **dadosDicionario);
void encontreVerbete(Descritor **dadosDicionario, char *palavra);
void iniciarPilha();
void push(char *palavra);
void popComSignificado(Descritor **dadosDicionario);
void pilhaSignificados(Descritor **dadosDicionario, char *frase);
void lerFrases(Descritor **dadosDicionario);
void imprimeVerbetes(Descritor **desc);
void menu(Descritor **dadosDicionario);

#endif