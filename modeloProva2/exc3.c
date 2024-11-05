int ehCircular(struct No *inicio) {
    if(inicio == NULL) {
        printf("Lista Vazia!\n");
        return 0;
    }
    struct No *aux = inicio;

    do {
        aux = aux->prox;

        if(aux == inicio) return 1;
    } while(aux != NULL);

    return 0;
}