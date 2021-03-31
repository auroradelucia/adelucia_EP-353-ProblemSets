#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sndfile.h>

//don't forget to use -lsndfile at the end of the file name when compiling this

#define kSampleRate 48000
#define kSec 1
#define kNumFrames (kSampleRate * kSec)
#define kNumChannels 1
#define kFormat (SF_FORMAT_WAV | SF_FORMAT_PCM_24)
#define kFileName "TriangleWave.wav"
#define kHarmonics 10

int main(void){
  SNDFILE *sndFile;
  SF_INFO sfInfo;
  double *buffer;

  double amplitude = 0.25;
  double frequency = 440.0;

  buffer = malloc(kNumChannels * kNumFrames * sizeof(double));
  if (!buffer){
    printf ("Error : malloc failed.\n");
		return 1;
	}

  memset(&sfInfo, 0, sizeof(SF_INFO));
  memset(buffer, 0, kNumChannels * kNumFrames);
  sfInfo.samplerate = kSampleRate; //setting the format for the sound file to be saved
	sfInfo.frames = kNumFrames;
	sfInfo.channels = kNumChannels;
	sfInfo.format = kFormat;

  sndFile = sf_open(kFileName, SFM_WRITE, &sfInfo); //opening our file
  if(!sndFile){
    printf ("Error : could not open file : %s\n", kFileName);
		puts(sf_strerror (NULL));
		return 1;
  }

  for (int t = 0; t < kNumFrames; t++){
    for (int i = 0; i < kHarmonics; i++){
      int index = 2 * i+1; //turns i into only odd numbers
      float sign = pow(-1, i); //will make every other odd harmonic negative
      float amp = sign * sin(2.0 * M_PI * ((frequency * index)/kSampleRate) * t) / pow(index, 2);
      double sample = amp * amplitude; //scale the output by amplitude
      for(int c = 0; c < kNumChannels; c++){
        buffer[kNumChannels * t + c] += sample;
      }
    }
  }

  sf_count_t count = sf_write_double(sndFile, buffer, sfInfo.channels * kNumFrames); //result

  //Make sure writing the file succeeeded
  if(count != sfInfo.channels * kNumFrames){
    puts(sf_strerror(sndFile));
  }

  sf_close(sndFile); //close out file we opened
  free(buffer); //free the space we set aside 

  return 0;
}
