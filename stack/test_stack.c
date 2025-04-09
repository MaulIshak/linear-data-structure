// File: test_stack.c
// Author: Maulana Ishak
// Date: 09-04-2025
// Description: Main function to test stack implementation in C
// License: MIT License
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
  Stack myStack;
  infotype temp;

    // Initialize the stack
    create_stack(&myStack);
    printf("Initial State: ");
    print_stack(myStack);

    // Test pushing elements onto the stack
    printf("\nPushing elements onto the stack:\n");
    push(&myStack, 10);
    print_stack(myStack);
    push(&myStack, 20);
    print_stack(myStack);
    push(&myStack, 30);
    print_stack(myStack);
    push(&myStack, 40);
    print_stack(myStack);

    // Test popping elements from the stack
    printf("\nPopping elements from the stack:\n");
    pop_print(&myStack, &temp);

    pop_print(&myStack, &temp);
    
    pop_print(&myStack, &temp);

    pop_print(&myStack, &temp);

    print_stack(myStack);

  return 0;
}
