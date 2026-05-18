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
    struct ListNode *atual = head->next;
    struct ListNode *teste = atual;
    int i=0;

    while (anterior != NULL)
    {
        anterior = anterior->next;
        i++;
    }

    anterior = head;
    *returnSize = i;
    int *resposta = malloc(sizeof(int) * i);
    i=0;

    while (atual != NULL)
    {
        while (teste != NULL)
        {
            if (anterior->val < teste->val)
            {
                resposta[i] = teste->val;
                i++;
                anterior = teste;
                teste = atual;
            }
            else
            {
                teste = teste->next;
            }
            
        }
        resposta[i] = 0;

        anterior = atual;
        atual = atual->next;
        teste = atual;
    }
    resposta[i]=0;

    return resposta;
}