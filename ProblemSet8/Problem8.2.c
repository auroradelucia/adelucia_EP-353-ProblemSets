#include <stdio.h>
#include <stdlib.h>
#include <string.h> //to give us access to known functions, like memset
#include <sndfile.h>

//don't forget to use -lsndfile at the end of the file name when compiling this

#define kBufferSize 4096

int main(void) {
  SNDFILE *inFile = NULL, *outFile = NULL;
	SF_INFO sfInfo;
  float buffer[kBufferSize];

  memset(&sfInfo, 0, sizeof(SF_INFO));

  inFile = sf_open("sine.wav", SFM_READ, &sfInfo); //opening the original sound file
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

  outFile = sf_open("sineInverted.wav", SFM_WRITE, &sfInfo); //the file to write to

  if(!outFile){ //opening the file to write to
    printf ("Oh goodness gracious! The SineInverted file's not opening! Different cry time.\n");
		puts (sf_strerror(NULL));
		return 1;
	}

  int readcount;
  while((readcount = sf_read_float(inFile, buffer, kBufferSize)) > 0) {
    for (int i = 0; i < kBufferSize; i++){
      buffer[i] = buffer[i] * -1; //changing everything from positive to negative in order to invert it
    }
    sf_write_float(outFile, buffer, readcount);
  }

  sf_close(inFile); //closing the files 
	sf_close(outFile);

  return 0;
}
