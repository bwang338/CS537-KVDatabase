#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node{
	int key;
	char *value;
	struct node *next;
};


void put(struct node **head_ref, int key, char *value){
	struct node *temp = *head_ref;
	if (temp != NULL && temp->key == key){
		temp->value = value;
		return;
	}

	while(temp != NULL && temp->key != key){
		temp = temp->next;
	}
	if (temp == NULL){
		struct node *newNode = (struct node *) malloc(sizeof(struct node));
		newNode->key = key;
		newNode->value = strdup(value);
		newNode->next = (*head_ref);
		(*head_ref) = newNode;
		return;
	}
	temp->value = value;
}

void get(struct node *head_ref, int key){
        if (head_ref == NULL){
		printf("%d not found\n", key);
		return;
	}
	struct node *ptr = head_ref;
        while(ptr->key != key) {
                if (ptr->next == NULL){
			printf("%d not found\n", key);
			return;
		}
                ptr = ptr->next;
        }
	printf("%d,%s\n", ptr->key, ptr->value);
}

void delete(struct node **head_ref, int key){
	struct node *current = *head_ref;
	struct node *prev = NULL;
	if (current != NULL && current->key == key){
		*head_ref = current->next;
		free(current);
		return;
	}	

	while(current != NULL && current->key != key) {
		prev = current;
		current = current->next;
	}

	if (current == NULL){
		return;
	}

	prev->next = current->next;
	free(current);
}

void printAll(struct node *head_ref){
	if (head_ref == NULL) return;
	struct node *current = head_ref;
	while(current != NULL){
		printf("%d,%s\n", current->key, current->value);
		if (current->next == NULL){
			return;
		}
		current = current->next;
	}	
}


int main(int argc, char *argv[]){
	//puts everything from the database into a linkedlist
	struct node *head = NULL;
	FILE *fp;
        fp = fopen("database.txt", "a+");
	char *line = NULL;
	size_t line_buf_size = 0;
	ssize_t line_size;
	while((line_size = getline(&line, &line_buf_size, fp)) != -1){
		line[line_size-1] = '\0';
		char *key = strsep(&line, ",");
		int realKey = atoi(key);
		char *value = strsep(&line, ",");
		put(&head, realKey, value);
		free(line);
		line = NULL;
	}
	//close stuff after everything is into the linkedlist
	free(line);
	line = NULL;
	fclose(fp);
	fp = NULL;
	//look at the arguments
	if (argc < 2){
		exit(0);
	}
	for (int i = 1; i < argc; i++){
		//take each individual line argument
		size_t len = strlen(argv[i]);
		char *command = malloc(len*sizeof(char));
		char *argument;
		strcpy(command, argv[i]);
		//loop through the command and split it
		while((argument = strsep(&command, ",")) != NULL){
			//want to get a value using a key
			if (strcmp(argument, "g") == 0){
				char* key,*test;
				if ((key = strsep(&command, ",")) == NULL){
					printf("bad command\n");
					return(0);
				}
				if ((test = strsep(&command, ",")) != NULL){
					printf("bad command\n");
					break;
				}
				int realKey = atoi(key);
				get(head, realKey);
			}
			//want to put a key-value pair in
			else if (strcmp(argument, "p") == 0){
				char *key,*value;
				if ((key = strsep(&command, ",")) == NULL){
					printf("bad command\n");
					exit(0);
				}
				int realKey = atoi(key);
				if (realKey == 0){
					printf("bad command\n");
					exit(0);
				}
				if ((value = strsep(&command, ",")) == NULL){
					printf("bad command\n");
					exit(0);
				}
				put(&head, realKey, value);
			}
			//want to delete a key-value pair using a key
			else if (strcmp(argument, "d") == 0){
				char *key;
				if ((key = strsep(&command, ",")) == NULL){
					printf("bad command\n");
					exit(0);
				}
				int realKey = atoi(key);
				delete(&head, realKey);
			}
			//want to clear the entire hashMap thing
			else if (strcmp(argument, "c") == 0){
				head = NULL;
			}
			//want to print all key-value pairs
			else if (strcmp(argument, "a") == 0){
				printAll(head);
			}
			else{
				printf("bad command\n");
			}
		}
	}
	//when it's over, overwrite the database with the new linked list
        fp = fopen("database.txt", "w");
	while (head != NULL){
		fprintf(fp, "%d,%s\n", head->key, head->value);
		if (head->next == NULL){
			break;
		}
		head = head->next;
	}
	fclose(fp);
	fp = NULL;
}
