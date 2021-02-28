#include <stdio.h> //This file makes it so functions work with normal definitions without having to specifically define them. So, including this is what makes the printf function work.

int main() {
  char pitches[] = {74, 68, 54, 28, 89, 51, 35}; //setting up the initial array
  int i = 0;
  while (i < 6) { //in this while loop, we're comparing numbers to the one in front of it. That's why once we get to the 6th place number (starting from 0), we are at the end, and can stop the comparisions
    int num1 = pitches[i]; //This is the number in the array that starts the comparison
    int num2 = pitches[i+1];//this says we'll compare to the number next to (in front of) it
    if (num1 > num2) { //if the number to the left is bigger than the number to the right, then -
      pitches[i] = num2; //they will switch places and the smaller one will move to the the number on the left
      pitches[i+1] = num1;
      if (i > 0) {i--;} //this just moves back one and in the function of this code (but not too far back to space -1 before the array, hence that i must be bigger than 0 to go backwards) - this makes it look back to the last one so it will keep sorting until definitely the one all the way at the left is indeed the smallest
    }
    else { //if the number on the right is bigger (after the switching, etc), then this has us move forward to the next number (until we get to the end, since the while loop does it only until we've gotten to one below 6th place (smaller than 6))
      i++;
    }
  }
  for (int i = 0; i < 7; i++) { //In this for loop, this will print through the array.
    printf("MIDI Pitch Value: %d\n", pitches[i]); //(just a print function with arguments for printing the pitches within the array now that they're in the correct order)
  }


  return 0; //0 means we've reached the end
}
