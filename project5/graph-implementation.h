/****************************************
  This file is written by Yuan Liang 
  for project4 cmsc216

  use linked list to store vetex of graph
 *****************************************/
#ifndef GRAPH_IMPLMENTATION_H
#define GRAPH_IMPLMENTATION_H
#include<stddef.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct node_t node_t;
typedef struct edge_t edge_t;
typedef struct vertex_t vertex_t;
/*use linked list to store vertices*/
typedef vertex_t data_t;

struct node_t {
	data_t *data;
	node_t *next;
};


/*structs used for implement directional graph*/
struct vertex_t {
	char *name;
	edge_t **edges;
	int num_edges, cap_edges;
};

struct edge_t {
	int cost;
	char *source;
	char *dest;
};

typedef struct Graph {
	/*I will use linked list to store vertex */
	node_t *vertices;
	int num_vertices;

} Graph;
/*end structs*/
#endif
