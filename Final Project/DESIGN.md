# User Manual Documentation 
 
### Aurora's Reverb

#### The gist

Basically, this is a take on your original reverb code that I've modified and expanded. So, the first thing you're gonna wanna do is take a file and put it in the same folder "AurorasReverb.c" is in.

***You also must make sure that LPF.c is in the same folder, because it is used in AurorasReverb.c***

For demonstration purposes, I've put in CheeseSynth.wav, because the changes are fairly obvious when it spits out the new version of that file. 

I also added "ToxicTest.wav" which is just Britney Spears' Toxic, as a test, so you can see the reverb more on a whole song rather than a snippet. 

(The bigger/longer the file, the longer it takes to get your new added reverb file. It will do it. It just may take a minute.)

If you would like to try your own file, please make sure it's a mono (not stereo) file, and rthat it's a .wav.

(If you forget or don't see any of the instructions in this documentation, you'll be reminded in the terminal when you go to run it.)

So, you'll navigate to your folder in the terminal, as usual. Assuming you're not moving folders around, everything you need should be available in the "Final Project" folder available in my GitHub

Specifically, this is the web address you will go to to find it. 

``` https://github.com/auroradelucia/adelucia_EP-353-ProblemSets/tree/main/Final%20Project ```

Okay, now that you know the gist, let me give you a super specific - 

## STEP BY STEP

### 1) Navigate to my GitHub folder, available here 

``` https://github.com/auroradelucia/adelucia_EP-353-ProblemSets/tree/main/Final%20Project ```

### 2) Add a mono .wav sound file - *if* you want to use your own, otherwise, you may use what I already have.

### 3) Within your terminal, using the command line, navigate to that terminal folder

[So, for me, that's 

``` cd /Users/rora/Documents/GitHub/adelucia_EP-353-ProblemSets/Final\ Project ```

I'm sure yours will be a different username (not "Rora") at the top.]

### 4) Compile using the command below

 ``` clang AurorasReverb.c -lsndfile ```
 
 *do not forget -lsndfile*
 
 ### 5) Once it's compiled, you may run the code using
 
  ``` ./a.out ```
  
And then you will get a set of instructions. [If you would like, you can skip that part, enter all this information from the beginning, skipping the ./a.out phase where you just get intstructions

### 5A) Basically, you'll enter

 ``` ./a.out [YourFileName.wav] FeedbackParameter from 0-1 CutoffParameter from 0-1 SizeParameter from 0-1 ```
 
**(There are spaces between each thing. So, Basically, an example of exactly how this would look is - )**
 
  ``` ./a.out CheeseSynth.wav 0.8 0.6 0.5 ```
 

## Notes

- If you do not use anything after your file name, it will resort to the defaults which do give a fair amount of reverb, so it is possible to run it, with example, say 

  ``` ./a.out CheeseSynth.wav ```
  
  And like I said, it will then just do the defaults.
  
- As I said earlier, the numbers go from 0 - 1 and represent feedback, cutff, and delay

	- So with feedback, it's just the amount of feedback, obv., the closer you get to 1, the higher it will be. 

	- with cutoff, it will be more open/leave more high frequiences the higher you go, so the *more* you want it to technically "cutoff," the lower the number you give 

	- and then in the final number, the bigger the delay you want, the bigger you make that last number.

## The end!
I believe this covers everything, I hope. Obviously if you have any questions, ask me anytime. Thanks a million! 