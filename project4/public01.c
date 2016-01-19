#include <stdio.h>
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2015, Project #4
 * Public test 1 (public01.c)
 *
 * Tests initializing a graph and calling num_vertices() before any
 * vertices have been added, and after a few vertices have been added.
 */

int main() {
  Graph graph;

  init_graph(&graph);

  assert(num_vertices(graph) == 0);

  printf("Victory!\n");  /* the assertion succeeded */

  return 0;
}
