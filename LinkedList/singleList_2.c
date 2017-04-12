/**********************************************************
 * File        : singleList.c
 * Description : Show Insertion at a particular Position of the List
 * Author      : Babribhan Jangra
 * Date        : May 04, 2018
 **********************************************************/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define EXIT_SUCCESS 0
struct node 
{
	int info;
	struct node *link;
};
typedef struct node NODE;
NODE *head= NULL;
int totalNode =0;
NODE * createNode()
{
	NODE *nodeToReturn = (NODE *)malloc(sizeof(NODE));
	nodeToReturn->link = NULL;
	return nodeToReturn;
}
void InsertAtBeg(int data)
{
	NODE *newNode = createNode();
	newNode->info = data;
	if ( head == NULL )
	{
		head = newNode;
	}
	else
	{
		newNode->link = head;
		head = newNode;
	}
	totalNode++; //One More Node is created.
}
void PrintList()
{
	NODE *iterator = head;
	printf("List is : ");
	while(iterator != NULL )
	{
		printf("%d ",iterator->info);
		iterator = iterator->link;
	}
	printf("\n");
}
void  InsertAtLoc(int loc , int element)
{
	int i;
	NODE *tmpNode = head ;
	NODE *newNode = createNode();
	// If Location is Not valid .
	if (loc >totalNode+1)
	{
		printf("Oh ! Data cannot be inserted here.Try Again with valid Location.\n");
		exit(1);
	}
	for(i=1;i<loc-1;i++)
	{

		tmpNode = tmpNode->link;
	}
	newNode->info = element;
	newNode->link = tmpNode->link;
	tmpNode->link = newNode;
	totalNode++;



}

int main(int argc , char* argsv[])
{
	int noOfElement;
	int data;
	int i;
	int newNodeLoc;
	printf("How many Numbers.\n");
	scanf("%d",&noOfElement);
	for(i =1;i<=noOfElement;i++)
	{
		printf("Data :\n");
		scanf("%d",&data);
		InsertAtBeg(data);

	}
	PrintList();

	printf("At What Location do you want to insert a Node.\n");
	scanf("%d",&newNodeLoc);
	printf("Give me Data for Locatoin.\n");
	scanf("%d",&data);
	InsertAtLoc(newNodeLoc , data );
	PrintList();



	return EXIT_SUCCESS;
}


