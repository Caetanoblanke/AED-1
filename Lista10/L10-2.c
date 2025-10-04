#include <stdio.h>
#include <stdlib.h>

int main(){

    int tamanho;
    int *vetor;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    vetor = (int*) malloc(sizeof(int) * tamanho);

    for (int i = 0; i < tamanho; i++)
    {
        printf("Digite o valor da posicao %d: ",i+1);
        scanf("%d", &vetor[i]);
    }

    printf("Valores do vetor: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    
    free(vetor);
}
