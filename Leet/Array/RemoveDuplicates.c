#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize);

int main(){

    int numsSize;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &numsSize);

    int *nums = malloc(sizeof(int) * numsSize);

    for (int i = 0; i < numsSize; i++)
    {
        printf("Digite o valor %d: ",i+1);
        scanf("%d", &nums[i]);
    }

    printf("Vetor normal:\n");
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d ",nums[i]);
    }
    

    int k = removeDuplicates(nums,numsSize);

    printf("\nVetor sem duplicados: \n");
    for (int i = 0; i < k; i++)
    {
        printf("%d ",nums[i]);
    }
}

int removeDuplicates(int* nums, int numsSize)
{
    int i=0;

    for (int j = 1; j < numsSize; j++)
    { 
        if (nums[j] != nums[i])
        {
            i++;
            nums[i]=nums[j];
        }
    }

    return i + 1;
}