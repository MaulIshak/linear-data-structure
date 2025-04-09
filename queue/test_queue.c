// File: test_queue.c
// Author: Maulana Ishak
// Date: 09-04-2025
// Description: Main function to test queue implementation in C
// License: MIT License
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{

  Queue myQueue;
  create_queue(&myQueue);
  infotype temp;
  printf("Initial State: ");
  print_queue(myQueue);
  
  enqueue(&myQueue, 10);
  enqueue(&myQueue, 20);
  enqueue(&myQueue, 30);
  enqueue(&myQueue, 40);
  print_queue(myQueue);
  dequeue(&myQueue, &temp);
  printf("Dequeued element: %d\n", temp);
  print_queue(myQueue);
  dequeue(&myQueue, &temp);
  printf("Dequeued element: %d\n", temp);
  print_queue(myQueue);

  return 0;
}
