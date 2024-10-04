struct no {
    int capacidadeMax, quantCombustivel;
    struct no *prox;
};

typedef struct no No;
typedef struct{
    No *head;
    No *tail;
} Descritor;

