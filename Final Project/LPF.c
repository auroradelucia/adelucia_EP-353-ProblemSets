//goes with Reverb.c file

float map(float value, float istart, float istop, float ostart, float ostop) { //this works like map in Max (remaps one range of numbers to another (input to output))
        return ostart + (ostop - ostart) * ((value - istart) / (istop - istart));
}

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

void LPF (float* input, float* output, int length, int range) //. This calls AS from above and makes the low pass filter. (Takes the average of samples around it (removing high frequency detail, so it sounds more authentically like reverb, since reverb normally loses some high frequency))
{
        for (size_t i = 0; i < length; i++) {
                output[i] = AS (i, range, length, input);
        }
}

void LPFAlloc (float* input, int length, int range) //allocating a new buffer because of all the delay lines [same as above, but only takes one input buffer instead of 2] - we don't want to create a new output buffer for every delay line. (We don't need the dry delay lines)
{
        float* temp = (float*) malloc(length * sizeof (float));
        LPF(input, temp, length, range);
        for (size_t i = 0; i < length; i++) {
                input[i] = temp[i];
        }
        free(temp);
}

void calculateDelay (float* dry, float* delayLine, int length, int time, float feedback) //write the delay into the delay line 
{
        for (size_t i = 0; i < length; i++) {
                int offset = i - time; //we don't want this to be less than 0
                if (offset >= 0) {
                        delayLine[i] = dry[offset];
                        delayLine[i] += delayLine[offset] * feedback;
                }
        }
}

void Reverb (float* input, float* output, int length, float wet, int numDelay, int time, float feedback, int cutoff)
{
        float** delayLines = (float**) malloc (numDelay * sizeof(float*)); //pointer to pointers (array of arrays, to make as many delays as you want)
        for (size_t i = 0; i < numDelay; i++) {
                delayLines[i] = (float*) malloc (length * sizeof(float));
                int offset = rand()%5000; //because this is in terms of samples, not delay time
                calculateDelay (input, delayLines[i], length, time + offset, feedback); //so now each delay line has a random delay time
                LPFAlloc(delayLines[i], length, cutoff);
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
