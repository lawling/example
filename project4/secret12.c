#include <stdio.h>
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2015, Project #4
 * Secret test 12 (secret12.c)
 *
 * Tests calling num_neighbors() on a nonexistent vertex.
 */

int main() {
  Graph graph;
  const char *vertices_to_add[]= {"caterpillar", "porcupine", "elephant"};
  int i;

  init_graph(&graph);

  /* add some vertices */
  for (i= 0; i < sizeof(vertices_to_add) / sizeof(vertices_to_add[0]); i++)
    add_vertex(&graph, vertices_to_add[i]);

  assert(num_neighbors(graph, "Venezuelan poodle moth") == -1);

  printf("Victory!\n");  /* the assertion succeeded */

  return 0;
}
