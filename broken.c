#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct node {
   	//char name[128];
	char *name;
	//char *name[128];
	struct node *next;
};

void list_insert_ordered(char *name,  struct node **head) {

/*	//printf("Name: %s", name);
	struct node *newnode = malloc(sizeof(struct node));
	//printf("Name: %s", name);
	//printf(head);
	//(*newnode).name = (char) name;
	char word = strncpy(newnode->name, name, 127);

    if (name == NULL) {
        return;
    }

    if (head == NULL) { //previously *head
        *head = newnode;
    }

    if (strncasecmp(name, (*head)->name, 127) < 0) {
	//if (strcasecmp(name, (*head)->name) < 0){
        	*head = newnode;
        	newnode->next = *head;
    	}

    struct node *curr = malloc(sizeof(head));
    curr = *head;

    while (curr->next != NULL && strncasecmp(name, curr->next->name, 127) >= 0) {
        curr = curr->next;
    }

    curr->next = newnode;
*/
	//printf("Name: %s\n",name);
	//printf("\n",head);
	struct node *newnode = (struct node*) malloc(sizeof(struct node));
	struct node *temp, *previous;

	previous = &(*head);
	//temp = &(*head);
	temp = *head;
	if (name == NULL){ return; }

	else if ( *head == NULL){
		//struct node *newnode = (struct node*) malloc(sizeof(struct node));
		head = &newnode;
		newnode->name = name;
		newnode->next = NULL;
		return;
	}
	while ( temp->next != NULL){
		if (strcasecmp(temp->name, name) < 0){
			//struct node *newnode = (struct node*) malloc(sizeof(struct node));
			head = &newnode;
			newnode->next = temp;
			newnode->name = name;
			temp = temp->next;
			previous = previous->next;
		}else if (strcasecmp(temp->name, name) >= 0){
			newnode->name = name;
			previous->next = newnode; //maybe &newnode
			newnode->next = temp;
		}
	}
	






/*
	while (*head != NULL){

		if(strcasecmp(*name, curr->name) < 0 && (*head)->next == NULL){
			struct node *insert = malloc(sizeof(struct node));
			insert->name = name;
			curr = &insert;

		}else{
			curr = curr->next;
		}

	}

*/




}


void list_print(struct node *list) {
    int i = 0;
    printf("\n\nDumping list\n");
    while (list != NULL) {
        printf("%d: %s\n", i+1, list->name);
        i += 1;
        list = list->next;
    }
}

void list_clear(struct node *list) {
    while (list != NULL) {
        free (list);
        list = list->next;
    }
}

int main(int argc, char **argv)
{
    struct node *head = NULL;

    char s1[] = "apple";
    char s2[] = "banana";
    char s3[] = "coconut";
    char s4[] = "date";
    char s5[] = "fig";
    char s6[] = "grape";

    list_insert_ordered(NULL, &head);
    list_insert_ordered(s2, &head);
    list_insert_ordered(s3, &head);
    list_insert_ordered(s1, &head);
    list_insert_ordered(s5, &head);
    list_insert_ordered(s6, &head);
    list_insert_ordered(s4, &head);

    list_print(head);
    list_clear(head);
    printf("I finished! (but you still need to check memory leaks!)\n");

    return 0;
}
