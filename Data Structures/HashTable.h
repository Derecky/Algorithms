#include <stdio.h>
#include <stdlib.h>
#define SIZE_TABLE 11

typedef struct Element{
	int key;
	int value;
}Element;

typedef struct Hashtable{
	Element *table[SIZE_TABLE];
}Hashtable;



Hashtable* create_hashtable(){
	Hashtable *hashtable = (Hashtable*) malloc(sizeof(Hashtable)); 
	int i;
	for(i = 0 ; i < SIZE_TABLE ; i++){
		hashtable->table[i] = NULL;
	}
	return hashtable;
}

void put(Hashtable *hashtable , int key , int value){
	int h = key % SIZE_TABLE;
	while(hashtable->table[h] != NULL){
		if (hashtable->table[h]->key == key){
			hashtable->table[h]->value = value;
			break;		
		}
		h = (h+1) % SIZE_TABLE;
	}
	if(hashtable->table[h] == NULL){
		Element *new_element = (Element*) malloc(sizeof(Element));
		new_element->key = key;
		new_element->value = value;
		hashtable->table[h] = new_element;
	}
}

int get(Hashtable *hashtable, int key){
	int h = key % SIZE_TABLE;
	while(hashtable->table[h] != NULL){
		if(hashtable->table[h]->key == key){
			return ht->table[h]->value;
		}
		h = (h+1) % SIZE_TABLE;
	}
	
	return -100;
}

void remove(Hashtable *hashtable, int key){
	int h = key % SIZE_TABLE;
	while (ht->table[h] != NULL) {
		if (ht->table[h]->key == key) {
			ht->table[h]->key = -1;
		}
		h = (h + 1) % 11;
	}
}

	
