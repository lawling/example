#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include "./graph.h"
char* random_str(){
   int len,i = 0;
   char* p;
   len = rand()%101;
   p = malloc(sizeof(char)*len);
   while(i < len){
      p[i] = rand()%26 +65 ;
      i++;
   }
   return p;
}
int main(){
   int i,to,from,k,n_tmp;
   char** tmp;
   Graph* g;
   int n_v,n_c,n_e;
   char** vs;
   int* cs;

   time_t t;


  for(k = 0; k < 1001; k++){
      printf(" k = %d\n",k);
      srand((unsigned) time(&t));
      g = malloc(sizeof(Graph));
      n_v = rand()%101, n_c = rand()%101,n_e = 0;
      vs = malloc(sizeof(char*) *n_v);
      cs = malloc(sizeof(int) * n_c);
      for(i = 0 ; i < n_c; i++)
	 cs[i] = rand()%1001;

      init_graph(g);
      for(i = 0 ; i < n_v; i++){
	 vs[i] = random_str();
	 if(add_vertex(g,vs[i]) == 0)
	    printf("add vertex %s fail\n",vs[i]);
      }

      for(i = 0,n_e = 0; i < n_c; i++){
	 to = rand()%n_v;
	 from = rand()%n_v;
	 if(add_edge(g,vs[from],vs[to], cs[i]) == 1)
	    n_e++;

	 if(rand()%5 == 0){
	    remove_edge(g,vs[from],vs[to]);
	    printf("removing edge from %s to %s \n",vs[from],vs[to]);
	 }
      }

      for(i = 0; i < n_v; i++)
	 if(has_vertex(*g,vs[i]) == 0)
	    printf("the graph does not have vertex %s\n",vs[i]);

      printf("finished test has_vertex \n");
     n_tmp = n_v;
      if(rand() % 3 == 0){
	 i = rand()%n_v;
	n_tmp--; 
	 remove_vertex(g,vs[i]);
	 printf(" removing vertex %s \n",vs[i]);
      }
      tmp = get_vertices(*g);
      for(i = 0; tmp[i] != NULL;i++)
	 printf("graph has vertices %s\n",tmp[i]);

      free_vertex_name_list(tmp);

      printf("successfully adding %d edges \n",n_e);

      for(i = 0; i < n_v;i++)
	 free(vs[i]);
      clear_graph(g);
      free(vs);
      free(cs);
      free(g);
}
   return 0;
}
