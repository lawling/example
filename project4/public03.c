#include <stdio.h>
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2015, Project #4
 * Public test 3 (public03.c)
 *
 * Tests the return value of add_vertex() when a new vertex is successfully
 * added, and when it's called on the names of already existing vertices.
 */

int main() {
  Graph graph;

  init_graph(&graph);

  assert(add_vertex(&graph, "koala") == 1);
  assert(add_vertex(&graph, "quokka") == 1);
  assert(add_vertex(&graph, "platypus") == 1);

  assert(add_vertex(&graph, "koala") == 0);
  assert(add_vertex(&graph, "quokka") == 0);
  assert(add_vertex(&graph, "platypus") == 0);

  printf("Victory!\n");  /* all assertions succeeded */

  return 0;
}
