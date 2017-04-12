/*----------------------------------------------------------------
  | FILE NAME : List1.c
  | DATE      : Aug 29 ,2016
  | AUTHOR    : Babribhan Jangra
  | 
  |DESCRIPTION: A Program to Implement a Single Linked List.
  |----------------------------------------------------------------*/
#include "LinkedList.h"

/* FUNCITON TO GET A NEW NODE */ 
int isEmpty(Node *head){
	return (head == NULL);

}

/* UTILITY FUNCTION TO GET A NODE */

Node* getNode(){
	Node *tempNode =(Node*)malloc(sizeof(Node));
	tempNode->next = NULL;
	return tempNode;
}

/* FUNCTION TO PUSH A NODE AT FRONT */
void  InsertFront(Node **head ,Node **tail , int value){
	Node *newNode;
	if(isEmpty(*head)){
		newNode = getNode();
		newNode->data = value;
		(*tail) = (*head) = newNode;
	}
	else {
		newNode = getNode();
		newNode->data = value;
		newNode->next = (*head);
		(*head) = newNode;

	}
}

void  insertAfter(Node *prev_node , int value){
	Node *newNode;
	if(isEmpty(prev_node)){
		printf("prev_node can't be NULL.\n");
		return ;
	}
	else {
		newNode = getNode();
		newNode->data = value;
		newNode->next = prev_node->next;
		prev_node->next = newNode;

	}
}
/* FUNCTION TO APPEND A NODE TO A LIST */
void Append(Node** tail , int value){
	Node *newNode = getNode(); 
	if(isEmpty(*tail)){
		newNode->data = value ;
		(*tail) = newNode;
	}
	else{
		newNode->data = value;
		(*tail)->next = newNode;
		(*tail) = newNode;
	}


}

void DisplayList(Node *head){
	Node *current = head ;
	if ( isEmpty(head )){
		printf("List is empty.\n");
		return ;
	}
	else {
		printf("List is : ");
		while(current != NULL ){
			printf("%d-->",current->data);
			current = current->next;
		}
		printf("NULL\n");
	}

}
void deleteNode(Node **head , int key ){
	Node *temp = *head;
	Node *prev = NULL;
	if ( temp !=NULL && temp->data == key)
	{
		*head = (*head)->next;
		free(temp);
		return ;
	}
	while ( temp != NULL && temp->data !=key)
	{
		prev = temp;
		temp = temp->next;
	}

	if ( temp == NULL )
		return ;

	prev->next = temp->next;
	free(temp); // Free Memory.

}

void deleteNodeAt( Node **head , int position )
{

	int i;
	if ( *head == NULL ) return ; // List is empty.

	Node *temp = *head ;

	if ( position == 0 )
	{
		*head = (*head)->next ;
		free(temp); 
		return ;
	}
	for ( i  =0 ;temp != NULL &&  i< position-1; i++)
		temp = temp->next;
	if ( temp == NULL  && temp->next == NULL )
		return ;

	Node *next = temp->next->next;
	free(temp->next);  // Free memory.
	temp->next = next;   // Unlink the Deleted node.

}

/* ITERATIVE LENGTH COUNT API */

int getCount(Node *head )
 {
   int count =0;
   Node *current = head;
   if ( isEmpty(head))
   {
    return count;
   }
   else 
{
 while ( current != NULL )
  {
  count++;
  current = current->next;
  }
  return count;
 }
}

/* RECURRSIVE LENGTH COUNT API */

int getCountR(Node *head )
{
	if ( isEmpty(head))
	{
		return 0;
	}
	else 
	{
		return (1+getCount(head->next));
	}
}

void swapNode(Node **head , int x , int y)
{
 // if X and Y are Same Then do Nothing.
 if ( x == y )
   {
 printf("Both x and y are equal.\n");  
  return ;
}
 // Search For x and keep track of it's Pervious Node.
  Node *currX = *head , *prevX = NULL,*temp = NULL;
  while ( currX && currX->data != x )
       {
      prevX = currX;
      currX = currX->next;
}

 // Search For y and keep track of it's Pervious Node.
  Node *currY = *head , *prevY = NULL;
  while ( currY && currY->data != y )
       {
      prevY = currY;
      currY = currY->next;
}
  // If either x or y is not present then do nothing.
   if ( currY == NULL || currX == NULL )
{
      printf("Either x or y is not present in the list.\n");
       return ;
}

  // if x is not the head of the linked list.
  if ( prevX != NULL )
       prevX->next = currY;
  else
      *head = currY;
  // If y is not the head of the linked list.
  if ( prevY != NULL)
      prevY->next = currX;
  else 
      *head = currY;

// Swap the next pointers.
  temp = currX->next;
  currX->next = currY->next ;
  currY->next = temp;
 

}

