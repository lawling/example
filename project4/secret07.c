#include <stdio.h>
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2015, Project #4
 * Secret test 7 (secret07.c)
 *
 * Tests that edges are being properly added- adds edges in both directions
 * between two vertices, adds different outgoing edges with the same cost
 * going from a vertex to different neighbors, and checks that adding an
 * outgoing edge from a vertex does not cause an incoming edge to be added
 * as well.
 */

int main() {
  Graph graph;
  const char *vertices_to_add[]= {"hedgehog", "koala", "platypus", "kangaroo",
                                  "quokka", "numbat"};
  int expected_neighbors[]= {3, 0, 1, 1, 0, 0};
  int i;

  init_graph(&graph);

  /* add some vertices */
  for (i= 0; i < sizeof(vertices_to_add) / sizeof(vertices_to_add[0]); i++)
    add_vertex(&graph, vertices_to_add[i]);

  /* add a pair of edges in both directions between two vertices */
  add_edge(&graph, "hedgehog", "kangaroo", 8);
  add_edge(&graph, "kangaroo", "hedgehog", 2);

  /* add multiple outgoing edges from the same vertex with the same cost */
  add_edge(&graph, "hedgehog", "platypus", 8);
  add_edge(&graph, "hedgehog", "numbat", 8);

  /* used to check that adding an edge does not add the symmetric edge */
  add_edge(&graph, "platypus", "koala", 7);

  /* check the results */
  for (i= 0; i < sizeof(vertices_to_add) / sizeof(vertices_to_add[0]); i++)
    assert(num_neighbors(graph, vertices_to_add[i]) == expected_neighbors[i]);

  assert(get_edge_cost(graph, "hedgehog", "kangaroo") == 8);
  assert(get_edge_cost(graph, "kangaroo", "hedgehog") == 2);

  assert(get_edge_cost(graph, "hedgehog", "platypus") == 8);
  assert(get_edge_cost(graph, "hedgehog", "numbat") == 8);

  assert(get_edge_cost(graph, "koala", "platypus") == -1);

  printf("Victory!\n");  /* all assertions succeeded */

  return 0;
}
