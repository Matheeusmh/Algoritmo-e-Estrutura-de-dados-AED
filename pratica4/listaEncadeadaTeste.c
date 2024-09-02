#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int valor;
    struct elemento *prox;
} defElemento;

defElemento *cabeca = NULL;

defElemento* criarLista(int v) {
    defElemento *ptr;
    ptr = (defElemento *)malloc(sizeof(defElemento));

    if(ptr == NULL) {
        printf("Falha ao alocar memoria!");
    }


    ptr->valor = v;
    ptr->prox = NULL;

    cabeca = ptr;

    return ptr;
}

defElemento* adicionarElemento(int v) {
    if(cabeca == NULL) {
        return criarLista(v);

    }
        defElemento *ptr;
        ptr = (defElemento *)malloc(sizeof(defElemento));

        if(ptr == NULL) {
            printf("Falha ao alocar a memoria!");
        }

        ptr->valor = v;
        ptr->prox = cabeca;
        cabeca = ptr;

        return ptr;
}

void imprimirElementos() {
    defElemento *ptrCabeca;
    ptrCabeca = cabeca;

    while(ptrCabeca != NULL) {
        printf("%d ", ptrCabeca->valor);
        ptrCabeca = ptrCabeca->prox;
    }
}

defElemento* find(int x) {
    defElemento *aux;
    aux = cabeca;

    while(aux != NULL) {
            if(aux->valor == x) {
                return aux;
            }
            aux = aux->prox;
    }
}

void eliminarElemento(int x) {
    defElemento *ptr, *aux;
    ptr = cabeca;
    aux = cabeca->prox;

    while(aux != NULL) {
        if(aux->valor == x) {
            if(aux->prox == NULL) ptr->prox = NULL;
            ptr->prox = aux->prox;
            break;
        }
        else {
            aux = aux->prox;
            ptr = ptr->prox;
        }
    }
}

int main()
{
    int x;

    printf("Adicionando os seguintes elementos a lista: 3 4 5 10\n");

    adicionarElemento(3);
    adicionarElemento(4);
    adicionarElemento(5);
    adicionarElemento(10);

    printf("Lista: ");
    imprimirElementos();

    printf("\n\nDigite um numero para ser procurar: ");
    scanf("%d", &x);

    if(!find(x)) {
        printf("Esse valor nao esta na lista!\n");
    }
    else {
        printf("O valor %d foi encontrado!", x);
    }

    printf("\n\nDigite um numero que voce deseja retirar da lista: ");
    scanf("%d", &x);

    eliminarElemento(x);
    printf("Nova lista: ");
    imprimirElementos();

    printf("\n");

    return 0;
}
