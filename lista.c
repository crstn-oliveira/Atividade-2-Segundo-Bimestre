#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No; 

No* criarNo(int valor) {
    No *novo = malloc(sizeof(No));

    novo->valor = valor;
    novo->prox = NULL;

    return novo;
}

void inserirFinal(No **head, int valor) {
    No *novo = criarNo(valor);

    if (*head == NULL) {
        *head = novo;
        return;
    }

    No* atual = *head;

    while (atual->prox != NULL){
        atual = atual->prox;
    }

    atual->prox = novo;
}

void exibirLista(No *head)
{
    No *atual = head;

    while (atual != NULL)
    {
        printf("%d -> ", atual->valor);

        atual = atual->prox;
    }

    printf("NULL\n");
}

void inserirPosicao(No **head, int valor, int posicao)
{
    if (posicao < 0)
    {
        printf("Posicao invalida!\n");
        return;
    }

    No *novo = criarNo(valor);

    if (posicao == 0)
    {
        novo->prox = *head;
        *head = novo;
        return;
    }

    No *atual = *head;

    int i = 0;

    while (atual != NULL && i < posicao - 1)
    {
        atual = atual->prox;
        i++;
    }

    if (atual == NULL)
    {
        printf("Posicao invalida!\n");
        return;
    }

    novo->prox = atual->prox;

    atual->prox = novo;
}

int buscarValor(No *head, int valor)
{

    No *atual = head;
    int posicao = 0;

    while (atual != NULL)
    {
        if (atual->valor == valor)
        {
            return posicao;
        }

        atual = atual->prox;

        posicao++;
    }

    return -1;
}

void inverterLista(No **head)
{

    No *anterior = NULL;
    No *atual = *head;
    No *proximo = NULL;

    while (atual != NULL)
    {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    *head = anterior;
}

void dividirLista(No *head, No **lista1, No **lista2)
{
    if (head == NULL)
    {
        *lista1 = NULL;
        *lista2 = NULL;
        return;
    }

    No *lento = head;
    No *rapido = head;

    while (rapido->prox != NULL && rapido->prox->prox != NULL)
    {
        lento = lento->prox;
        rapido = rapido->prox->prox;
    }

    *lista1 = head;
    *lista2 = lento->prox;

    lento->prox = NULL;
}

int main()
{
    No *lista = NULL;

    
    inserirFinal(&lista, 10);
    inserirFinal(&lista, 20);
    inserirFinal(&lista, 30);

    exibirLista(lista);

    // EXERCÍCIO 1: inserir em posição específica

    inserirPosicao(&lista, 99, 1);
    printf("Lista com 99 na posicao 1:\n ");
    exibirLista(lista);

    // EXERCÍCIO 2: buscar por valor
    int pos = buscarValor(lista, 20);

    printf("Posicao do valor 20: %d", pos);
    pos = buscarValor(lista, 100);

    printf("\nPosicao do valor 100: %d", pos);

    // EXERCÍCIO 3: inverter lista
    printf("\nLista invertida:\n");

    inverterLista(&lista);
    exibirLista(lista);

    // EXERCÍCIO 4: dividir lista em duas
    No *primeira = NULL;
    No *segunda = NULL;

    dividirLista(lista, &primeira, &segunda);

    printf("\nPrimeira metade:\n");
    exibirLista(primeira);

    printf("\nSegunda metade:\n");
    exibirLista(segunda);

    return 0;
}

