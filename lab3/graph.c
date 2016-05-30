#include "graph.h"


struct graph *graph_init()
{
    struct graph *g;
    g = malloc(sizeof(*g));
    g->h = malloc(sizeof(int) * (VERTICES + 1));
    g->matrix = (int **) malloc(VERTICES * sizeof(int *));
    if (g->matrix != NULL) {
        for (int i = 0; i < VERTICES; i++) {
            g->matrix[i] = (int *) malloc(VERTICES * sizeof(int));
        }
    }
    else {
        printf("Error of memory allocation!\n");
    }

    for (int i = 0; i < VERTICES; i++) 
    {
       g->h[i] = 0;
       for (int j = 0; j < VERTICES; j++) 
       {
           g->matrix[i][j] = 0;
       }
    }
    return g;
}

void graph_free(struct graph *g)
{
    for (int i = 0; i < VERTICES; i++)
	free(g->matrix[i]);
    free(g->matrix);
    free(g);
}

void graph_set_edge(struct graph *g, int i, int j, int weight)
{
    g->matrix[i - 1][j - 1] = weight;
    g->matrix[j - 1][i - 1] = weight;
}

int graph_get_edge(struct graph *g, int i, int j)
{
    return g->matrix[i - 1][j - 1];
}

struct graph_map *Search_Shortest_Path(struct graph *g, int src, int dest)
{
    int *prev = malloc((VERTICES + 1) * sizeof(int));
    int *d = malloc((VERTICES + 1) * sizeof(int));
    
    ShortestPath_Dijekstra(g, src, d, prev);
    
    struct graph_map *p;
    p = malloc(sizeof(*p));
    
    int i = dest;
    
    p->len = d[dest];
    int length = 0;
    while (i != src) 
    {
	   i = prev[i];
	   length++;
    }
    p->edge = length;
    
    p->path = calloc(length , sizeof(int));
    i = dest;
    int j = length;
    
    while(i != src) 
    {
	   p->path[j] = i;
	   i = prev[i];
	   j--;
    }
    p->path[j] = src;
    free(prev);
    free(d);

    return p;
}

void ShortestPath_Dijekstra(struct graph *g, int src, int *d, int *prev)
{
    struct heap *pqueue;
    pqueue = heap_create(VERTICES);
    
    int v;
    
    for (v = 1; v <= VERTICES; v++) 
    {
	   if (v != src) 
       {
	       g->h[v] = 0;
           d[v] = INT_MAX;
	       prev[v] = -1;
	       heap_insert(pqueue, d[v], v);
       }
    }
    
    d[src] = 0;
    prev[src] = -1;
    g->h[src] = 0;
    heap_insert(pqueue, d[src], src);
    
    struct heapnode node;
    int tmp;
    for (v = 1; v <= VERTICES; v++) 
    {
	   node = heap_extract_min(pqueue);
	   tmp = node.value;
	   g->h[tmp] = 1;
	   for (int u  = 1; u <= VERTICES; u++) 
        {
	    
	       int way = graph_get_edge(g, tmp, u);
	       if ((way != 0) && (g->h[u] != 1)) 
            {
		      if (d[tmp] + way < d[u]) 
                {
                    d[u] = d[tmp] + way;
                    heap_decrease_key(pqueue, u, d[u]);
                    prev[u] = tmp;
                }
            }
	    }
    }
}
