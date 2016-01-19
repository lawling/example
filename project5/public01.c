#include <stdio.h>
#include <assert.h>
#include "graph.h"
#include "memory-checking.h"

/* CMSC 216, Fall 2015, Project #5
 * Public test 1 (public01.c)
 *
 * Tests that calling clear_graph() on a graph with several vertices (but no
 * edges) frees all of the memory of the graph, and has no errors in the
 * heap.
 */

int main() {
  Graph graph;
  const char *vertices_to_add[]= {"koala", "platypus", "snake", "salamander",
                                  "gecko", "frog", "dog", "hedgehog"};
  int i;

  setup_memory_checking();

  init_graph(&graph);

  /* add some vertices */
  for (i= 0; i < sizeof(vertices_to_add) / sizeof(vertices_to_add[0]); i++)
    add_vertex(&graph, vertices_to_add[i]);

  /* now trash the whole thing */
  clear_graph(&graph);

  check_heap();

  /* if this is the only thing printed the heap must be valid, and there
   * must not have been any memory leaks
   */
  printf("Triumph!\n");

  return 0;
}
