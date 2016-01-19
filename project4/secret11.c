#include <stdio.h>
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2015, Project #4
 * Secret test 11 (secret11.c)
 *
 * Creates multiple graphs, to ensure that their data doesn't conflict.
 */

int main() {
  Graph graph1, graph2;
  const char *vertices_to_add1[]= {"hedgehog", "koala", "platypus"};
  const char *vertices_to_add2[]= {"orangutan", "jellyfish", "amoeba",
                                   "unicorn", "Venezuelan poodle moth"};
  int i, size;

  init_graph(&graph1);
  init_graph(&graph2);

  /* add some vertices to the first graph */
  for (i= 0; i < sizeof(vertices_to_add1) / sizeof(vertices_to_add1[0]); i++)
    add_vertex(&graph1, vertices_to_add1[i]);

  /* add some vertices to the second graph */
  for (i= 0; i < sizeof(vertices_to_add2) / sizeof(vertices_to_add2[0]); i++)
    add_vertex(&graph2, vertices_to_add2[i]);

  /* add some edges to the first graph */
  add_edge(&graph1, "hedgehog", "koala", 2);
  add_edge(&graph1, "hedgehog", "platypus", 3);
  add_edge(&graph1, "koala", "hedgehog", 4);
  add_edge(&graph1, "koala", "platypus", 5);
  add_edge(&graph1, "platypus", "hedgehog", 6);
  add_edge(&graph1, "platypus", "koala", 7);

  /* add some edges to the second graph */
  size= sizeof(vertices_to_add2) / sizeof(vertices_to_add2[0]);
  for (i= 0; i < size; i++)
    add_edge(&graph2, vertices_to_add2[i], vertices_to_add2[(i + 2) % size],
             i + 2);

  /* ensure that edges between the graphs can't be added */
  assert(add_edge(&graph1, "hedgehog", "Venezuelan poodle moth", 5) == 0);
  assert(add_edge(&graph1, "Venezuelan poodle moth", "platypus", 6) == 0);
  assert(add_edge(&graph2, "hedgehog", "Venezuelan poodle moth", 7) == 0);
  assert(add_edge(&graph2, "Venezuelan poodle moth", "platypus", 8) == 0);

  /* check the results */
  for (i= 0; i < sizeof(vertices_to_add1) / sizeof(vertices_to_add1[0]); i++)
    assert(num_neighbors(graph1, vertices_to_add1[i]) == 2);

  for (i= 0; i < sizeof(vertices_to_add2) / sizeof(vertices_to_add2[0]); i++)
    assert(num_neighbors(graph2, vertices_to_add2[i]) == 1);

  printf("Victory!\n");  /* all assertions succeeded */

  return 0;
}
