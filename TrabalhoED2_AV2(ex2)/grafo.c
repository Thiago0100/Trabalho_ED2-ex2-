#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#define INFINITY 9999
#define MAX 10


void dijkstra(int G[MAX][MAX],int n,int startnode)
{

	int cost[MAX][MAX],distance[MAX],pred[MAX];
	int visited[MAX],count,mindistance,nextnode,i,j;

	//pred[] stores the predecessor of each node
	//count gives the number of nodes seen so far
	//create the cost matrix
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];

	//initialize pred[],distance[] and visited[]
	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}

	distance[startnode]=0;
	visited[startnode]=1;
	count=1;

	while(count<n-1)
	{
		mindistance=INFINITY;

		//nextnode gives the node at minimum distance
		for(i=0;i<n;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}

			//check if a better path exists through nextnode
			visited[nextnode]=1;
			for(i=0;i<n;i++)
				if(!visited[i])
					if(mindistance+cost[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+cost[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}

	//print the path and distance of each node
	for(i=0;i<n;i++)
		if(i!=startnode)
		{
			printf("\nDistance of node%d=%d",i,distance[i]);
			printf("\nPath=%d",i);

			j=i;
			do
			{
				j=pred[j];
				printf("<-%d",j);
			}while(j!=startnode);
	}
}


void cria_grafo(Grafo* g, int vertices)
{
    int i,j;

    g->mat = calloc (vertices, sizeof(int*));
    for (i = 0; i < vertices; i++)
    {
        g->mat[i] = calloc (i, sizeof(int));
    }

    g->total_vertices = vertices;
    g->peso = INFINITY;

    for (i = 0; i < g->total_vertices; i++)
        for (j = 0; j < g->total_vertices; j++)
            g->mat[i][j] = 0;


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
    int v1, v2;

    //Pega o peso do primeiro vértice

    for (i = 0; i < g->total_vertices; i++)
    {
        for (j = 0; j < g->total_vertices; j++)
        {
            if(g->mat[i][j] != INFINITY && g->mat[i][j] < rota)
            {
                rota = g->mat[i][j];
                v1 = i;
                v2 = j;
            }
        }
        if (rota != g->peso)
        {
            printf ("\nCaminho[%d][%d] peso %d\n", v1, v2,rota);
            rota = g->peso;
        }

    }

}
void imprime_grafo(Grafo *g)
{
    int i,j;
    for (i = 0; i < g->total_vertices; i++)
        for (j = 0; j < g->total_vertices; j++)
        {
            if(g->mat[i][j] != INFINITY)
            {
                printf ("\nCaminho[%d][%d] = %d\n", i, j,g->mat[i][j]);
            }
        }

}



