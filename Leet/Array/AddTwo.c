#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode 
{
    char numero;
    struct ListNode *prox;
}ListNode;


ListNode *cria();
void preencher(ListNode *cabeca);
int ListaParaNumero(ListNode *l);
int addTwoNumbers(ListNode *l1, ListNode *l2);  

int main(){

    ListNode *l1 = cria();
    ListNode *l2 = cria();

    preencher(l1);
    preencher(l2);

    ListaParaNumero(l1);
    ListaParaNumero(l2);

    addTwoNumbers(l1,l2);
}

ListNode *cria()
{
    ListNode *cabeca = (ListNode*) malloc(sizeof(ListNode));
    cabeca->prox = NULL;
    return cabeca;
}

void preencher(ListNode *cabeca)
{
    ListNode *fim = cabeca;
    for (int i = 0; i < 3; i++)
    {
        ListNode *novo = (ListNode*) malloc (sizeof(ListNode));
        if (novo == NULL)
        {
            printf("Erro\n");
        }

        printf("Digite o valor: ");
        scanf(" %c", &novo->numero);
        novo->prox = NULL;
        fim->prox = novo;
        fim = novo;
    }

    ListNode *atual = cabeca->prox;

    while (atual != NULL)
    {
        printf("%c ",atual->numero);
        atual = atual->prox;
    }
    printf("\n");
    

}

int ListaParaNumero(ListNode *l)
{
    int num = 0;
    ListNode *atual = l->prox;
    while (atual != NULL)
    {
        num = num * 10 + (atual->numero - '0');
        atual = atual->prox;
    }

    return num;
    
}


int addTwoNumbers(ListNode *l1,ListNode *l2)
{
    printf("Soma das duas listas:\n");
    int n1 = ListaParaNumero(l1);
    int n2 = ListaParaNumero(l2);

    int soma = n1 + n2;

    printf("%d",soma);
    return soma;
}

