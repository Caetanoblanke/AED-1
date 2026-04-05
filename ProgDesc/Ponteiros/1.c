/*Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char. Associe as variaveis aos ponteiros (use &). Modifique os valores de ´
cada variavel usando os ponteiros. Imprima os valores das variáveis antes e depois das modificação*/

#include <stdio.h>
#include <string.h>

int main(){

    int inteiro = 1;
    float flutuante = 5.5;
    char caracteres[50] = "Palavra";

    int *ponteiroInt = &inteiro;
    float *ponteiroFloat = &flutuante;
    char *ponteiroChar = caracteres;

    *ponteiroInt = 10;
    *ponteiroFloat = 9.9;
    strcpy(ponteiroChar, "mudou");

    printf("Inteiro: %d\n", *ponteiroInt);
    printf("Float: %f\n", *ponteiroFloat);
    printf("Char: %s\n", ponteiroChar);

}