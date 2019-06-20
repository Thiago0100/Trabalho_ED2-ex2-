#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"



int main()
{
  Grafo g;
  cria_grafo(&g,4);
  adiciona_aresta(&g,0,1,5);
  adiciona_aresta(&g,0,3,2);
  adiciona_aresta(&g,1,2,2);
  adiciona_aresta(&g,3,2,8);

 melhor_caminho(&g);

}
