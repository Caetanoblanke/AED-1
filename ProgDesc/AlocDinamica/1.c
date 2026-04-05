/*Crie um programa que:
(a) Aloque dinamicamente um array de 5 numeros inteiros,
(b) Peça para o usuario digitar os 5 números no espaço alocado,
(c) Mostre na tela os 5 numeros, ´
(d) Libere a memoria alocada. */

#include <stdio.h>
#include <stdlib.h>

int main(){

    int *vetor;
    vetor = malloc(sizeof(int) * 5);
    if (!vetor)
    {
        printf("Erro ao alocar memoria\n");
        return -1;
    }
    
    
    printf("Preencha o vetor:\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d",&vetor[i]);
    }

    printf("Imprimindo vetor.\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Numero %d: %d\n", i+1, vetor[i]);
    }

    free(vetor);

}
