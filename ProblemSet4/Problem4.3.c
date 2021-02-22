#include <math.h> //This file makes it so math functions work with normal definitions without having to specifically define them. So, including this is what makes the math stuff work.
#include <stdio.h> //This file makes it so functions work with normal definitions without having to specifically define them. So, including this is what makes the printf function work.

int global = 9; //this is a global integer meaning it's malleable in all functions throughout

void decrement() {
  int local = 9; //this variable is set inside of this function, so only things inside this function will affect it
  printf("  %d   |   %d   \n", local, global);
  local--; //even those this one also technically goes down by one, it's reset every time, since it's set to 9 at the top of every function
  global--; //these -- mean every time it prints, it will go down one
}

int main() {
  printf("\nlocal | global\n--------------\n"); //this is just the header on two lines (starting with a blank line as well for clarity and aesthetic)
  for (int i = 10; i > 0; i--) { //this is just how the line prints 10 times
    decrement(); //this is running the function decrement
  }



  return 0; //\t is for each of the tabs, and \n is for new lines //0 means we've reached the end
}
