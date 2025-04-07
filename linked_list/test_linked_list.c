// File: main_linked_list.c
// Author: Maulana Ishak
// Date: 06-04-2025
// Description: Main function to test linked list implementation in C
// License: MIT License
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main()
{
  LinkedList myList;
  create_list(&myList);
  printf("Initial State: ");
  print_list(myList);
  printf("List lenght: %d\n", get_length(myList));
  
  insert_last(&myList, 10);
  print_list(myList);
  
  insert_first(&myList, 20);
  print_list(myList);

  insert_last(&myList, 32);
  print_list(myList);

  insert_last(&myList, 60);
  print_list(myList);
  
  insert_after(&myList, 20, 25);
  print_list(myList);
  
  insert_after(&myList, 10, 199);
  print_list(myList);
  
  insert_at(&myList, 2, 100);
  print_list(myList);

  insert_before(&myList, 100, 99);
  print_list(myList);
  insert_before(&myList, 10, 9);
  print_list(myList);

  printf("List lenght: %d\n", get_length(myList));
  return 0;
}
