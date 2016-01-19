/****************************************
  This file is written by Yuan Liang 
  for project4 cmsc216

  add dellocation functions for project 5

  use linked list to store vetex of graph
 *****************************************/
#include"./graph.h"
#include"./graph-implementation.h"
#define UNUSED(x) ((void*)x)
/*healper functions declarations*/
static data_t *index_v(node_t * head, int idx);
static int addNode(node_t ** head, data_t * data);
static int greater(const void *a,const  void *b);	/*function for sorting strings */
static int dataDeleter(data_t * data);	/*it should be changed if data_t changed */
static int deleteNode(node_t ** head, int idx,
      int (*deleter) (data_t *));
static int findVertexByName(node_t * vertices, const char name[]);
static int findEdgeBySourceNDest(edge_t ** edges,
      int size,
      const char
      source[], const char dest[]);
/*static void clear_edges_to_neighbors(Graph * graph, char vertex[]);*/

/*declarations end*/
/*The following are linked list function*/
/*index the linked list*/
static data_t *index_v(node_t * head, int idx)
{
   int i = 0;
   if (head == NULL)
      return NULL;

   if (idx < 0)
      return NULL;

   while (i < idx) {

      head = head->next;
      if (head == NULL) {

	 return NULL;
      }
      i++;
   }

   return head->data;
}

/*a helper function to add node to linked list*/
static int addNode(node_t ** head, data_t * data)
{
   node_t *n, *t;

   if (head == NULL)
      return -1;

   n = malloc(sizeof(node_t));
   if (n == NULL)
      return -1;
   n->data = data;
   n->next = NULL;

   if (*head != NULL) {
      t = *head;
      while (t->next != NULL)
	 t = t->next;

      t->next = n;
   } else
      *head = n;

   return 1;
}

/*a helper function to delete node to linked list*/
static int dataDeleter(data_t * data)
{
   /*maybe changed for deleting data_t*/
   int i;
   if (data == NULL)
      return -1;

   for (i = 0; i < data->num_edges; i++) {
      free( (data->edges)[i]->source);
      free( (data->edges)[i]->dest);
      free((data->edges)[i]);
   }
   free(data->edges);
   free(data->name);
   free(data);
   /*do nothing if data points to static memory*/
   /*UNUSED(data); */
   return 1;
}

static int deleteNode(node_t ** head, int idx,
      int (*deleter) (data_t *))
{
  
   node_t  *p,*c;
   int i,e_idx;
   if (head == NULL)
      return -1;
   

   p = *head;
   if (*head != NULL)
      c = (*head)->next;
   else
      return -1;

   if (idx == 0) {
      (*head) = (*head)->next;
      (deleter) (p->data);
      free(p);

   }else{
      for(i = 0; i < (idx-1);i++){
            c = c->next;
            p = p->next;

}
      (deleter)(c->data);
      p->next = p->next->next;
      free(c);
   }

   return 1;

}

/*helper functions for access vertices and edges*/

/*paramenters: array of vertex_t, name of vertex*/
/*return index_v of vertex has name in array, unfound return -1*/
static int findVertexByName(node_t * vertices, const char name[])
{

   int i = 0;
   if (vertices == NULL)
      return -1;

   while (index_v(vertices, i) != NULL) {
      if (!strcmp(index_v(vertices, i)->name, name))
	 return i;
      i++;
   }
   return -1;
}

/*paramenters: array of edge_t, name of des*/
/*return index_v of edge has name in array, unfound return -1*/

   static int
findEdgeBySourceNDest(edge_t ** edges, int size,
      const char source[], const char dest[])
{
   int i;
   for (i = 0; i < size; i++)
      if ((!strcmp(edges[i]->dest, dest))
	    && (!strcmp(edges[i]->source, source)))
	 return i;

   return -1;
}

/*helper functions end*/

/*graph functions*/
void init_graph(Graph * graph)
{
   if (graph == NULL)
      return;

   graph->num_vertices = 0;
   graph->vertices = NULL;

   return;

}

int add_vertex(Graph * graph, const char new_vertex[])
{

   data_t *data;

   if (graph == NULL)
      return 0;

   if (findVertexByName(graph->vertices, new_vertex) >= 0)
      return 0;

   /*initialize a new data */

   data = malloc(sizeof(vertex_t));
   if (data == NULL)
      return 0;

   data->name = malloc(sizeof(char) * (strlen(new_vertex) + 1));
   strcpy(data->name, new_vertex);
   data->cap_edges = 10;

   data->edges = malloc(sizeof(edge_t *) * data->cap_edges);

   data->num_edges = 0;
   /*add the node */
   addNode(&(graph->vertices), data);

   graph->num_vertices++;

   return 1;
}

int num_vertices(Graph graph)
{
   return graph.num_vertices;
}

int has_vertex(Graph graph, const char name[])
{
   if (findVertexByName(graph.vertices, name)
	 >= 0)
      return 1;
   return 0;
}

   int
