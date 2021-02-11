#include <math.h> //This file makes it so math functions work with normal definitions without having to specifically define them. So, including this is what makes the math stuff work.
#include <stdio.h> //This file makes it so functions work with normal definitions without having to specifically define them. So, including this is what makes the printf function work.

int main() {
  char note = 'F';
  int pitchClass = 12; //if pitch class is not between 0-11 (stays at 12), that means the computer hasn't done anything and I've failed my switch, or it's a non-musical letter. So, this lets me know something is wrong - if something is wrong

    switch (note) {
      case 'C':
            pitchClass = 0;
          break;
      case 'D':
              pitchClass = 2;
          break;
      case 'E':
              pitchClass = 4;
          break;
      case 'F':
              pitchClass = 5;
          break;
      case 'G':
                pitchClass = 7;
          break;
      case 'A':
                pitchClass = 9;
          break;
      case 'B':
                pitchClass = 11;
          break;

      default: ;
    }

    if (pitchClass == 12) {printf("%c is not a note\n", note);} //this is just having us look at the switch commands above. If we put in a note, then it's assigned what will happened in each case. If it's a note we don't use, it will tell us here that it's not a note.
    else {printf ("A note '%c' translates to %d in pitch class.\n", note, pitchClass);}

  return 0; //\t is for each of the tabs, and \n is for new lines //0 means we've reached the end
}
