#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#define MAX 10

void main()
{
      FILE *arquivo;
      int valor;
      int G[MAX][MAX],i,j,n,u;

      arquivo = fopen("matriz.txt", "r");

      if (arquivo == NULL)
      {
          perror("\nErro ao tentar abrir o arquivo.\n");
          system("pause");
          exit(EXIT_FAILURE);
      }

      //número de vértices
      fscanf(arquivo, "%d",&n);

      //vértice inicial
      fscanf(arquivo, "%d",&u);

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

      printf("\n\n ----------------------- Melhor caminho ---------------------- \n");
      dijkstra(G,n,u);
}
