#include <stdio.h>

int main(){

    for (int i = 0; i <= 100; i++)
    {
        printf("%d\n",i);
    }

    printf("\n");

    int num=1;
    while (num <= 100)
    {
        printf("%d\n",num);
        num++;
    }

    num=1;
    do
    {
        printf("%d\n",num);
        num++;
    } while (num <=100); 
}