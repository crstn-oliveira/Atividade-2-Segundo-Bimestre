#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char musica[100];
    struct No *prox;
    struct No *ant;
} No;

No* criarNo(char *nome)
{
    No *novo = malloc(sizeof(No));

    int i = 0;

    while (nome[i] != '\0')
    {
        novo->musica[i] = nome[i];
        i++;
    }

    novo->musica[i] = '\0';

    novo->prox = novo;
    novo->ant = novo;

    return novo;
}

void adicionarMusica(No **head, char *nome)
{
    No *novo = criarNo(nome);

    if (*head == NULL)
    {
        *head = novo;
        return;
    }

    No *ultimo = (*head)->ant;

    ultimo->prox = novo;
    novo->ant = ultimo;

    novo->prox = *head;
    (*head)->ant = novo;
}

void proximaMusica(No **atual)
{
    if (*atual != NULL)
    {
        *atual = (*atual)->prox;
    }
}

void musicaAnterior(No **atual)
{
    if (*atual != NULL)
    {
        *atual = (*atual)->ant;
    }
}

void exibirPlaylist(No *head)
{
    if (head == NULL)
    {
        printf("Playlist vazia!\n");
        return;
    }

    No *atual = head;

    do {
        printf("[%s] <-> ", atual->musica);
        atual = atual->prox;
    }
    while (atual != head);

    printf("(volta ao inicio)\n");
}

int totalMusicas(No *head)
{
    if (head == NULL)
    {
        return 0;
    }

    int total = 0;

    No *atual = head;

    do {
        total++;
        atual = atual->prox;
    }
    while (atual != head);

    return total;
}

void tocarPlaylist(No *head)
{
    if (head == NULL)
    {
        return;
    }

    No *atual = head;

    do {
        printf("Tocando: %s\n", atual->musica);
        atual = atual->prox;
    }
    while (atual != head);

    printf("Todas as musicas foram tocadas.\n");
}

void liberarPlaylist(No **head)
{
    if (*head == NULL)
    {
        return;
    }

    No *atual = (*head)->prox;

    while (atual != *head)
    {
        No *temp = atual;

        atual = atual->prox;

        free(temp);
    }

    free(*head);

    *head = NULL;
}

int main()
{
    No *playlist = NULL;

    adicionarMusica(&playlist, "Rock");
    adicionarMusica(&playlist, "Jazz");
    adicionarMusica(&playlist, "Pop");

    printf("PLAYLIST:\n");
    exibirPlaylist(playlist);

    printf("\nTotal de musicas: %d\n", totalMusicas(playlist));

    No *atual = playlist;

    printf("\nMusica atual: %s\n", atual->musica);

    proximaMusica(&atual);
    printf("Proxima: %s\n", atual->musica);

    proximaMusica(&atual);
    printf("Proxima: %s\n", atual->musica);

    proximaMusica(&atual);
    printf("Volta circular: %s\n", atual->musica);

    musicaAnterior(&atual);
    printf("Anterior: %s\n", atual->musica);

    printf("\nPercorrendo playlist inteira:\n");
    tocarPlaylist(playlist);

    liberarPlaylist(&playlist);

    return 0;
}