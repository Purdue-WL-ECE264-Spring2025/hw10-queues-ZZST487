// #include "linked_list.h"

// #include <stdlib.h>

// struct list_node *new_node(size_t value) { return NULL; }

// void insert_at_head(struct linked_list *list, size_t value) {}

// void insert_at_tail(struct linked_list *list, size_t value) {}

// size_t remove_from_head(struct linked_list *list) { return 0; }

// size_t remove_from_tail(struct linked_list *list) { return 0; }

// void free_list(struct linked_list list) {}

// // Utility function to help you debugging, do not modify
// void dump_list(FILE *fp, struct linked_list list) {
//   fprintf(fp, "[ ");
//   for (struct list_node *cur = list.head; cur != NULL; cur = cur->next) {
//     fprintf(fp, "%zu ", cur->value);
//   }
//   fprintf(fp, "]\n");
// }


// #include <stdlib.h>
// #include "linked_list.h"

// typedef struct Node {
//     int data;
//     struct Node* next;
// } Node;

// typedef struct LinkedList {
//     Node* head;
//     Node* tail;
// } LinkedList;

// LinkedList* create_linked_list() {
//     LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
//     list->head = NULL;
//     list->tail = NULL;
//     return list;
// }

// void insert_at_head(LinkedList* list, int value) {
//     Node* new_node = (Node*)malloc(sizeof(Node));
//     new_node->data = value;
//     new_node->next = list->head;
//     list->head = new_node;
//     if (list->tail == NULL) {
//         list->tail = new_node;
//     }
// }

// void insert_at_tail(LinkedList* list, int value) {
//     Node* new_node = (Node*)malloc(sizeof(Node));
//     new_node->data = value;
//     new_node->next = NULL;
//     if (list->tail != NULL) {
//         list->tail->next = new_node;
//     }
//     list->tail = new_node;
//     if (list->head == NULL) {
//         list->head = new_node;
//     }
// }

// int remove_from_head(LinkedList* list) {
//     if (list->head == NULL) {
//         return -1; // Indicates that the list is empty
//     }
//     Node* temp = list->head;
//     int value = temp->data;
//     list->head = list->head->next;
//     if (list->head == NULL) {
//         list->tail = NULL;
//     }
//     free(temp);
//     return value;
// }

// int remove_from_tail(LinkedList* list) {
//     if (list->tail == NULL) {
//         return -1; // Indicates that the list is empty
//     }
//     Node* temp = list->tail;
//     if (list->head == list->tail) {
//         list->head = list->tail = NULL;
//     } else {
//         Node* current = list->head;
//         while (current->next != list->tail) {
//             current = current->next;
//         }
//         list->tail = current;
//         list->tail->next = NULL;
//     }
//     int value = temp->data;
//     free(temp);
//     return value;
// }

// void free_linked_list(LinkedList* list) {
//     Node* current = list->head;
//     while (current != NULL) {
//         Node* next = current->next;
//         free(current);
//         current = next;
//     }
//     free(list);
// }





#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the head
void insert_at_head(Node** head, int data) {
    Node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a node at the tail
void insert_at_tail(Node** head, int data) {
    Node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to remove a node from the head
int remove_from_head(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = *head;
    int data = temp->data;
    *head = (*head)->next;
    free(temp);
    return data;
}

// Function to remove a node from the tail
int remove_from_tail(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = *head;
    if (temp->next == NULL) {
        int data = temp->data;
        free(temp);
        *head = NULL;
        return data;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    int data = temp->next->data;
    free(temp->next);
    temp->next = NULL;
    return data;
}

// Function to free the linked list
void free_list(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}