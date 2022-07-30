#include "scoreboard.h"

//function to write final scoreboard data to text file -scoreboard.txt
void scoreCardPrint(int nbat, int nbowl){

struct  batsman  bat[nbat];
struct bowler bowl[nbowl];
int choice,i;

int totalruns=0;

FILE  *f;
f = fopen("scorecard.txt","w");

for(i =0; i<nbat; i++){
totalruns=totalruns+ bat[i].runs;
}


int batno;
int bowlno;

              fprintf(f, "                     Innings summary\n");
              fprintf(f, "==========================================================================\n");
              fprintf(f, " Batsman        runs           balls        fours       sixes         sr   \n");
              fprintf(f, "==========================================================================\n");

              for(i=0;i<nbat;i++)
                {
                    fprintf(f, " %-15s %s %-14d %-13d %-11d %-11d %-9.2f\n\n", bat[i].name, bat[i].lastname, bat[i].runs, bat[i].balls, bat[i].fours, bat[i].sixes, bat[i].str);
                }
              fprintf(f, "TOTAL RUNS:%d\n\n",totalruns);
              fprintf(f, "\n\n");
              fprintf(f, "=================================================================\n");
              fprintf(f, " Bowler        overs           runs        wicket       economy\n");
              fprintf(f, "=================================================================\n");

               for(i=0;i<nbowl;i++)
               { 
                  fprintf(f, " %-15s %s %-14d %-13d %-11d %-11.2f\n\n\n", bowl[i].name, bowl[i].lastname, bowl[i].overs, bowl[i].runs, bowl[i].wickets,bowl[i].econ);
               }
display();
}
