//Qual é a saída do seguinte código? Explique.
#include <stdio.h>
void f(int *j) {
  (*j)++;
}

int main() {
  int i = 20;
  int *p = &i;
  f(p);
  printf("i = %d\n", i);
  return 0;
}

// A saída será 21, já que houve passagem por referência, o que como consequência alterou o valor do conteúdo do endereço passado.