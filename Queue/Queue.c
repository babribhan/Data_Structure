/************************************************************************
 * A Program to Implment a Q.
 ************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
typedef struct queue
{
	int front,rear,size;
	unsigned capacity;
	int *arr;
}Queue;

Queue* createQueue(unsigned capacity)
{
	Queue *q = (Queue *)malloc(sizeof(Queue));
	q->capacity = capacity;
	q->front = q->rear = -1;
	q->size = 0;
	q->arr = (int *)malloc(capacity * sizeof(int));
return q;
}
int isFull(Queue *q)
{
	return (q->size == q->capacity );
}
int isEmpty(Queue *q)
{
	return ( q->size == 0 );
}
void Enqueue(Queue *q, int item)
{
	if ( isFull(q))
	{
		printf("Queue Overflow.\n");
		return ;
	}
	else
	{
		q->arr[++(q->rear)] = item;
		q->size++;
		if (q->size == 1)
		{
			q->front = 0;
		}
		printf("%d is Enqueue in Q.\n",item);

	}
}
void Dequeue(Queue *q)
{
	if ( isEmpty(q))
	{
		printf("Queue UnderFlow.\n");
		return ;
	}
	else 
	{
		printf("%d is Dequeue from the Q.\n",q->arr[q->front]);
		q->size --;
		if ( q->size == 0)
		{
			q->front =-1;
			q->rear = -1;
		}
		else 
			q->front ++;

	}

}
int getRear(Queue *q)
{
if ( isEmpty(q))
return INT_MIN;
else 
    return q->arr[q->rear];
}
int getFront(Queue *q)
{
if ( isEmpty(q))
return INT_MIN;
else 
    return q->arr[q->front];
}
int getSize(Queue *q)
{
return q->size;
}

int main()
{
Queue* queue = createQueue(1000);
 
    Enqueue(queue, 10);
    Enqueue(queue, 20);
    Enqueue(queue, 30);
    Enqueue(queue, 40);
    Dequeue(queue);
    Dequeue(queue);

 
    printf("Front item is %d\n", getFront(queue));
    printf("Rear item is %d\n", getRear(queue));
    printf("Size of Q is %d \n",getSize(queue));


return 0;
}

