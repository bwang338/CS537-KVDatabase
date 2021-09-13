#include <stdio.h>
#include <stdlib.h>

struct node{
	int key;
	char *value;
	struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

int main(int argc, char *argv[]){
	char *command = argv[1];
	int key = atoi(argv[2]);
	char *value = argv[3];
	char *file = "database.txt";
	//put pair into kv
	if (strcmp(command, "p") == 0){
		
	}
	//get value from kv using key
	if (strcmp(command, "g") == 0){
		
        }
	//delete key value pair using key
	if (strcmp(command, "d") == 0){
		
        }
	//clear removes all key-value pairs
	if (strcmp(command, "c") == 0){
		
        }
	//prints all key-value pairs
	if (strcmp(command, "a") == 0){
		
        }
	else{
		
	}
}

void put(int key, char *value){
	struct node *link = (struct node*) malloc(sizeof(struct node));
	link->key = key;
	link->value = value;
	link->next = head;
	head = link;
}

void get(int key){
	struct node *ptr = head;
	while(ptr != NULL) {
		if(ptr->key == key){
			printf("%s\n", ptr->value);
		}
		ptr = ptr->next;
	}
}

void delete(int key){
	struct node *ptr = head;
	while(ptr != NULL) {
		if (ptr->key == key){
			if (ptr->next == NULL){
				ptr == NULL;
			}
			else{
				ptr->value == ptr->next->value;
				ptr->key == ptr->next->key;
				ptr->next == ptr->next->next;
			}
		}
	}
}

void removeAll(){
		
}

void printAll(){
	FILE *fp = fopen("database.txt", "r");
}



