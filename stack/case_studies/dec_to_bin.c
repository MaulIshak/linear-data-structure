// File: dec_to_bin.c
// Author: Maulana Ishak
// Date: 09-04-2025
// Description: Program to convert decimal number to binary using stack
// License: MIT License

#include <stdio.h>
#include <stdlib.h>
#include "../stack.h"

int main()
{
  Stack myStack;
  infotype temp;
  int number;
  create_stack(&myStack);

  printf("Enter Decimal Number: ");
  scanf("%d", &number);

  while(number > 0){
    push(&myStack, number%2);
    number /= 2;
  }
  printf("Binary: ");
  while (!is_stack_empty(myStack))
  {
    pop_print(&myStack, &temp);
  }
  printf("\n");
  return 0;
}
