#include "scoreboard.h"


// function to display linked list
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

// insert node at the beginning of the linked list
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

// function to write linked list to a file
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

// edit nth element, takes head and index as inputs, edits the particular element
void editNode(struct node* head, int index) {
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
    
}

/*function to read linked list,
returns struct node pointer
takes string filename as input */
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

/*controller code for this file*/
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
    printf("\n1. Enter Info\n2. Edit Particular Batsman info\n3. Display Linked List\n3. Exit");
    scanf("%d", &input);
    
    if(input==1){
    
	    	for(int i=1; i<num+1; i++){
	    	printf("\nEnter info for batsman %d",i);
		//take name
	   	  printf("Enter name: ");
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
    		//to be written
    		printf("\nEnter the batman's number");
    		scanf("%d", &edit);
    		editNode(head, edit);
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
