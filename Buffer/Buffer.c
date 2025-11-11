#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_PESSOA (sizeof(char) * 50 + sizeof(int) + sizeof(char) * 50)
#define AREA_TEMP (sizeof(char) * 50 + sizeof(int) + sizeof(char) * 50)

void adiciona(void **pBuffer);
void removePessoa(void **pBuffer);
void busca(void *pBuffer);
void lista(void *pBuffer);

int main(){

    void *pBuffer = malloc(sizeof(int) * 2 + AREA_TEMP);
    if (!pBuffer)
    {
        printf("Erro ao alocar memoria\n");
        return -1;
    }

    int *qtd = (int*) pBuffer;
    *qtd = 0;

    int *opcao = (int*)((char*)pBuffer + sizeof(int));
    *opcao = 0;

    while (*opcao != 5)
    {
        printf("\nMenu:\n1-Adcionar Pessoa.\n2-Remover Pessoa.\n3-Buscar Pessoa.\n4-Listar Pessoas.\n5-Salvar e sair.\n");
        scanf("%d",opcao);
        getchar();

        switch (*opcao)
        {
        case 1:
            adiciona(&pBuffer);
            break;
        
        case 2:
            removePessoa(&pBuffer);
            break;

        case 3:
            busca(pBuffer);
            break;

        case 4:
            lista(pBuffer);
            break;

        case 5:
        printf("Saindo...\n");
            break;

        default:
            printf("Insira um numero valido\n");
        }
    }

    free(pBuffer);
}

void lista(void *pBuffer)
{
    int *qtd = (int*) pBuffer;
    if (*qtd == 0)
    {
        printf("Lista esta vazia\n");
        return;
    }

    char *pessoa = (char*) pBuffer + sizeof(int) * 2 + AREA_TEMP;

    printf("Listando pessoas:\n");
    for (int i = 0; i < *qtd; i++)
    {
        char *nome = pessoa;
        int *idade = (int*)(pessoa + sizeof(char) * 50);
        char *email = (char*)(pessoa + sizeof(char) * 50 + sizeof(int));

        printf("Pessoa %d:\n",i+1);
        printf("  Nome:  %s\n",nome);
        printf("  Idade: %d\n", *idade);
        printf("  Email: %s\n", email);

        pessoa = pessoa + TAM_PESSOA;
    }
}

void busca(void *pBuffer)
{
    int *qtd = (int*) pBuffer;
    if (*qtd == 0)
    {
        printf("Lista vazia.\n");
        return;
    }

    void *areaTemp = (char*) pBuffer + sizeof(int) * 2;
    char *emailBusca = (char*) areaTemp + sizeof(char) * 50 + sizeof(int); 

    printf("Digite o email da pessoa que busca: ");
    scanf("%49s",emailBusca);
    
    void *pessoa = (char*) pBuffer + AREA_TEMP + sizeof(int) * 2;

    for (int i = 0; i < *qtd; i++)
    {
        char *nome = (char*) pessoa;
        int *idade =(int*)(pessoa + sizeof(char) * 50);
        char *email = (char*)(pessoa + sizeof(char) * 50 + sizeof(int));

        if (strcmp(email,emailBusca) == 0)
        {
            printf("Pessoa encontrada\n");
            printf("Nome: %s\n",nome);
            printf("Idade: %d\n",*idade);
            printf("Email: %s\n",email);

            return;

        }
        pessoa = (char*)pessoa + TAM_PESSOA;
    }

    printf("Pessoa nao encontrada.\n");
}


void adiciona(void **pBuffer)
{
    int *qtd = (int*) (*pBuffer);
    
    char *nomeTemp = (char*)(*pBuffer) + sizeof(int) * 2; 
    int *idadeTemp = (int*)(nomeTemp + sizeof(char) * 50);
    char *emailTemp = (char*)(nomeTemp + sizeof(char) * 50 + sizeof(int));

    printf("Digite o nome que deseja adicionar: ");
    scanf("%49s", nomeTemp);

    printf("Digite a idade da pessoa que deseja adicionar: ");
    scanf("%d", idadeTemp);

    printf("Digite o email da pessoa que quer adcionar: ");
    scanf("%49s", emailTemp);

    void *pessoa = (char*)(*pBuffer) + AREA_TEMP + sizeof(int) * 2;

    for (int i = 0; i < *qtd; i++)
    {
        char *email = (char*)(pessoa + sizeof(char) * 50 + sizeof(int));

        if (strcmp(email,emailTemp) == 0)
        {
            printf("Email ja cadastrado.\n");
            return;
        }

        pessoa = (char*) pessoa + TAM_PESSOA;
    }

    *pBuffer = realloc(*pBuffer,sizeof(int) * 2 + AREA_TEMP + TAM_PESSOA * (*qtd + 1));
    if (!(*pBuffer))
    {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    qtd = (int*)(*pBuffer);

    pessoa = (char*)(*pBuffer) + sizeof(int) * 2 + AREA_TEMP + (TAM_PESSOA * (*qtd));

    memcpy(pessoa,(char*)(*pBuffer) + sizeof(int) * 2,TAM_PESSOA);

    (*qtd)++;

    printf("Pessoa adicionada com sucesso.\n");
    return;
}



void removePessoa(void **pBuffer)
{
    int *qtd = (int*) *pBuffer;
    if (*qtd == 0)
    {
        printf("Lista vazia.\n");
        return;
    }

    void *areaTemp = (char*)(*pBuffer) + sizeof(int) * 2;
    char *emailTemp =(char*)(areaTemp + sizeof(char) * 50 + sizeof(int));

    printf("Digite o email da pessoa que deseja remover: ");
    scanf("%49s", emailTemp);

    void *pessoa = (char*)(*pBuffer) + AREA_TEMP + sizeof(int) * 2;

    for (int i = 0; i < *qtd; i++)
    {
        char *email = (char*)pessoa + sizeof(char) * 50 + sizeof(int);

        if (strcmp(email, emailTemp) == 0)
        {
            printf("Pessoa encontrada e removida.\n");

            char *proxima = (char*) pessoa + TAM_PESSOA;
            memmove(pessoa, proxima, (*qtd - i - 1) * TAM_PESSOA);

            (*qtd)--;

            *pBuffer = realloc(*pBuffer, sizeof(int) * 2 + AREA_TEMP + ((*qtd) * TAM_PESSOA));
            if (!(*pBuffer))
            {
                printf("Erro ao realocar memoria.\n");
                return;
            }

            return;
        }

        pessoa = (char*) pessoa + TAM_PESSOA;
    }

    printf("Pessoa nao esta na lista.\n");
}