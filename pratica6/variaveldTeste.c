#include<stdio.h>

void imprime(int **ll, int *l, int *i) {
    printf("%d\n", ll);
    printf("%d\n", **ll);
    printf("%d\n", l);
    printf("%d\n", *l);
    printf("%d\n", *i);
}

int main(void) {
    int a = 10, *ptrS;
    ptrS = &a;

    printf("%d\n", &ptrS);
    imprime(&ptrS, ptrS, &a);

    return 0;
}