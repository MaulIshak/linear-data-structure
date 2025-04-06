// File: linked_list.h
// Author: Maulana Ishak
// Date: 06-04-2025
// Description: Header file for linked list implementation in C
// License: MIT License

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

#define info int

// Define the structure for a node in the linked list
typedef struct Node {
    info data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

// Utility Functions
// Initialize the linked list
void create_list(LinkedList* list);
// Create a new node with the given data
Node* create_node(info data);
// Check if the list is empty
bool is_list_empty(LinkedList list);
// Check if given data exists in the list
bool is_exist(LinkedList list, info data);
// Find a node with the given data in the list
Node* find_node(LinkedList list, info data);
// Find the previous node of the given node in the list
Node* find_prev_node(LinkedList list, Node* node);
// Get the length of the linked list
int get_length(LinkedList list);

// destroy the linked list and free memory
void destroy_list(LinkedList* list);
// Print the linked list in forward order
void print_list(LinkedList list);
// Print the linked list in reverse order
void print_list_reverse(LinkedList list);

// Insert Operations
// Insert a new node at the beginning of the list
void insert_first(LinkedList* list, info data);
// Insert a new node at the end of the list
void insert_last(LinkedList* list, info data);
// Insert a new node after the given node in the list
void insert_after(LinkedList* list, Node* prev_node, info data);
// Insert a new node at the given position in the list
void insert_at(LinkedList* list, int position, info data);

// Delete Operations
// Delete the first node in the list
void delete_first(LinkedList* list, info* temp);
// Delete the last node in the list
void delete_last(LinkedList* list, info* temp);
// Delete the node after the given node in the list
void delete_after(LinkedList* list, Node* prev_node, info* temp);
// Delete the node with the given data in the list
void delete_node(LinkedList* list, info data, info* temp);
// Delete the node at the given position in the list
void delete_at(LinkedList* list, int position, info* temp);



#endif // !LINKED_LIST_H