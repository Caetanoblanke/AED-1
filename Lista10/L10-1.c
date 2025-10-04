#include <stdio.h>
#include <stdlib.h>

int main(){

    int tamanho = 5;

    int *vetor = (int*) malloc(sizeof(int) * tamanho);

    if (vetor == NULL)
    {
        printf("Erro ao alocar memoria\n");
    }

    for (int i = 0; i < tamanho; i++)
    {
        printf("Digite o valor da posicao %d do vetor: ",i+1);
        scanf("%d",&vetor[i]);
    }

    printf("Valores do vetor: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ",vetor[i]);
    }


    free(vetor);
    
}