#include <stdio.h>
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2015, Project #4
 * Secret test 10 (secret10.c)
 *
 * Tests calling add_edge() with two vertices that already have an edge
 * between them.
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

  /* these edges already exist */
  assert(add_edge(&graph, "hedgehog", "quokka", 100) == 0);
  assert(add_edge(&graph, "numbat", "platypus", 6) == 0);

  printf("Victory!\n");  /* all assertions succeeded */

  return 0;
}
