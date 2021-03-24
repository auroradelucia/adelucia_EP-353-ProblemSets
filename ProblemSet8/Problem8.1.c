#include <stdio.h>
#include <stdlib.h>
#include <string.h> //for known functions, like memset
#include <sndfile.h>

//don't forget to use -lsndfile at the end of the file name when compiling this 

#define kBufferSize 4096

int main(void) {
  SNDFILE *inFile = NULL, *outFile = NULL; //pointers to a sound files
	SF_INFO sfInfo; //hold an information about a sound file
  float buffer[kBufferSize]; //Buffer for holding samples

  memset(&sfInfo, 0, sizeof(SF_INFO));

  inFile = sf_open("sine.wav", SFM_READ, &sfInfo); //opening the original file
  if(!inFile){
    printf ("Sad devastated mangled face. So sad. The file , alas, is not open. Cry time.\n");
		puts (sf_strerror (NULL));
		return 1;
  }

  if(!sf_format_check(&sfInfo)){
    sf_close(inFile);
		printf("Invalid encoding\n");
		return 1;
	}

  outFile = sf_open("sine5.wav", SFM_WRITE, &sfInfo); //the file we're gonna write to

  if(!outFile){
    printf ("Oh goodness gracious! The file's not opening! Different cry time.\n");
		puts (sf_strerror(NULL));
		return 1;
	}

  int readcount;
  for (int i = 0; i < 5; i++) {//this is adding a second 5 times
  while((readcount = sf_read_float(inFile, buffer, kBufferSize)) > 0) {
    sf_write_float(outFile, buffer, readcount);
  }
  sf_seek(inFile, 0, SEEK_SET); //making sure the second gets added by going back to it
}

  sf_close(inFile);//closing files that are open
	sf_close(outFile);

  return 0;
}
