#include <stdio.h>
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2015, Project #4
 * Secret test 5 (secret05.c)
 *
 * Tests that vertex names are being correctly compared when vertices are
 * added and looked up using is_vertex().
 */

int main() {
  Graph graph;
  const char *vertices_to_add[]= {"caterpillar", "porcupine", "elephant"};
  int i;

  init_graph(&graph);

  /* add some vertices */
  for (i= 0; i < sizeof(vertices_to_add) / sizeof(vertices_to_add[0]); i++)
    add_vertex(&graph, vertices_to_add[i]);

  /* these are not names of existing vertices */
  assert(has_vertex(graph, "Caterpillar") == 0);
  assert(has_vertex(graph, "ELEPHANT") == 0);
  assert(has_vertex(graph, "cat") == 0);
  assert(has_vertex(graph, "cup") == 0);
  assert(has_vertex(graph, "ant") == 0);

  printf("Victory!\n");  /* all assertions succeeded */

  return 0;
}
