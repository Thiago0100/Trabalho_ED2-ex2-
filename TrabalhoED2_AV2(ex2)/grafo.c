#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#define INFINIT 2147483647

void cria_grafo(Grafo* g, int vertices)
{
    int i,j;

    g->mat = calloc (vertices, sizeof(int*));
    for (i = 0; i < vertices; i++)
    {
        g->mat[i] = calloc (i, sizeof(int));
    }

    g->total_vertices = vertices;
    g->peso = INFINIT;

     for (i = 0; i < g->total_vertices; i++)
        for (j = 0; i < g->total_vertices; i++)
             g->mat[i][j] = INFINIT;


}

void adiciona_aresta(Grafo *g, int vertice1, int vertice2, int peso)
{
    g->mat[vertice1][vertice2] = peso;

}

void destroi(Grafo *g)
{
    int i;
    for (i = 0; i < g->total_vertices; i++)
        free(g->mat[i]);
    free(g->mat);
}

void melhor_caminho(Grafo *g)
{
    int rota = g->peso,i,j;

    //Pega o peso do primeiro vértice

    for (i = 0; i < g->total_vertices; i++)
    {
        for (j = 0; i < g->total_vertices; i++)
        {
            if(g->mat[i][j] != INFINIT && g->mat[i][j] < rota)
            {
                printf ("\nCaminho[%d][%d] peso %d\n", i, j,g->mat[i][j]);

            }
        }

    }

}
void imprime_grafo(Grafo *g)
{
    int i,j;
    for (i = 0; i < g->total_vertices; i++)
        for (j = 0; i < g->total_vertices; i++)
        {
            //if(g->mat[i][j] != INFINIT)
            //{
                printf ("\nCaminho[%d][%d] = %d\n", i, j,g->mat[i][j]);
            //}
        }

}


