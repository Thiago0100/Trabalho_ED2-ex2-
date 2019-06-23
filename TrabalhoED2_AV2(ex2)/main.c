#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#define MAX 10



int main()
{
    /*
    Segundo o exemplo do professor
    A = 0
    B = 1
    C = 2
    D = 3
    E = 4
    */
/*
  Grafo g;
  cria_grafo(&g,5);
  adiciona_aresta(&g,0,1,10);
  adiciona_aresta(&g,0,2,50);
  adiciona_aresta(&g,0,3,65);
  adiciona_aresta(&g,1,2,30);
  adiciona_aresta(&g,1,4,4);
  adiciona_aresta(&g,1,4,4);
  adiciona_aresta(&g,2,3,20);
  adiciona_aresta(&g,2,4,44);
  adiciona_aresta(&g,3,1,70);
  adiciona_aresta(&g,3,4,23);
  adiciona_aresta(&g,4,0,6);

  */

  int G[MAX][MAX],i,j,n,u;
  printf("Enter no. of vertices:");
  scanf("%d",&n);
  printf("\nInsira a matriz adjacente:\n");

  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        scanf("%d",&G[i][j]);
  printf("\nInsira o no inicial: ");
  scanf("%d",&u);
  dijkstra(G,n,u);
  return 0;


}
