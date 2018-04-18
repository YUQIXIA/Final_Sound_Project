#include "comm.h"
#include "sound.h"
#include "screen.h"
#include <stdio.h>
#include <math.h>
/*
	function defination of displayWAVheader()
	This funtion is going to display the chunk size, subchunk 1 size, audio format,
	number of channel, sample rate, byte rate, block align, bits per sample,
	subchunk 2 size.
	input argument: char filename[]
	output argument: none
*/
void displayWAVHeader(char filename[])
{
	WAVHeader myheader;  //an instance of defined struct
	FILE *fp;
	fp=fopen(filename,"r");// open the file for reading
	if(fp==NULL){
		printf("error of opening file! \n");
		return;
	}
	fread(&myheader, sizeof(WAVHeader),1,fp);
	fclose(fp);
	printID(myheader.chunkID);
	printf("chunck size: %d\n",myheader.chunkSize);
	printID(myheader.format);
	printID(myheader.subchunk1ID);
	printf("subchunk 1 size: %d\n",myheader.subchunk1Size);
	printf("audio format: %d\n",myheader.audioFormat);
	printf("number of channel: %d\n",myheader.numChannels);
	printf("sample rate: %d\n",myheader.sampleRate);
	printf("byte rate: %d\n",myheader.byteRate);
	printf("block align: %d\n",myheader.blockAlign);
	printf("bits per sample: %d\n",myheader.bitePerSample);
	printID(myheader.subchunk2ID);
	printf("subchunk 2 size: %d\n",myheader.subchunk2Size);
}

/*
	function definition of printID()
	This function prints ID.
	intput argument: char id[]
	ouput argument: none
*/
void printID(char id[])
{
	for(int i=0;i<4;i++)
		printf("%c",id[i]);

	printf("\n");
}

/*
	function definition of displayBar()
	this function opens the "test.wav" file and read the second part(data) of
	the file ,and the samples should be in S16_LE format,and there are 16000 of
	them. The function processes every 200 saleses and calculate their RMS values
	and reders this values as a  vertical bar on terminal screen.
	iuput argumnet:char filename()
	output argument:none
*/
void displayBar(char filename[])
{
	WAVHeader myheader;  //an instance of defined struct
	FILE *fp;
	short int samples[SAMPLERATE];
	int i,j;
	double sum_200, rms_80[80], dB;
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("error of opening this file! \n");
		return;
	}
	fread(&myheader,sizeof(WAVHeader),1,fp);
	fread(&samples,sizeof(signed short),SAMPLERATE,fp);
	fclose(fp);
//ALL THE samples of the lsec are trad to the array samples[],we need to run a loop
//80 times for 80 bars on the screen,and each iteration of this loop will calculate
//a RMS(root mean square,junfanggen) value of 200 samples
	clearScreen();
	for(i=0;i<80;i++)
	{
		for(j=0,sum_200=0.0;j<200;j++)
		{
			sum_200 += samples[j+i*200] * samples[j+i*200];
		}
		rms_80[i]=sqrt(sum_200/200);
		dB=20*log10(rms_80[i]);
#ifdef DEBUG
		printf("RMS[%d] = %10.4f = %10.4fdB\n",i,rms_80[i],dB);
#else
		bar(i,dB);
#endif
	}//for
#ifdef COMM 
	sendToServer(rms_80);
#endif
}//function

