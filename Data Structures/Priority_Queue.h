#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int item;
	int priority;
	struct Node* next_node;
	struct Node* previous_node;
} Node;

typedef struct Pqueue {
	int queue_size;
	Node* first;
	Node* last;
} Pqueue;

void enqueue(Pqueue *pqueue ,int item, int priority){
	Node *new_node = (Node*) malloc(sizeof(Node));
	new_node->item = item;
	new_node->priority = priority;
	pqueue->queue_size += 1;	
	if((pqueue->first == NULL) || (priority > pqueue->first->priority)){
		new_node->next_node = pqueue->first;
		pqueue->first = new_node;
	}
	else{
		Node *current = pqueue->first;
		while((current->next_node != NULL) && (current->priority > priority)){
	current = current->next_node;
		}
		new_node->next = current->next;
		current->next = new_node;
	}
}

Node* dequeue(Pqueue *pqueue){
	if(pqueue->first != NULL){
		Node *current = pqueue->first;
		pqueue->first = pqueue->first->next_node;
		current->next_node = NULL;
		return current;
	}
	else{
		printf("Empty priority queue!");
		return NULL;
	}
}

int maximum(Pqueue *pqueue){
	if (pqueue->first != NULL) {
		return pq->first->i;
	} 
	else {
		printf("Empty priority queue!");
		return -1;
	}
}

int is_empty(Pqueue *pqueue){ 
	return (pqueue->first == NULL);
}

