#include <stdio.h>
#include <stdlib.h>

struct node{
	int key;
	char *value;
	struct node *next;
};

struct node *head = NULL;

int main(int argc, char *argv[]){
	for (int i = 1; i < argc; i++){
		char[] command = argv[i];
	}
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

void put(struct node** head_ref, int key, char *value){
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	newNode->key = key;
	newNode->value = value;
	newNode->next = (*head_ref);
	(*head_ref) = newNode;
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

void delete(struct node** head_ref, int key){
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
	char buff[255];
	FILE *fp = fopen("database.txt", "r");
	
	
}



