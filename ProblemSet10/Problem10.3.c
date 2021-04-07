#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sndfile.h>

//don't forget to use -lsndfile at the end of the file name when compiling this

#define kInputFileName "sine.wav"
#define kOutputFileName "reduct.aiff"

typedef struct SoundFile {
        SNDFILE *file;
        SF_INFO info;
} SoundFile;

int openInputSndFile(SoundFile *inFile);
int createOutputSndFile(SoundFile *inFile, SoundFile *outFile);
void process(short *inBuffer, short *outBuffer, sf_count_t bufferSize);

int main(void){
        SoundFile inFile, outFile;

        int error = openInputSndFile(&inFile);

        if(error) return 1;

        sf_count_t bufferSize = inFile.info.frames; //get buffer size

        short *inBuffer = (short *) malloc(bufferSize*sizeof(short));
        short *outBuffer = (short *) calloc(bufferSize, sizeof(short));

        sf_read_short(inFile.file, inBuffer, bufferSize);

        process(inBuffer, outBuffer, bufferSize);

        error = createOutputSndFile(&inFile, &outFile); //create output file and write result
        if (error) return 1;
        sf_write_short(outFile.file, outBuffer, bufferSize);

        sf_close(inFile.file);
        sf_close(outFile.file);
        free(inBuffer);
        free(outBuffer);

        return 0;
}

short keep_bits_from_16( short input, int keepBits ) {
        return (input & (-1 << (16-keepBits)));
}

void process(short *inBuffer, short *outBuffer, sf_count_t bufferSize){
  #define BITS 4

        for (sf_count_t i = 0; i < bufferSize; i++) {
                outBuffer[i] = keep_bits_from_16(inBuffer[i], BITS);
        }

}

int openInputSndFile(SoundFile *sndFile){
        memset(&sndFile->info, 0, sizeof(SF_INFO)); //required for reading

        sndFile->file = sf_open(kInputFileName, SFM_READ, &sndFile->info);//open original file in read mode
        if(!sndFile->file) {//Check if the file was succefully opened
                printf("Error : could not open file : %s\n", kInputFileName);
                puts(sf_strerror(NULL));
                return 1;
        }

        if(!sf_format_check(&sndFile->info)) { //check the file
                sf_close(sndFile->file);
                printf("Invalid encoding\n");
                return 1;
        }

        if(sndFile->info.channels > 1) {
                printf("Input file is not mono\n");
                return 1;
        }

        printf("Sample rate for this file is %d\n", sndFile->info.samplerate);
        printf("A number of channels in this file is %d\n", sndFile->info.channels);
        printf("A number of frames in this file is %lld\n", sndFile->info.frames);
        printf("time is %f\n", (double)sndFile->info.frames / sndFile->info.samplerate);

        return 0;
}

int createOutputSndFile(SoundFile *inFile, SoundFile *outFile){ //open another sound file in write mode
        inFile->info.format = SF_FORMAT_AIFF | SF_FORMAT_PCM_24;
        outFile->file = sf_open(kOutputFileName, SFM_WRITE, &inFile->info);
        if(!outFile->file) {//Check if the file was succefully opened
                printf("Error : could not open file : %s\n", kOutputFileName);
                puts(sf_strerror(NULL));
                return 1;
        }
        return 0;
}
