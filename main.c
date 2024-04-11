#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 5

typedef struct {
    char items[MAX_ITEMS][50];
    int topo;
} GrupoLivros;

void InicializarGrupo(GrupoLivros *grupo)
{
    grupo->topo = -1;
}

int GrupoCheio(GrupoLivros *grupo)
{
    return (grupo->topo == MAX_ITEMS - 1);
}

int GrupoVazio(GrupoLivros *grupo)
{
    return (grupo->topo == -1);
}

void AdicionarLivro(GrupoLivros *grupo, char *livro)
{
    if (GrupoCheio(grupo))
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
        strcpy(fila->items[i],fila->items[i+1]);
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

int main(int argc, char *argv[])
{
    char sep[] = "\\\\-------------------------\\\\\n";
    GrupoLivros pilha;
    InicializarGrupo(&pilha);
    GrupoLivros fila;
    InicializarGrupo(&fila);

    AdicionarLivro(&fila, "O Pistoleiro");
    AdicionarLivro(&fila, "Mar de Monstros");
    AdicionarLivro(&fila, "Os Três Mosqueteiros");
    AdicionarLivro(&fila, "Cálice de Fogo");

    PrintLivros(&fila);
    printf(sep);

    AdicionarLivro(&pilha, AndarFila(&fila));
    AdicionarLivro(&pilha, AndarFila(&fila));

    printf(sep);
    PrintLivros(&fila);

    printf(sep);
    PrintLivros(&pilha);

    return 0;
}