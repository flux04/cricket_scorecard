/*
this file is for functions that read data out of the text files - batsman.txt and bowler.txt
this data is then stored to the batsman and bowler structures, total runs, balls, wickets and other parameters are calculated using the data
*/

#include "scoreboard.h"


/*
function to read batsman data and save it to stuct batsman
takes in number of batsmen as parameter.
function uses a loop to traverse in the data file, reads a chunk at a time and stores it in suitable struct
*/
void batReader(int nbat){
struct  batsman  bat[nbat];
FILE  *f;
f = fopen("batsman.txt","r");


 for(int i = 0; i < nbat; i++) // each loop will read new line of file;
    {
        fscanf(f, "%s %s %d %d %d %d ", bat[i].name, bat[i].lastname, &bat[i].runs, &bat[i].balls, &bat[i].fours, &bat[i].sixes); //store info
        printf("batsman %d:\n%s %s \truns:%d, balls:%d, fours:%d, sixes: %d\n",i+1, bat[i].name, bat[i].lastname, bat[i].runs, bat[i].balls, bat[i].fours, bat[i].sixes); //print data
    }
  for(int i=0;i<nbat; i++){
  bat[i].str=bat[i].runs*100.00/bat[i].balls;
  }
  
	
fclose(f);
}

/*
function to read bowler data and save it to struct bowler
takes in number of bowler as parameter.
function uses a loop to traverse in the data file, reads a chunk at a time and stores it in suitable struct
*/
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
for(int i=0;i<nbowl; i++)
	{
	bowl[i].overs=bowl[i].balls/6;
	bowl[i].econ=bowl[i].runs/bowl[i].overs;
	}
fclose(f);
}


/*
readController function acts as the function to control the flow of the score reading sequence.
we use it to prompt admins with multiple menus and those menus lead into all the reading related functions.
*/
void readController(int nbat, int nbowl){
batReader(nbat);
bowlReader(nbowl);
//calculator();
scoreCardPrint(nbat, nbowl);
}
