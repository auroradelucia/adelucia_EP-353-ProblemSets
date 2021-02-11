#include <stdio.h> //This file makes it so functions work with normal definitions without having to specifically define them. So, including this is what makes the printf function work.

float frequency = 415.304;
float decibel = -47.9;

int main() {
  printf("This sine tone has: \n\t Frequency of %.3fHz \n\t Decibel level of %.1fdB \n", frequency, decibel); //the .numbers before the fs are the "precision" numbers, which say how many decimal places we show in the printing
  return 0; //\t is for each of the tabs, and \n is for new lines //0 means we've reached the end
}
