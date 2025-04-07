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
Node* create_node(infotype data){
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
bool is_exist(LinkedList list, infotype data){
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
Node* find_node(LinkedList list, infotype data){
  Node* curr;

  curr = list.head;
  while(curr != NULL){
    if(curr->data == data){
      return curr;
    }else{
      curr = curr->next;
    }
  }

  return NULL;
}
Node* find_prev_node(LinkedList list, Node* node){
  Node* curr;
  curr = list.head;

  if(curr == NULL || node == NULL){
    return NULL;
  }

  while(curr != NULL && curr->next != node){
    curr = curr->next;
  }

  return curr;
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

void destroy_list(LinkedList* list){
  Node* curr;
  Node* temp;

  curr = list->head;
  while(curr != NULL){
    temp = curr;
    curr = curr->next;

    temp->next = NULL;
    free(temp);
  }
  list->head = NULL;
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


void insert_first(LinkedList* list, infotype data){
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

void insert_last(LinkedList* list, infotype data){
  Node  *new_node, *curr;
  new_node = create_node(data);
  if(new_node == NULL) return;

  curr = list->head;
  if(curr == NULL){
    insert_first(list, data);
  }else{
    while(curr->next != NULL){
      curr = curr->next;
    }
    curr->next = new_node;
  }
}

void insert_after(LinkedList* list, infotype prev_data, infotype data){
  Node *new_node, *prev, *after;
  new_node = create_node(data);
  if(new_node == NULL) return;

  prev = find_node(*list, prev_data);

  if(prev == NULL){
    printf("Node with data %d not found\n", prev_data);
    return;
  }
  after = prev->next;
  prev->next = new_node;
  new_node->next = after;

}

void insert_at(LinkedList* list, int position, infotype data){
  Node *new_node, *curr;
  new_node = create_node(data);
  if(new_node == NULL) return;

  if(position < 1 || position > get_length(*list)){
    printf("Invalid position\n");
    return;
  }

  if(position == 1){
    insert_first(list, data);
  }else{
    curr = list->head;
    for(int i = 1; i < position-1; i++){
      curr = curr->next;
    }
    new_node->next = curr->next;
    curr->next = new_node;
  }
}

void insert_before(LinkedList* list, infotype next_data, infotype data){
  Node *new_node, *prev, *next;
  new_node = create_node(data);
  if(new_node == NULL) return;

  prev = find_prev_node(*list, find_node(*list, next_data));
  if(prev == NULL){
    printf("Node with data %d not found\n", next_data);
    return;
  }
  next = prev->next;
  prev->next = new_node;
  new_node->next = next;
}

void delete_first(LinkedList* list, infotype* temp){
  Node* curr;
  if(is_list_empty(*list)){
    printf("List is empty\n");
    return;
  }else{
    curr = list->head;
    *temp = curr->data;
    list->head = curr->next;
    free(curr);
  }
}
void delete_last(LinkedList* list, infotype* temp){
  Node *curr, *prev;
  if(is_list_empty(*list)){
    printf("List is empty\n");
    return;
  }else{
    curr = list->head;
    prev = NULL;
    while(curr->next != NULL){
      prev = curr;
      curr = curr->next;
    }
    *temp = curr->data;
    if(prev == NULL){
      free(curr);
      list->head = NULL;
    }else{
      free(curr);
      prev->next = NULL;
    }
  }
}
