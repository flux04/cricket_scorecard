#include "scoreboard.h"
 
//function reads from scoreboard.txt and displays it to the terminal

void display(){
system("clear");
char str[1024];
FILE * file;
file = fopen( "scorecard.txt" , "r");
while (fgets(str, 100, file))  
	printf("%s", str);
}


