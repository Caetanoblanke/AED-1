#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10
typedef struct
{
    int id;
    char alunos[50];
}classe;

typedef struct
{
    classe alunos[MAX];
    int topo;

}pilha;

void reset(pilha *pilha)
{
    pilha->topo = 0;
}

void pop(pilha *pilha)
{
    if (pilha->topo == 0)
    {
        printf("Pilha ja esta vazia\n");
        return;
    }

    pilha->topo--;
}

void push(pilha *pilha, classe a)
{
    if (pilha->topo == MAX)
    {
        printf("Pilha ja esta cheia\n");
        return;
    }
    
    pilha->alunos[pilha->topo] = a;
    pilha->topo++; 
}

void lista(pilha *pilha)
{
    if (pilha->topo == 0)
    {
        printf("Lista vazia\n");
        return;
    }

    int contador = 0;
    while (pilha->topo != 0)
    {
        printf("ID: %d\n", pilha->alunos[pilha->topo - 1].id);
        printf("Aluno: %s\n", pilha->alunos[pilha->topo - 1].alunos);
        pilha->topo--;
        contador++;
    }

    pilha->topo = contador;
}
int main(){

}

int calPoints(char** operations, int operationsSize) {

    char pilha[strlen(operations)];
    char ch = *operations;
    for (int i = 0; operations != 0; i++)
    {
        
        
    }
    
    


    
}