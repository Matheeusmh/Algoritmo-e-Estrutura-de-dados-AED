#include<stdio.h>

int main(void) {
    int vet[3];

    for(int i = 0; i < 3; i++) {
        scanf("%d", &vet[i]);
    }
    for(int i = 0; i < 3; i++) {
        printf("%d ", vet[i]);
    }

    return 0;
}