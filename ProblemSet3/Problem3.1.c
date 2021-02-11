#include <math.h> //This file makes it so math functions work with normal definitions without having to specifically define them. So, including this is what makes the math stuff work.
#include <stdio.h> //This file makes it so functions work with normal definitions without having to specifically define them. So, including this is what makes the printf function work.

int main() {
char midiNote = 'C'; // C in this case equals 67
float frequency = pow(2, ((float)midiNote-69)/12)*440;

printf("The frequency of a MIDI note number %d is %fHz\n", midiNote, frequency);//using %d instead of %C because I want the numerical value, not the literal character
return 0; //\t is for each of the tabs, and \n is for new lines //0 means we've reached the end
}
