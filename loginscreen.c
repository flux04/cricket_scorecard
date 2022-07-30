#include "scoreboard.h"


/*
login function to take credentials as input from user,
it reads from file named 'login.txt' where we have username and password stored.
it then validates the credentials entered by the user against the ones present in the file.
*/
void login (void)
{
char username[30],password[20];
FILE *log;

log = fopen("login.txt","r");//opened file in read mode

if (log == NULL)      //if an error occurs, it'll display error message
	{
	        fputs("Error at opening File!", stderr);
	        exit(1);
	}

	struct login l;


//accepting username and password

printf("\nPlease Enter your login credentials below\n\n");
printf("Username:  ");
fgets(username, 30, stdin);		
printf("\nPassword: ");
printf("\n");
fgets(password, 20, stdin);


bool keep_reading = true;		//bool to run loop to keep reading
int current_line = 1;		//shows current line
int username_line = 1; 			//line with username
int password_line = 3;			//line with password
char buffer[30];
    //read from file and store username in l.username, password in l.password
do 
{
	// read the next line from the file, store it into buffer
	fgets(buffer, 30, log);

	// now, we go to lines 1 & 3 and copy their values to l.username and l.password
	if (current_line == username_line)
	{
		keep_reading = true;
		strcpy(l.username, buffer);
	}
	else if (current_line == password_line)
	{
		keep_reading = false;
		strcpy(l.password, buffer);
	}

// continue to keep track of the current line we are reading
current_line++;

} while(keep_reading);    

	if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)
		{printf("\nSuccessful Login\n");
		printf("\nPress any key to continue\n");
		getchar();
		system("clear");
		writeController();}
        else 
        	{printf("\nIncorrect Login Details\nPlease enter the correct credentials\n");}

	fclose(log);

	return;
}



/*
registration function to register or change admin credentials,
it writes the credentials to the file named 'login.txt'.
it then leads to login function so the admin can login.
*/
void registration(void)					//function for new admin registration
{

FILE *log;

//open file in write mode
log=fopen("login.txt","w");
if (log == NULL)
	{
		fputs("Error opening File!", stderr);
		exit(1);
	}


struct login l;

//prompt admin to choose username and password
system("clear");
printf("Choose a username and password as credentials for system login\n"); 

//accept user name and password
printf("\nEnter Username:\n");
fgets(l.username, 15, stdin);
printf("\nEnter Password:\n");
fgets(l.password, 15, stdin);

//put username and password into the file leaving 1 line in between
fputs(l.username,log);
fprintf(log,"\n");
fputs(l.password,log);

//close file
fclose(log);

//show user that account has been created
printf("\nConfirming details...\n...\nWelcome!\n\n");
printf("\nRegistration Successful!\n");
printf("Press any key to continue...");

getchar();
system("clear");

printf("\nNow running login utility\n");
   
login();
}
/*
loginController function acts as the function to control the flow of the login sequence.
we use it to prompt user with multiple menus and those menus lead into all the login related functions.
if a guest is logged in, they move to score display function
if an admin is loggin in, they move to another menu to edit or make new scorecards for the guests
*/
void loginController (void)				//controller function to control login screen
{
	system("clear");
	int option,input1;
	
	//first prompt for admin/guest screen
	printf("1. Admin login\n2. Guest login\n\n");
	scanf("%d",&input1);
	
	//if user is admin, program moves to login / registration screen
	if(input1==1)
	{
	system("clear");
	printf("\n----------------------------------------------------------------------\n");
	printf("\nAdmin login page:\n");       
	printf("1. Register new admin\n2. Login\n\n");
	scanf("%d",&option);

	getchar();           // catching newline.

	if(option == 1)
		{
	 		registration();
		}

 	else if(option == 2)
        	{  
			login();
		}
    	}
    	//if user is a guest, we can move to cricket display
	else if(input1==2)
	{
		system("clear");
		printf("\nWelcome to Cricket Scoring System!\n Click any button to continue\n");
		getchar();
		system("clear");
		
	display();		//Function to print scorecard
    	}
}
