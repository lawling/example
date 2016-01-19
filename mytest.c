#include <stdio.h>
#include <assert.h>
#include "graph.h"
#include<stdlib.h>
#include<string.h>
#include<time.h>
/* CMSC 216, Fall 2015, Project #4
 * Public test 10 (public10.c)
 *
 * Creates a larger graph and calls some of the functions on it.
 */

#define NUM_EDGES 50

   int
main ()
{
   Graph graph;
   char name[2] = "";
   char ch;
   int i;

   time_t t;


   char sources[NUM_EDGES][2];
   char destinations[NUM_EDGES][2];
   int costs[NUM_EDGES];
   int expected_neighbors[26] = {0};
   int j,cnt[26][26]= {{0}},k,m  ;
for(m = 0; m < 1000 ; m++)
   for(k = 0; k< 1000 ; k++){
/*reinitilized*/
for(i = 0; i < 26;i++){
expected_neighbors[i] = 0;
for(j = 0; j < 26 ;j++)
   cnt[i][j] = 0;
}






      srand ((unsigned) time (&t));
      for (i = 0; i < NUM_EDGES; i++)
      {
	 sources[i][0] = rand () % 26 + 'A';
	 sources[i][1] = '\0';
	 destinations[i][0] = rand () % 26 + 'A';
	 destinations[i][1] = '\0';
	 costs[i] = rand () % 100;

      }
      

      init_graph (&graph);

      /* add 26 vertices */
      for (ch = 'A'; ch <= 'Z'; ch++)
      {
	 name[0] = ch;
	 add_vertex (&graph, name);
      }

      assert (num_vertices (graph) == 26);
      /*print vertex */

      /* add 50 edges */
      for (i = 0; i < NUM_EDGES; i++)
	 assert (add_edge (&graph, sources[i], destinations[i], costs[i]) == 1);

      for(i =  0; i < NUM_EDGES; i++){
	 cnt[sources[i][0]-'A'][destinations[i][0]-'A']++;
	 expected_neighbors[sources[i][0]-'A']++;

	 if(cnt[sources[i][0]-'A'][destinations[i][0]-'A'] > 1){

		  expected_neighbors[sources[i][0]-'A']--;
		  cnt[sources[i][0]-'A'][destinations[i][0]-'A'] = 1;

	    for(j = 0; j < i ; j ++)
	       if( (!strcmp(sources[i],sources[j]))&&
		     (!strcmp(destinations[i],destinations[j]) ) ){
		  costs[j] = costs[i];
	       }


	 }
}
      /* check the edges */
      for (i = 0; i < NUM_EDGES; i++)
      {
	 assert (get_edge_cost (graph, sources[i], destinations[i]) == costs[i]);
      }
      /* change the edge costs */
      for (i = 0; i < NUM_EDGES; i++)
	 assert (change_edge_cost (&graph, sources[i], destinations[i],
		  costs[i] * 2) == 1);

      /* check the edge costs now */
      for (i = 0; i < NUM_EDGES; i++)
	 assert (get_edge_cost (graph, sources[i], destinations[i]) ==
	       costs[i] * 2);

      /* check the number of neighbors that each vertex has */
      for (ch = 'A'; ch <= 'Z'; ch++)
      {
	 name[0] = ch;

	 assert (num_neighbors (graph, name) == expected_neighbors[ch - 'A']);
      }

      printf (" the %d*%d th Victory!\n",m,k);	/* all assertions succeeded */
   }
   return 0;
}
