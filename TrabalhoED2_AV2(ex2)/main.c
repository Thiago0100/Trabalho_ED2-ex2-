#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"



int main()
{
  Grafo **g;
  cria_grafo(&g, 6);
  adiciona_aresta(&g,0,1,5);
  adiciona_aresta(&g,0,3,2);
  adiciona_aresta(&g,3,1,2);
  adiciona_aresta(&g,3,2,8);
  adiciona_aresta(&g,1,2,2);
  imprime_grafo(&g);

}
