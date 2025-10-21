#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {

    int numeros[MAX];
    int top;
    int base;
    int limit;
} MyQueue;


MyQueue* myQueueCreate();
void myQueuePush(MyQueue* queue, int numeros);
int myQueuePop(MyQueue* queue);
int myQueuePeek(MyQueue* queue);
bool myQueueEmpty(MyQueue* queue);
void myQueueFree(MyQueue* queue);

int main(){

    MyQueue *queue = myQueueCreate();
    if (!queue)
    {
        printf("Error\n");
        return 1;
    }

    myQueuePush(queue,10);
    myQueuePush(queue,20);

    printf("Queue top: %d",myQueuePeek(queue));

    myQueuePop(queue);
    
    printf("\nCheck if queue is empty:\n");
    if (myQueueEmpty(queue))
    {
        printf("Queue empty\n");
    }
    else
    {
        printf("Queue not empty\n");
    }
    
    myQueueFree(queue);
    free(queue);
}



MyQueue* myQueueCreate() {
    MyQueue *queue;
    queue = malloc(sizeof(MyQueue));
    if (queue == NULL)
    {
        printf("\nError to alocate memory\n");
    }
    queue->top = 0;
    queue->base = 0;
    queue->limit = MAX;
    return queue;
}

void myQueuePush(MyQueue* queue, int numeros)
{
    if (queue->top == queue->limit)
    {
        printf("\nQueue is full\n");
        return;
    }

    queue->numeros[queue->top] = numeros;
    queue->top++;
}

int myQueuePop(MyQueue* queue)
{
    if (queue->top == queue->base)
    {
        printf("\nQueue is empty");
        return -1;
    }

    int valor = queue->numeros[queue->base];
    for (int i = queue->base; i < queue->top - 1; i++)
    {
        queue->numeros[i] = queue->numeros[i + 1];
    }


    queue->top--;
    return valor;
}

int myQueuePeek(MyQueue* queue)
{
    if (queue->top == queue->base)
    {
        printf("\nQueue empty");
        return -1;
    }
    return queue->numeros[queue->base];
}

bool myQueueEmpty(MyQueue* queue)
{
    if (queue->top == queue->base)
    {
        return true;
    }
    else
    {
        return false;
    }  
}

void myQueueFree(MyQueue* queue)
{
    if (queue->top > queue->base)
    {
        printf("\nQueue already empty");
        return;
    }

    queue->base = 0;
    queue->top = 0;

    printf("\nQueue Cleared\n");
}