#include <stdio.h> //This file makes it so functions work with normal definitions without having to specifically define them. So, including this is what makes the printf function work.

int main() {
  int numbers[] = {5, 9, 1, 2, 4, 8, 3}; //setting up the initial array
  for (int i = 0; i < 3; i++) {//okay, so these numbers are the numbers *of* the array - meaning WHERE they sit in the order. So, 5 (the first number) corresponds with 0, since it has the first spot in the order. Then, "9" is 1, "1" is 2 and so on - they're assigned the numbers they appear in the array. Since there are 7 numbers, 0, 1, and 2 will need to be switched with 4, 5, and 6 respectively. (and 3 will stay the same), so since 0, 1, and 2 need to be switched, that's why we're looking for "numbers" (aka order in the array) starting with 0 and going to 2 (aka smaller than 3)
    int num1 = numbers[i]; //i is the place in the array we just described above, and will cycle through based on parameters above
    int num2 = numbers[6-i]; //this is the initial equation will switch the places (since 0 needs to switch with 6, 1 with 5 etc, and they all follow this equation)
    numbers[6-i] = num1;
    numbers[i] = num2;
  }
  for (int i = 0; i < 7; i++) {
    printf("The value of arr at index %i is %i\n", i, numbers[i]); //this prints the value of all the various places in the array as they all switch. It prints multiple lines becase this is a function in the for loop
  }


  return 0; //0 means we've reached the end
}
