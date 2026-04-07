#include <stdio.h>
#include <stdlib.h>

int main(){

    int tamanhoVetor;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanhoVetor);

    int *vetor;
    vetor = malloc(sizeof(int) * tamanhoVetor);
    if (!vetor)
    {
        printf("Sem espaco para alocar\n");
        return -1;
    }

    printf("Preencha o vetor:\n");
    for (int i = 0; i < tamanhoVetor; i++)
    {
        scanf("%d", &vetor[i]);
    }

    printf("Imprimindo vetor:\n");
    for (int i = 0; i < tamanhoVetor; i++)
    {
        printf("Numero %d: %d\n", i+1, vetor[i]);
    }
    
    free(vetor);
}