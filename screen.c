//contains screen manipulation functions, such as clearSreen(),gotoxy(),
//setColor(),etc.
#include "screen.h"
#include <stdio.h>

/*
	Function definition of clearScreen()
	This function will use VT100 escape sequence "\E[2J" to erase the total
	terminal screen
	intput argument: none
	output argument: none
*/
void clearScreen(void)
{
	printf("%c[2J",ESC);
	fflush(stdout);
}

/*
	Function difinition of gotoxy()
	This function uses VT100 escape sequence "\ESC[row;col]" to set the cursor
	to the specigic location of the terminal screen
	input argument:
		int row: row number(1 is top)
		int col: col number(1 is left)
	return argument: none 
*/
void gotoxy(int row, int col)
{
	printf("%c[%d;%dH",ESC,row,col);
	fflush(stdout);
}

/*
    Function difinition of bar()
    This function use function gotoxy() to calculate the location for each bar,
    ues unicode to show the bars. when the vualue is less than 15 the color of 
    the bar will be set to withe, when the value is bigger than 15 and less than
    20 the bar will be set to yellow, when the value is bigger than 20 the color
    of the bar will be set to red.
    input argument:
     	 int col: col number(1 is left)
     	 double dB:value of sound in dB unit
    return argument: none
*/
void bar(int col, double dB)
{
	int i;
	for(i=0;i<dB/4;i++)  //for the real value is too big to use bars to show on the tetminal screen, so we devide the value by 4
	{
		gotoxy(30-i,col+1);  // the fisrt bar start from col=1
#ifndef UNICODE
		printf("%c",'*');
#else
		if(i<60/4) setColor(WHITE);
		else if(i<80/4 && i>=60/4) setColor(YELLOW);
		else setColor(RED);
		printf("%s",BAR);
#endif
	}
}


/*
    Function difinition of setColor()
    This function uses VT100 escape sequence "\ESC[color" to set the color of 
    each bar
    	input argument:
        	int color
    return argument: none
*/
void setColor(int color)
{
	printf("%c[1;%dm",ESC,color);
	fflush(stdout);
}
