#include <stdio.h>

int main(){

    int vetor[6];

    for (int i = 0; i < 6; i++)
    {
        printf("Digite o valor %d: ",i+1);
        scanf("%d",&vetor[i]);
    }
    for (int i = 0; i < 6; i++)
    {
        printf("%d", vetor[i]);
    } 
}