#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int key;
	char* value;
	struct Node *next;
} Node;

int main(int argc, char *argv[]){
	char* in = argv[1];
	int key = atoi(argv[2]);
	char* value = argv[3];
	char* file = "database.txt";
	//put pair into kv
	if (strcmp(in, "p") == 0){
		
	}
	//get value from kv using key
	if (strcmp(in, "g") == 0){
		
        }
	//delete key value pair using key
	if (strcmp(in, "d") == 0){
		
        }
	//clear removes all key-value pairs
	if (strcmp(in, "c") == 0){
		
        }
	//prints all key-value pairs
	if (strcmp(in, "a") == 0){
		
        }
	else{
		
	}
}


