#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int tamanho;
    printf("Digite o tamanho da string: ");
    scanf("%d", &tamanho);

    char *frase;
    frase = malloc(sizeof(char) * tamanho);
    if (!frase)
    {
        printf("Sem espaco para alocar\n");
        return-1;
    }

    printf("Preencha a string:\n");
    for (int i = 0; i < tamanho; i++)
    {
        scanf(" %c", &frase[i]);
    }
    
    for (int i = 0; i < tamanho; i++)
    {
        char c = frase[i];
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
        {
            printf("%c", c);
        }  
    }

    free(frase);
}