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

/* FUNCTION TO PUSH A NODE AT FRONT */
void  InsertFront(Node **head ,Node **tail, int value)
{
	Node *newNode= getNewNode(value);
	if(isEmpty(*head)){
		*tail = *head = newNode;
	}
	else {
		newNode->next = *head;
		*head = newNode;

	}
}

/* FUNCTION TO INSERT A NODE AFTER A GIVEN NODE */
void  insertAfter(Node *prev_node ,Node **tail, int value){
	Node *newNode;
	if(isEmpty(prev_node)){
		printf("prev_node can't be NULL.\n");
		return ;
	}
	else if (prev_node->next == NULL) // It's Last Node so We Need to Update Tail.
	{
		newNode = getNewNode(value);
		prev_node->next = newNode;
		*tail = newNode; // Update Tail.

	}
	else 
	{
		newNode = getNewNode(value);
		newNode->next = prev_node->next;
		prev_node->next = newNode;

	}
}
/* FUNCTION TO APPEND A NODE TO A LIST */
void InsertEnd(Node** head,Node** tail , int value){
	Node *newNode = getNewNode(value); 
	if(isEmpty(*tail)){
	     *head=*tail = newNode;
	}
	else{
		(*tail)->next = newNode;
		*tail = newNode;
	}


}

/* FUNCTION TO DELETE  A NODE FROM FRONT */
void  DeleteFront(Node **head ,Node **tail)
{
	Node *nodeToDelete;
	if(isEmpty(*head)){
		printf("List Underflow.\n");
		return ;
	}
	nodeToDelete = *head;
	*head = (*head)->next;
	if ( *head == NULL ) 
	{
		*tail = NULL; // Making List Empty.
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
        else if ( prev->next == NULL )
        {
        printf("Given Node is the Last Node of the List or List have only One Node.\n");
        return ;
        }
        else if ( prev->next->next == NULL ) // Given Node is Second Last Node.
        {
        *tail = prev;// Update Tail.
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
void DisplayList(Node *head){
	Node  *current = head ;
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
insertAfter(tail,&tail,9);
DisplayList(head );
printf("Data at Front is <%d>.\n",getFront(head));
printf("Data at End is <%d>.\n",getTail(tail));
return 0;
}
