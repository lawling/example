#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2015, Project #4
 * Public test 4 (public04.c)
 *
 * Tests calling get_edge_cost() on some edges that have been added to a
 * graph.
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

  add_edge(&graph, "hedgehog", "kangaroo", 8);
  add_edge(&graph, "koala", "quokka", 2);
  add_edge(&graph, "numbat", "platypus", 6);
  add_edge(&graph, "koala", "numbat", 10);
  add_edge(&graph, "hedgehog", "quokka", 1);
  add_edge(&graph, "platypus", "koala", 7);
  add_edge(&graph, "hedgehog", "hedgehog", 9);

  assert(get_edge_cost(graph, "hedgehog", "kangaroo") == 8);
  assert(get_edge_cost(graph, "numbat", "platypus") == 6);
  assert(get_edge_cost(graph, "platypus", "koala") == 7);
  assert(get_edge_cost(graph, "hedgehog", "hedgehog") == 9);

  printf("Victory!\n");  /* all assertions succeeded */

  return 0;
}
