/**********************************************************
 * File        : singleList.c
 * Description : Show Insertion at Beginning of the List 
 * Author      : Babribhan Jangra 
 * Date        : May 04, 2018 
 **********************************************************/
#include <stdio.h>
#include <malloc.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE -1

// Define a Node 
struct node {
	int info;
	struct node *link;
};
typedef struct node NODE;

NODE *HEAD =NULL;
NODE *LAST =NULL;

//   API to get a New Node 
NODE * getNewNode()
{
	NODE *temp=(NODE *)malloc(sizeof(NODE));
	temp->link=NULL;
	return temp;

}

// API to Insert A node at Begininng.
void InsertAtBeg(int data )
{
	NODE *newNode =getNewNode();
	newNode->info = data ;
	// For empty List 
	if (HEAD == NULL )
	{
		LAST = HEAD = newNode;
	}
	else 
	{
		// List is having some nodes.
		newNode->link = HEAD;
		HEAD = newNode;

	}
}

// API For Printing the List .
void PrintList()
{
	NODE *iterator =HEAD;
	printf("List is : ");
	while (iterator != NULL )  // till the end of the list.
	{
		printf("%d ",iterator->info);
		iterator = iterator->link;
	}


	printf("\n");
}

// API For Checking A Loop in List and find the start of the Loop.
int hasLoop()
{

	NODE *slow , *fast;

	slow = fast = HEAD;
	while ( fast != NULL && fast->link != NULL )
	{
		slow = slow->link; // Move Slow Pointer One step at a time.
		fast = fast->link->link;  // Move Fast Pointer Two step at a time.
		if ( slow == fast )
		{
			printf("Loop is detected in the List.\n");
			slow = HEAD;
			while ( slow->link != fast->link )
			{
				slow = slow->link;
				fast = fast->link;
			}
			printf("Loop start at Node Value %d and Address %p\n",slow->info,slow);
                        fast->link =  NULL;
			return 0;
		}

	}
	printf("There is no Loop exist in the List.\n");
	return 0;

}
int main(int argc, char* argv[])
{
	InsertAtBeg(2);
	InsertAtBeg(3);
	InsertAtBeg(7);
	InsertAtBeg(5);
	InsertAtBeg(8);
	InsertAtBeg(1);
	InsertAtBeg(9);
	PrintList();
	// Create A Loop in the List .
	LAST->link = HEAD->link->link;
	//PrintList();       
	// Detect a Loop in the list.
	hasLoop(); 
	hasLoop(); 
	return EXIT_SUCCESS;
}

