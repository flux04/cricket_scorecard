#include "scoreboard.h"


/* 
function to write batsman data into 'batsman.txt' text file. 
It produces output with comma separated values and every batsman entry is on a new line
It takes in int n as input which is meant to be the number of batsmen (admin controlled)
*/
void writebatsman(int n)
{
   printf("--------------------------\n");
   printf("batsman no.%d info:\n",n);
   char buffer[100];
   char *s;
   FILE *fptr;
   char name[10], lastname[10];
   int runs, balls, fours, sixes;
   fptr = fopen("batsman.txt","a");

   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }

//take name
   printf("Enter name: ");
   //fgets(buffer, 10, stdin);
   scanf("%s", name);
   fprintf(fptr,"%s ",name);
   
   
//take surname

   printf("Enter surname: ");
   //fgets(buffer, 10, stdin);
   scanf("%s", lastname);
   fprintf(fptr,"%s ",lastname);

// take runs  
   printf("Enter runs: ");
   scanf("%d",&runs);
   fprintf(fptr,"%d ", runs);
   
// take runs  
   printf("Enter balls: ");
   scanf("%d",&balls);
   fprintf(fptr,"%d ", balls);
   
// take fours
   printf("Enter fours: ");
   scanf("%d",&fours);
   fprintf(fptr,"%d ", fours);
   
// take sixes
   printf("Enter sixes: ");
   scanf("%d",&sixes);
   fprintf(fptr,"%d ", sixes);
   fprintf(fptr,"\n");
   
   fclose(fptr);
   

}

/* 
function to write bowler into 'bowler.txt' text file. 
It produces output with comma separated values and every bowler entry is on a new line 
It takes in int n as input which is meant to be the number of bowlers (admin controlled)
*/
void writebowler(int n)
{

   printf("\n--------------------------\n");
   printf("bowler no.%d info:\n",n);
   char buffer[100];
   char *s;
   FILE *fptr;
   char name[10], lastname[10];
   int runs, balls, wickets, maiden;
   // use appropriate location if you are using MacOS or Linux
   fptr = fopen("bowler.txt","a");

   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }

//take name
   printf("Enter name: ");
   //fgets(buffer, 10, stdin);
   scanf("%s", name);
   fprintf(fptr,"%s ",name);
   
   
//take surname
   printf("Enter surname: ");
   //fgets(buffer, 10, stdin);
   scanf("%s", lastname);
   fprintf(fptr,"%s ",lastname);

// take runs  
   printf("Enter runs given: ");
   scanf("%d",&runs);
   fprintf(fptr,"%d ", runs);
   
// take balls 
   printf("Enter balls: ");
   scanf("%d",&balls);
   fprintf(fptr,"%d ", balls);
   
// take wickets
   printf("Enter wickets: ");
   scanf("%d",&wickets);
   fprintf(fptr,"%d ", wickets);
   
// take maidens
   printf("Enter maiden: ");
   scanf("%d",&maiden);
   fprintf(fptr,"%d ", maiden);
      
   fprintf(fptr,"\n");
   fclose(fptr);

}

/*
writeController function acts as the function to control the flow of the score writing sequence.
we use it to prompt admins with multiple menus and those menus lead into all the writing related functions.
it prompts the admin to 3 choices and depending on the choice, it leads to suitable functions
*/
void writeController(){
int control=1,input1,input2;
printf("\n1. View existing scorecard\n2. Write a new static scorecard\n3. Write an dynamic scorecard");
scanf("%d", &control);
if(control==1){
	display();
}
else if(control==2){
	printf("\nEnter no. of batsmen");
	scanf("%d", &input1);
	printf("\nEnter no. of bowlers");
	scanf("%d", &input2);
		int i;
		for(i=1;i<input1+1;i++){
			writebatsman(i);}
		for(i=1;i<input2+1;i++){
			writebowler(i);}
	readController(input1, input2);
}
else if(control==3){
	editableController();
}
}
