#include <stdio.h>
#include <stdlib.h>
#include "sound.h"

int main(void){
	while(1){
	// record 1 sec of sound into test.wav
	system("arecord -q -r16000 -c1 -f S16_LE -d1 test.wav"),
	//then open the wav file and read samples
	displayWAVheader("test.wav");
	//display necessary information (duration,header etc)
	//then calculate fast dBs
	displayBar("test.wav");
	//send fasT dBs to wed (php program on www.cc.puv.fi)
	break;// for testing just run the loop once
	}
}
