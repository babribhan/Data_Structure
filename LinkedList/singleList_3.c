/**********************************************************
 * File        : singleList_3.c
 * Description : Show Deletion from  Beginning of the List 
 * Author      : Babribhan Jangra 
 * Date        : May 04, 2018 
 **********************************************************/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define EXIT_SUCCESS 0
// Define a Node 
struct node {
	int info;
	struct node *link;
};
typedef struct node NODE;
NODE *head =NULL;
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
	if (head == NULL )
	{
		head = newNode;
	}
	else 
	{
		// List is having some nodes.
		newNode->link = head;
		head = newNode;

	}
}

void DeleteBeg()
{
  // Check if list is empty.
if ( head == NULL )
     {
     printf("List is empty.\n");
exit(-1);     
}
NODE *tmp =head;
head = head->link;
free(tmp);


}


// API For Printing the List .

void PrintList()
{
	NODE *iterator =head;
	printf("List is : ");
	while (iterator != NULL )  // till the end of the list.
	{
		printf("%d ",iterator->info);
		iterator = iterator->link;
	}


}


int main(int argc, char* argv[])
{
	int noOfElement;
	int i;
	int element;
	printf("How many elements .\n");
	scanf("%d",&noOfElement);
	printf("_________\n");
	for (i=1;i<=noOfElement;i++)
	{
		printf("Data :\n");
		scanf("%d",&element); 
		InsertAtBeg(element);
	}
	PrintList();
        printf("\n");
	printf("List After First Node Deletion.\n");
	DeleteBeg();
	PrintList();
	printf("\n");
	return EXIT_SUCCESS;
}

