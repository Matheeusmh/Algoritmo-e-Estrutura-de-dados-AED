#include<stdio.h>
#include<stdlib.h>

const int INF = 0x3f3f3f3f;

typedef struct pilha{
    double topo;
    struct pilha *prox;
} Pilha;

Pilha *Topo = NULL;

void push(double x) {
    Pilha *novo;
    novo = (Pilha *)malloc(sizeof(Pilha));
    if(novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    novo->prox = Topo;
    novo->topo = x;
    Topo = novo;
}

double pop() {
    if(Topo == NULL) {
        printf("Pilha Vazia!\n");
        return 0;
    }

    Pilha *aux = Topo;
    double x;

    x = Topo->topo;
    Topo = Topo->prox;

    free(aux);

    return x;
}

int main (void) {
    int n;
    double media = 0, maior = -INF, menor = INF;

    printf("Digite quantos numeros deseja armazenar: ");
    scanf("%d", &n);

    printf("Digite os numeros: ");
    for(int i = 0; i < n; i++) {
        double x;

        scanf("%lf", &x);

        push(x);
    }

    while(Topo != NULL) {
        double x = pop();

        if(x > maior) maior = x;
        if(x < menor) menor = x;

        media += x;
    }

    media /= n;

    printf("Maior: %lf\nMenor: %lf\nMedia: %.2lf\n", maior, menor, media);


    return 0;
}
