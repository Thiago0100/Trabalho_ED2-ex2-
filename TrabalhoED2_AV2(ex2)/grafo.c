#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

void cria_grafo(Grafo* g, int vertices)
{
    int i;

    g->mat = calloc (vertices, sizeof(int*));
    g->mat[0] = NULL;

    for (i = 1; i < vertices; i++)
        g->mat = calloc (i, sizeof(int));

    g->total_vertices = vertices;
}

void adiciona_aresta(Grafo *g, int vertice1, int vertice2, int peso)
{
    g->mat[vertice1][vertice2] = peso;
}
