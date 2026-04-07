#include <stdio.h>

void troca(int numero1, int numero2);

int main(){

    int numero1, numero2;
    printf("Digite o valor do numero 1: ");
    scanf("%d", &numero1);

    printf("Digite o valor do numero 2: ");
    scanf("%d", &numero2);

    printf("Valor normal: \nPrimeiro: %d\nSegundo: %d\n\n", numero1,numero2);

    troca(numero1,numero2);
}

void troca(int numero1,int numero2){

    int *pont1 = &numero1;
    int *pont2 = &numero2;
    int temp = numero1;

    *pont1 = numero2;
    *pont2 = temp;

    printf("Valor trocado: \nPrimeiro: %d\nSegundo: %d", numero1,numero2);
}