add_edge(Graph * graph, const char source[],
      const char dest[], int cost)
{
   int s_idx, d_idx, v_idx;
   vertex_t *source_v, *dest_v;
   edge_t *edge;

   v_idx = findVertexByName(graph->vertices, source);
   if (v_idx >= 0)
      if (0 <=
	    findEdgeBySourceNDest(index_v
	       (graph->vertices,
		v_idx)->edges,
	       index_v
	       (graph->vertices,
		v_idx)->num_edges,
	       source, dest))
	 return 0;

   if (cost < 0)
      return 0;
   edge = malloc(sizeof(edge_t));
   edge->cost = cost;
   edge->source = malloc(sizeof(char) * 10);
   strcpy(edge->source, source);
   edge->dest = malloc(sizeof(char) * 10);
   strcpy(edge->dest, dest);

   s_idx = findVertexByName(graph->vertices, source);
   if (s_idx < 0) {
      return 0;
   }
   d_idx = findVertexByName(graph->vertices, dest);
   if (d_idx < 0) {
      return 0;
   }
   /*check validity of idxs */

   source_v = index_v(graph->vertices, s_idx);
   dest_v = index_v(graph->vertices, d_idx);

   /*rellocate memory if capacity is reach */
   if (source_v->num_edges >= source_v->cap_edges) {
      source_v->edges =
	 realloc(source_v->edges,
	       sizeof(edge_t *) *
	       source_v->cap_edges * 2);
      source_v->cap_edges *= 2;
   }

   (source_v->edges)[source_v->num_edges] = edge;
   (source_v->num_edges)++;

   if (dest_v->num_edges >= dest_v->cap_edges) {
      dest_v->edges =
	 realloc(dest_v->edges,
	       sizeof(edge_t *) * dest_v->cap_edges * 2);
      dest_v->cap_edges *= 2;
   }
   (dest_v->edges)[dest_v->num_edges] = edge;
   (dest_v->num_edges)++;
   return 1;
}

int get_edge_cost(Graph graph, const char source[], const char dest[])
{
   int v_idx, e_idx;
   if (source == NULL)
      return -1;
   if (dest == NULL)
      return -1;

   v_idx = findVertexByName(graph.vertices, source);

   if (v_idx < 0)
      return -1;

   e_idx =
      findEdgeBySourceNDest(index_v
	    (graph.vertices,
	     v_idx)->edges,
	    index_v(graph.vertices,
	       v_idx)->num_edges,
	    source, dest);

   if (e_idx < 0)
      return -1;

   return index_v(graph.vertices, v_idx)->edges[e_idx]->cost;
}

   int
change_edge_cost(Graph * graph,
      const char source[], const char dest[], int new_cost)
{
   int v_idx, e_idx;
   if (new_cost < 0)
      return 0;

   v_idx = findVertexByName(graph->vertices, source);

   if (v_idx < 0)
      return 0;
   e_idx =
      findEdgeBySourceNDest(index_v
	    (graph->vertices,
	     v_idx)->edges,
	    index_v(graph->vertices,
	       v_idx)->num_edges,
	    source, dest);

   if (e_idx < 0)
      return 0;

   index_v(graph->vertices,
	 v_idx)->edges[e_idx]->cost = new_cost;

   return 1;
}

int num_neighbors(Graph graph, const char vertex[])
{
   int i, sum = 0, idx;
   if (vertex == NULL)
      return -1;

   idx = findVertexByName(graph.vertices, vertex);
   if (idx < 0)
      return -1;

   for (i = 0; i < graph.num_vertices; i++)
      if (findEdgeBySourceNDest
	    (index_v
	     (graph.vertices, idx)->edges,
	     index_v(graph.vertices,
		idx)->num_edges,
	     vertex, index_v(graph.vertices, i)->name) >= 0)
	 sum++;

   return sum;
}

/*helper functions for dellocation*/
/*clear all edges of vertex connect to neighbors*/
/*
   static void clear_edges_to_neighbors(Graph * g, char vertex[])
   {
   int v_idx, e_idx;
   int i, j, num_edges;
   edge_t **edges;

   v_idx = findVertexByName(g->vertices, vertex);

   edges = index_v(g->vertices, v_idx)->edges;
   num_edges = index_v(g->vertices, v_idx)->num_edges;

   for (i = 0; i < g->num_vertices; i++) {
   e_idx =
   findEdgeBySourceNDest(edges,
   num_edges,
   vertex,
   index_v
   (g->vertices, i)->name);

   if (e_idx >= 0) {

   free(edges[e_idx]);
   index_v(g->vertices, v_idx)->num_edges--;

   e_idx =
   findEdgeBySourceNDest
   (edges, num_edges,
   index_v(g->vertices, i)->name, vertex);

   index_v(g->vertices, i)->num_edges--;

   for (j = e_idx;
   j <
   index_v(g->vertices, i)->num_edges; i++)
   index_v(g->vertices,
   i)->edges[i] =
   index_v(g->vertices,
   i)->edges[i + 1];
   }
   }
   }*/

