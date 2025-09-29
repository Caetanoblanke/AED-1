#include <stdio.h>

int main(){

    char ch;
    FILE *file = fopen("arq.txt","w");
    if (file == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }

    printf("Digite os caracteres ('0' para sair)\n");

    while (ch != '0')
    {
        scanf("%c", &ch);

        if (ch == '0')
        {
            break;
        }
        
        fputc(ch,file);
    }
    

    fclose(file);


    file = fopen("arq.txt","r");
    if (file == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }

    printf("Conteudo do arquivo:\n");

    while (fscanf(file,"%c", &ch) == 1)
    {
        printf("%c",ch);
    }

    fclose(file);  
}