/*this file is for functions that read data out of the text files - batsman.txt and bowler.txt
this data is then stored to the batsman and bowler structures, total runs, balls, wickets and other parameters are calculated using the data*/

#include "scoreboard.h"


/*function to calculate and save derived values
void calculator(){
struct  batsman  bat[nbat];
struct  bowler  bowl[nbowl];

  for(int i=0;i<nbat; i++){
  bat[i].str=bat[i].runs*100.00/bat[i].balls;
  }
  
  for(int i=0;i<nbowl; i++){
  bowl[i].overs=bowl[i].balls/6;
  bowl[i].econ=bowl[i].runs/bowl[i].overs;
  }
}
*/
/*function to read batsman data and save it to stuct batsman
 takes in number of batsmen as parameter.
 function uses a loop to traverse in the data file, reads a chunk at a time and stores it in suitable struct*/
void batReader(int nbat){
struct  batsman  bat[nbat];
FILE  *f;
f = fopen("batsman.txt","r");


 for(int i = 0; i < nbat; i++) // each loop will read new line of file; i<3 for 3 lines in file
    {
        fscanf(f, "%s %s %d %d %d %d ", bat[i].name, bat[i].lastname, &bat[i].runs, &bat[i].balls, &bat[i].fours, &bat[i].sixes); //store info
        printf("batsman %d:\n%s %s \truns:%d, balls:%d, fours:%d, sixes: %d\n",i+1, bat[i].name, bat[i].lastname, bat[i].runs, bat[i].balls, bat[i].fours, bat[i].sixes); //print data
    }

/*const char s[2] = ", ";
char *token;
int i;
bool keep_reading = true;	//bool to run loop to keep reading
int current_line = 1;		//shows current line

char buffer[MAX_LINE];
do 
{
	// read the next line from the file, store it into buffer
	fgets(buffer, MAX_LINE, f);
	//printf("%s",buffer);
	
	/*sscanf(buffer, "%s, %s, %d, %d, %d, %d", bat.name, bat.lastname, &bat.runs, &bat.balls, &bat.fours, &bat.sixes);
	
printf("name:%s %s\n runs:%d, balls:%d, fours:%d, sixes: %d)\n",bat.name, bat.lastname, bat.runs, bat.balls, bat.fours, bat.sixes);
	*/

	       
/*if (feof(f))
    {
      // stop reading from the file, and tell the user the number of lines in 
      // the file as well as the line number they were trying to read as the 
      // file is not large enough
      keep_reading = false;
    }

// continue to keep track of the current line we are reading
current_line++;

} while(keep_reading);    



/*fscanf(f, "%s, %s, %d, %d, %d, %d", bat.name, bat.lastname, &bat.runs, &bat.balls, &bat.fours, &bat.sixes);
printf("------------=batsman info=------------");
printf("name:%s %s\n runs:%d, balls:%d, fours:%d, sixes: %d)\n",bat.name, bat.lastname, bat.runs, bat.balls, bat.fours, bat.sixes);
	for (i = 0; i < nb && !feof(f); ++i) {
	fscanf(f, "%s, %s, %d, %d, %d, %d", bat[i].name, bat[i].lastname, &bat[i].runs, &bat[i].balls, &bat[i].fours, &bat[i].sixes);
	}

	for (i = 0; i < nb; i++)
	{
	printf("name:%s %s\n runs:%d, balls:%d, fours:%d, sixes: %d)\n",bat[i].name, bat[i].lastname, bat[i].runs, bat[i].balls,  bat[i].fours, bat[i].sixes);
	}
	*/
	
	
fclose(f);
}

/*function to read bowler data and save it to struct bowler
takes in number of bowler as parameter.
function uses a loop to traverse in the data file, reads a chunk at a time and stores it in suitable struct*/
void bowlReader(int nbowl){
struct  bowler bowl[nbowl];
FILE  *f;
f = fopen("bowler.txt","r");

printf("\n------------------------------\n");
printf("bowlers info:\n");
 for(int i = 0; i < nbowl; i++) // each loop will read new line of file; i<3 for 3 lines in file
    {
        fscanf(f, "%s %s %d %d %d %d ", bowl[i].name, bowl[i].lastname, &bowl[i].runs, &bowl[i].balls, &bowl[i].wickets, &bowl[i].maidens); //store info
        printf("bowler %d:\n%s %s \truns given:%d, balls:%d, wickets:%d, maidens: %d)\n", i+1, bowl[i].name, bowl[i].lastname, bowl[i].runs, bowl[i].balls, bowl[i].wickets, bowl[i].maidens); //print data
    }
fclose(f);
}




void readController(int nbat, int nbowl){
batReader(nbat);
bowlReader(nbowl);
//calculator();
scoreCardPrint(nbat, nbowl);
}
