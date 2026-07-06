#include <stdio.h>
#include <stdlib.h>

int main(){

    int numsSize;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &numsSize);

    int *nums;
    nums = malloc(sizeof(int) * numsSize);
    int pares = 0;

    printf("Preencha o vetor:\n");
    for (int i = 0; i < numsSize; i++)
    {
        scanf("%d",&nums[i]);
    }

    for (int i = 0; i < numsSize-1 ; i++)
    {
        for (int j = i + 1; j < numsSize ; j++)
        {
            if (nums[i] > 2*nums[j])
            {
                pares++;
            }   
        }
    }

    printf("Pares: %d\n", pares);
}