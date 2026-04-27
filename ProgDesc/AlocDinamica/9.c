#include <stdio.h>
#include <stdlib.h>

int main(){

    int tamanho;
    printf("Quantos numeros quer alocar: ");
    scanf("%d", &tamanho);

    int *vetor = malloc(sizeof(int) * tamanho);
    if (!vetor)
    {
        printf("Erro ao alocar\n");
        return -1;
    }

    int contador = 0;

    printf("Preencha o vetor:\n");
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &vetor[i]);
        if (vetor[i] < 0)
        {
            break;
        }

        contador++; 
    }

    vetor = realloc(vetor,contador);

    printf("Vetor apos parar no negativo:\n");
    for (int i = 0; i < contador; i++)
    {
        printf("%d\n", vetor[i]);
    }

    free(vetor);
}