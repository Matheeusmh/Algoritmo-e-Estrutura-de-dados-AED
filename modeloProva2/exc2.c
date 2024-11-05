typedef struct no{
    char nome[25];
    char atuacao[25];
    double valorAtual;
    double valorAnterior;
    struct no *prox;
    struct no *ant;
} No;

void alta(No **ll){
    if(*ll == NULL) {
        printf("Vazio!\n");
        return;
    }

    No *aux = *ll;

    do {
        if(aux->valorAnterior < aux->valorAtual) {
            printf("A empresa %s esta em alta por %.2lf porcento!\n", aux->nome, ((aux->valorAtual / aux->valorAnterior) - 1) * 100);
        }

        aux = aux->prox;
    } while(aux != *ll);
}

void removeMenor(No **ll) {
    if(*ll == NULL) {
        printf("Vazio!");
        return;
    }

    if((*ll)->prox == (*ll)) return;

    No *aux = *ll;
    No *menor = *ll;
    double menorValor = aux->valorAtual;

    do {
        if(aux->valorAtual < menorValor) {
            menor = aux;
        }

        aux = aux->prox;
    } while(aux != *ll);

    if(menor == *ll) {
        (*ll)->ant->prox = (*ll)->prox;
        (*ll)->prox->ant = (*ll)->ant;
        *ll = (*ll)->prox;
        free(menor);
        return;
    }

    menor->ant->prox = menor->prox;
    menor->prox->ant = menor->ant;

    free(menor);
}

void percursoInfinito(No **ll) {
    No *aux = *ll;

    while(1) {
        if(aux->valorAtual < aux->valorAnterior) {
            printf("Acao da %s em baixa!\n", aux->nome);
        }

        aux = aux->prox;
    }
}
