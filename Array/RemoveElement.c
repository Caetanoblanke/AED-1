#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val);

int main(){

    int numsSize;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &numsSize);

    int *nums = malloc(sizeof(int) * numsSize);
    if (nums== NULL)
    {
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    printf("Preenchendo vetor:\n");
    for (int i = 0; i < numsSize; i++)
    {
        printf("Digite o valor da posicao %d: ", i+1);
        scanf("%d", &nums[i]);
    }

    int val;
    printf("Digite o numero que deseja apagar: ");
    scanf("%d", &val);
    

    int novoVetor = removeElement(nums,numsSize,val);

    free(nums);
}

int removeElement(int* nums, int numsSize, int val) {
    
    int k=0;

    printf("\nVetor sem descarte:\n ");
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d ", nums[i]);
    }

    printf("\n");
    
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != val)
        {
            nums[k]=nums[i];
            k++;
        }
        
    }

    printf("Numeros diferentes de %d: %d",val,k);
    printf("\nVetor apos descarte: \n");
    for (int i = 0; i < k; i++)
    {
        printf("%d ", nums[i]);
    }

    return k;

}