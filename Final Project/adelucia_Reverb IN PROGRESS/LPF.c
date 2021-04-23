//goes with Reverb.c file

float AS (int index, int range, int length, float* input) //AS stands for average sample
{
        int left = index-range;
        int right = index+range;

        if (left < 0) left = 0; //so, if it's negative, we're setting it to zero
        if (right > length-1) right = length-1; //this is keeping us from reading outside the bounds of the array

        float avg = 0;
        for (int i = left; i < right; i++) {
          avg += input[i];
        }
        return avg / (right - left);
}

void LPF (float* input, float* output, int length, int range)
{
  for (size_t i = 0; i < length; i++) {
    output[i] = AS (i, range, length, input);
  }
}

void calculateDelay (float* dry, float* delayLine, int length, int time, float feedback)
{
  for (size_t i = 0; i < length; i++) {
    int offset = i - time; //we don't want this to be less than 0
    if (offset >= 0){
      delayLine[i] = dry[offset];
      delayLine[i] += delayLine[offset] * feedback;
    }
  }
}

void Reverb (float* input, float* output, int length, float wet, int numDelay, int time, float feedback)
{
  float** delayLines = (float**) malloc (numDelay * sizeof(float*)); //pointer to pointers (array of arrays, to make as many delays as you want)
  for (size_t i = 0; i < numDelay; i++) {
    delayLines[i] = (float*) malloc (length * sizeof(float));
    int offset = rand()%5000; //because this is in terms of samples, not delay time
    calculateDelay (input, delayLines[i], length, time + offset, feedback); //so now each delay line has a random delay time
  }
  for (size_t i = 0; i < length; i++) {
    output[i] = input[i] * (1 - wet);
  }
  for (size_t i = 0; i < numDelay; i++) {
    for (size_t j = 0; j < length; j++) {
      output[j] += delayLines[i][j] * wet * (1.0/numDelay);
    }
  }
}
