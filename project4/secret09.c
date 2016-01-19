#include <stdio.h>
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2015, Project #4
 * Secret test 9 (secret09.c)
 *
 * Tests that add_edge() and change_edge_cost() allow zero-weight edges.
 */

int main() {
  Graph graph;

  init_graph(&graph);

  add_vertex(&graph, "hedgehog");
  add_vertex(&graph, "koala");
  add_vertex(&graph, "platypus");
  add_vertex(&graph, "kangaroo");
  add_vertex(&graph, "quokka");
  add_vertex(&graph, "numbat");

  add_edge(&graph, "hedgehog", "quokka", 1);
  add_edge(&graph, "platypus", "koala", 7);

  assert(add_edge(&graph, "hedgehog", "kangaroo", 0) == 1);
  assert(add_edge(&graph, "numbat", "platypus", 0) == 1);

  assert(change_edge_cost(&graph, "hedgehog", "quokka", 0) == 1);
  assert(change_edge_cost(&graph, "platypus", "koala", 0) == 1);

  assert(get_edge_cost(graph, "hedgehog", "kangaroo") == 0);
  assert(get_edge_cost(graph, "numbat", "platypus") == 0);
  assert(get_edge_cost(graph, "hedgehog", "quokka") == 0);
  assert(get_edge_cost(graph, "platypus", "koala") == 0);

  printf("Victory!\n");  /* all assertions succeeded */

  return 0;
}
