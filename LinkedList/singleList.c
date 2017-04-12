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
typedef struct node {
	int info;
	struct node *link;
}NODE;

//   API to get a New Node 
NODE * getNewNode()
{
	NODE *temp=(NODE *)malloc(sizeof(NODE));
	temp->link=NULL;
	return temp;

}
// API to Insert A node at Begininng.

NODE * Push(NODE *h ,int data )
{
	NODE *newNode =getNewNode();
	newNode->info = data ;
	// For empty List 
	if (h == NULL )
	{
		h = newNode;
	}
	else 
	{
		// List is having some nodes.
		newNode->link = h;
		h = newNode;

	}
	return h;
}
// API For Printing the List .

void PrintList(NODE *h)
{
	NODE *iterator = h;
	printf("List is : ");
	while (iterator != NULL )  // till the end of the list.
	{
		printf("%d-->",iterator->info);
		iterator = iterator->link;
	}
	printf ("NULL\n");

}

NODE * ReverseList(NODE *h )
{
	if ( h == NULL || h->link == NULL)
	{ 
		return h;
	} 
	NODE *previous = NULL,*current = h , *next = NULL;
	while ( current != NULL )
	{
		next = current->link; // store next node.
		current->link = previous;// reverse link
		previous = current ;  
		current = next;
	}
	h = previous ;
	return h;
}

NODE * ReverseListK(NODE *h , int k)
{
	NODE *previous = NULL,*current = h , *next = NULL;
	int count = 0 ;
	while ( current != NULL && count < k )
	{
		next = current->link; // store next node.
		current->link = previous;// reverse link
		previous = current ;  
		current = next;
		count++;
	}
	if ( next != NULL )
		h->link = ReverseListK(next,k);
	return previous;
}
void swap(NODE **h ,int x , int y )
{
	if ( x == y ) 
	{
		printf("Data on Both Nodes are equal so nothing to do.\n");
		return ;
	}
	// Search for x and keep track of prev and current for x.
	NODE *currX = *h , *prevX = NULL;
	while( currX && currX->info != x )
	{
		prevX = currX;
		currX = currX->link;
	}

	// Search for y and keep track of prev and current for y.
	NODE *currY = *h , *prevY = NULL;
	while( currY && currY->info != y )
	{
		prevY = currY;
		currY = currY->link;
	}

	if ( currX == NULL || currY == NULL )
	{
		printf("Either x or y is not present in the List.\n");
		return ;

	}
	// if x is not the head of the list.
	if ( prevX != NULL )
	{
		prevX->link = currY;
	}
	else
	{
		*h = currY; 
	}

	// if y is not the head of the list.
	if ( prevY != NULL )
	{
		prevY->link = currX;
	}
	else
	{
		*h = currX; 
	}

	// swap link pointers.

	NODE *temp = currX->link;
	currX->link = currY->link;
	currY->link = temp;
}
NODE * deleteMid(NODE *h)
{
	if ( h == NULL ) // Deal with empty list.
	{
		return NULL;
	}
	if ( h->link == NULL ) // Deal with sinle element list.
	{
		free ( h);
		return NULL;
	}

	// take Two Pointers one slow and other fast.
	NODE *slow = h , * fast = h ,*slow_prev = NULL;

	while ( fast != NULL && fast->link != NULL )
	{
		fast = fast->link->link;
		slow_prev = slow;
		slow = slow->link;
	}

	slow_prev->link = slow->link;
	free(slow);
	return h;
}

int main(int argc, char* argv[])
{
	NODE *head =NULL;
	head = Push(head,1);
	head = Push(head,2);
	head = Push(head,3);
	head = Push(head,4);
	head = Push(head,5);
	PrintList(head);
	head = ReverseList(head);
	printf("List After Reverse is : \n");
	PrintList(head);
	//printf("\n");
	//swap(&head , 1, 5);	
	//PrintList(head);
	//printf("\n");
	//deleteMid(head);
	//PrintList(head);
	//printf("\n");
	//deleteMid(head);
	//PrintList(head);
	//printf("\n");
	 head = ReverseListK(head ,2);
	PrintList(head);
	return EXIT_SUCCESS;
}

