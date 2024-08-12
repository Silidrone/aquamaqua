# aquamaqua
aquamaqua - by Muhamed Cicak,

I wrote this way back when I was 14 years old, so be mindful of that :)

This is an aquarium monitoring project, written in C++ for esp8266
microcontrollerm, with interactive UI on a TFT display
(with switch buttons). The microprocessor reads values from sensors
periodically and logs them to the server by connecting to the Wi-Fi (user
can choose which wi-fi to connect via GUI and enter the password). The
system also shows real time graphs (which I coded from scratch, using only
drawBP and drawLine functions from TfT Adafruit library). Graphs are
configurable as to what density they should have etc. Object Oriented
Programming was extensively used. I basically wrote my own GUI library for
TFT where you can easily create textboxes, keyboard interface, shapes,
graphs, handle input etc. Also I created a Screen concept where you can
construct screens user will go through and what GUI elements will take place
on those screens (I think I borrowed this idea from the Unity game
engine). Inputs are handled with interrupts, so that the user doesn't have
any "lag". I also wrote a wrapper around the interface code
for accessing EEPROM to use it easily (I created a similar api to
localStorage in web browsers, where you can add data with string key and
value pairs and access it easily later on). Most things were written from
scratch, even things as basic as a linked list. There's probably some things
I left out in this README, from details to features, because it's been quite
a while since I last interacted with this project, so feel free to explore
the source code youself :-). Cheers!

P.S. This code was run by Platformio plugin VSCode. In lib/ directory you
have all of the libraries needed to run the system.
