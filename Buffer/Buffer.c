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

    *(int*)pBuffer = 0;
    *(int*)((char*)pBuffer + sizeof(int)) = 0;

    do
    {
        int *opcao = (int*)((char*)pBuffer + sizeof(int));

        printf("\nMenu:\n1-Adcionar Pessoa.\n2-Remover Pessoa.\n3-Buscar Pessoa.\n4-Listar Pessoas.\n5-Sair.\n");
        printf("Escolha: ");
        scanf("%d", opcao);
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
            printf("Opcao invalida\n");
        }

    } while (*(int*)((char*)pBuffer + sizeof(int)) != 5);

    free(pBuffer);
}

void lista(void *pBuffer)
{
    int *qtd = (int*) pBuffer;

    if (*qtd == 0)
    {
        printf("Lista vazia\n");
        return;
    }

    char *pessoa = (char*) pBuffer + sizeof(int) * 2 + AREA_TEMP;
    char *fim = pessoa + (*qtd * TAM_PESSOA);

    while (pessoa < fim)
    {
        char *nome = pessoa;
        int *idade = (int*)(pessoa + 50);
        char *email = (char*)(pessoa + 50 + sizeof(int));

        printf("Nome: %s\n", nome);
        printf("Idade: %d\n", *idade);
        printf("Email: %s\n\n", email);

        pessoa += TAM_PESSOA;
    }
}

void busca(void *pBuffer)
{
    int *qtd = (int*) pBuffer;

    if (*qtd == 0)
    {
        printf("Lista vazia\n");
        return;
    }

    void *areaTemp = (char*) pBuffer + sizeof(int) * 2;
    char *emailBusca = (char*) areaTemp + 50 + sizeof(int);

    printf("Digite o email: ");
    scanf("%49s", emailBusca);
    getchar();

    char *pessoa = (char*) pBuffer + sizeof(int) * 2 + AREA_TEMP;
    char *fim = pessoa + (*qtd * TAM_PESSOA);

    while (pessoa < fim)
    {
        char *nome = pessoa;
        int *idade = (int*)(pessoa + 50);
        char *email = (char*)(pessoa + 50 + sizeof(int));

        if (strcmp(email, emailBusca) == 0)
        {
            printf("Encontrado:\n%s %d %s\n", nome, *idade, email);
            return;
        }

        pessoa += TAM_PESSOA;
    }

    printf("Nao encontrado\n");
}

void adiciona(void **pBuffer)
{
    int *qtd = (int*) (*pBuffer);

    char *nomeTemp = (char*)(*pBuffer + sizeof(int) * 2);
    int *idadeTemp = (int*)(nomeTemp + 50);
    char *emailTemp = (char*)(nomeTemp + 50 + sizeof(int));

    printf("Nome: ");
    scanf("%49s", nomeTemp);
    getchar();

    printf("Idade: ");
    scanf("%d", idadeTemp);

    printf("Email: ");
    scanf("%49s", emailTemp);
    getchar();

    char *pessoa = (char*)(*pBuffer) + sizeof(int) * 2 + AREA_TEMP;
    char *fim = pessoa + (*qtd * TAM_PESSOA);

    while (pessoa < fim)
    {
        char *email = pessoa + 50 + sizeof(int);

        if (strcmp(email, emailTemp) == 0)
        {
            printf("Email ja existe\n");
            return;
        }

        pessoa += TAM_PESSOA;
    }

    *pBuffer = realloc(*pBuffer, sizeof(int) * 2 + AREA_TEMP + TAM_PESSOA * (*qtd + 1));

    if (!(*pBuffer))
    {
        printf("Erro realloc\n");
        exit(1);
    }

    qtd = (int*)(*pBuffer);

    char *destino = (char*)(*pBuffer) + sizeof(int) * 2 + AREA_TEMP + (*qtd * TAM_PESSOA);

    memcpy(destino, (char*)(*pBuffer) + sizeof(int) * 2, TAM_PESSOA);

    (*qtd)++;

    printf("Adicionado com sucesso\n");
}

void removePessoa(void **pBuffer)
{
    int *qtd = (int*) *pBuffer;

    if (*qtd == 0)
    {
        printf("Lista vazia\n");
        return;
    }

    void *areaTemp = (char*)(*pBuffer) + sizeof(int) * 2;
    char *emailTemp = (char*)(areaTemp + 50 + sizeof(int));

    printf("Email para remover: ");
    scanf("%49s", emailTemp);
    getchar();

    char *pessoa = (char*)(*pBuffer) + sizeof(int) * 2 + AREA_TEMP;
    char *fim = pessoa + (*qtd * TAM_PESSOA);

    while (pessoa < fim)
    {
        char *email = pessoa + 50 + sizeof(int);

        if (strcmp(email, emailTemp) == 0)
        {
            char *proxima = pessoa + TAM_PESSOA;

            memmove(pessoa, proxima, fim - proxima);

            (*qtd)--;

            *pBuffer = realloc(*pBuffer, sizeof(int) * 2 + AREA_TEMP + (*qtd * TAM_PESSOA));

            if (!(*pBuffer))
            {
                printf("Erro realloc\n");
                return;
            }

            printf("Removido\n");
            return;
        }

        pessoa += TAM_PESSOA;
    }

    printf("Nao encontrado\n");
}