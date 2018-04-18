#---------------------------SOUND SENSOR PROJECT-----------------------------
This project is meant to collect sound level at a proximity of a Raspberry Pi 
divece. The RPi is equipped with a USB sound card( C-Media Electronics,Inc. 
Audio Adapter)and a microphone. The sound is recored at 16000Hz sample rate
and every second will produce 80 pieces of RMS value as a bar-diagram and all
the RMS value are stored in a txt file named sound_log.txt. 

Table of Content
1.Configuration
2.Installation
3.Operation
4.Manifest(list of files and short description of their roles)
5.License
6.Contact information

-----------------------------------------------------------------------------

1.Configuration
---------------
For a new Raspberry Pi,firstly have to do RPi defualt booting and set proper
keyboard layout. Then set USB sound card as defualt.

2.Installation
--------------
Copy link form git hub,then run make command, after that will be able to run 
the application. 

3.Operation
----------- 
Run make command should be able to see a sound.a file,run  ./sound.a command 
then e sound is recored at 16000Hz sample rate and every second will produce 
80 pieces of RMS value as a bar-diagram dispaly on the window, use shift+c 
to stop the application. RMS data value can be checked in sound_log file in 
a formate of "Y-m-d H:i:s" and 8 value saperated by semicolon. You also can 
copy sound.php file in a public folder in your pc and change the related url
of sound.php file.

4.Manifest
----------
comm.c
comm.h
makefile
main.c
screen.c
screen.h
sound.c
sound.h
sound.php

5.License
---------
This License refers to version 3 of the GNU General Public License.

6.Contact information
---------------------
Yuqi Xia
Department of Information Technology
Vaasa University of Applied Sciences
Wolffintie 30, Vaasa, Finland
Home: http://www.cc.puv.fi/~e1701269
Email: yuqi.xia@outlook.com
-----------------------------------End-----------------------------------------
