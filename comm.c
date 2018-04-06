#include "comm.h"
#include <stdio.h>    //sprintf()
#include <curl/curl.h>  // libcurl
#include <math.h>
//This fuction takes in RMS value od 1 second, each id calculated be
//16000/80=200 samoles,but hte function will re-calulate 8-pieces of RMS values,
//each corresponding to 2000 samples or 125mx of sound

void sendToServer(double r80[]){
	double r8[8],sum;
	int i,j;//loop counters
	CURL *curl;
	CURLcode res;
	char post[1000];
	
	for(i=0;i<8;i++)//to calculate 8-pieces of fast values
	{
		sum=0;
		for(j=0;j<10;j++){
			sum+=r80[j+i*10]*r80[j+i*10]*200;
		}
		r8[i]= sqrt(sum/2000);
	}
	sprintf(post,"data=%.2f;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f",
		r8[0],r8[1],r8[2],r8[3],r8[4],r8[5],r8[6],r8[7]);
	//send data
	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();
	if(curl) {
	    /* First set the URL that is about to receive our POST. This URL can
	           just as well be a https:// URL if that is what should receive the
	                  data. */ 
		curl_easy_setopt(curl, CURLOPT_URL,URL);
	 /* Now specify the POST data */ 
	 	curl_easy_setopt(curl, CURLOPT_POSTFIELDS,post);
	 /* Perform the request, res will get the return code */ 
		res = curl_easy_perform(curl);
	 /* Check for errors */ 
		if(res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
	 /* always cleanup */ 
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
}

