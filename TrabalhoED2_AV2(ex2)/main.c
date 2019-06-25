#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#define MAX 10

void main()
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
      FILE *arquivo;
      int valor;
      int G[MAX][MAX],i,j,n,u;

      arquivo = fopen("matriz.txt", "r"); // read mode

      if (arquivo == NULL)
      {
          perror("\nErro ao tentar abrir o arquivo.\n");
          system("pause");
          exit(EXIT_FAILURE);
      }

      fscanf(arquivo, "%d",&n);

      fscanf(arquivo, "%d",&u);

      fflush(stdin);

      printf("\nQuantidade de vertices: %d\n", n);
      printf("\nVertice inicial: %d\n", u);

      printf("\nMatriz Adjacente:\n");

      for(i=0;i<n;i++)
      {
        for(j=0;j<n;j++)
        {
            fscanf(arquivo, "%d", &G[i][j]);
        }
      }

      fclose(arquivo);


      for(i=0;i<n;i++)
      {
          printf("\n");
          for(j=0;j<n;j++)
          {
              printf("%d ", G[i][j]);
          }
      }



      //fflush(stdin);
      printf("\n\n ----------------------- Melhor caminho ---------------------- \n");
      dijkstra(G,n,u);
}
