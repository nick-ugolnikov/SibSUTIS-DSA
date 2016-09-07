#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <limits.h>

#include "queue.h"
#include "bheap.h"

#define VERTICES 20

struct graph_map 
{
    int len;
    int edge;
    int *path;
};

struct graph 
{
    int **matrix;
    int *h;
};

struct graph *graph_init();
void graph_free(struct graph *g);
void graph_set_edge(struct graph *g, int i, int j, int weight);
int graph_get_edge(struct graph *g, int i, int j);
struct graph_map *Search_Shortest_Path(struct graph *g, int src, int dest);
void ShortestPath_Dijekstra(struct graph *g, int src, int *d, int *prev);

#endif
