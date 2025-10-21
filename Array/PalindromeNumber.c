#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x);
int main(){

    int x;
    printf("Digite o numero de X: ");
    scanf("%d", &x);

    if (isPalindrome(x))
    {
        printf("palindromo");
    }
    else
    {
        printf("Nao eh palindromo");
    }
    
    
}


bool isPalindrome(int x) {

    if (x < 0)
    {
        return false;
    }
    
    int copia = x;
    long reverso = 0;

    while (x != 0)
    {
        int digito = x % 10;
        reverso = (reverso * 10) + digito;
        x /= 10;

    }

    return copia == reverso;
}