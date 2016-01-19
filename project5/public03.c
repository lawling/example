#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2015, Project #5
 * Public test 3 (public03.c)
 *
 * Tests calling get_vertices() on a graph with several vertices.
 */

int main() {
  Graph graph;
  const char *vertices_to_add[]= {"koala", "quokka", "platypus", "zebra",
                                  "hedgehog", "dog", "frog"};
  const char *expected_results[]= {"dog", "frog", "hedgehog", "koala",
                                   "platypus", "quokka", "zebra"};
  char **names;
  int i;

  init_graph(&graph);

  /* add some vertices */
  for (i= 0; i < sizeof(vertices_to_add) / sizeof(vertices_to_add[0]); i++)
    add_vertex(&graph, vertices_to_add[i]);

  names= get_vertices(graph);

  /* check the vertices against the results that we expect to be returned */
  i= 0;
  while (names[i] != NULL) {
    assert(strcmp(names[i], expected_results[i]) == 0);
    i++;
  }

  clear_graph(&graph);

  printf("Triumph!\n");  /* all assertions succeeded */

  return 0;
}
