#include <stdio.h>
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2015, Project #4
 * Public test 2 (public02.c)
 *
 * Tests calling has_vertex() on some nonexistent vertices and some vertices
 * that are present in a graph.
 */

int main() {
  Graph graph;

  init_graph(&graph);

  add_vertex(&graph, "hedgehog");
  add_vertex(&graph, "koala");
  add_vertex(&graph, "platypus");
  add_vertex(&graph, "kangaroo");
  add_vertex(&graph, "elephant");
  add_vertex(&graph, "naked mole rat");

  assert(has_vertex(graph, "hedgehog") == 1);
  assert(has_vertex(graph, "platypus") == 1);
  assert(has_vertex(graph, "elephant") == 1);
  assert(has_vertex(graph, "naked mole rat") == 1);

  assert(has_vertex(graph, "deer") == 0);
  assert(has_vertex(graph, "rabbit") == 0);

  printf("Victory!\n");  /* all assertions succeeded */

  return 0;
}
