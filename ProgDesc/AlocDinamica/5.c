#include <stdio.h>
#include <stdlib.h>

int main(){

    int tamanho;
    printf("Digite o tamanho: ");
    scanf("%d" , &tamanho);

    int *vetor;
    vetor = malloc(sizeof(int) * tamanho);
    if (!vetor)
    {
        printf("Sem espaco para alocar\n");
        return -1;
    }

    printf("Preencha o vetor:\n");
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &vetor[i]);
    }

    int numero;
    printf("Digite o numero que deseja ver os multiplos: ");
    scanf("%d", &numero);

    printf("Imprimindo multiplos...\n");
    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] % numero == 0)
        {
            printf("%d\n",vetor[i]);
        }   
    }

    free(vetor);
}