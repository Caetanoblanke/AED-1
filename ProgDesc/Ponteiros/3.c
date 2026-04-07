#include <stdio.h>

int main(){

    int num1, num2;

    printf("Digite o valor do numero 1 e 2: ");
    scanf("%d %d", &num1, &num2);

    int *pont1 = &num1;
    int *pont2 = &num2;

    if (pont1 > pont2)
    {
        printf("%d", *pont1);
    }
    else
    {
        printf("%d", *pont2);
    }
}