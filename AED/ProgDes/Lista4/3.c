#include <stdio.h>

int main(){

    float vetor[10];
    float quadrado[10];

    printf("Lendo o vetor\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Digite o valor da posicao %d: ",i+1);
        scanf("%f", &vetor[i]);
    }

    printf("\nVetor:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%0.2f ", vetor[i]);
    }
    
    printf("\nQuadrado do vetor:\n");
    for (int i = 0; i < 10; i++)
    {
        quadrado[i] = vetor[i]*vetor[i];
        printf("%0.2f ", quadrado[i]);
    }
}