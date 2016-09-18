#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int item;
	struct Node *next_node;
}Node;

Node* create_linked_list(){
	return NULL;
}

Node* insert(Node* first, 	int item){
	Node *new_node = (Node*) malloc(sizeof(Node));
	new_node->item = item;
	new_node->next_node = first;
	return new_node;
}

int is_empty(Node* first){
	return (first == NULL);
}

void print_linked_list(Node* first){
	Node *i;
	for(i=first ; i!=NULL ; i = i->next_node){
		printf("%d ", i->item);
	}
}

Node* search(Node *first, int item){
	Node *i;
	for(i=first ; i!=NULL ; i = i->next_node){
		if(i->item == item){
			return i;
		}
	}
	
	return NULL;
}

Node* remove(Node* first, int item){
	Node *previous = NULL;
	Node *current = first;
	
	while(current!=NULL && current->item != item){
		previous = current;
		current = current->next_node;
	}

	if(current == NULL){
		return first;
	}
	
	if(previous == NULL){
		first = current->next_node;
	}
	else{
		previous->next_node = current->next_node;
	}

	free(current);
	return first;
}
