#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n);

int main(){
    int flowerbedSize;
    printf("type the flowerbed size: ");
    scanf("%d" ,&flowerbedSize);

    int *flowerbed = malloc(sizeof(int) * flowerbedSize);
    if (!flowerbed)
    {
        printf("error\n");
        return -1;
    }

    printf("Type 0 to empty 1 to not empty: \n");
    for(int i = 0; i < flowerbedSize; i++)
    {
        scanf("%d" ,&flowerbed[i]);
    }

    int n;
    printf("Insert how many flower you want add: ");
    scanf("%d", &n);

    canPlaceFlowers(flowerbed,flowerbedSize,n);

    free(flowerbed);
    
}


bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n)
{
   for (int i = 0; i < flowerbedSize && n>0; i++)
    {
        
        if (flowerbed[i]==0 && (i==0 || flowerbed[i-1] == 0) && (i==flowerbedSize-1 || flowerbed[i+1]==0))
        {
            n--;
            flowerbed[i] = 1;
        }
    }

    if (n==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}  


