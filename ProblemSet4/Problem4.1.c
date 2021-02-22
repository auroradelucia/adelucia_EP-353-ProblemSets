#include <stdio.h> //This file makes it so functions work with normal definitions without having to specifically define them. So, including this is what makes the printf function work.
#include <stdlib.h>//Standard library header, needed for if there's an error it exits
#include <errno.h>//this is for the perror function (so it knows what to do with errors)

int main(int argc, char **argv) {
  int count = 0; //count starts at 0 before we start counting lines
  int c; //naming the variable to help us count up as we see how many lines there are
  char *input = argv[1];
  FILE *inputfile;

  inputfile = fopen (input, "r");
  if (inputfile == 0) //this if statement means if there's no file, it won't work
  {
    perror ("cannot open input file \n");
    exit (-1);
  }
  else { //this else statement means that if there is a file, we're going forward
    while ((c = fgetc (inputfile)) != EOF) //this just means we go until the end of file, and then we'll print
    {
      if (c == '\n')//\n means new line
      {
        count++; //this just means that we'll count up by one every time the character starts a new line
      }
    }
  }
  printf("The number of newlines in %s is %d\n", input, count); //these arguments say the file type we're using and then the number of lines we've ended up with


  return 0; //\t is for each of the tabs, and \n is for new lines //0 means we've reached the end
}
