#include <stdio.h>

void maior(int *pont1, int *pont2);

int main(){

    int numero1, numero2;
    printf("Digite o valor do numero 1: ");
    scanf("%d", &numero1);
    
    printf("Digite o valor do numero 2: ");
    scanf("%d", &numero2);

    int *pont1 = &numero1;
    int *pont2 = &numero2;

    maior(&numero1, &numero2);

    printf("Maior numero: %d\nMenor numero: %d", numero1,numero2);
}

void maior(int *pont1, int *pont2)
{
    if (*pont1 < *pont2)
    {
        int temp = *pont1;
        *pont1 = *pont2;
        *pont2 = temp;
    }
    
}
