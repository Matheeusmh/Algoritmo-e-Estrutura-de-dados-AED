#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct no {
   int vidas;
   char nome[10];
   float distancia;
   struct no* prox;
};

typedef struct no No;

void insere_lista_de(No **li, int v, char *n, float a){
  struct no* novo;
  novo = (No*) malloc (sizeof(No));
  novo->vidas = v;
  novo->distancia = a;
  strcpy(novo->nome,n); 
  novo->prox = *li;
  *li = novo;    
}
void imprime(No *li){
   if (li == NULL)
      printf("\nLista Vazia");
   else{
      No *aux;
      aux = li;
      while(aux != NULL){
          printf("\n%3d \t%s \t%f",aux->vidas, aux->nome, aux->distancia);
          aux = aux->prox;
      }
   }
}

void removeListaM(No **lista) {
    float menorDist = 0;
    No *aux = *lista;
    No *anterior = NULL;

    while(aux != NULL) {
        if(aux->distancia == (*lista)->distancia) {
            menorDist = aux->distancia;
        }
        else {
            if(aux->distancia < menorDist) menorDist = aux->distancia;
        }
    }

    while(aux != NULL) {
        if(aux->distancia == menorDist) {
            if(anterior == NULL) {
                *lista = aux->prox;
            }
            else {
                anterior->prox = aux->prox;
            }
        }
    }
}
int main(void) {
  No* lista;
  lista = (No*) malloc (sizeof(No));
  lista = NULL;
  insere_lista_de(&lista,100,"hackr",6.33);
  insere_lista_de(&lista,60,"gamr",7.2);
  insere_lista_de(&lista,70,"strkid",10.7);
  insere_lista_de(&lista,110, "jog1",9.65);

  printf("\nLista de ataques: \nVidas \tJogador \tDistancia");
  imprime(lista);

  removeListaM(&lista);

  printf("\nLista de ataques: \nVidas \tJogador \tDistancia");
  imprime(lista);

  return 0;
}

