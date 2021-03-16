#include <stdio.h> //This file makes it so functions work with normal definitions without having to specifically define them. So, including this is what makes the printf function work.
#include <stdlib.h> //Giving us more C funtion options to call
#include <stdbool.h>//So TRUE statements read

typedef struct { //doing this with typedef as opposed to struct Note (and putting "Note" after makes it easier to write just "Note" throughout the code)
        unsigned char pitch, velocity, channel;
} Note; //declaring a structure that we're gonna fill the values of (above - pitch, velocity, channel)

void printNote (Note *n){ //The printing function we'll use later
  printf("The MIDI Note has:\n");
  printf("Pitch -> %i\n", n -> pitch);
  printf("Velocity -> %i\n", n -> velocity);
  printf("Channel -> %i\n", n-> channel);
}

int main() {
        Note *usrNote;
        usrNote = (Note*) malloc (sizeof (Note));//setting aside space for the variables of Note.
        int tempPitch; //declaring a temporary variable while we decide if the variable fits the boundaries we've laid out
        while (true) {
                printf("Hey pal! Please input a pitch - somewhere between 0 and 127.\n");
                scanf("%i", &tempPitch); //we scan the temp variable we declared, that the user has entered in
                if (tempPitch >=0 && tempPitch <= 127) {//if the variable fits the bounds we've set, we move on
                        usrNote -> pitch = tempPitch; //and then we full pitch of our structure with the variable that was temp
                        break; //this just means we're good, we've gotten what we need. We can break out of the while loop and keep going on
                }
                else {printf("Oops! The number is outside the range. Please start over.\n");}
        }

        int tempVelocity; //this works the same as above for how we did pitch, only this time, it's velocity
        while (true) {
                printf("Thanks! Now, please enter a velocity, also between 0 and 127.\n");
                scanf("%i", &tempVelocity); //the ampersand gets us the original address to fully change the variable in the function
                if (tempVelocity >=0 && tempVelocity <= 127) {
                        usrNote -> velocity = tempVelocity;
                        break;
                }
                else {printf("Eep! The number is outside the range. Please try again.\n");}
        }

        int tempChannel; //this also works the same as how we did ptich, only this time, it's channel
        while (true) {
                printf("Great job! Lastly, please enter a channel between 1 and 16.\n");
                scanf("%i", &tempChannel);
                if (tempChannel >=1 && tempChannel <= 16) {
                        usrNote -> channel = tempChannel;
                        break;
                }
                else {printf("Gah! The number is outside the range. Please try again.\n");}
        }
        printNote(usrNote); //Now that we have all the values we need, this sends it to the global print function we defined earlier to print

        free(usrNote);//freeing up the space we'd set aside for the variables in Note, now that we're done with them (and printing them)

        return 0; //0 means we've reached the end
}
