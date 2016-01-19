#include <stdio.h>
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2015, Project #4
 * Secret test 1 (secret01.c)
 *
 * Creates a graph with a large number of vertices.
 */

#define NUM_VERTICES 1234

int main() {
  Graph graph;
  char name[12];
  int i;

  init_graph(&graph);

  /* create many vertices */
  for (i= 0; i < NUM_VERTICES; i++) {
    printf("i = %d\n",i);
    sprintf(name, "vertex%05d", i);
    add_vertex(&graph, name);
  }

  assert(num_vertices(graph) == NUM_VERTICES);

  printf("Victory!\n");  /* the assertion succeeded */

  return 0;
}
