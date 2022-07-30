#include "scoreboard.h"


/* 
function to display linked list
this function takes struct node pointer to root or starting address of linked list and prints every node from there
*/
void displayLinkedList(struct node *root)
{
    int i=0;
    struct node *temp = root;
    printf("\nLinkedList: ");
    while(temp!=NULL)
    {
    ++i;
        printf("batsman %d:\n%s %s \truns:%d, balls:%d, fours:%d, sixes: %d \n",i, temp->name, temp->lastname, temp-> runs, temp->balls, temp->fours, temp->sixes);
        temp = temp->next;
    }
    printf("NULL\n\n");
}

/* 
insert node at the beginning of the linked list
returns a pointer to first node
takes linked list head pointer, array for name,lastname, integers-runs, balls, fours and sixes (batsman data) as its inputs
the task of the function is to insert a node at the beginning and link it to the rest of the list
*/
struct node* insertAtBegin(node *head, char *name, char *lastname, int runs, int balls, int fours, int sixes)
{
    
    struct node *ptr;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    strcpy(temp->name, name);
    strcpy(temp->lastname, lastname);
    temp->runs = runs;
    temp->balls = balls;
    temp->fours = fours;
    temp->sixes = sixes;
    temp->next = NULL;
    
    if(head==NULL)
    {
        head = temp;    
    }
    else 
    {
        temp->next = head;
        head = temp;
    }    
    
    return head;
    
}

/* 
function to write linked list to a file
takes in the filename and head node pointer of linked list as its inputs
task of function is to write all the data from linked list to the file
*/
void writeLinkedList(char filename[], node* head){
    
    struct node* temp = head;
    
    FILE* file;
    file = fopen (filename, "w");
    if (file == NULL)
    {
        fprintf(stderr, "\nCouldn't Open File'\n");
        exit (1);
    }
    
    // writing all the nodes of the linked list to the file
    while(temp!=NULL)
    {
        fwrite(temp, sizeof(struct node), 1, file);
        temp = temp->next;
    }
    
    if(fwrite != 0)
    {
        printf("Linked List stored in the file successfully\n");
    }
       else
    {
           printf("Error While Writing\n");
    }
    
    fclose(file);
    
    
}

/* 
function takes head pointer of linked list as input, and the index of the node to be edited (number of the batsman whose data has to be edited)
task of function is to edit nth element, takes head and index as inputs, edits the particular element
*/
struct node* editNode(node* head, int index) {
    struct node* temp = (struct node *)malloc(sizeof(struct node));
    struct node* current = head;
    char name[10], lastname[10];
    int runs, balls, fours, sixes; 
    // the index of the node we're currently looking at
    int count = 0;
    while (current != NULL) {
        if (count == index)
        {
        	//take name
   		printf("Enter name: ");
   		scanf("%s", name);
   
		//take surname
   		printf("Enter surname: ");
  		 scanf("%s", lastname);

		// take runs  
  		 printf("Enter runs: ");
   		scanf("%d",&runs);
   
		// take runs  
  		 printf("Enter balls: ");
  		 scanf("%d",&balls);
   
		// take fours
   		printf("Enter fours: ");
  		 scanf("%d",&fours);
   
		// take sixes
   		printf("Enter sixes: ");
  		 scanf("%d",&sixes);
  		 
		temp->runs = runs;
		temp->balls = balls;
		temp->fours = fours;
		temp->sixes = sixes;
        }
            
        count++;
        current = current->next;
    }
        return head;
    
}

/*
function to read linked list, from file (if needed)
returns struct node pointer
takes string filename as input 
*/
struct node* readLinkedList(char filename[]){
    
    struct node* temp = (struct node *)malloc(sizeof(struct node));
    struct node* head; // points to the first node of the linked list in the file
    struct node* last; // points to the last node of the linked list in the file
    last = head = NULL;
    
    FILE* file;
    file = fopen (filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "\nCouldn't Open File'\n");
        exit (1);
    }
    
    // reading nodes from the file
    // nodes are read in the same order as they were stored
    // we are using the data stored in the file to create a new linked list
    while(fread(temp, sizeof(struct node), 1, file))
    {
        
        if(head==NULL)
        {
            head = last = (struct node *)malloc(sizeof(struct node));
        }
        else
        {
            last->next = (struct node *)malloc(sizeof(struct node));
            last = last->next;
        }
        strcpy(last->name, temp->name);
        strcpy(last->lastname, temp->lastname);
        last->runs = temp->runs;
        last->balls = temp->balls;
        last->fours = temp->fours;
        last->sixes = temp->sixes;
        last->next = NULL;
        
    }
    
    fclose(file);
    
    return head;
    
}

/*
editableController code for this file
it presents the admin with menus to choose what he wants to do, enter data he wants and edit the linked list
acts as the main controller for all functions in this file and gives them control whenever needed
*/
void editableController() {
    struct node *head = NULL;
    system("clear");
    bool cont=true;
    char name[10], lastname[10];
    int runs, balls, fours, sixes;
    int input;
//taking input from user
    int num,edit;
    printf("\nEnter No. of batsmen: ");
    scanf("%d", &num);
    
    while(cont){
    printf("\n1. Enter Info\n2. Edit Particular Batsman info\n3. Display Linked List\n4. Exit");
    scanf("%d", &input);
    
    if(input==1){
    
	    	for(int i=1; i<num+1; i++){
	    	printf("\nEnter info for batsman %d",i);
		//take name
	   	  printf("\nEnter name: ");
	   	//fgets(buffer, 10, stdin);
	   	  scanf("%s", name);
	   
	   
		//take surname
		   printf("Enter surname: ");
		   //fgets(buffer, 10, stdin);
		   scanf("%s", lastname);

		// take runs  
		   printf("Enter runs: ");
		   scanf("%d",&runs);
		   
		// take runs  
		   printf("Enter balls: ");
		   scanf("%d",&balls);
		   
		// take fours
		   printf("Enter fours: ");
		   scanf("%d",&fours);
		   
		// take sixes
		   printf("Enter sixes: ");
		   scanf("%d",&sixes);

		head =insertAtBegin(head, name, lastname, runs, balls, fours, sixes);
    
    }
 }
    
    else if(input==2)
    	{
    		printf("\nEnter the batman's number");
    		scanf("%d", &edit);
    		struct node* newHead= editNode(head, edit);
    		displayLinkedList(newHead);
    		
    	}   
    else if(input==3)
    	{
		displayLinkedList(head);
		writeLinkedList("editable_score.txt", head);
		    
		printf("\nReading Scorecard into Linked List from file!\n");
		struct node* newHead = readLinkedList("editable_score.txt");
		printf("\nNew Linked List\n");
		displayLinkedList(newHead);
    	}
    else if(input==4)
    	{
    		cont=false;
    	}
   }
}
