/*header file for the program
here we define all include statements, libraries, one constant for max line length (not used), structures and declaring functions
this file is used for pre-processing for the entire program
we have 6 program files for this program right now!
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
//removed all global variables for optimization

typedef struct node
{
	char name[25], lastname[20];
	int runs, balls, fours, sixes;
	float str;
	struct node *next;
}node;

struct login                           
{
	char username[30];
	char password[20];
};

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
void editableController();
void writeController();
void readController(int, int);
void writebatsman(int);
void writebowler(int);
void batReader(int);
void bowlReader(int);
void calculator(int, int);
void scoreCardPrint(int, int);
void display();

//LL functions
struct node* readLinkedList(char filename[]);
void writeLinkedList(char filename[], struct node* head);
struct node* insertAtBegin(struct node *head, char *name, char *lastname, int runs, int balls, int fours, int sixes);
void displayLinkedList(struct node *root);
struct node* editNode(node* head, int index);
