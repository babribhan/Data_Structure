/*----------------------------------------------------------------
  | FILE NAME : List.c
  | DATE      : Aug 29 ,2016
  | AUTHOR    : Babribhan Jangra
  | 
  |DESCRIPTION: A Program to Implement a Single Linked List.
  |----------------------------------------------------------------*/
#include "LinkedList.h"
/* FUNCITON TO GET A NEW NODE */ 
int isEmpty(Node *head)
{
	return (head == NULL);

}

/* UTILITY FUNCTION TO GET A NODE */
Node* getNewNode(int value)
{
	Node *tempNode =(Node*)malloc(sizeof(Node));
	tempNode->next = NULL;
        tempNode->data = value;
return tempNode;
}

/* FUNCTION TO PUSH A NODE AT FRONT OF CIRCULAR LIST */
void  InsertFront(Node **head ,Node **tail, int value)
{
	Node *newNode= getNewNode(value);
	if(isEmpty(*head)){
		*tail = *head = newNode;
                (*tail)->next = *head; // Make a Loop.
	}
	else {
		newNode->next = *head;
		*head = newNode;
                (*tail)->next = *head;  // Update Tail with New Head.

	}
}

/* FUNCTION TO INSERT A NODE AFTER A GIVEN NODE */
void  insertAfter(Node *prev_node ,Node **tail, int value){
	Node *newNode;
	if(isEmpty(prev_node)){
		printf("prev_node can't be NULL.\n");
		return ;
	}
        newNode = getNewNode(value);
	if (prev_node->next == *tail) // It's Last Node so We Need to Update Tail.
	{
		newNode = getNewNode(value);
		newNode->next = prev_node->next; // Update Loop.
                prev_node->next = newNode;
		*tail = newNode; // Update Tail.
                

	}
        else if ( prev_node  == *tail)
            {
              newNode->next = prev_node->next; // Update Loop.
              prev_node->next = newNode;
              *tail = newNode; // Update Tail. 
            }
	else 
	{
		newNode->next = prev_node->next;
		prev_node->next = newNode;

	}
}
/* FUNCTION TO APPEND A NODE TO A CIRCULAR LIST */
void InsertEnd(Node** head,Node** tail , int value){
	Node *newNode = getNewNode(value); 
	if(isEmpty(*tail)){
	     *head=*tail = newNode;
             *tail = *head ; // Make  a Loop.
	}
	else{
                newNode->next = (*tail)->next;
		(*tail)->next = newNode;
		*tail = newNode;
	}


}

/* FUNCTION TO DELETE  A NODE FROM FRONT OF CIRCULAR LIST*/
void  DeleteFront(Node **head ,Node **tail)
{
	Node *nodeToDelete;
	if(isEmpty(*head)){
		printf("List Underflow.\n");
		return ;
	}
	nodeToDelete = *head;
	*head = (*head)->next;
	if ( *head == *tail) // When only one Node is There in the list.
	{
		*tail = NULL; // Making List Empty.
	}
	else 
	{
		(*tail)->next = *head; // Update Loop.

	}
}
/* FUNCTION TO DELETE  A NODE ATER A GIVEN NODE */
void  DeleteAfter(Node *prev ,Node **tail)
{
	Node *nodeToDelete;
	if(isEmpty(*tail)){
		printf("List Underflow.\n");
		return ;
	}
        else if ( prev->next == prev )
        {
        printf("List have only One Node.\n");
        return ;
        }
        else if ( prev->next == *tail ) // Given Node is Second Last Node.
        {
        *tail = prev;// Update Tail.
        }
        else if ( prev == *tail ) // if Last Node(tail ) is given.Then we need to update Head.
        {
        (*tail)->next  = (*tail)->next->next ;// Update Head.

        }
	nodeToDelete = prev->next;
        prev->next = prev->next->next;
        free(nodeToDelete);
}
/* FUNCTION TO GET DATA AT END OF LIST */
int getTail(Node *tail)
{
	if(isEmpty(tail))
		return INT_MIN;
	else 
		return tail->data;

}
/* FUNCTION TO GET DATA AT FRONT OF LIST */
int getFront(Node *head)
{
	if(isEmpty(head))
		return INT_MIN;
	else 
		return head->data;

}
/* SUPPORTIVE METHOD TO PRINT CIRCULAR LIST */
void DisplayList(Node *head){
	Node  *current = head ;
	if ( isEmpty(head )){
		printf("List is empty.\n");
		return ;
	}
	else {
		printf("List is : ");
		do 
		{
			printf("%d-->",current->data);
			current = current->next;
		}
		while(current  != head );
		printf(".......\n");
	}

}

int main(){

Node *head = NULL , *tail = NULL;
InsertFront(&head ,&tail,2);
InsertFront(&head ,&tail,3);
InsertFront(&head ,&tail,6);
insertAfter(head->next,&tail,9);
InsertEnd(&head,&tail,4);

DisplayList(head );
DeleteFront(&head ,&tail);

InsertFront(&head ,&tail,16);
DisplayList(head );
DeleteAfter(head,&tail);
DisplayList(head );
printf("Data at Front is <%d>.\n",getFront(head));
printf("Data at End is <%d>.\n",getTail(tail));
printf("Data at Next of End is <%d>.\n",getTail(tail->next));
insertAfter(tail,&tail,9);
DisplayList(head );
printf("Data at Front is <%d>.\n",getFront(head));
printf("Data at End is <%d>.\n",getTail(tail));
printf("Data at Next of End is <%d>.\n",getTail(tail->next));
return 0;
}
