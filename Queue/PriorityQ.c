/*
File:        PriorityQ.c
Description: An Implementation of Priority Q using Binary Heap.
Author:      Babribhan Jangra
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//--------------------------
#define RCHILD(x) (2*x + 2)
#define LCHILD(x) (2*x + 1)
#define PARENT(x) (x - 1)/2

typedef struct p_queue
{
	unsigned size;
	unsigned capacity;
	int* arr;
}pQueue;

pQueue* initPriorityQ(unsigned max_size)
{
	pQueue* tempQ = (pQueue*)malloc(sizeof(pQueue));
	tempQ->size = 0 ;
	tempQ->capacity = max_size;
	tempQ->arr = (int*)malloc(sizeof(int)*max_size); 
	return tempQ;
}
int isEmpty(pQueue *pq)
{
	return (pq->size == 0 );
}
int isFull(pQueue *pq)
{
	return (pq->size == pq->capacity);
}

int size(pQueue *pq)
{
	return pq->size;
}

void swap(int *element1 , int *element2)
{
	int tempValue = *element1;
	*element1 = *element2;
	*element2 = tempValue;
}
void minHeapify(pQueue *pq , int index)
{
	int right = RCHILD(index);
	int left  = LCHILD(index);
	int smallest = index;
	if ( left < size(pq) && pq->arr[left] < pq->arr[index])
	{
		smallest = left;
	}
	if ( right < size(pq) && pq->arr[right] < pq->arr[smallest])
	{
		smallest = right;
	}
	if ( smallest != index)  // if minHeap property is violated then fix it.
	{
		swap(&pq->arr[smallest], &pq->arr[index]);
		minHeapify(pq, smallest);
	}

}
int minKey(pQueue *pq)
{
	if (isEmpty(pq) )
	{
		printf("Error : Queue is empty.\n");
		exit(1);
	}
	return pq->arr[0];
}
int  removeMinKey(pQueue *pq)
{
	if (isEmpty(pq) )
	{
		printf("Error : Queue is empty.\n");
		exit(1);
	}
	else if ( 1 == size(pq) )
	{
		pq->size--;
		return pq->arr[0];
	}
	int root = pq->arr[0] ;
	pq->arr[0] = pq->arr[pq->size-1];
	pq->size--;
	minHeapify(pq,0);
	return root;
}
void insertKey(pQueue *pq , int value)
{
	if(isFull(pq))
	{
		printf("Error : Queue is full.\n");
		exit(1);
	}
	pq->size++;
	int index = pq->size -1 ;  // Put the item at Last index.
	pq->arr[index] = value;
	while( index && pq->arr[PARENT(index)] > pq->arr[index]) // Fix Min heap property if it is violated.
	{
		swap(&pq->arr[PARENT(index)], &pq->arr[index]);
			index = PARENT(index);
	}
printf("Element <%d> is inserted in the PQ.\n",value);
}
void increasePriority(pQueue *pq , int index ,int new_value)
{
	if (isEmpty(pq) )
	{
		printf("Error : Queue is empty.\n");
		exit(1);
	}
	pq->arr[index] = new_value; // Put New value at Given index.
	while( index && pq->arr[PARENT(index)] > pq->arr[index]) // Fix Min Property if it is violated.
	{
		swap(&pq->arr[index], &pq->arr[index]);
			index = PARENT(index);
	}
}
void decreasePriority(pQueue *pq , int index ,int new_value)
{
	if (isEmpty(pq) )
	{
		printf("Error : Queue is empty.\n");
		exit(1);
	}
	pq->arr[index] = new_value; // Put New value at Given index.
	minHeapify(pq,index); // Fix Min Property if it is violated.
}
void deleteKey(pQueue *pq , int index)
{
	if (isEmpty(pq) )
	{
		printf("Error : Queue is empty.\n");
		exit(1);
	}
	pq->arr[index] = INT_MIN;
	removeMinKey(pq);
}

void printPQueue(pQueue *pq)
{
 if (isEmpty(pq) )
 {
         printf("Error : Queue is empty.\n");
         exit(1);
 }
int index ;
for ( index = 0 ; index <= pq->size -1 ; index++)
printf("pq->arr[%d] = %d\n",index,pq->arr[index]);
}

int main(void)
{
pQueue *pq = initPriorityQ(9);
insertKey(pq,4);
insertKey(pq,8);
insertKey(pq,12);
insertKey(pq,1);
insertKey(pq,18);
insertKey(pq,9);
insertKey(pq,22);
insertKey(pq,11);
printPQueue(pq);
increasePriority(pq ,1,2);
printPQueue(pq);
decreasePriority(pq ,0,23);
printPQueue(pq);
printf("Size of Q is <%d>\n",size(pq));
return 0;
}
