#include <stdio.h> //This file makes it so functions work with normal definitions without having to specifically define them. So, including this is what makes the printf function work.

void leftRotateByOne(int *numbers, int size) { //this is setting up the ability to rotate by one to the left whenever we have a negative number
	int temp = numbers[0];
	for(int ro = 0; ro < size-1; ro++) {
		numbers[ro] = numbers[ro+1];
	}
	numbers[size-1] = temp;
}

void rightRotateByOne(int *numbers, int size) {//this is setting us up up to rotate to the right when there's a positive number
	int temp = numbers[size-1];
	for(int ro = size-1; ro > 0; ro--) {
		numbers[ro] = numbers[ro-1];
	}
	numbers[0] = temp;
}

void rotate(int *numbers, int size, int steps) { //now that we've established which kind of number goes which way, we're asking the comptuer to pay attention and go to the left or right depending on what the variable is
	if(steps > 0) {
		for(int i = 0; i < steps; i++) {
			rightRotateByOne(numbers, size);
		}
	}
	if(steps < 0) {
		for(int i = 0; i < -steps; i++) {//as stated above, this is whether the computer rotates to left of right (in this case, left)
			leftRotateByOne(numbers, size);
		}
	}
}

void printArray(int *array, int length){
	for(int k = 0; k < length; k++) {
		printf("%d", array[k]); //one the header has printed, this will print the numbers that were input
		if(k+1 != length) {
			printf(", "); //and this adds commas between those numbers
		}
	}
	printf("\n"); //once we have the entire row of numbers, we print the new line to go to the next one
}

int main() {
	int i = 0;
	int size = 5;
	int numbers[5]; //initializing our array with 5 characters, since we're asking people to input 5 variables
	int steps;

	printf("Input a set of 5 numbers, separated by commas, please.\n"); //This is where we ask users to input their set of numbers

	for(i = 0; i < size; i++) { //reading what the user input
		scanf("%d,", &(numbers[i]));
	}

	printf("Input steps of rotation please.\n"); //so now we ask the user for number of steps to rotate
	scanf("%d", &steps); //and we read the amount of steps they put in
	printf("User input:            "); //this is basically a "header" to make it look like the print in the assignment. (Technically, these could've also been done with \t for tabs. Either way should work okay)

	printArray(numbers, size);
	rotate(numbers, size, steps);
	printf("After %d rotation:      ", steps); //this is another "header" at the top of the row
	printArray(numbers, size);

	return 0; //return 0 is just that we're fully finished
}
