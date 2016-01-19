#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "graph.h"
#include "memory-checking.h"

/* CMSC 216, Fall 2015, Project #5
 * Public test 4 (public04.c)
 *
 * Tests calling free_vertex_names() on the list of vertices returned by
 * get_vertices(), to ensure that all of the memory is properly freed and
 * there are no errors in the heap.  (This is the same as the previous test
 * except for freeing the list of neighbors, and checking the consistency
 * and correctness of the heap afterwards.)
 */

int main() {
  Graph graph;
  const char *vertices_to_add[]= {"koala", "quokka", "platypus", "zebra",
                                  "hedgehog", "dog", "frog"};
  const char *expected_results[]= {"dog", "frog", "hedgehog", "koala",
                                   "platypus", "quokka", "zebra"};
  char **names;
  int i;

  setup_memory_checking();

  init_graph(&graph);

  /* add some vertices */
  for (i= 0; i < sizeof(vertices_to_add) / sizeof(vertices_to_add[0]); i++)
    add_vertex(&graph, vertices_to_add[i]);

  names= get_vertices(graph);

  /* check the vertices against the results that we expect to be returned */
  i= 0;
  while (names[i] != NULL) {
    assert(strcmp(names[i], expected_results[i]) == 0);
    i++;
  }

  /* now clean up after ourselves */
  free_vertex_name_list(names);
  clear_graph(&graph);

  check_heap();

  /* if this is the only thing printed the heap must be valid, and there
   * must not have been any memory leaks
   */
  printf("Triumph!\n");  /* all assertions succeeded */

  return 0;
}
