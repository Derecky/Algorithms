#include <stdio.h>
#include <stdlib.h>

/* ----------- Tipos	/	Estruturas -------------------*/

typedef struct Node{
	int item;
	struct Node* next_node;
}Node;

typedef struct Stack{
	Node* top;
	int current_size;
}Stack;



/* ----------- 	Comandos de pilha ------------------------*/


void push( Stack *stack , int item){
	Node* new_top = (Node*) malloc(sizeof(Node));
	new_top->item = item;
	new_top->next = stack->top;
	stack->current_size += 1;
	stack->top = new_top;
}

Stack* create_stack(){
	Stack *stack = (Stack*) malloc(sizeof(Stack));
	stack->top = NULL;
	stack->current_size = 0;

	return stack;
}

int pop(Stack *stack) {
	if (stack->current_size == 0){ 
		return -1;
	}

	int item = stack->top->item;
	stack->top = stack->top->nextNode;
	stack->size -= 1;

	return item;
}

int peek(Stack *stack){
	if(current->size == 0){
		return -1;
	}
	
	return stack->top->item;
}

int is_empty(Stack *stack){
	return (stack->current_size);
}
