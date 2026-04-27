#include <stdio.h>
#include <stdlib.h>

int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    
    int m = matSize;
    int n = matColSize[0];

    int* resultado = malloc(sizeof(int) * (m * n));
    if (!resultado)
    {
        printf("Erro ao alocar");
        return NULL;
    }

    int k = 0;

    for (int d = 0; d < m + n - 1; d++)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i + j == d)
                {
                    resultado[k] = mat[i][j];
                    k++;
                }
                
            }
            
        }
        
    }
    
    *returnSize = k;
    return resultado;
}