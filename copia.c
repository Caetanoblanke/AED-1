#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool lemonadeChange(int* bills, int billsSize);

int main(){

    int billsSize;
    printf("Digite o numero de compradores: ");
    scanf("%d", &billsSize);

    int *bills = malloc(sizeof(int) * billsSize);
    if (!bills)
    {
        printf("Erro ao alocar\n");
        return -1;
    }

}

bool lemonadeChange(int* bills, int billsSize) {
    int cinco = 0;
    int dez = 0;

    for (int i = 0; i < billsSize; i++)
    {
        if (bills[i] == 5)
        {
            cinco++;
        }

        else if (bills[i] == 10)
        {
            if (cinco < 1)
            {
                return false;
            }
            dez++;
            cinco--;
        }
        
        else if (bills[i] == 20)
        {
            if (cinco >= 1 && dez >= 1)
            {
                cinco--;
                dez--;
            }
            else if (cinco >= 3)
            {
                cinco -=3;
            }
            else
            {
                return false;
            }
        }
        
    }
    return true;
}