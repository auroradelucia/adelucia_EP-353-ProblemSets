#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sndfile.h> //the libraries we must include
#include "LPF.c" //part of my code is in another document, needing to be included here

//clang this with -lsndfile at the end

#define kOutputFileName "AddedReverb-%s"

typedef struct SoundFile { //pointer of how we write to sound files and info about the file are put together in the same struct
        SNDFILE *file;
        SF_INFO info;
} SoundFile;

int openInputSndFile(SoundFile *inFile, char *fileName); //declaring the functions so that they may be called in the main function
int createOutputSndFile(SoundFile *inFile, SoundFile *outFile);
void process(float *inBuffer, float *outBuffer, sf_count_t bufferSize, float feedback, int cutoff, int size);

char* inputFileName; //global variable of the file name someone will bring in

int main(int argc, char *argv[]){
        if (argc < 2) {
                printf("Hi! Welcome to this fun new reverb! \nIf you're seeing this, please re-run this, entering \"%s YourFileName.wav\"\n", argv[0]); //argv[0] is basically ./a.out (or whatever runs it on their system)
                printf("You may also enter 3 parameters. \nThe order is feedback, cutoff, and size. \nIf you do not specify, the deaults will be used. \n The only acceptable files this can work on are mono .wav files. \nIf your file type does not work, please try again with a mono.wav file type.\n");
                printf("If you would like to specify, the range for each is from 0 - 1. \nFor example, you'd enter \"%s YourFileName.wav 0.8 0.6 0.5\"\n", argv[0]);
                printf("Play around, and have fun! \nThanks and happy reverbing!\n");
                return 1;
        }

        float feedback = 0.8; //defaults, if the user doesn't enter parameters
        float cutoff = 0.6;
        float size = 0.5;
        float* args[3];
        args[0] = &feedback; // kinda the gist here is we've defined these for when defaults should be used, and we've made an array so they may be changed by the user
        args[1] = &cutoff;
        args[2] = &size;
        for (size_t i = 2; i < argc; i++) { //allowing the user to input their own parameters if they'd like
                *args[i - 2] = strtof(argv[i], NULL); //string to float
        }

        int cutoff_i = (int) map(cutoff, 0, 1, 100, 1); //remapping the input range (0 -1) to the actual output range (for both of these lines)
        int size_i = (int) map(size, 0, 1, 5, 100);

        SoundFile inFile, outFile;

        int error = openInputSndFile(&inFile, argv[1]);
        if(error) return 1;

        sf_count_t bufferSize = inFile.info.frames;

        float *inBuffer = (float *) malloc(bufferSize*sizeof(float)); //allocating buffers
        float *outBuffer = (float *) calloc(bufferSize,sizeof(float));


        sf_read_float(inFile.file, inBuffer, bufferSize);
        process(inBuffer, outBuffer, bufferSize, feedback, cutoff_i, size_i);

        error = createOutputSndFile(&inFile, &outFile);
        if(error) return 1;
        sf_write_float(outFile.file, outBuffer, bufferSize);

        sf_close(inFile.file); //letting go of memory we've been using, and closing the files
        sf_close(outFile.file);
        free(inBuffer);
        free(outBuffer);

        return 0;
}

void process(float *inBuffer, float *outBuffer, sf_count_t bufferSize, float feedback, int cutoff, int size){ //adding reverb according to parameters that have been laid out
        Reverb (inBuffer, outBuffer, bufferSize, 0.5, size, 4000, feedback, cutoff); //this is the function from LPF.c
}

int openInputSndFile(SoundFile *sndFile, char *fileName){ //this function has already been called, we're just defining it down here. This is all about opening the file that needs reverb added, and checking and understanding said file
        inputFileName = malloc(strlen(fileName) * sizeof(char));
        strcpy(inputFileName, fileName); //grabbing the input file name to add as part of the output file name

        memset(&sndFile->info, 0, sizeof(SF_INFO));

        sndFile->file = sf_open(fileName, SFM_READ, &sndFile->info);
        if(!sndFile->file) {//Check if the file was succefully opened
                printf("Error : could not open file : %s\n", fileName);
                puts(sf_strerror(NULL));
                return 1;
        }

        if(!sf_format_check(&sndFile->info)) {
                sf_close(sndFile->file);
                printf("Invalid encoding\n");
                return 1;
        }

        if(sndFile->info.channels > 1) {
                printf("Input file is not mono\n");
                return 1;
        }
        return 0;
}

int createOutputSndFile(SoundFile *inFile, SoundFile *outFile){ //same deal as above, the function was already called earlier, this is just it being defined. We're making the output sound file with the changes (added reverb)
        char* tempName = (char*)malloc((strlen(kOutputFileName) + strlen(inputFileName)) * sizeof(char));
        sprintf(tempName, kOutputFileName, inputFileName); //add the input file name to the output file name
        outFile->file = sf_open(tempName, SFM_WRITE, &inFile->info);
        free(tempName); //protecting from memory leak
        if(!outFile->file) {//Check if the file was succefully opened
                printf("Error : could not open file : %s\n", kOutputFileName);
                puts(sf_strerror(NULL));
                return 1;
        }
        return 0;
}
