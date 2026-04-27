#include <stdio.h>
#include <stdlib.h>

int main(){

    int loteria[6];
    printf("Numeros da loteria:\n");
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &loteria[i]);
    }

    int jogador[6];
    printf("Escolha seus numeros:\n");
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &jogador[i]);
    }

    int contador = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (jogador[j] == loteria[i])
            {
                contador++;
            }   
        }
    }

    int *corretos = malloc(sizeof(int) * contador);
    if (!corretos)
    {
        printf("Sem espaco na memoria\n");
        return -1;
    }

    int k = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (jogador[j] == loteria[i])
            {
                corretos[k] = jogador[j];
                k++;
            }
            
        }
        
    }

    printf("Numeros da loteria: ");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", loteria[i]);
    }
    printf("\n");

    printf("Numeros do jogador: ");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", jogador[i]);
    }
    printf("\n");
    
    printf("Numeros acertados: ");
    for (int i = 0; i < contador; i++)
    {
        printf("%d ", corretos[i]);
    }
    printf("\n");

    free(corretos);
}