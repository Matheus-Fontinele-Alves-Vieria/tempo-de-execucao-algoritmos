#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

int randomInteger(int low, int high) {
    int k;

    srand((unsigned)time(NULL));

    k = (rand() % high) + low;

    return k;
}

void bubbleSort(int v[TAM]) {
    int i, j, aux;

    for(i = TAM - 1; i >= 1; i++) {
        for(j = 0; j < i; j++) {
            if(v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

int main() {
    clock_t time;
    int vetor[TAM];
    int i;

    for(i = 0; i < TAM; i++) {
        vetor[i] = randomInteger(-100, 100);
    }

    time = clock();
    bubbleSort(vetor);
    time = clock() - time;

    printf("Tempo de execução: %lf", ((double)time) / ((CLOCKS_PER_SEC / 1000)));
}
