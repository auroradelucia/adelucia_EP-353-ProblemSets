#include <stdio.h> //This file makes it so functions work with normal definitions without having to specifically define them. So, including this is what makes the printf function work.

int note = 68;
int velocity = 110;
int channel = 1;

int main() {
  printf("This MIDI note consists of: \n\t Pitch: \t %d \n\t Velocity: \t %d \n\t Channel: \t %d \n\n", note, velocity, channel); //the last 3 words are the arguments saying where the values will be printed

velocity = 0; //no need to repeat "int" because it was already established. Now we are just changing values

  printf("This MIDI note consists of: \n\t Pitch: \t %d \n\t Velocity: \t %d \n\t Channel: \t %d \n\n", note, velocity, channel);
  return 0; //\t is for each of the tabs, and \n is for new lines //0 means we've reached the end
}
