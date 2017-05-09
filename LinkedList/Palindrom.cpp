/*----------------------------------------------------------------
  | FILE NAME : List.c
  | DATE      : Aug 29 ,2016
  | AUTHOR    : Babribhan Jangra
  |
  |DESCRIPTION: A Program to Implement a Single Linked List.
  |----------------------------------------------------------------*/
#include<iostream>
#include<stack>
#include "LinkedList.h"
using namespace std;
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
  free(nodeToDelete);
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
/* FUNCTION TO DISPLAY LIST */
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
 /* FUNCTION TO REVERSE A LINKED LIST USING RECURSION */
 void reverse(Node **head)
 {
  if ( *head && (*head)->next )
    {
    Node *prev = NULL,*curr = *head , *next = NULL;
    while(curr)
    {
     next = curr->next;
     curr->next = prev;
     prev = curr;
     curr = next;
    }
     *head = prev;
    }
 }
 /* FUNCTION TO CHECK A SINGLY LINKED LIST IS PALINDROM OR NOT BY REVERSING HALF PART
   OF THE LIST. */
bool isPalindrom(Node *head)
{
if ( !head || !head->next ) return true;
 else
 {
   Node *slow = head , *fast = head , *prev = NULL;
   while( fast && fast->next )
   {
     fast = fast->next->next;
     prev = slow;
     slow = slow->next;
   }
   reverse(&slow);
   prev->next = slow;
   fast = head;
   Node *mid = slow;
   while(mid)
   {
     if ( fast->data != mid->data )
     {
       reverse(&slow);
       prev->next = slow;
       return false;
     }
     fast = fast->next;
     mid = mid->next;
   }
   reverse(&slow);
   prev->next = slow;
   return true;
 }
}
/* FUNCTION TO CHECK LINKED LIST IS PALINDROM OR NOT BY USING STACK */
bool checkPalindrom(Node *head )
{
 stack <int> s;
 Node *temp  =head;
 while ( temp )
   {
     s.push(temp->data);
     temp = temp->next;
     }
 temp = head ;
 while ( temp && s.empty() == false )
  {
   if ( temp->data != s.top() )
     {
      return false;
     }
   temp = temp->next;
   s.pop();
  }
  return true;
}
/* FUNCTION TO CHECK LINKED LIST IS PALINDROM OR NOT BY ONLY RECURSION */
bool isPalindromUtil(Node **left , Node *right)
{
  if (!right) return true;
  if ( !isPalindromUtil(left,right->next)) return false;
  // Check the values.
  bool isp = ((*left)->data == right->data);
  *left = (*left)->next;
  return isp;
}
bool isPalindrom1(Node *head)
{
  return isPalindromUtil(&head,head);
}
int main(){

Node *head = NULL , *tail = NULL;
InsertFront(&head ,&tail,3);
InsertFront(&head ,&tail,3);
InsertFront(&head ,&tail,1);
InsertEnd(&head,&tail,2);
DisplayList(head );
//if (isPalindrom(head))
if (isPalindrom1(head))
  printf("List is Palindrom.\n");
  else
    printf("list is not Palindrom.\n");
return 0;
}
