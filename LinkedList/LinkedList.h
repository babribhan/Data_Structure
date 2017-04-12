#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

/* S T A N D A R D   I N C L U D E S  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct node {
	int data;
	struct node* next;
        int size;
}Node;

int isEmpty( Node *);

/* S T A N D A R D   O P E R T I O N S */
void Push(Node**,Node**, int );

void  Append(Node**, int);

void DisplayList(Node *);

Node* getNode();

void  insertAfter(Node *,Node **, int );

#endif
