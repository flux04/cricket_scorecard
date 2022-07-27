#include <stdio.h>
#include <stdlib.h>


/* function to write batsman data into 'batsman.txt' text file. It produces output with comma separated values and every batsman entry is on a new line*/
void writebatsman(int n)
{
   printf("--------------------------\n");
   printf("batsman no.%d info:\n",n);
   char buffer[100];
   char *s;
   FILE *fptr;
   char name[10], lastname[10];
   int runs, balls, fours, sixes;
   // use appropriate location if you are using MacOS or Linux
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
//take name
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

/* function to write bowler into 'bowler.txt' text file. It produces output with comma separated values and every bowler entry is on a new line */
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
//take name
   printf("Enter surname: ");
   //fgets(buffer, 10, stdin);
   scanf("%s", lastname);
   fprintf(fptr,"%s ",lastname);

// take runs  
   printf("Enter runs given: ");
   scanf("%d",&runs);
   fprintf(fptr,"%d ", runs);
   
// take runs  
   printf("Enter balls: ");
   scanf("%d",&balls);
   fprintf(fptr,"%d ", balls);
   
// take wickets
   printf("Enter wickets: ");
   scanf("%d",&wickets);
   fprintf(fptr,"%d ", wickets);
   
// take sixes
   printf("Enter maiden: ");
   scanf("%d",&maiden);
   fprintf(fptr,"%d ", maiden);
      
   fprintf(fptr,"\n");
   fclose(fptr);

}


void main(){
int i;
for(i=1;i<11;i++){
writebatsman(i);}
for(i=1;i<5;i++){
writebowler(i);}
}
