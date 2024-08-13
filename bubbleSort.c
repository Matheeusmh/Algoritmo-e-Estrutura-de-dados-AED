#include <stdio.h>

void bubbleSort(int array[]);
void troca(int array[], int j);

int main(void) {
    int array[10];
    
    for(int i = 0; i < 10; i++) {
        printf("Type a int number: ");
        scanf("%d", &array[i]);
    }
    
    bubbleSort(array);

    for(int i = 0; i < 10; i++) {
        printf("%d ", *(array + i));
    }

    return(0);
}

void bubbleSort(int array[]) {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10 - i - 1; j++) {
            if(*(array + j) > *(array + (j + 1))) {
                troca(array, j);
            }
        }
    }
}

void troca(int array[], int j) {
    int aux = 0;
    aux = array[j];
    array[j] = array[j + 1];
    array[j + 1] = aux;
}
