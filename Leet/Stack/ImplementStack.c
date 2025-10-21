#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10



typedef struct
{
    int numeros[MAX];
    int topo;
    int base;
    int limite;
    
} MyStack;


MyStack* myStackCreate();
void myStackPush(MyStack* obj, int x);
int myStackPop(MyStack* obj);
int myStackTop(MyStack* obj);
bool myStackEmpty(MyStack* obj);
void myStackFree(MyStack* obj);


int main(){

    MyStack *obj = myStackCreate();

    printf("%d",(myStackEmpty(obj)));
}

MyStack* myStackCreate()
{
    MyStack *obj;
    obj = malloc(sizeof(MyStack));
    if (!obj)
    {
        printf("Error\n");
    }
    obj->base = 0;
    obj->topo = 0;
    obj->limite = MAX;
    return obj;
}

void myStackPush(MyStack* obj, int x)
{
    if (obj->topo == obj->limite)
    {
        printf("Stack full");
        return;
    }
    
    obj->numeros[obj->topo] = x;
    obj->topo++;
    
}

int myStackPop(MyStack* obj)
{
    if (obj->topo == obj->base)
    {
        printf("Stack empty");
        return -1;
    }

    obj->topo--;
    return obj->numeros[obj->topo];
    
}

int myStackTop(MyStack* obj)
{

    if (obj->topo == 0)
    {
        return -1;
    }

    return obj->numeros[obj->topo - 1];
    
}

bool myStackEmpty(MyStack* obj)
{
    if (obj->base == obj->topo)
    {
        return true;
    }
    else
    {
        return false;
    }

}

void myStackFree(MyStack* obj)
{
   if (obj->topo == obj->base)
   {
     printf("Stack empty");
     return;
   }
   
   for (int i = obj->base; i < obj->topo; i++)
   {
     obj->numeros[i] = 0;
   }
   
   free(obj);
}