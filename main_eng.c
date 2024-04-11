#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 5

typedef struct {
    char items[MAX_ITEMS][50];
    int top;
} GrupoLivros;

void InicializeGroup(GrupoLivros *group)
{
    group->top = -1;
}

int isGroupFull(GrupoLivros *group)
{
    return (group->top == MAX_ITEMS - 1);
}

int isGroupEmpty(GrupoLivros *group)
{
    return (group->top == -1);
}

void AddBook(GrupoLivros *group, char *livro)
{
    if (isGroupFull(group))
    {
        printf("The group is full! One more book and there will be no more space on Earth!\n");
        return;
    }
    group->top++;
    strcpy(group->items[group->top],livro);
}

void PrintBooks(GrupoLivros *group)
{
    if (isGroupEmpty(group))
    {
        printf("The queue is empty! Ya tryn' ta knock da shelf down?!\n");
        return;
    }
    for (int i = 0; i <= group->top; i++)
    {
        printf("Book[%d]: %s\n", i, group->items[i]);
    }
}

char *Dequeue(GrupoLivros *queue)
{
    if (isGroupEmpty(queue))
    {
        printf("The queue is empty!\n");
        return NULL;
    }
    queue->top--;
    for (int i = 0; i <= queue->top; i++)
    {
        strcpy(queue->items[i],queue->items[i+1]);
    }
    return queue->items[queue->top+1];
}

char *Unstack(GrupoLivros *stack)
{
    if (isGroupEmpty(stack))
    {
        printf("The stack is empty! Are you trying to dig?\n");
        return NULL;
    }
    stack->top--;
    return stack->items[stack->top+1];
}

int main(int argc, char *argv[])
{
    char sep[] = "\\\\-------------------------\\\\\n";
    GrupoLivros stack;
    InicializeGroup(&stack);
    GrupoLivros queue;
    InicializeGroup(&queue);

    AddBook(&queue, "The Gunslinger");
    AddBook(&queue, "Sea of Monsters");
    AddBook(&queue, "Three Musqueteers");
    AddBook(&queue, "Calice of Fire");

    PrintBooks(&queue);
    printf(sep);

    AddBook(&stack, Dequeue(&queue));
    AddBook(&stack, Dequeue(&queue));

    printf(sep);
    PrintBooks(&queue);

    printf(sep);
    PrintBooks(&stack);

    return 0;
}