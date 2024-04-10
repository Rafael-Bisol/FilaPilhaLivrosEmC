#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 5

typedef struct {
    char items[MAX_ITEMS][20];
    int topo;
} GrupoLivros;
