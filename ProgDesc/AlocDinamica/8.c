#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int *vetor = calloc(1500, sizeof(int));
    if (!vetor)
    {
        printf("Erro ao alocar\n");
        return -1;
    }

    int contador = 0;
    for (int i = 0; i < 1500; i++)
    {
        if (vetor[i] == 0)
        {
            contador++;
        }
    }

    printf("Quantidade de 0: %d\n", contador);

    for (int i = 0; i <= 1500; i++)
    {
        vetor[i] = i;
    }

    printf("Primeiros 10 numeros:\n");
    for (int i = 1; i < 10; i++)
    {
        printf("Numero %d: %d\n", i,vetor[i]);
    }

    printf("Ultimos 10 numeros:\n");
    for (int i = 1491; i <= 1500; i++)
    {
        printf("Numero %d: %d\n", i, vetor[i]);
    }
    
    
    
    free(vetor);
    


    
}