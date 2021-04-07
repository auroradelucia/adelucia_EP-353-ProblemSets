#include <stdio.h>
#include <stdlib.h>
#include <string.h> //to give us access to known functions, like memset
#include <sndfile.h>
#include <math.h>

//don't forget to use -lsndfile at the end of the file name when compiling this

int main(void) {
        SNDFILE *inFile = NULL, *outFile = NULL;
        SF_INFO sfInfo;
        long long filesize;
        memset(&sfInfo, 0, sizeof(SF_INFO));

        inFile = sf_open("noisy.wav", SFM_READ, &sfInfo); //This is us opening the original file
        if(!inFile) {
                printf ("Sad devastated mangled face. So sad. The file, alas, is not open. Cry time.\n");//if the file doesn't open, we pint our sad error message
                puts (sf_strerror (NULL));
                return 1;
        }

        if(!sf_format_check(&sfInfo)) {
                sf_close(inFile);
                printf("Invalid encoding\n");
                return 1;
        }

        filesize = sfInfo.frames;

        outFile = sf_open("noisegate.wav", SFM_WRITE, &sfInfo); //now this is the file we'll be writing to.

        if(!outFile) {
                printf ("Oh goodness gracious! The file's not opening! Different cry time.\n");//just checking again that the file opens successfully
                puts (sf_strerror(NULL));
                return 1;
        }
        printf("%lld\n", filesize);

        float *buffer = (float*) malloc(filesize * sizeof(float));
        sf_read_float(inFile, buffer, filesize);
        for (int i = 0; i < filesize; i++) {
            if (fabs(buffer[i]) < 0.02) {
              buffer[i] = 0;
            }
        }
        sf_write_float(outFile, buffer, filesize);

        sf_close(inFile); //closing out the files we were using
        sf_close(outFile);

        return 0;
}
