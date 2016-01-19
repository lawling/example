#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2015, Project #4
 * Public test 5 (public05.c)
 *
 * Tests the return value of add_edge() with both positive and negative
 * weight edges.
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

  assert(add_edge(&graph, "hedgehog", "kangaroo", 8) == 1);
  assert(add_edge(&graph, "koala", "quokka", 2) == 1);
  assert(add_edge(&graph, "numbat", "platypus", -10) == 0);
 
  printf("Victory!\n");  /* all assertions succeeded */

  return 0;
}
