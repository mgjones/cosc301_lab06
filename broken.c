#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[128];
    struct node *next; 
};

void list_insert_ordered(char *name,  struct node **head) {
    struct node *newnode = malloc(sizeof(struct node));
    strncpy(newnode->name, name, 127);
    
    if (name == NULL) {
        return;
    }
        
    if (*head == NULL) {
        *head = newnode;
    }
    
    if (strncasecmp(name, (*head)->name, 127) < 0) {
        *head = newnode;    
        newnode->next = *head;
    }

    struct node *curr = malloc(sizeof(head));
    curr = *head;

    while (curr->next != NULL && strncasecmp(name, curr->next->name, 127) >= 0) {
        curr = curr->next;
    }
    
    curr->next = newnode;
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

    list_insert_ordered(s2, &head);
    list_insert_ordered(s3, &head);
    list_insert_ordered(s1, &head);
    list_insert_ordered(s5, &head);
    list_insert_ordered(s6, &head);
    list_insert_ordered(s4, &head);
    list_insert_ordered(NULL, &head);

    list_print(head);
    list_clear(head);
    printf("I finished! (but you still need to check memory leaks!)\n");

    return 0;
}
