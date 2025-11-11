#include <stdio.h>
#include <stdlib.h>

int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination);

int main(){
    int distanceSize;
    printf("Insert distance size:");
    scanf("%d", &distanceSize);

    int *distance = malloc(sizeof(int) * distanceSize);
    if (!distance)
    {
        printf("Alocate error");
        return -1;
    }

    for (int i = 0; i < distanceSize; i++)
    {
        distance[i] = [i+1];
    }
    

    int start;
    printf("Insert your start");
    scanf("%d", &start);

    int destination;
    printf("Insert your destination");
    scanf("%d", &destination);
}

int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination)
{
    int counter1 = 0;
    int counter2 = 0;
    
    if (destination>start)
    {
        for (int i = start; i != destination; i++)
        {
            counter1++;
        }
    }
    else
    {
        for (int i = start; i != destination; i--)
        {
            counter1++;
        }
        
    }
    
    
    
    
        
    
    

}