#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
typedef struct grafo {
  int total_vertices;      /* Número de vertices*/
  int **mat;  /* Matriz (a ser alocada dinamicamente) */
  int peso;
} Grafo;

void cria_grafo(Grafo* g, int vertices);
void adiciona_aresta(Grafo *g, int vertice1, int vertice2, int peso);
void melhor_caminho(Grafo *g);

#endif // GRAFO_H_INCLUDED
