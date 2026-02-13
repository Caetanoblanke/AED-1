#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* findLongestWord(char* s, char** dictionary, int dictionarySize);

int main() {
    int dictionarySize;

    printf("Digite o tamanho do dicionario: ");
    scanf("%d", &dictionarySize);

    char s[1000];
    printf("Digite a string base: ");
    scanf("%s", s);

    char **dictionary = malloc(sizeof(char*) * dictionarySize);

    for (int i = 0; i < dictionarySize; i++) {
        dictionary[i] = malloc(sizeof(char) * 1000);
        printf("Digite a palavra %d: ", i + 1);
        scanf("%s", dictionary[i]);
    }

    char *resultado = findLongestWord(s, dictionary, dictionarySize);

    printf("\nMaior palavra encontrada: %s\n", resultado);

    for (int i = 0; i < dictionarySize; i++) {
        free(dictionary[i]);
    }
    free(dictionary);

    return 0;
}



char* findLongestWord(char* s, char** dictionary, int dictionarySize) {
    char *palavraLonga = "";
    for (int i = 0; i < dictionarySize; i++)
    {
        char *palavra = dictionary[i];
        int j = 0;
        for (int k = 0; k < strlen(s); k++)
        {
            if (s[k] == palavra[j])
            {
                j++;
            }
        }
        if (j == strlen(palavra))
        {
            if (strlen(palavra) > strlen(palavraLonga) || (strlen(palavra) == strlen(palavraLonga) && strcmp(palavra, palavraLonga) < 0))
            {
                palavraLonga = palavra;
            }
        }
    }
    return palavraLonga;
    
}

