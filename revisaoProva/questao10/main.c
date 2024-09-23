Desenvolva um programa para permitir o cadastro de 500 veículos em uma lista. Cada veículo deve ser representado por uma estrutura formada por um marca (máximo de 30 caracteres), um modelo (máximo de 40 caracteres), o ano de fabricação e um conjunto de dados técnicos. O conjunto de dados técnicos, que também deve ser representado por uma estrutura, é composto de: potência em CV, cilindradas e número de válvulas.

(a) Defina as estruturas e faça uma função para a criação da lista. A lista deve ser criada dinamicamente e o vetor para permitir o cadastro dos veículos também deve ser criado dinamicamente.
 
(b) Crie uma função para inserir veículos na lista. 
    
(c) Elabore uma função para calcular a performance estrutural do veículo através da seguinte fórmula: dobro da potência somado com o valor das cilindradas, e dividido pela quantidade de válvulas. Se a quantidade de válvulas for maior ou igual a 16, multiplique a potência por 3 ao invés de 2.

(d) Exiba todas as informações cadastradas, incluindo a performance estrutural.
    
(e) Calcule e exiba a quantidade de veículos cuja performance estrutural é inferior a 150.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int quantVeiculos = 2;

struct no {
    veiculo veiculo;
    struct No *prox;
};

typedef struct no No;

No *cabeca = NULL;

typedef struct{
    char marca[31];
    char modelo[41];
    int anoFabricacao;
    infTecnicas informacoes;
    
} veiculo;

typedef struct {
    int cv;
    int cilindradas;
    int valvulas;
} infTecnicas;

void criarLista(No **lista) {
    if(*lista == NULL) {
        *lista = (No *) malloc(sizeof(No));
        (*lista)->prox = NULL;
    }
}
void inserirLista(No **lista, veiculo **veiculos){
    No *aux;
    aux = (No *)malloc(sizeof(No));

    if(*lista == NULL) {
        criarLista(lista);
    }

    (*lista)->veiculo = 
}
int main(void) {
    veiculo *veiculos;
    veiculos = (veiculo *) malloc(quantVeiculos * sizeof(veiculo));
    criarLista(&cabeca);

    for(int i = 0; i < quantVeiculos; i++) {
        printf("Digite a marca do veiculo: ");
        scanf("%s", veiculos[i].marca);
        printf("Digite o modelo do veiculo: ");
        scanf("%s", veiculos[i].modelo);
        printf("Digite o ano de fabricacao do veiculo: ");
        scanf("%d", &veiculos[i].anoFabricacao);
        printf("Digite a potencia em CV do veiculo: ");
        scanf("%d", &veiculos[i].informacoes.cv);
        printf("Digite as cilindradas do veiculo: ");
        scanf("%d", &veiculos[i].informacoes.cilindradas);
        printf("Digite o numero de valvulas do veiculo: ");
        scanf("%d", &veiculos[i].informacoes.valvulas);
        veiculo *pointer = &veiculos[i];
        inserirLista(&cabeca, &pointer);
    }

    return 0;
}