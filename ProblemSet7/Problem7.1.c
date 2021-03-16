#include <stdio.h> //This file makes it so functions work with normal definitions without having to specifically define them. So, including this is what makes the printf function work.
#include <stdlib.h> //Giving us more C funtion options to call
#include <time.h>

int index2D(int x, int y, int width){
        return x + y * width;
}

void printColumnHeader (int numBeats){ //this is just printing those column headers for the cells Xs will go in, in the table
        printf("  |");
        for (int i = 0; i < numBeats; i++) {
                printf(" %d  ", i + 1);
        }
        printf("\n==+");
        for (int i = 0; i < numBeats; i++) {
                if (i <=8) {//when trying this at smaller than or equal to 9 (because I wanted double digit numbers to have extra room to accomodate them), it wasn't working, so I needed to set it to 8, I believe because it counts from 0
                        printf("===+");
                }
                else
                        printf("====+"); //the reason for the if else statement in this and all the other headers is because the single digit numbers need less space than the double digit ones
        }
        printf ("\n");
}

void printSeperator (int numBeats){ //this is just adding the lines between the rows
        printf("\n--+");
        for (int i = 0; i < numBeats; i++) { //'if else' continues to be to adjust space for single vs double digit numbers
                if (i <=8) {
                        printf("---+");
                }
                else
                        printf("----+");
        }
        printf("\n");
}

void printRowHeader (int Perc){ //this is adding the headers going vertically
        if (Perc >= 1 && Perc <= 9) { //as said before, this is for single vs double digit numbers
                printf("%d |", Perc);
        }
        else
                printf("%d|", Perc);
}

void printCellOn (int Beat, int beat) {
        if (Beat == 1) {
                if (beat <= 8)
                        printf(" x |"); //this is just adding Xs in cells for 1s, and not printing anything for 0, so it's physically showing the randomness
                else printf(" x  |");
        }
}

void printCellOff (int Beat, int beat) {
        if (Beat == 0) {
                if (beat <= 8)
                        printf("   |"); //this is just adding Xs in cells for 1s, and not printing anything for 0, so it's physically showing the randomness
                else printf("    |");
        }
}

int main() {
        int numBeats; //declaring a variable for beats which will be assigned by user input
        int numPercs; //declaring a variable for percussion sounds which will be assigned by user input
        printf("Hey user friend! How many beats would you like in the drum pattern?\n"); //asking the user this question
        scanf("%i", &numBeats); //scanning user answer; the ampersand gets us the original address to fully change the variable in the function

        printf("Thanks pal! Now, how many percussion sounds do you want in your drum kit?\n");
        scanf("%i", &numPercs);

        int *sequenceArray = malloc(numBeats * numPercs * sizeof(int)); //this is basically setting aside the RAM space for this array

        srand(time (NULL));

        for (int i = 0; i < numPercs * numBeats; i++) {
                sequenceArray[i] = rand()%2;//dividing by two will make the remainder 1 or 0 which are the numbers we want
        }

        printColumnHeader (numBeats); //we set up all these print functions above, and now we're using them with all our new information from the user
        for (int perc = 0; perc < numPercs; perc++) {
                printRowHeader (perc + 1); //this just makes it so it doesn't start printing at 1, and has 1 be the first row number it prints
                for (int beat = 0; beat < numBeats; beat++) {
                        printCellOn (sequenceArray[index2D(beat, perc, numBeats)], beat);
                        printCellOff (sequenceArray[index2D(beat, perc, numBeats)], beat);
                }
                printSeperator (numBeats);
        }

        free(sequenceArray); //and now I'm telling the computer, thanks for the RAM! You can have it back, buddy
        return 0; //0 means we've reached the end
}
