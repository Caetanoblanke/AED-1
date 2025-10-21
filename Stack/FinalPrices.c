#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* finalPrices(int* prices, int pricesSize, int *returnSize);

int main(){
    int returnSize;
    int pricesSize;
    printf("Type the size array of prices: ");
    scanf("%d", &pricesSize);

    int *prices = malloc(sizeof(int) * pricesSize);
    if (!prices)
    {
        printf("Error to alocate\n");
        return -1;
    }

    for (int i = 0; i < pricesSize; i++)
    {
        printf("Type de price %d: ",i+1);
        scanf("%d", &prices[i]);
    }
    
    int *vetor = finalPrices(prices,pricesSize,&returnSize);

    printf("Final prices: \n");
    for (int i = 0; i < pricesSize; i++)
    {
        printf("%d ", prices[i]);
    }
    

    free(vetor);

}


int* finalPrices(int* prices, int pricesSize, int *returnSize)
{
    *returnSize = pricesSize;

    for (int i = 0; i < pricesSize; i++) 
    {
        for (int j = i + 1; j < pricesSize ; j++)
        {
            if (prices[j] <= prices [i])
            {
                prices[i] -= prices[j];
                break;
            }   
        }        
    }
    
    return prices;
}