void sum(Pilha **pilha) {
    float a, b;

    if(pilha == NULL) {
        printf("Pilha insuficiente!\n");
        return;
    }

    a = pop(pilha);

    if(pilha == NULL) {
        printf("Pilha insuficiente!\n");
        return;
    }
    
    b = pop(pilha);

    push(pilha, a + b);
}