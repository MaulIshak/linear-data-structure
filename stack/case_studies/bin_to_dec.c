// File: bin_to_dec.c
// Author: Maulana Ishak
// Date: 09-04-2025
// Description: Program to convert binary number to decimal using stack
// License: MIT License

#include <stdio.h>
#include <stdlib.h>
#include "../stack.h"

#define MAX_SIZE 1024

int power(int a, int b){
  int result = 1;
  if(a == 0){
    return 0;
  }
  for (int i = 0; i < b; i++)
  {
    result *= a;
  }
  return result;
}

int main()
{
  Stack binStack;
  infotype dec;
  int i , resultElmt, result = 0, bin;
  char* binStr = (char*)malloc(sizeof(char) * MAX_SIZE);

  if (binStr == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  printf("Enter a binary number: ");
  scanf("%s", binStr);

  create_stack(&binStack);

  i = 0;
  while(binStr[i] != '\0'){
    bin = binStr[i] - '0';
    push(&binStack, bin);
    i++;
  }

  i = 0;
  while(!is_stack_empty(binStack)){
    pop(&binStack, &resultElmt);
    result += resultElmt * power(2,i);
    i++;
  }

  printf("Decimal: %d\n", result);

  free(binStr);
  return 0;
}

