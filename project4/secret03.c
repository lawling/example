#include <stdio.h>
#include <string.h>  /* for the memset() function */
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2015, Project #4
 * Secret test 3 (secret03.c)
 *
 * Adds some vertices with very long names to a graph.
 */

#define NAME_SZ 1234567
#define NUM_VERTICES 20

int main() {
  Graph graph;
  char ch= '\0', name[NAME_SZ + 1], name2[NAME_SZ + 1];
  int i;

  init_graph(&graph);

  /* create 20 vertices with really long names */
  for (i= 0; i < NUM_VERTICES; i++) {
    /* fill vertex names with the characters 'A' for the first vertex, 'B'
       for the second one, etc. */
    memset(name, (ch++ + 'A'), NAME_SZ);
    name[NAME_SZ]= '\0';

    add_vertex(&graph, name);
  }

  assert(num_vertices(graph) == NUM_VERTICES);

  /* add an edge from every vertex to the one with the next name, except for
   * the last one, which has an edge back to the first one
   */
  ch= '\0';
  for (i= 0; i < NUM_VERTICES; i++) {
    memset(name, ch + 'A', NAME_SZ);
    name[NAME_SZ]= '\0';

    ch= (ch + 1) % NUM_VERTICES;
    memset(name2, ch + 'A', NAME_SZ);
    name2[NAME_SZ]= '\0';

    assert(add_edge(&graph, name, name2, i * 3) == 1);
  }

  /* check the edges */
  ch= '\0';
  for (i= 0; i < NUM_VERTICES; i++) {
    memset(name, ch + 'A', NAME_SZ);
    name[NAME_SZ]= '\0';

    ch= (ch + 1) % NUM_VERTICES;
    memset(name2, ch + 'A', NAME_SZ);
    name2[NAME_SZ]= '\0';

    assert(num_neighbors(graph, name) == 1);
    assert(get_edge_cost(graph, name, name2) == i * 3);
  }

  printf("Victory!\n");  /* all assertions succeeded */

  return 0;
}
