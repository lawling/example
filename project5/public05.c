#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2015, Project #5
 * Public test 5 (public05.c)
 *
 * Tests calling get_neighbors() on a vertex with several neighbors.
 */

int main() {
  Graph graph;
  const char *vertices_to_add[]= {"koala", "platypus", "snake", "salamander",
                                  "gecko", "frog", "dog", "hedgehog"};
  const char *from[]= {"dog", "frog", "hedgehog", "hedgehog", "hedgehog",
                       "platypus", "platypus", "gecko", "snake", "snake"};
  const char *to[]= {"frog", "dog", "dog", "salamander", "koala", "koala",
                     "salamander", "frog", "salamander", "platypus"};
  const int costs[]= {2, 5, 9, 8, 7, 3, 1, 2, 10, 6};
  const char *expected_results[]= {"dog", "koala", "salamander"};
  char **names;
  int i;

  init_graph(&graph);

  /* add some vertices */
  for (i= 0; i < sizeof(vertices_to_add) / sizeof(vertices_to_add[0]); i++)
    add_vertex(&graph, vertices_to_add[i]);

  /* add some edges */
  for (i= 0; i < sizeof(from) / sizeof(from[0]); i++)
    add_edge(&graph, from[i], to[i], costs[i]);

  names= get_neighbors(graph, "hedgehog");

  /* check the neighbors against the results that we expect to be returned */
  i= 0;
  while (names[i] != NULL) {
    assert(strcmp(names[i], expected_results[i]) == 0);
    i++;
  }

  /* now clean up after ourselves */
  free_vertex_name_list(names);
  clear_graph(&graph);

  printf("Triumph!\n");  /* all assertions succeeded */

  return 0;
}
