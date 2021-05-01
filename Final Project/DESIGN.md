# Design
 
### Aurora's Reverb

So, I started with your file (Reverb.c in our class materials), and then changed and built from there. 

I guess we can kind of start from the top and go from there. 

So, at the very top, I added an output file name that would keep the original file name and add "AddedReverb" to the top.

Then, I added a print function where I tell the user things they need to input, and I give them the ability to enter their own file, and change three parameters. 

After that, I enter the defaults for feedback, cutoff, and size for if the user doesn't enter anything. 
And then I have arrays for if they do want to enter values of their own. 

Also, after that, I basically map the input range (0-1) to the actual (bigger) output ranges (1-100). 

And then, I include the function from my other document - LPF.c, which is basically a low pass filter included with the reverb. 

The low pass filter itself takes the average sample of things around it, sort of 'blurring' the sound (if you're likening it to what would happen with a visual blur averaging the frames). 

Part of the reason for the low pass filter is to try to mimic reverb as much a possible, which often doesn't reflect as much in the higher frequencies (to my understanding). 

Then, I made a bunch of delay lines which get random delay times, which all make up the reverb function. 

(Anything that isn't clear from this document should probably be clear in the comments of the file, hopefully.)

### Why I Did What I Did

As far as why I made the decisions I did, to be honest, a lot of them were just what I was capable of. If I had unlimited knowledge, I would've had the user enter more parameters, and would've made it a better user experience, in general, like where you enter the parameters one at a time on different lines instead of all together at the top. 

Also, I think if I had more knowledge/ability, I would make it so stereo files would also work, and files that weren't just .wav. 

Also, on the backend, I'm sure someone with more skill than I have could've made the backend cleaner and sleeker. But I tried my best! haha 

As far as the more positive side - the additions I made from your file, I did it so that the reverb was bigger, with I suppose more possibilities, and more user control. 