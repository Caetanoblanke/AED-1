#include <stdio.h>
#include <stdlib.h>

int* sortArrayByParity(int* nums, int numsSize, int* returnSize);

int main(){

}

int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {

    for (int i = 1; i < numsSize; i++)
    {
        int chave = nums[i];
        int j = i - 1;
        
        while (j >= 0 && nums[j] % 2 != 0 && chave % 2 == 0)
        {
            nums[j+1] = nums[j];
            j--;
        }

        nums[j+1] = chave;

    }

    *returnSize = numsSize;
    return nums;
}