// File: linked_list.c
// Author: Maulana Ishak
// Date: 06-04-2025
// Description: Implementation of linked list functions in C
// License: MIT License

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"

// Initialize the linked list
void create_list(LinkedList* list){
  list->head = NULL;
}

// Create a new node with the given data
Node* create_node(info data){
  Node* new_node = (Node*)malloc(sizeof(Node));
  if(new_node == NULL){
    printf("Overflow, Memory allocation failed\n");
    return NULL;
  }
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Check if the list is empty
bool is_list_empty(LinkedList list){
  if(list.head == NULL){
    return true;
  }
  return false;
}

// Check if given data exists in the list
bool is_exist(LinkedList list, info data){
  Node* curr;

  curr = list.head;
  while(curr != NULL){
    if(curr->data == data){
      return true;
    }else{
      curr = curr->next;
    }
  }

  return false;
}
// Print the linked list in forward order
void print_list(LinkedList list){
  Node* curr;
  if(is_list_empty(list)){
    printf("list empty\n");
  }else{
    curr = list.head;
    while(curr->next != NULL){
      printf("[%d]->", curr->data);
      curr = curr->next;
    }
    printf("[%d]\n", curr->data);
  }
}
// Get the length of the linked list
int get_length(LinkedList list){
  Node* curr;
  int count;

  curr = list.head;
  count = 0;

  while(curr != NULL){
    count++;
    curr = curr->next;
  }

  return count;
  
}


void insert_first(LinkedList* list, info data){
  Node* new_node;
  new_node = create_node(data);
  if(new_node == NULL) return;

  if(is_list_empty(*list)){
    list->head = new_node;
  }else{
    new_node->next = list->head;
    list->head = new_node;
  }
}