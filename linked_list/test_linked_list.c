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

  insert_first(&myList, 20);
  insert_first(&myList, 30);
  insert_first(&myList, 35);
  insert_first(&myList, 40);

  insert_first(&myList, 50);
  print_list(myList);
  printf("List lenght: %d\n", get_length(myList));

  return 0;
}
