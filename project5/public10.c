#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "graph.h"
#include "name-list-to-string.h"
#include "memory-checking.h"

/* CMSC 216, Fall 2015, Project #5
 * Public test 10 (public10.c)
 *
 * Tests that there are no memory leaks or errors in the heap after some
 * vertices and edges are removed from a graph, then new ones are added.
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
  const char *new_edges_from[]= {"chicken", "chicken", "elephant", "elephant",
                                 "hippopotamus", "hippopotamus",
                                 "hippopotamus", "cow", "cow", "goat", "goat",
                                 "mule", "mule", "mule"};
  const char *new_edges_to[]= {"goose", "turkey", "hippopotamus", "mule",
                               "cow", "horse", "goat", "horse", "elephant",
                               "horse", "lamb", "lamb", "hippopotamus",
                               "elephant"};
  const char *final_vertices[]= {"chicken", "cow", "elephant", "goat",
                                 "hippopotamus", "horse", "lamb", "mule",
                                 "turkey"};
  const char *final_neighbors[]= {
    "cow lamb mule turkey",                     /* neighbors of chicken */
    "chicken elephant horse turkey",            /* neighbors of cow */
    "hippopotamus mule",                        /* neighbors of elephant */
    "cow horse lamb mule turkey",               /* neighbors of goat */
    "cow goat horse",                           /* neighbors of hippopotamus */
    "turkey",                                   /* neighbors of horse */
    "chicken goat horse lamb mule turkey",      /* neighbors of lamb */
    "cow elephant hippopotamus horse lamb turkey",  /* neighbors of mule */
    "cow"                                       /* neighbors of turkey */
  };
  char **names, **names2;
  char neighbors_str[MAX_LEN + 1];
  int i;

  setup_memory_checking();

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

  /* remove some vertices */
  remove_vertex(&graph, "donkey");
  remove_vertex(&graph, "goose");

  /* now add some new vertices */
  add_vertex(&graph, "elephant");
  add_vertex(&graph, "hippopotamus");

  /* now add some new edges */
  for (i= 0; i < sizeof(new_edges_from) / sizeof(new_edges_from[0]); i++)
    add_edge(&graph, new_edges_from[i], new_edges_to[i], i + 20);

  /* now check the final vertices against the results that we expect */
  assert(num_vertices(graph) == 9);
  names= get_vertices(graph);
  i= 0;
  while (names[i] != NULL) {
    assert(strcmp(names[i], final_vertices[i]) == 0);
    i++;
  }

  /* now check the final neighbors of all vertices */
  i= 0;
  while (names[i] != NULL) {
    names2= get_neighbors(graph, names[i]);
    name_list_to_string(names2, neighbors_str);
    assert(strcmp(neighbors_str, final_neighbors[i++]) == 0);
    free_vertex_name_list(names2);
  }

  /* now clean up after ourselves */
  free_vertex_name_list(names);
  clear_graph(&graph);

  check_heap();

  printf("Triumph!\n");  /* all assertions succeeded, and the heap must be OK */

  return 0;
}
