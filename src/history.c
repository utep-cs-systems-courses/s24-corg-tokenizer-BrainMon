#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"

/*
typedef struct s_Item {
    int id;
    char *str;
    struct s_Item *next;
} Item;

typedef struct s_List {
    struct s_Item *root;
} List;
*/

/* Initialize the linked list to keep the history. */
List* init_history() {
    List *list = (List*) malloc(sizeof(List));

    list->root = NULL;
    return list;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store*/
void add_history(List *list, char *str) {
    Item *newItem = (Item *)malloc(sizeof(Item));
    int i = 2;

    newItem->id = (list->root == NULL) ? 1 : list->root->id + 1; // Assign unique id
    newItem->str = strdup(str);
    newItem->next = NULL;

    if (list->root == NULL) {
        list->root = newItem;
    } else {
        Item *current = list->root;
        while (current->next != NULL) {
            current = current->next;
	    i++;
        }
	newItem->id = i;
        current->next = newItem;
    }
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id) {
  Item *current = list->root;
  while (current != NULL) {
    if (current->id == id) {
      return current->str;
    }
    current = current->next;
  }

  return NULL; // ID not found
}

/* Print the entire contents of the list. */
void print_history(List *list) {
  Item *current = list->root;
  while (current != NULL) {
    printf("Item ID: %d, String: %s\n", current->id, current->str);
    current = current->next;
  }
}

/* Free the history list and the strings it references. */
void free_history(List *list) {
  Item *current = list->root;
  while (current != NULL) {
    Item *temp = current;
    current = current->next;
    free(temp->str);
    free(temp);
  }
  free(list);
}
