#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2015, Project #5
 * Public test 9 (public09.c)
 *
 * Tests removing a vertex and several edges from a graph.
 */

int main() {
  Graph graph;
  const char *vertices[]= {"horse", "cow", "chicken", "turkey", "lamb", "goat",
                           "donkey", "goose", "mule"};
  const char *from[]= {"cow", "cow", "cow", "cow",
                       "lamb", "lamb", "lamb", "lamb", "lamb", "lamb", "lamb",
                       "mule", "mule", "mule", "mule",
                       "donkey", "donkey", "donkey", "donkey",
                       "turkey",
                       "horse", "horse",
                       "chicken", "chicken", "chicken", "chicken",
                       "goat", "goat", "goat", "goat", "goat"};
  const char *to[]= {"lamb", "turkey", "chicken", "goat",
                     "mule", "turkey", "goat", "horse", "lamb", "chicken",
                       "goose",
                     "turkey", "horse", "goat", "cow",
                     "mule", "goose", "cow", "chicken", 
                     "cow",
                     "goose", "turkey",
                     "lamb", "cow", "horse", "mule",
                     "cow", "goose", "turkey", "horse", "mule"};
  const int costs[]= {9, 3, 4, 10, 4, 15, 3, 18, 7, 5, 21, 1, 12, 5, 30, 17,
                      14, 21, 8, 29, 15, 27, 3, 1, 5, 1, 8, 15, 26, 10, 9};
  const char *remaining_vertices[]= {"chicken", "cow", "goat", "goose",
                                     "horse", "lamb", "mule", "turkey"};
  char **names;
  int i;

  init_graph(&graph);

  /* add some vertices */
  for (i= 0; i < sizeof(vertices) / sizeof(vertices[0]); i++)
    add_vertex(&graph, vertices[i]);

  /* add some edges */
  for (i= 0; i < sizeof(from) / sizeof(from[0]); i++)
    add_edge(&graph, from[i], to[i], costs[i]);

  /* remove some edges */
  remove_edge(&graph, "chicken", "horse");
  remove_edge(&graph, "cow", "goat");
  remove_edge(&graph, "cow", "lamb");
  remove_edge(&graph, "goat", "horse");
  remove_edge(&graph, "mule", "goat");

  /* remove a vertex */
  remove_vertex(&graph, "donkey");

  /* check the remaining vertices against the results that we expect */
  assert(num_vertices(graph) == 8);
  names= get_vertices(graph);
  i= 0;
  while (names[i] != NULL) {
    assert(strcmp(names[i], remaining_vertices[i]) == 0);
    i++;
  }

  /* check the current edges of the vertices that we removed some edges from */
  assert(num_neighbors(graph, "chicken") == 3);
  assert(num_neighbors(graph, "cow") == 2);
  assert(num_neighbors(graph, "goat") == 4);
  assert(num_neighbors(graph, "mule") == 3);

  /* now clean up after ourselves */
  free_vertex_name_list(names);
  clear_graph(&graph);

  printf("Triumph!\n");  /* all assertions succeeded */

  return 0;
}
