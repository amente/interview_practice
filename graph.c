#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ROOT_DISTANCE 0;
#define DEFAULT_CAPACITY 10;


typedef struct _Vertex{
	char *name;
	int len;
	struct _Vertex **neighbours;
	int distance;
}Vertex;

typedef struct _Graph{
	Vertex ** vertices;
	int capacity;
	int size;
	int dRoot;
	void (*add)(struct _Graph *g,Vertex *v1,int distance);
	void (*addEdge)(struct _Graph *g,Vertex *v1,Vertex *v2,float weight);	
}Graph;

void Graph_add(Graph *g,Vertex *v1, int distance);
void Graph_addEdge(Graph *g, Vertex *v1,Vertex *v2, int distance);

// Creates a Vertex
Vertex *Graph_Vertex(char *name,int len){
	Vertex *v = malloc(sizeof(Vertex));
	assert(v!=NULL);
	//Copy the name
	v->name = malloc(sizeof(char)*len);
	assert(v->name!=NULL);
	int i;
	for(i=0;i<len;i++){
		v->name[i] = name[i];
	}	
	v->len = len;	
}

Graph *Graph_Graph(int capacity){
	Graph *g = malloc(sizeof(Graph));
	assert(g!=NULL);
	g->capacity = capacity;
	g->size = 0;	
	g->vertices = malloc(sizeof(Vertex *) * g->capacity);
	g->dRoot = ROOT_DISTANCE;	
	g->add = Graph_add;
	g->addEdge = Grap_addEdge;
}

void Graph_add(Graph *g,Vertex *v1){
	if(g->size > capacity){
		//TODO: Reallocate vertices
	}
	g->vertices[size] = v1;
	g->size++;
}









