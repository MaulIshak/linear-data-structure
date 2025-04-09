// File: queue.h
// Author: Maulana Ishak
// Date: 09-04-2025
// Description: Header file for queue implementation in C
// License: MIT License

#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 20

#include "../linked_list/linked_list.h"

typedef struct Queue{
  Node* front;
  Node* rear;
} Queue;

// Function to create a queue
void create_queue(Queue* queue);
// Function to check if the queue is empty
bool is_queue_empty(Queue queue);
// Function to check if the queue is full
bool is_queue_full(Queue queue);
// Function to enqueue an element into the queue
void enqueue(Queue* queue, infotype data);
// Function to dequeue an element from the queue
void dequeue(Queue* queue, infotype* data);
// Function to get the front element of the queue
void destroy_queue(Queue* queue);
// Function to print the queue
void print_queue(Queue queue);




#endif // QUEUE_H