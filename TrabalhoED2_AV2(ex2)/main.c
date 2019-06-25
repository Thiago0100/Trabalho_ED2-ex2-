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
      char ch, file_name[25];
      int valor;
      int G[MAX][MAX],i,j,n,u;


      printf("\nInsira o no inicial: ");
      scanf("%d",&u);
      printf("Enter no. of vertices:");
      scanf("%d",&n);
      fflush(stdin);

      printf("\nInserindo a matriz adjacente:\n");

      arquivo = fopen("matriz.txt", "r"); // read mode

      if (arquivo == NULL)
      {
          perror("\nErro ao tentar abrir o arquivo.\n");
          system("pause");
          exit(EXIT_FAILURE);
      }

      for(i=0;i<n;i++)
      {
        for(j=0;j<n;j++)
        {
            fscanf(arquivo, "%d", &G[i][j]);
        }
      }
  //gets(file_name);


  //if(fscanf(arquivo, "%s", &file_name) == "Matriz Adjacente:" || fgets(file_name, 25, arquivo) == "Matriz Adjacente")
/*
      while(fgetc(arquivo) != EOF)
      {
          fscanf(arquivo, "%d", &valor);
          printf("%d ", valor);
      }
*/
/*
  while((valor = (int)fgetc(arquivo)) != EOF)
  {
        fscanf(arquivo, "%d", &valor);
        printf("%d ", valor);
  }
*/

      for(i=0;i<n;i++)
      {
          printf("\n");
        for(j=0;j<n;j++)
        {
            printf("%d ", G[i][j]);
        }
      }


      fflush(stdin);
      //dijkstra(G,n,u);
      fclose(arquivo);
}
