#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#define MAX 10

typedef struct grafo {
  int total_vertices;      /* Número de vertices*/
  int **mat;  /* Matriz (a ser alocada dinamicamente) */
  int peso;
} Grafo;

void cria_grafo(Grafo* g, int vertices);
void imprime_grafo(Grafo *g);
void dijkstra(int G[MAX][MAX],int n,int startnode);


#endif // GRAFO_H_INCLUDED
