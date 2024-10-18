#ifndef LISTA_DUPLA_ENCADEADA
#define LISTA_DUPLA_ENCADEADA

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

void iniciarLista(Descritor **lista, Elem **novo);
void inserirNaLista(Descritor **lista, int elemento);
void imprimirLista(Descritor **lista);
void insereInicioRepetidos(Descritor **lista1, Descritor **lista2);
void insereInicioNrepetidos(Descritor **lista1, Descritor **lista2);
void insereFinal(Descritor **lista1, Descritor **lista2);
void procurarElemento(Descritor **ll, int elemento);
void menu(Descritor **lista1, Descritor **lista2);

#endif