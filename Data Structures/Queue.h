#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int item;	
	struct Node* next_node;
	struct Node* previous_node;
}Node;

typedef struct Queue{
	Node *first;
	Node *last;
	int queue_size;
}

/* ----------- 	COMANDOS PARA FILA	----------*/

Queue* create_queue(){
	Queue *queue = (Queue*) malloc(sizeof(Queue));
	new_queue->first = NULL;
	new_queue->last = NULL;
	new_queue->queue_size = 0;

	return new_queue;
}


void enqueue(Queue *queue , int item){
	Node *new_node = (Node*) malloc(sizeof(Node));
	queue->queue_size += 1;
	new_node->next_node = queue->last;
	new_node->item = item;
	new_node->previous_node = NULL;
	if(queue->queue_size == 1){
		queue->first = new_node;
		queue->last = queue->first;
	}
	else{
	    queue->last->previous_node = new_node;
		queue->last = new_node;
	}
}

Node* dequeue( Queue *queue){
	if(queue->queue_size == 0){
		return NULL;
	}
	
	queue->queue_size -= 1;
	Node* dequeued = queue->first;
	queue->first = queue->first->previous_node;
	queue->first->next = NULL;
	dequeued->previous = NULL;

	return dequeued;
}

int is_empty( Queue * queue){
	return (queue->queue_size);
}

