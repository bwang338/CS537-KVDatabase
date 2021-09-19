#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int key;
	char *value;
	struct node *next;
};

struct node *head = NULL;

int main(int argc, char *argv[]){
	//puts everything from the database into a linkedlist
	FILE *fp;
        fp = fopen("database.txt", "a+");
	char *line = NULL;
	size_t line_buf_size = 0;
	ssize_t line_size;
	line_size = getline(&line, &line_buf_size, fp);
	while(line_size > 0){
		char *line_copy;
		strcpy(line_copy, line);
		char *key = strsep(&line_copy, ",");
		int realKey = atoi(key);
		char *value = strsep(&line_copy, ",");
		put(head, key, value);
	}
	fclose(fp);
	//look at the arguments
	for (int i = 1; i < argc; i++){
		//take each individual line argument
		int len = strlen(argv[1]);
		char command[len];
		char *argument;
		strcpy(command, argv[1]);
		//loop through the command and split it
		while((argument = strsep(&command, ",")) != NULL){
			//want to get a value using a key
			if (strcmp(argument, "g") == 0){
				char* key;
				if ((key = strsep(&command, ",")) == NULL){
					printf("wrong number of commands (no KEY)");
				}
				int realKey = atoi(key);
				get(&head, realKey);
			}
			//want to put a key-value pair in
			if (strcmp(argument, "p") == 0){
				char *key,value;
				if ((key = strsep(&command, ",")) == NULL){
					printf("wrong number of commands (no KEY)");
				}
				int realKey = atoi(key);
				if ((value = strsep(&command, ",")) == NULL){
					printf("wrong number of commands (no VALUE)");
				}
				put(&head, realKey, value);
			}
			//want to delete a key-value pair using a key
			if (strcmp(argument, "d") == 0){
				char *key;
				if ((key = strsep(&command, ",")) == NULL){
					printf("wrong number of commands (no KEY)");
				}
				int realKey = atoi(key);
				delete(&head, realKey);
			}
			//want to clear the entire hashMap thing
			if (strcmp(argument, "c") == 0){
				remove("database.txt");
				FILE *fp = fopen("database.txt", "a");
				fclose(fp);
			}
			//want to print all key-value pairs
			if (strcmp(argument, "a") == 0){
				printAll();
			}
		}
	}
	//when it's over, overwrite the database with the new linked list
	fp = fopen("database.txt", "w");
	while (head != NULL){
		char *keyP = head->key;
		char *valueP = head->value;
		char comma[1];
		strcpy(comma, ",");
		strcat(keyP, comma);
		strcat(keyP, valueP);
		fputs(keyP, fp);
		fputs("\n", fp);
		if (head->next == NULL){
			break;
		}
		head = head->next;
	}
}

void put(struct node** head_ref, int key, char *value){
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	newNode->key = key;
	newNode->value = value;
	newNode->next = (*head_ref);
	(*head_ref) = newNode;
}

void get(struct node** head_ref, int key){
	struct node *ptr = &head;
	while(ptr != NULL) {
		if(ptr->key == key){
			printf("%s\n", ptr->value);
		}
		if (ptr->next == NULL){
			printf("this doesn't exist");
			exit(0);
		}
		ptr = ptr->next;
	}
}

void delete(struct node** head_ref, int key){
	struct node *ptr = &head;
	while(ptr != NULL) {
		if (ptr->key == key){
			if (ptr->next == NULL){
				ptr = NULL;
			}
			else{
				ptr->value = ptr->next->value;
				ptr->key = ptr->next->key;
				ptr->next = ptr->next->next;
			}
		}
	}
}

void printAll(){
	FILE *fp;
        fp = fopen("database.txt", "r");
	char *line = NULL;
	size_t line_buf_size = 0;
	ssize_t line_size;
	line_size = getline(&line, &line_buf_size, fp);
	while (line_size > 0){
		printf("%s", line);
		line_size = getline(&line, &line_buf_size, fp);
	}
}



