#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));

    int tamanho;
    printf("Qual o tamanho do vetor: ");
    scanf("%d", &tamanho);

    double *vetor = malloc(sizeof(double) * tamanho);
    if (!vetor)
    {
        printf("Erro ao alocar\n");
        return -1;
    }

    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = rand() % 101;
    }

    printf("Mostrando 10 primeiros:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Numero %d: %lf\n", i,vetor[i]);
    }

    free(vetor);
}