#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"



int main()
{
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

 melhor_caminho(&g);

}
