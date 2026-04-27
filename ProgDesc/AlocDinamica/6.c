//Ajusetei a posição como se comecasse no 1 para o programa ficar mais intuitivo.

#include <stdio.h>
#include <stdlib.h>

int main(){

    int tamanho;
    printf("Digite o tamanho: ");
    scanf("%d", &tamanho);

    int *vetor = malloc(sizeof(int) * tamanho);
    if (!vetor)
    {
        printf("Sem espaco para alocar\n");
        return -1;
    }

    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = 0;
    }

    int opcao = 0;

    while (opcao != 3)
    {
        printf("1- Inserir numero:\n2- Procurar em posicao:\n3-Sair:\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
            int posicao;
            printf("Digite em qual posicao deseja inserir um numero: ");
            scanf("%d",&posicao);
            while (posicao > tamanho)
            {
                printf("Digite um valor valido: ");
                scanf("%d", &posicao);
            }
        
        
            int i = 0;
            while (i != posicao)
            {
                i++;
            }

            int numero;
            printf("Digite o numero que deseja inserir: ");
            scanf("%d", &numero);

            vetor[i-1] = numero;

            for (int i = 0; i < tamanho; i++)
            {
                printf("Numero %d: %d\n", i+1,vetor[i]);
            }
            break;
    
            case 2:
            int lugar;
            printf("Digite a posicao que deseja ver o numero: ");
            scanf("%d", &lugar);

            int j = 0;
            while (j != lugar)
            {
                j++;
            }

            printf("Numero da posicao %d: %d\n", lugar,vetor[j-1]);
            break;


            case 3:
            printf("Saindo...\n");
            break;

            default:
            break;
        }   
    }
}