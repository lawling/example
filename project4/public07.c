#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2015, Project #4
 * Public test 7 (public07.c)
 *
 * Tests calling change_edge_cost() on some edges that have been added to a
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

  change_edge_cost(&graph, "koala", "numbat", 100);
  change_edge_cost(&graph, "platypus", "koala", 400);
  change_edge_cost(&graph, "hedgehog", "kangaroo", 200);
  change_edge_cost(&graph, "hedgehog", "hedgehog", 300);

  assert(get_edge_cost(graph, "koala", "numbat") == 100);
  assert(get_edge_cost(graph, "platypus", "koala") == 400);
  assert(get_edge_cost(graph, "hedgehog", "kangaroo") == 200);
  assert(get_edge_cost(graph, "hedgehog", "hedgehog") == 300);

  printf("Victory!\n");  /* all assertions succeeded */

  return 0;
}
