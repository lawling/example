#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2015, Project #5
 * Public test 8 (public08.c)
 *
 * Tests using remove_vertex() to remove all of the vertices from a
 * graph.
 */

int main() {
  Graph graph;
  const char *vertices_to_add[]= {"koala", "quokka", "platypus", "zebra",
                                  "hedgehog", "dog", "frog"};
  int i;

  init_graph(&graph);

  /* add some vertices */
  for (i= 0; i < sizeof(vertices_to_add) / sizeof(vertices_to_add[0]); i++)
    add_vertex(&graph, vertices_to_add[i]);

  /* now remove all of the vertices */
  for (i= 0; i < sizeof(vertices_to_add) / sizeof(vertices_to_add[0]); i++)
    remove_vertex(&graph, vertices_to_add[i]);

  assert(num_vertices(graph) == 0);

  /* there should be no need to clear the graph here; everything is gone */

  printf("Triumph!\n");  /* the assertion succeeded */

  return 0;
}
