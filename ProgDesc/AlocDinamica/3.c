#include <stdio.h>
#include <stdlib.h>

int main(){

    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int *vetor;
    vetor = malloc(sizeof(int) * tamanho);
    if (!vetor)
    {
        printf("Sem espaco na memoria\n");
        return -1;
    }
    
    int pares = 0;
    int impares = 0;
    
    printf("Preencha o vetor:\n");
    for (int i = 0; i < tamanho; i++)
    {
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
    
    printf("Quantidade numeros pares: %d\n", pares);
    printf("Quantidade numeros impares: %d\n", impares);
    
}