#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "sound.h"

int main(void){
	int ret;
	while(1){
	// record 1 sec of sound into test.wav
	ret = system("arecord -q -r16000 -c1 -f S16_LE -d1 test.wav");
	if(WIFSIGNALED (ret) && (WTERMSIG(ret)==SIGINT)) break;
	//then open the wav file and read samples
	displayWAVHeader("test.wav");
	//display necessary information (duration,header etc)
	//then calculate fast dBs
	displayBar("test.wav");
	//send fasT dBs to wed (php program on www.cc.puv.fi)
	//break; for testing just run the loop once
	}
}
