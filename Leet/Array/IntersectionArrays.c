#include <stdio.h>
#include <stdlib.h>

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);

int main(){

    int nums1Size;
    printf("Type the array 1 size: ");
    scanf("%d" ,&nums1Size);

    int nums2Size;
    printf("Type the array 2 size: ");
    scanf("%d", &nums2Size);

    int *nums1, *nums2;
    nums1 = malloc(sizeof(int) * nums1Size);
    nums2 = malloc (sizeof(int) * nums2Size);
    if (nums1 == NULL || nums2 == NULL)
    {
        printf("Error to alocate memory");
        return 1;
    }

    for (int i = 0; i < nums1Size; i++)
    {
        printf("Type the number %d: ",i+1);
        scanf("%d", &nums1[i]);
    }

    for (int i = 0; i < nums2Size; i++)
    {
        printf("Type the number %d: ",i+1);
        scanf("%d", &nums2[i]);
    }

    int returnSize;
    int *result = intersection(nums1, nums1Size, nums2, nums2Size, &returnSize);


    free(nums1);
    free(nums2);   
    free(result);
}


int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size,int *returnSize)
{
    int k = 0;
    int *vetor;
    if (nums1Size > nums2Size)
    {
        vetor = malloc(sizeof(int) * nums1Size);
    }
    else
    {
        vetor = malloc(sizeof(int) * nums2Size);
    }
    if (vetor == NULL)
    {
        printf("Error\n");
    }

    int new = 0;
    for (int i = 0; i < nums1Size; i++)
    {
        int duplicate = 0;
        for (int j = 0; j < i; j++)
        {
            if (nums1[i] == nums1[j])
            {
                duplicate = 1;
                break;
            } 
        }

        if (!duplicate)
        {
            nums1[new] = nums1[i];
            new++;
        }
    }

    int novo = 0;
    for (int i = 0; i < nums2Size; i++)
    {
        int duplicado = 0;
        for (int j = 0; j < i; j++)
        {
            if (nums2[i] == nums2[j])
            {
                duplicado = 1;
            }
        }
        if (!duplicado)
        {
           nums2[novo] = nums2[i];
           novo++;
        }
    }
    
    for (int i = 0; i < new; i++)
    {
        for (int j = 0; j < novo; j++)
        {
            if (nums1[i] == nums2[j])
            {
                
                vetor[k] = nums1[i];
                k++;
                break;
            }
        }  
    }

    if (k == 0)
    {
        printf("\nArrays without same numbers\n");
    }
    else
    {
        printf("\nIntersection:\n");
        for (int i = 0; i < k; i++)
        {
            printf("%d ", vetor[i]);
        }   
    }

    *returnSize = k;
    return vetor;
}