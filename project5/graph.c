/****************************************
  This file is written by Yuan Liang 
  for project4 cmsc216

  add dellocation functions for project 5

  use linked list to store vetex of graph

  dataDeleter function is for delete data in node
 *****************************************/
#include"./graph.h"
#include"./graph-implementation.h"
#define UNUSED(x) ((void*)x)
/*healper functions declarations*/
/*linked list functions*/
static data_t *index_v(node_t * head, int idx);
static int addNode(node_t ** head, data_t * data);
static int deleteNode(node_t ** head, int idx, int (*deleter) (data_t *));
static int dataDeleter(data_t * data);	/*it should be changed if data_t changed */
/*linked list function end*/
static void del_edge_ptr_to_vertex(Graph * g, int vertex_index);
static int greater(const void *a, const void *b);	/*function for sorting strings */
static int edgeDeleter(edge_t * edge);
static int findVertexByName(node_t * vertices, const char name[]);
static int findEdgeBySourceNDest(edge_t ** edges, int size,
				 const char source[], const char dest[]);
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
static int edgeDeleter(edge_t * edge)
{
	free(edge->source);
	free(edge->dest);
	free(edge);
	return 1;

}

static int dataDeleter(data_t * data)
{
	/*maybe changed for deleting data_t */
	int i;
	if (data == NULL)
		return -1;

	for (i = 0; i < data->num_edges; i++) {
		if ((i + 1) == data->num_edges) {
			edgeDeleter((data->edges)[i]);
		} else if ((data->edges)[i] != (data->edges)[i + 1]) {
			edgeDeleter((data->edges)[i]);
		}
	}
	free(data->edges);
	free(data->name);
	free(data);
	/*do nothing if data points to static memory */
	/*UNUSED(data); */
	return 1;
}

static int deleteNode(node_t ** head, int idx, int (*deleter) (data_t *))
{
	node_t *p, *c;
	int i;
	if (head == NULL)
		return -1;

	p = *head;
	if (*head != NULL)
		c = (*head)->next;
	else
		return -1;

	if (idx == 0) {
		(*head) = (*head)->next;
		(*deleter) (p->data);
		free(p);

	} else {
		for (i = 0; i < (idx - 1); i++) {
			c = c->next;
			p = p->next;

		}
		(*deleter) (c->data);
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
	if (vertices == NULL || name == NULL)
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
	if (source == NULL || dest == NULL)
		return -1;

	for (i = 0; i < size; i++) 
		if (!strcmp(edges[i]->dest, dest))
			if (!strcmp(edges[i]->source, source)) 
				return i;
	
	return -1;
}

/* end*/

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

	if (graph == NULL || new_vertex == NULL)
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

int add_edge(Graph * graph, const char source[], const char dest[], int cost)
{
	int s_idx, d_idx, num_edges;
	vertex_t *source_v, *dest_v;
	node_t *vertices;
	edge_t *edge, **edges;

	vertices = graph->vertices;
	if (graph == NULL || source == NULL || dest == NULL)
		return 0;

	s_idx = findVertexByName(vertices, source);
	if (s_idx < 0) {
		return 0;
	}

	edges = index_v(vertices, s_idx)->edges;
	num_edges = index_v(vertices, s_idx)->num_edges;
	if (findEdgeBySourceNDest(edges, num_edges, source, dest) >= 0)
		return 0;
	d_idx = findVertexByName(graph->vertices, dest);
	if (d_idx < 0) {
		return 0;
	}
	edge = malloc(sizeof(edge_t));
	edge->cost = cost;
	edge->source = malloc(sizeof(char) * (strlen(source) + 1));
	strcpy(edge->source, source);
	edge->dest = malloc(sizeof(char) * (strlen(dest) + 1));
	strcpy(edge->dest, dest);

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
        vertex_t *v;
	if (source == NULL)
		return -1;
	if (dest == NULL)
		return -1;

	v_idx = findVertexByName(graph.vertices, source);

	if (v_idx < 0)
		return -1;
        v = index_v(graph.vertices,v_idx);
	e_idx =
	    findEdgeBySourceNDest(v->edges,v->num_edges, source, dest);

	if (e_idx < 0)
		return -1;

	return index_v(graph.vertices, v_idx)->edges[e_idx]->cost;
}

int
change_edge_cost(Graph * graph,
		 const char source[], const char dest[], int new_cost)
{
	int v_idx, e_idx;
        vertex_t *v;
	if (graph == NULL || source == NULL
	    || dest == NULL || new_cost < 0)
		return 0;

	v_idx = findVertexByName(graph->vertices, source);

	if (v_idx < 0)
		return 0;
        v = index_v(graph->vertices,v_idx);
	e_idx =
	    findEdgeBySourceNDest(v->edges,v->num_edges, source, dest);

	if (e_idx < 0)
		return 0;

	v->edges[e_idx]->cost = new_cost;

	return 1;
}

int num_neighbors(Graph graph, const char vertex[])
{
	int i, sum = 0, idx;
	node_t *vs = graph.vertices;
	vertex_t *v, *v_tmp;
	if (vertex == NULL)
		return -1;

	idx = findVertexByName(vs, vertex);
	if (idx < 0)
		return -1;
	v = index_v(vs, idx);
	for (i = 0; i < graph.num_vertices; i++) {
		v_tmp = index_v(vs, i);
		if (findEdgeBySourceNDest(v->edges, v->num_edges,
					  vertex, v_tmp->name) >= 0)
			sum++;
	}

	return sum;
}

/*dellocation helper functions end*/
void clear_graph(Graph * g)
{
	while (g->num_vertices != 0)
		remove_vertex(g, index_v(g->vertices, 0)->name);

	return;
}

char **get_vertices(Graph g)
{
	int n_vertices = g.num_vertices;

	int i;
	char **vertices_name = malloc(sizeof(char *) * (n_vertices + 1));

	char *tmp_str;

	vertices_name[n_vertices] = NULL;
	for (i = 0; i < n_vertices; i++) {
		tmp_str = index_v(g.vertices, i)->name;
		vertices_name[i] =
		    malloc(sizeof(char) * (strlen(tmp_str) + 1));
		strcpy(vertices_name[i], tmp_str);
	}
	qsort((void *)vertices_name, n_vertices, sizeof(char *), greater);
	return vertices_name;
}

static int greater(const void *a, const void *b)
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
	for (i = 0, j = 0; i < graph.num_vertices; i++) {
		e_idx =
		    findEdgeBySourceNDest(edges,
					  num_edges,
					  vertex,
					  index_v(graph.vertices,
						  i)->name);
		if (e_idx >= 0) {
			tmp_str =
			    malloc(sizeof(char) *
				   (strlen(edges[e_idx]->dest) + 1));
			strcpy(tmp_str, edges[e_idx]->dest);
			neighbors[j] = tmp_str;
			j++;
		}
	}
	qsort((void *)neighbors, n_neighbors, sizeof(char *), greater);
	return neighbors;
}

