                                                      /******************************
                                                      Assignment for Programming in C
                                                      by PlusPlusNoob
                                                      ******************************/


#include<stdlib.h>
#include <stdio.h>
     
//Functions
void display();
void Push();
void InsertEnd();
void InsertPos();
void Pop();
void DeleteEnd();
void DeletePos();

//creating a structure node
struct node

{

        float holder; //decimal holder, allows the program to read and print decimals
        struct node *next;
};
struct node *head=NULL; 
    int main()
{
  int choice; //declaring choices for the menu
    while(1) //the 1 makes the menu loop until a valid choice is made
    {
    printf("\n***********************************************\n");//creates some room to make reading easier for each options     
    printf("\nNumber List Customization");
    printf("\n 1.Display List");
    printf("\n 2.Insert number on top (Push)");
    printf("\n 3.Insert number on bottom");
    printf("\n 4.Insert number at specified position");
    printf("\n 5.Delete number from top (Pop)");
    printf("\n 6.Delete number from bottom");
    printf("\n 7.Delete number from specified position");
    printf("\n 8.Exit\n");
    printf("Selection:");
    scanf("%d",&choice); //input from user, selecting their choices
    printf("Processing...\n"); //again just to make some room for easier reading and kind of cool
while(choice < 1 || choice > 8) //only 1-8 are valid choices
{
     while(getchar() != '\n');
     printf("\n\nSorry, you've made an invalid selection! Please select using only the numbers 1 through 8.\n\nPlease enter a selection (1 - 8): ");
     scanf("%d", &choice);
   }
switch(choice) //switch Functions - what each choice above correlates to.
                {

  case 1:
    display();
    break;
             
  case 2: 
    Push();
    break;
                  
  case 3:
    InsertEnd();
    break;
                                        
  case 4:
    InsertPos();
    break;
                                        
  case 5:
    Pop();
    break;
                                        
  case 6:
    DeleteEnd();
    break;
                                        
  case 7:
    DeletePos();
    break;
                        
  case 8:
  {
  printf("This program deserves an A");//What other grade does this awesome program deserves? Maybe A++
  

                }
    exit(0);//exits the program
  
    break;

   }  
        }
        return 0;
}
//what each switches do

//1.display
void display()
{
        struct node *ptr;
        if(head==NULL)//tells the user when the list is empty
        {
                printf("***********************************************"); 
                printf("\nList is empty:\n\n");
               
                return;
        }
        else
        {
            //loop
                ptr=head;//points at head
                printf("The List numbers are:\n");
                while(ptr!=NULL)//if pointer is not empty do this
                {
                        printf("%.2f \n",ptr->holder );//prints 2 decimal place number in list
                        ptr=ptr->next ;//pointer moves to next node then we repeat until pointer is empty displaying the list
                }
        }
}

//2.insert from the top
void Push()
{
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
     

        printf("Enter the number to  be put on top of the list:" );
        scanf("%f",&temp->holder);//user can input any number on top of list including decimals
        
        temp->next =NULL;
        if(head==NULL)
        
        {
                head=temp;
        }
        else
        {
                temp->next=head;
                head=temp;
                
        
        }
}
//3.insert on the bottom
void InsertEnd()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
   
        printf("Enter the number you want to be put on the bottom of the list:" );
        scanf("%f",&temp->holder );//user can input any number on bottom of list including decimals
        temp->next =NULL;
        if(head==NULL)
        {
                head=temp;
        }
        else
        {
                ptr=head;
                while(ptr->next !=NULL)
                {
                        ptr=ptr->next ;
                }
                ptr->next =temp;
        }
}
//4.insert position starting at 0
void InsertPos()
{
        struct node *ptr,*temp;
        int i,pos;
        temp=(struct node *)malloc(sizeof(struct node));
   
        //position input
        printf("Enter the position for the new number to be inserted; remember 0 is top: ");
        scanf("%d",&pos);//user inputs the position of the number
        
        //number input
        printf("Enter the number you want in that position: ");
        scanf("%f",&temp->holder);//user inputs the actual number
  
        temp->next=NULL;
        if(pos==0)
        {
                temp->next=head;
                head=temp;
        }
        else
        {
            //checks if position entered by user exists
                for(i=0,ptr=head;i<pos-1;i++) 
		{ 
			ptr=ptr->next;
                        if(ptr==NULL)
                        {
                                printf("Position not found! Remember top position is 0: ");
                                return;
                        }

                }
                temp->next =ptr->next ;
                ptr->next=temp;
        }
}

//5.delete from top
void Pop()
{
        struct node *ptr;
        if(ptr==NULL)//if list is empty do this
        {
                printf("List is Empty:\n");//tells user the list is empty
                return;
        }
        else
        {
            //removes the top number
                ptr=head;
                head=head->next ;
                printf("The beginning/top number %f has been deleted\n",ptr->holder);
                free(ptr);//frees the pointer
        }
}

//6.delete from the bottom
void DeleteEnd()
{
        struct node *temp,*ptr;
        if(head==NULL)//list is empty
        {
                printf("List is Empty:\n");//tells user list is empty
                
        }
        //checks if the bottom number is top number = only 1 number in list
        else if(head->next ==NULL)
        {
                ptr=head;
                head=NULL;
                //tells the user there's only 1 number left and it's been removed
                
                printf("The only number left, %f has been deleted\n",ptr->holder);
                free(ptr);//frees the pointer
        }
        else
        {
                ptr=head;
                while(ptr->next!=NULL)
                {
                        temp=ptr;
                        ptr=ptr->next;
                }
                temp->next=NULL;
                printf("The ending/bottom number %f has been deleted\n",ptr->holder);//tells user the bottom number is deleted
                free(ptr);//frees the pointer
        }
}

//7.delete from any position; starting at 0
void DeletePos()
{
        int i,pos;
        struct node *temp,*ptr;
        if(head==NULL)//checks if list is empty
        {
                printf("The List is Empty:\n");//tells user list is empty
                
        }
        else
        {
            //function begins; 
                printf("Enter the position of the node to be deleted, top is 0:");
                scanf("%d",&pos);
                if(pos==0)
                {
                    //deleting the number in that position
                        ptr=head;
                        head=head->next ;
                        printf("The deleted number is:%f\n",ptr->holder  );
                        free(ptr);
                }
                else
                {
                    //checks the position if empty
                        ptr=head;
                        for(i=0;i<pos;i++) 
			{
			 temp=ptr; ptr=ptr->next ;
                                if(ptr==NULL)
                                {
                                        printf("Position not Found; remember top is 0:\n");
                                        return;
                                }
                        }
                        temp->next =ptr->next ;
                        printf("The deleted number is:%f\n",ptr->holder );
                        free(ptr);
                }
        }
}
//Program Ends
