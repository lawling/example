#include <stdio.h>
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2015, Project #4
 * Secret test 6 (secret06.c)
 *
 * Tests that vertex names are being correctly compared when edges are added
 * and looked up using get_edge_cost() and in change_edge_cost().  This also
 * tests calling add_edge() and get_edge_cost() with nonexistent source and
 * destination vertices.
 */

int main() {
  Graph graph;
  const char *vertices_to_add[]= {"caterpillar", "porcupine", "elephant"};
  int i, j, size= sizeof(vertices_to_add) / sizeof(vertices_to_add[0]);

  init_graph(&graph);

  /* add some vertices */
  for (i= 0; i < size; i++)
    add_vertex(&graph, vertices_to_add[i]);

  /* add some edges */
  for (i= 0; i < size; i++)
    for (j= 0; j < size; j++)
      add_edge(&graph, vertices_to_add[i], vertices_to_add[j], (i * 10) + j);

  /* these are not names of existing vertices */
  assert(get_edge_cost(graph, "Caterpillar", "porcupine") == -1);
  assert(get_edge_cost(graph, "porcupine", "Caterpillar") == -1);
  assert(get_edge_cost(graph, "ELEPHANT", "caterpillar") == -1);
  assert(get_edge_cost(graph, "caterpillar", "ELEPHANT") == -1);
  assert(get_edge_cost(graph, "cat", "ant") == -1);
  assert(get_edge_cost(graph, "ant", "cat") == -1);
  assert(get_edge_cost(graph, "cup", "cat") == -1);
  assert(get_edge_cost(graph, "cat", "cup") == -1);

  assert(change_edge_cost(&graph, "Caterpillar", "porcupine", 100) == 0);
  assert(change_edge_cost(&graph, "porcupine", "Caterpillar", 101) == 0);
  assert(change_edge_cost(&graph, "ELEPHANT", "caterpillar", 102) == 0);
  assert(change_edge_cost(&graph, "caterpillar", "ELEPHANT", 103) == 0);
  assert(change_edge_cost(&graph, "cat", "ant", 104) == 0);
  assert(change_edge_cost(&graph, "ant", "cat", 105) == 0);
  assert(change_edge_cost(&graph, "cup", "cat", 106) == 0);
  assert(change_edge_cost(&graph, "cat", "cup", 107) == 0);

  for (i= 0; i < size; i++)
    for (j= 0; j < size; j++)
      assert(get_edge_cost(graph, vertices_to_add[i], vertices_to_add[j]) ==
             (i * 10) + j);

  printf("Victory!\n");  /* all assertions succeeded */

  return 0;
}