/*dellocation helper functions end*/
void clear_graph(Graph * g)
{
   int n_vertices = g->num_vertices;
   int i;
   for (i = n_vertices-1; i >= 0; i--)
      deleteNode(&(g->vertices), i, dataDeleter);

   return;
}

char **get_vertices(Graph g)
{
   int n_vertices = g.num_vertices;

   int i;
   char **vertices_name =
      malloc(sizeof(char *) * n_vertices + 1);
   char *tmp_str;
   vertices_name[n_vertices] = NULL;

   for (i = 0; i < n_vertices; i++) {
      tmp_str = index_v(g.vertices, i)->name;
      vertices_name[i] =
	 malloc(sizeof
	       (sizeof(char) * (strlen(tmp_str) + 1)));
      strcpy(vertices_name[i], tmp_str);
   }

   return vertices_name;
}

static int greater(const void *a,const void *b)
{
   return strcmp(*(char **)a, *(char **)b);
}

char **get_neighbors(Graph graph, const char vertex[])
{
   char **neighbors;
   char *tmp_str;
   edge_t **edges;
   int i, j, v_idx, e_idx, num_edges, n_neighbors;

   n_neighbors = num_neighbors(graph, vertex);

   v_idx = findVertexByName(graph.vertices, vertex);
   num_edges = index_v(graph.vertices, v_idx)->num_edges;

   neighbors = malloc(sizeof(char *) * (n_neighbors + 1));
   neighbors[n_neighbors] = NULL;

   edges = index_v(graph.vertices, v_idx)->edges;
   for (i = 0, j = 0; i < num_edges; i++) {
      e_idx =
	 findEdgeBySourceNDest(edges,
	       num_edges,
	       vertex,
	       index_v
	       (graph.vertices, i)->name);
      if (e_idx >= 0) {
	 tmp_str =
	    malloc(sizeof(char) *
		  (strlen(edges[e_idx]->dest) + 1));
	 strcpy(tmp_str, edges[e_idx]->dest);
	 neighbors[j] = tmp_str;
	 j++;
      }
   }
   qsort((void*)neighbors,(size_t) num_neighbors, sizeof(char *), greater);
   return neighbors;
}

void free_vertex_name_list(char **vertex_name)
{
   int i;
   for (i = 0; vertex_name[i] != NULL; i++) {
      free(vertex_name[i]);
   }
   free(vertex_name);
}

int remove_edge(Graph * graph, const char source[], const char dest[])
{
   /*both source and dest vertices have pointers to the edge */

   int sv_idx, dv_idx, e_idx;
   int i, num_edges;

   node_t *vertices = graph->vertices;
   sv_idx = findVertexByName(vertices, source);
   dv_idx = findVertexByName(vertices, dest);

   /*edge index in source vertex */
   e_idx =
      findEdgeBySourceNDest(
	    index_v(vertices, sv_idx)->edges, 
	    index_v(vertices, sv_idx)->num_edges,
	    source, dest);

   free(index_v(vertices, sv_idx)->edges[e_idx]);
   num_edges = --(index_v(vertices, sv_idx)->num_edges);

   for (i = e_idx; i < num_edges; i++)
      index_v(vertices,
	    sv_idx)->edges[i] =
	 index_v(vertices, sv_idx)->edges[i + 1];

   /*edge index in dest vertex */
   e_idx =
      findEdgeBySourceNDest(
	    index_v(vertices,dv_idx)->edges,
	    index_v(vertices,dv_idx)->num_edges,
	    source, dest);
   num_edges = --(index_v(vertices, dv_idx)->num_edges);
   for (i = e_idx; i < num_edges; i++)
      index_v(vertices,
	    dv_idx)->edges[i] =
	 index_v(vertices, dv_idx)->edges[i + 1];

   return 1;
}

int remove_vertex(Graph * g, const char vertex[])
{

   int v_idx, e_idx;
   int i, j;
   vertex_t* t;

   if (g == NULL)
      return 0;
   if (vertex == NULL)
      return 0;

   v_idx = findVertexByName(g->vertices, vertex);
   if (v_idx < 0)
      return 0;

   deleteNode(&(g->vertices), v_idx, dataDeleter);


   g->num_vertices--;
   /*update the change of edge relates to the deleted node*/
   for(i = 0; i < g->num_vertices; i++){
    t = index_v(g->vertices,i);

      e_idx = findEdgeBySourceNDest(t->edges,
	    t->num_edges,
	    t->name,
	    index_v(g->vertices,v_idx)->name);

      if(e_idx >= 0){
	 t->num_edges--;
	 for(i = e_idx; i < t->num_edges; i++)
	    t->edges[i] = t->edges[i+1];
      }
   }
   return 1;
}
