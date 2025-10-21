#include <stdio.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target);

int main(){

    int numsSize;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &numsSize);

    int *nums = malloc(sizeof(int) * numsSize);
    if (nums == NULL)
    {
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    for (int i = 0; i < numsSize; i++)
    {
        printf("Digite o valor da posicao %d: ",i+1);
        scanf("%d", &nums[i]);
    }

    int target;
    printf("Digite o numero que deseja procurar: ");
    scanf("%d", &target);

    int pos = searchInsert(nums,numsSize,target);
    printf("Indice do alvo: %d",pos);

}


int searchInsert(int* nums, int numsSize, int target)
{
    
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] >= target)
        {
            return i;
        }
    }

    return numsSize;
}