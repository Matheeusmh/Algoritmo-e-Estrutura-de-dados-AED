#include <stdio.h>

typedef struct no{
    int posicao;
    struct no *prox;
    struct no *ant;
} No;

void iniciarLista(No **circulo) {
    (*circulo) = (No *) malloc(sizeof(No));

    (*circulo)->posicao = 1;
    (*circulo)->ant = *circulo;
    (*circulo)->prox = *circulo;

}

void inserirInicio(No **circulo) {
    if(*circulo == NULL) {
        iniciarLista(circulo);
        return;
    }
}

void menu(No **circulo) {
    int op;

    while(1) {
        printf("[1] Inserir nó no início\n");
        printf("[2] Remover um nó a partir de um ponteiro\n");
        printf("[3] Percurso para frente\n");
        printf("[4] Percurso para trás\n");
        printf("[5] Escolha do líder (percurso + remoção)\n");
        printf("[0] Finalizar programa\n");
        printf(" OPCAO: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                inserirInicio(circulo);
                break;
        }
    }
}

int main(void) {
    No *circulo;

    main(&circulo);
    return 0;
}