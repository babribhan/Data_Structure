/**************************************************************************
 * A program to Implement a Circular Q .
 * 
 ******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Cqueue
{
int front ,rear ,size;
unsigned capacity;
int *arr;
}CQ;

CQ* createCQ(unsigned capacity)
{
 CQ *Cqueue = (CQ*)malloc(sizeof(CQ));
 Cqueue->front = Cqueue->rear = Cqueue->size = 0 ;
 Cqueue->capacity = capacity;
 Cqueue->arr = (int *)malloc(sizeof(int)*capacity);
 return Cqueue;
}

int isFull(CQ *cq)
{

return ( cq->front = (cq->rear % cq->capacity) + 1 );
}

int isEmpty(CQ *cq)
{

return cq->front == cq->rear;
}

void Enqueue(CQ *cq ,int item)
{
 if ( isFull(cq))
{
printf("Error : Q is Full.\n");
return ;
}
cq->rear =( cq->rear == cq->capacity ? (cq->rear % cq->capacity) + 1 : cq->rear +1 );

cq->arr[cq->rear] = item;
cq->size ++;
printf("[ %d ] is Enquee in the CQ.\n",item);
}
void Dequeue(CQ *cq)
{
 if ( isEmpty(cq))
{
printf("Error : Q is Empty.\n");
return ;
}
cq->size--;
printf("[ %d ] is Dequue from the CQ.\n",cq->arr[cq->front]);
return cq->arr[cq->front--];
}
int getFront(CQ *cq)
{
return cq->arr[cq->front];
}
int getRear(CQ *cq)
{
 return cq->arr[cq->rear];
}

int main(void)
{
CQ *cq = createCQ(100);
Enqueue(cq , 2);
Enqueue(cq , 8);
Enqueue(cq , 3);
Enqueue(cq , 6);
Enqueue(cq , 4);
Dequeue(cq);
Dequeue(cq);
Dequeue(cq);
printf("Front Element of the CQ is : [%d].\n",getFront(cq));
printf("Rear Element of the CQ is : [%d].\n",getRear(cq));
return 0;
}

