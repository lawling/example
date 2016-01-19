#include <stdio.h>
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2015, Project #4
 * Secret test 2 (secret02.c)
 *
 * Creates a graph with a large number of edges.
 */

#define NUM_VERTICES 500

int main() {
  Graph graph;
  char name[11], name2[11];
  int i, j;

  init_graph(&graph);

  /* create many vertices */
  for (i= 0; i < NUM_VERTICES; i++) {
    sprintf(name, "vertex%04d", i);
    add_vertex(&graph, name);
  }

  assert(num_vertices(graph) == NUM_VERTICES);

  /* create many edges; every vertex has an edge to every vertex */
  for (i= 0; i < NUM_VERTICES; i++)
    for (j= 0; j < NUM_VERTICES; j++) {
      sprintf(name, "vertex%04d", i);
      sprintf(name2, "vertex%04d", j);
      assert(add_edge(&graph, name, name2, i + j) == 1);
    }

  /* check the edges */  
  for (i= 0; i < NUM_VERTICES; i++) {
    sprintf(name, "vertex%04d", i);
    assert(num_neighbors(graph, name) == NUM_VERTICES);
  }

  printf("Victory!\n");  /* all assertions succeeded */

  return 0;
}
