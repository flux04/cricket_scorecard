#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_LINE 30
#define nbat 7
#define nbowl 4

struct batsman
{
   char name[25], lastname[20];
   int runs, balls, fours, sixes;
   float str;
 
};

struct bowler
{
   char name[25], lastname[20];
   int balls, runs, wickets, maidens;
   int overs;
   float econ;
};


void login ();
void registration();
void loginController ();
void writeController();
void readController();
void writebatsman(int n);
void batReader();
void bowlReader();
void calculator();
void scoreCardPrint();
void display();
