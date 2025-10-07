#include <stdio.h>
#include <stdlib.h>

int main(){

    int tamanho;
    int pares=0,impares=0;

    printf("Digite o tamaho do vetor: ");
    scanf("%d" ,&tamanho);

    int *vetor = (int*) malloc(sizeof(int) * tamanho);

    for (int i = 0; i < tamanho; i++)
    {
        printf("Digite o valor da posicao %d: ",i+1);
        scanf("%d", &vetor[i]);
        if (vetor[i] % 2 == 0)
        {
            pares++;
        }
        else
        {
            impares++;
        }
    }

    printf("Quantidade de numeros Pares: %d\n", pares);
    printf("Quantidade de numeros Impares: %d\n", impares);

    free(vetor);
}