#include <math.h> //This file makes it so math functions work with normal definitions without having to specifically define them. So, including this is what makes the math stuff work.
#include <stdio.h> //This file makes it so functions work with normal definitions without having to specifically define them. So, including this is what makes the printf function work.


int main() {

  for (int i = 11; i > -1; i--) { //i is 11 because that's the top of the range, and i must be bigger than -1 since it I want it to stop at 0. i goes -- instead of ++ because I want it in descending order
    switch (i) {
      case 11:
            printf("B " );
          break;
        case 10:
                printf("Bb " );
          break;
        case 9:
                printf("A " );
          break;
        case 8:
                printf("Ab " );
          break;
        case 7:
                printf("G " );
          break;
        case 6:
                printf("Gb " );
          break;
        case 5:
                printf("F " );
            break;
        case 4:
                printf("E " );
            break;
        case 3:
                printf("Eb " );
            break;
        case 2:
                printf("D " );
            break;
        case 1:
                printf("Db " );
            break;
        case 0:
                printf("C " );
            break;
      default: ;
    } //Basically, this whole swtich command with "case"s and "printf"s are just saying if the integer is the ones I mentioned, then it prints the notes I mention. I put spaces after the note, so they would show up as you asked in the assignment
  }

  printf("\n");
  return 0; //\t is for each of the tabs, and \n is for new lines //0 means we've reached the end
}
