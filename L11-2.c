#include <stdio.h>


int main(){

    char ch;
    int linhas=0;

    FILE *file = fopen("entrada.txt","r");
    if (file == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF )
    {
        if (ch == '\n')
        {
            linhas++;
        }
        
    }

    fclose(file);

    printf("O arquivo tem %d Linhas",linhas);
    
}
