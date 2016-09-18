#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

typedef struct Adjlist{
	int item;
	struct Adjlist next;
}Node;

typedef struct Graph{
	adjlist *vertices[MAX_SIZE];
	short visited[MAX_SIZE];
} Graph;

Graph* create_graph(){
	Graph *graph = (Graph*) malloc(sizeof(Graph));
	int i;
	for (i = 1; i <= MAX_SIZE - 1; i++) {
		graph->vertices[i] = NULL;
		graph->visited[i] = 0;
	}
	return graph;
}

Adjlist* create_adjlist(int item) {
	Adjlist *adjlist = (Adjlist*) malloc(sizeof(Adjlist));
	adjlist->item = item;
	adjlist->next = NULL;
	return adjlist;
}

void add_edge(Graph *graph, int vertex1, int vertex2) {
	Adjlist *vertex = create_adjlist(vertex2);
	vertex->next = graph->vertices[vertex1];
	graph->vertices[vertex1] = vertex;
	//Undirected graph. Edge to the other direction as well.
	vertex = create_adjlist(vertex1);
	vertex->next = graph->vertices[vertex2];
	graph->vertices[vertex2] = vertex;
}

void dfs(Graph *graph, int source){
	graph->visited[source] = 1;
	printf("%d\n", source);
	Adjlist *adjlist = graph->vertices[source];
	while (adjlist != NULL) {
		if (!graph->visited[adjlist->item]) {
			dfs(graph, adjlist->item);
		}
	adjlist = adjlist->next;
	}
}

void bfs(Graph *graph, int source){
	Queue *queue = create_queue();
	int dequeued;
	Adjlist *adjlist = graph->vertices[source];
	graph->visited[source] = 1;
	enqueue(queue, source);
	
	while (!is_empty(queue)) {
		dequeued = dequeue(queue);
		adjlist = graph->vertices[dequeued];
		while (adjlist != NULL) {
			if (!graph->visited[adjlist->item]) {
				printf("%d\n", adjlist->item);
				graph->visited[adjlist->item] = 1;
				enqueue(queue, adjlist->item);
			}
		adjlist = adjlist->next;
		}
	}
}