/* OPTIMISED API */
void swapNodeEff(Node **head , int x , int y)
{
	// if X and Y are Same Then do Nothing.
	if ( x == y )
	{
		printf("Both x and y are equal.\n");  
		return ;
	}
	Node *currX = *head , *prevX = NULL,*temp = NULL;
	Node *currY = *head , *prevY = NULL;
	while ( (currX && currX->data != x ) || (currY && currY->data != y))
	{
		// Search For x and keep track of it's Pervious Node.
		if ( currX->data != x && currX)
		{
			prevX = currX;
			currX = currX->next;
		}
		// Search For y and keep track of it's Pervious Node.
		if ( currY->data != y && currY)
		{
			prevY = currY;
			currY = currY->next;
		}
	}

	// If either x or y is not present then do nothing.
	if ( currY == NULL || currX == NULL )
	{
		printf("Either x or y is not present in the list.\n");
		return ;
	}

	// if x is not the head of the linked list.
	if ( prevX != NULL )
		prevX->next = currY;
	else
		*head = currY;
	// If y is not the head of the linked list.
	if ( prevY != NULL)
		prevY->next = currX;
	else 
		*head = currY;

	// Swap the next pointers.
	temp = currX->next;
	currX->next = currY->next ;
	currY->next = temp;
}

void reverse( Node **head )
{
 Node *prev = NULL,*curr = *head , *next = NULL;
 while( curr != NULL )
{
 next = curr->next;
 curr->next = prev;
 prev = curr;
curr = next;
}
*head = prev;

}

void revrec(Node **head )
{
Node *first=*head , *rest;
if( first == NULL) return ;
rest = first->next;
if ( rest == NULL) return ;

revrec(&rest);
first->next->next = first;
first->next = NULL;
*head = rest;
}

void revUtil(Node *curr , Node *prev , Node **head)
{
	if ( !curr->next ) // Last Node.
	{
		*head = curr; 
		curr->next = prev;
		return ;
	} 
	Node *next = curr->next;
	curr->next = prev;
	revUtil(next , curr, head );


}
void Rev(Node **head )
{
 if ( !(*head)) return ;
 
 revUtil(*head , NULL, head );

}

void rotate(Node **head , int k)
{
	if ( k == 0 ) return ;
	int count =1;
	Node *curr = *head ;
	while ( count < k && curr != NULL )
	{
		curr  = curr->next;
		count++;
	}

	if ( !curr ) return ;

	Node *kthNode = curr;
	while ( curr->next != NULL )
	{
		curr = curr->next ;
	}
	curr->next = *head ;

	*head = kthNode->next;
	kthNode->next =  NULL;



}


int main(){
	Node *head = NULL , *tail = NULL;
	InsertFront(&head ,&tail,2);
	InsertFront(&head, &tail,3);
	InsertFront(&head ,&tail,8);
	InsertFront(&head ,&tail,1);
	insertAfter(head->next ,9);
	Append(&tail,4);
	DisplayList(head );
        printf("Total Elements are : <%d> \n",getCount(head));
        printf("Total Elements are : <%d> \n",getCountR(head));
	deleteNode(&head ,1 );
	DisplayList(head );
        deleteNodeAt(&head ,2);
	DisplayList(head );
        swapNodeEff(&head , 3,3);
        swapNodeEff(&head , 3,5);
        swapNodeEff(&head , 5,3);
        swapNodeEff(&head , 9,2);
	DisplayList(head );
        swapNodeEff(&head , 8,2);
	DisplayList(head );
        swapNodeEff(&head , 9,8);
	DisplayList(head );
        reverse(&head);
	DisplayList(head );
        revrec(&head);
	DisplayList(head );
        Rev(&head);
	DisplayList(head );
        rotate(&head ,1);
	DisplayList(head );
        printf("Total Elements are : <%d> \n",getCount(head));
        printf("Total Elements are : <%d> \n",getCountR(head));
	return 0;
}
