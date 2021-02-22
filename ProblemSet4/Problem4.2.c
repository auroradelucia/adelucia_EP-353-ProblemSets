#include <stdio.h> //This file makes it so functions work with normal definitions without having to specifically define them. So, including this is what makes the printf function work.
#include <stdlib.h>//Standard library header, needed for if there's an error it exits (I'm just leaving this here for safety, but I don't think it's absolutely necessary in this one)

void beatbox(int bar) {
  if (bar%4 == 0) {//if there's not a remainder when divided by 4, it will print Potato Cats
    printf("Potato Cats!\n\n");
  }
  else {printf("Boots N Cats N\n");} //otherwise, when it's not divisible by 4, it will print Boots N Cats N
}

int main() {
  int b[1]; //declaring the array that is b
  printf("How many bars would you like to beatbox? (Please answer as an integer, don't spell out the number)\n"); //that extra ask in parenthesis is because if you type "five" it converts and runs a gazillion times
  scanf("%d", b); //%d is the integer type. And the argument b assigns the integer into the array
  printf ("\n"); //this is just putting a new line between the answer given and the print in terminal, to make it look better/separate them more
  for (int i = 1; i <= b[0]; i++) {beatbox (i);
  }


  return 0; //\n is for new lines //0 means we've reached the end
}
