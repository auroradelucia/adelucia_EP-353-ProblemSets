#include <stdio.h> //This file makes it so functions work with normal definitions without having to specifically define them. So, including this is what makes the printf function work.

void setArray(int *numbers, int value, int size){
  for (int index = 0; index < size; index++) {
    numbers [index] = value;
  }
}

int main() {
  int arraySize = 8;
  int numbers [arraySize];
  printf("Please enter a number!\n");
  int usersChoice;
  scanf("%i", &usersChoice);
  setArray(numbers, usersChoice, arraySize);
  for (int index = 0; index < arraySize; index++) {
    if (index == arraySize - 1) {
      printf("%i\n", numbers[index]);
    }
    else
      printf("%i, ", numbers[index]);
  }

  return 0; //0 means we've reached the end
}
