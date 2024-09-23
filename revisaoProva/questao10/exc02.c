#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Produto {
    char nome[20], descricao[20], categoria[20];
    float preco; 
}; 
void X (struct Produto p[], int *n, struct Produto p1) {
    p[*n] = p1;
    (*n)++;
}

int main(void) {
    int n = 0;
    struct Produto p1, p[10];

    strcpy(p1.nome, "Nome");
    strcpy(p1.descricao, "Descricao");
    strcpy(p1.categoria, "Categoria");

    X(p, &n, p1);

    return 0;
}
