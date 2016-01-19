#include <stdio.h>
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2015, Project #4
 * Secret test 13 (secret13.c)
 *
 * Tests calling some of the functions on an empty graph.
 */

int main() {
  Graph graph;

  init_graph(&graph);

  assert(has_vertex(graph, "Venezuelan poodle moth") == 0);
  assert(num_vertices(graph) == 0);
  assert(get_edge_cost(graph, "porcupine", "elephant") == -1);
  assert(num_neighbors(graph, "caterpillar") == -1);

  printf("Victory!\n");  /* all assertions succeeded */

  return 0;
}
