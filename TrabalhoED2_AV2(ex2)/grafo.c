#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#define INFINITY 9999
#define MAX 10


void dijkstra(int G[MAX][MAX],int n,int no_inicial)
{

	int cost[MAX][MAX],distancia[MAX],anterior[MAX];
	int visitado[MAX],count,mindistance,proximo_no,i,j;

	//anterior[] armazena o vertice anterior
	//count dá o número de nós vistos até o momento

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];

	//Inicializa os vetores
	for(i=0;i<n;i++)
	{
		distancia[i]=cost[no_inicial][i];
		anterior[i]=no_inicial;
		visitado[i]=0;
	}

	distancia[no_inicial]=0;
	visitado[no_inicial]=1;
	count=1;

	while(count<n-1)
	{
		mindistance=INFINITY;

		//pega a distância mínima para o próximo vértice
		for(i=0;i<n;i++)
			if(distancia[i]<mindistance&&!visitado[i])
			{
				mindistance=distancia[i];
				proximo_no=i;
			}

			//verifica se existe melhor caminho entre os vértices
			visitado[proximo_no]=1;
			for(i=0;i<n;i++)
				if(!visitado[i])
					if(mindistance+cost[proximo_no][i]<distancia[i])
					{
						distancia[i]=mindistance+cost[proximo_no][i];
						anterior[i]=proximo_no;
					}
		count++;
	}

	//imprime o caminho e a distância entre cada vértice
	for(i=0;i<n;i++)
		if(i!=no_inicial)
		{
			printf("\nDistancia do vertice %d = %d",i,distancia[i]);
			printf("\nCaminho: %d",i);

			j=i;
			do
			{
				j=anterior[j];
				printf("<-%d",j);
			}while(j!=no_inicial);
	}

	printf("\n\n\n");
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