void free_vertex_name_list(char **vertex_name)
{
	int i;
	for (i = 0; vertex_name[i] != NULL; i++) 
		free(vertex_name[i]);
	
	free(vertex_name);
}

int remove_edge(Graph * graph, const char source[], const char dest[])
{
	/*both source and dest vertices have pointers to the edge */

	int sv_idx, dv_idx, e_idx;
	int i, num_edges;
	vertex_t *v_tmp;
	node_t *vertices = graph->vertices;
	sv_idx = findVertexByName(vertices, source);

	dv_idx = findVertexByName(vertices, dest);
	if (sv_idx < 0 || dv_idx < 0)
		return 0;

	/*edge index in dest vertex */
	v_tmp = index_v(vertices, dv_idx);
	e_idx =
	    findEdgeBySourceNDest(v_tmp->edges, v_tmp->num_edges, source,
				  dest);
	num_edges = --(v_tmp->num_edges);
	for (i = e_idx; i < num_edges; i++)
		index_v(vertices, dv_idx)->edges[i] = v_tmp->edges[i + 1];

	/*edge index in source vertex */
	v_tmp = index_v(vertices, sv_idx);
	e_idx =
	    findEdgeBySourceNDest(v_tmp->edges, v_tmp->num_edges, source,
				  dest);
	edgeDeleter(v_tmp->edges[e_idx]);
	num_edges = --(v_tmp->num_edges);
	for (i = e_idx; i < num_edges; i++)
		index_v(vertices, sv_idx)->edges[i] = v_tmp->edges[i + 1];

	return 1;
}

static void del_edge_ptr_to_vertex(Graph * g, int vertex_index)
{
	node_t *vs = g->vertices;
	const char *v = index_v(vs, vertex_index)->name;
	int v_idx = vertex_index, e_idx, i, j, n_v = g->num_vertices;
	vertex_t *v_tmp;
	for (i = 0; i < n_v; i++) {
		if (i == v_idx) ;
		else {
			v_tmp = index_v(vs, i);
			e_idx =
			    findEdgeBySourceNDest(v_tmp->edges,
						  v_tmp->num_edges,
						  v_tmp->name, v);

			if (e_idx >= 0) {
				v_tmp->num_edges--;
				for (j = e_idx; j < v_tmp->num_edges; j++)
					v_tmp->edges[j] =
					    v_tmp->edges[j + 1];
			}
			e_idx =
			    findEdgeBySourceNDest(v_tmp->edges,
						  v_tmp->num_edges,
						  v, v_tmp->name);
			if (e_idx >= 0) {
				v_tmp->num_edges--;
				for (j = e_idx; j < v_tmp->num_edges; j++)
					v_tmp->edges[j] =
					    v_tmp->edges[j + 1];
			}
		}
	}
	return;
}

int remove_vertex(Graph * g, const char v[])
{
	int v_idx;
	if (g == NULL)
		return 0;
	if (v == NULL)
		return 0;
	v_idx = findVertexByName(g->vertices, v);
	if (v_idx < 0)
		return 0;
	del_edge_ptr_to_vertex(g, v_idx);
	deleteNode(&(g->vertices), v_idx, dataDeleter);
	g->num_vertices--;
	return 1;
}
