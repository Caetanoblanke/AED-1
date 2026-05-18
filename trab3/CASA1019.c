#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

int main(){

    struct ListNode *head = malloc(sizeof(struct ListNode));
    if (!head)
    {
        printf("Erro ao alocar");
        return;
    }
     
}

int* nextLargerNodes(struct ListNode *head, int* returnSize)
{
    struct ListNode *anterior = head;
    int i = 0;

    while (anterior != NULL)
    {
        anterior = anterior->next;
        i++;
    }

    anterior = head;
    *returnSize = i;
    int *resposta = malloc(sizeof(int) * i);
    i = 0;

    while (anterior != NULL)
    {
        struct ListNode *teste = anterior->next;
        int achou = 0;

        while (teste != NULL)
        {
            if (teste->val > anterior->val)
            {
                resposta[i] = teste->val;
                achou = 1;
                break;
            }
            
            teste = teste->next;
        }

        if (!achou)
        {   
            resposta[i] = 0;
        }
        anterior = anterior->next;
        i++;
    }

    return resposta;
}