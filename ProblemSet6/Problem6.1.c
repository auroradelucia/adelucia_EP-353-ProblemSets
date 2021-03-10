#include <stdio.h> //This file makes it so functions work with normal definitions without having to specifically define them. So, including this is what makes the printf function work.

void countCharacter(char *string){//making the function to count the characters
  int i; //declaring integer i
  for (i = 0; string[i] != '\0'; i++);//this will count the string starting from 0 until the string ends (\0)
  printf("The string, \"%s\", has %i characters.\n", string, i); //This is the final sentence that will be printed. Extra backslashes are to sepeate the quotes we want printed from the quotes that declare the sentence
}

int main() {
  char string [100]; //declaring the string (or character array)
  printf("Please type a string below - for example, a fun quote! (Thank you!)\n"); //This is will print the prompt for our user to enter a quote, or a string
  scanf("%[^\n]", string); //This reads what our user has input
  countCharacter(string); //This runs what your user has input through the function that counts the chracters (that has a print function at the end already, and therefore will print our final statement)

  return 0; //0 means we've reached the end
}
