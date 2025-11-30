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
    if (head == NULL || head->next == NULL)
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

    int meio = tamanho / 2;

    struct ListNode *anterior = NULL;
    struct ListNode *atual = head;

    for (int i = 0; i < meio; i++)
    {
        anterior = atual;
        atual = atual->next;
    }

    anterior->next = NULL;

    struct ListNode *prev = NULL;
    struct ListNode *curr = atual;
    struct ListNode *prox;

    while (curr != NULL)
    {
        prox = curr->next;
        curr->next = prev;
        prev = curr;
        curr = prox;
    }

    struct ListNode *l1 = head;
    struct ListNode *l2 = prev;

    while (l2 != NULL)
    {
        struct ListNode *l1_next = l1->next;
        struct ListNode *l2_next = l2->next;

        l1->next = l2;
        l2->next = l1_next;

        l1 = l1_next;
        l2 = l2_next;
    }
}
    
