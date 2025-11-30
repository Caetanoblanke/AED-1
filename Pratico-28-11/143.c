#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;

} ListNode;

void reorderList(ListNode *head);

int main()
{
}

void reorderList(struct ListNode *head)
{
    if (head == NULL)
    {
        return;
    }

    struct ListNode *aux = head;

    int tamanho = 0;
    while (aux != NULL)
    {
        tamanho++;
        aux = aux->next;
    }

    struct ListNode *anterior = head->next;
    struct ListNode *atual = anterior->next;
    struct ListNode *prox = atual->next;
}