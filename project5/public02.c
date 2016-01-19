#include <stdio.h>
#include <assert.h>
#include "graph.h"
#include "memory-checking.h"

/* CMSC 216, Fall 2015, Project #5
 * Public test 2 (public02.c)
 *
 * Tests that calling clear_graph() on a graph with several vertices and
 * edges frees all of the memory of the graph, and has no errors in the
 * heap.
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
  int i;

  setup_memory_checking();

  init_graph(&graph);

  /* add some vertices */
  for (i= 0; i < sizeof(vertices_to_add) / sizeof(vertices_to_add[0]); i++)
    add_vertex(&graph, vertices_to_add[i]);

  /* add some edges */
  for (i= 0; i < sizeof(from) / sizeof(from[0]); i++)
    add_edge(&graph, from[i], to[i], costs[i]);

  /* now nuke the whole thing */
  clear_graph(&graph);

  check_heap();

  /* if this is the only thing printed the heap must be valid, and there
   * must not have been any memory leaks
   */
  printf("Triumph!\n");

  return 0;
}
