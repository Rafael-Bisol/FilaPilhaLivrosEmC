#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 5

typedef struct {
    char items[MAX_ITEMS][20];
    int topo;
} GrupoLivros;

void InicializarGrupo(GrupoLivros *fila)
{
    fila->topo = -1;
}

int GrupoCheio(GrupoLivros *grupo)
{
    return (fila->topo == MAX_ITEMS - 1);
}

int GrupoVazio(GrupoLivros *grupo)
{
    return (fila->topo == -1);
}

void AdicionarLivro(GrupoLivros *grupo, char *livro)
{
    if (GrupoCheio(fila))
    {
        printf("O grupo esta cheio! Mais um livro e nao tem mais espaco na Terra!\n");
        return;
    }
    grupo->topo++;
    strcpy(grupo->items[grupo->topo],livro);
}

void PrintLivros(GrupoLivros *grupo)
{
    if (GrupoVazio(grupo))
    {
        printf("A fila esta vazia!\n");
        return;
    }
    for (int i = 0; i <= grupo->topo; i++)
    {
        printf("Livro[%d]: %s\n", i, grupo->items[i]);
    }
}

char *AndarFila(GrupoLivros *fila)
{
    if (GrupoVazio(fila))
    {
        printf("A fila esta vazia!\n");
        return NULL;
    }
    fila->topo--;
    for (int i = 0; i <= fila->topo; i++)
    {
        strcpy(fila->items[i],fila->items[i+1])
    }
    return fila->items[fila->topo+1];
}

char *Desempilhar(GrupoLivros *pilha)
{
    if (GrupoVazio(pilha))
    {
        printf("A pilha esta vazia! Esta tentando escavar?\n");
        return NULL;
    }
    pilha->topo--;
    return pilha->items[pilha->topo+1];
}