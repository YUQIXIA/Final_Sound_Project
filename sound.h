//#define DEBUG
#define SAMPLERATE 16000
//header file for processing sound (WAV) file.
//define the wav header
typedef struct{
	char chunkID[4];//"RIFF"
	unsigned int chunkSize;//4 bytes
	char format[4];//"WAVE"
	char subchunk1ID[4]; //"format"
	unsigned int subchunk1Size;
	unsigned short audioFormat;
	unsigned short numChannels;
	unsigned int sampleRate;
	unsigned int byteRate;
	unsigned short blockAlign;
	unsigned short bitePerSample;
	char subchunk2ID[4]; //"data"
	unsigned int subchunk2Size;
}WAVHeader;

//funciton prototypes
void displayWAVHeader(char filename[]);
void displayBar(char filename[]);
void printID(char []);

