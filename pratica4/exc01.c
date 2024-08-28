#include <stdio.h>
#include <stdlib.h>

void trocaA(int x, int y) {
  int temp = x;
  x = y;
  y = temp; }

void trocaB(int *x, int *y) {
 int temp = *x;
 *x = *y;
 *y = temp; }

int main() {
  int a = 5, b = 10;
  printf("Antes da trocaA: a = %d, b = %d\n", a, b);
  trocaA(a, b); // Por valor
  printf("Depois da trocaA: a = %d, b = %d\n", a, b);

  printf("Antes da trocaB: a = %d, b = %d\n", a, b);
  trocaB(&a, &b); // Por referência
  printf("Depois da trocaB: a = %d, b = %d\n", a, b);
  return 0;
}
