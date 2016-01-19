/****************************************
  This file is written by Yuan Liang 
  for project4 cmsc216

  use linked list to store vetex of graph
 *****************************************/
#include"./graph.h"
#include"./graph-implementation.h"
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

/*helper functions for access vertices and edges*/

/*paramenters: array of vertex_t, name of vertex*/
/*return index_v of vertex has name in array, unfound return -1*/
static int findVertexByName(node_t * vertices, const char name[])
{

	int i = 0;
	if (vertices == NULL || (name == NULL) )
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
findEdgeBySourceNDest(edge_t ** edges, int size, const char source[],
		      const char dest[])
{
	int i;
        if(source == NULL || dest == NULL)
                return -1;
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
        if (new_vertex == NULL)
             return 0;
	if (findVertexByName(graph->vertices, new_vertex) >= 0)
		return 0;

	/*initialize a new data */

	data = malloc(sizeof(vertex_t));
	if (data == NULL)
		return 0;

	data->name = malloc(sizeof(char) * (strlen(new_vertex)+1));
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
	if (findVertexByName(graph.vertices, name) >= 0)
		return 1;
	return 0;
}

int
add_edge(Graph * graph, const char source[], const char dest[], int cost)
{
	int s_idx, d_idx, v_idx;
	vertex_t *source_v, *dest_v;
	edge_t *edge;
 
        if(graph == NULL || source == NULL || dest == NULL)
                 return 0;
	v_idx = findVertexByName(graph->vertices, source);
	if (v_idx >= 0)
		if (0 <=
		     findEdgeBySourceNDest(index_v
					   (graph->vertices, v_idx)->edges,
					   index_v(graph->vertices,
						   v_idx)->num_edges,
					   source, dest)) 
			return 0;

	if (cost < 0)
		return 0;
	edge = malloc(sizeof(edge_t));
	edge->cost = cost;
	edge->source = malloc(sizeof(char) * (strlen(source)+1));
	strcpy(edge->source, source);
	edge->dest = malloc(sizeof(char) * (strlen(dest)+1));
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
			    sizeof(edge_t *) * source_v->cap_edges * 2);
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
        if(source == NULL) 
           return -1;
        if(dest == NULL)
           return -1;

	v_idx = findVertexByName(graph.vertices, source);

	if (v_idx < 0)
		return -1;

	e_idx =
	    findEdgeBySourceNDest(index_v(graph.vertices, v_idx)->edges,
				  index_v(graph.vertices,
					  v_idx)->num_edges, source, dest);

	if (e_idx < 0)
		return -1;

	return index_v(graph.vertices, v_idx)->edges[e_idx]->cost;
}

int
change_edge_cost(Graph * graph,
		 const char source[], const char dest[], int new_cost)
{
	int v_idx, e_idx;
        if(graph == NULL)
             return 0;

        if(new_cost < 0)
           return 0;

	v_idx = findVertexByName(graph->vertices, source);

	if (v_idx < 0)
		return 0;
	e_idx =
	    findEdgeBySourceNDest(index_v(graph->vertices, v_idx)->edges,
				  index_v(graph->vertices,
					  v_idx)->num_edges, source, dest);

	if (e_idx < 0)
		return 0;

	index_v(graph->vertices, v_idx)->edges[e_idx]->cost = new_cost;

	return 1;
}

int num_neighbors(Graph graph, const char vertex[])
{
	int i, sum = 0,idx;
        if(vertex == NULL)
            return -1;

	idx = findVertexByName(graph.vertices, vertex);
	if (idx < 0)
		return -1;

	for (i = 0; i < graph.num_vertices; i++)
		if (findEdgeBySourceNDest
		    (index_v(graph.vertices, idx)->edges,
		     index_v(graph.vertices, idx)->num_edges, vertex,
		     index_v(graph.vertices, i)->name) >= 0)
			sum++;

	return sum;
}
