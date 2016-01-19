#include <stdio.h>
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2015, Project #4
 * Secret test 14 (secret14.c)
 *
 * Tests calling some of the functions passing NULL into character array
 * parameters.
 */

int main() {
  Graph graph;
  const char *vertices_to_add[]= {"orangutan", "jellyfish", "amoeba",
                                  "unicorn", "Indian purple frog"};
  int i, j, size= sizeof(vertices_to_add) / sizeof(vertices_to_add[0]);

  init_graph(&graph);

  /* add some vertices */
  for (i= 0; i < size; i++)
    add_vertex(&graph, vertices_to_add[i]);

  /* add some edges */
  for (i= 0; i < size; i++)
    for (j= 0; j < size; j++)
      add_edge(&graph, vertices_to_add[i], vertices_to_add[j], (i * 10) + j);

  /* pass NULL into all functions that take character arrays as arguments */
  assert(add_vertex(&graph, NULL) == 0);
  assert(has_vertex(graph, NULL) == 0);
  assert(add_edge(&graph, NULL, "jellyfish", 2) == 0);
  assert(add_edge(&graph, "eel", NULL, 3) == 0);
  assert(get_edge_cost(graph, NULL, "Indian purple frog") == -1);
  assert(get_edge_cost(graph, "unicorn", NULL) == -1);
  assert(change_edge_cost(&graph, NULL, "Indian purple frog", 17) == 0);
  assert(change_edge_cost(&graph, "unicorn", NULL, 53) == 0);
  assert(num_neighbors(graph, NULL) == -1);

  /* check that nothing in the graph changed */
  assert(num_vertices(graph) == 5);

  for (i= 0; i < size; i++)
    assert(has_vertex(graph, vertices_to_add[i]));

  for (i= 0; i < size; i++)
    for (j= 0; j < size; j++)
      assert(get_edge_cost(graph, vertices_to_add[i], vertices_to_add[j]) ==
                           (i * 10) + j);

  printf("Victory!\n");  /* all assertions succeeded */

  return 0;
}
