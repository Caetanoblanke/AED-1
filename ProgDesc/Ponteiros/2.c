#include <stdio.h>

int main(){
    
    int numero1;
    int numero2;

    int *pont1 = &numero1;
    int *pont2 = &numero2;

    if (pont1 > pont2)
    {
        printf("%p", pont1);
    }
    else
    {
        printf("%p", pont2);
    }
}   