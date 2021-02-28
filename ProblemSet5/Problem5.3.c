#include <stdio.h> //This file makes it so functions work with normal definitions without having to specifically define them. So, including this is what makes the printf function work.

int main() {
  char lyric [128];
  printf("Enter the first line of your most favorite lyric: ");
  scanf("%128[0-9a-zA-Z'\" ]", lyric);//the internal backslash helps us know not to treat the internal quote mark as the end of the string
  for (int i = 0; lyric[i] != '\0'; i++) {
    char temp = lyric[i];
    if (temp >= 'A' && temp <= 'Z') {
      temp += 32; //We're adding 32 to change uppercase to lowercase, since that's the difference between them in ASCII
    }
    else if (temp >= 'a' && temp <= 'z') {
      temp -= 32; //same deal as above, subtracting 32 according to ASCII to change lowecase to uppercase
    }
    lyric[i] = temp;
    printf("%c", lyric[i]);
  }
printf("\n"); //This had to be in a seperate line, so as not to put new lines *between* characters, but instead at the whole end.
  return 0; //0 means we've reached the end
}
