#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define a Node.
typedef struct node
{
    int data;
    struct node *next;
}Node;
// Define a Queue.
typedef struct queue
{
    Node *front;
    Node *rear;
    int size;
}queue_t;

typedef struct stack
{
    queue_t *actQueue;
    queue_t *suppQueue;
}stack_t1;
    
queue_t* InitializeQueue()
{
 queue_t* q;
 printf("InitializeQueue\n");
 q = (queue_t*)malloc(sizeof(q));
 q->front = NULL;
 q->rear  = NULL;
 q->size  = 0;
return q;
}
stack_t1* InitializeStack()
{    printf("InitializeStack\n");
    stack_t1 *stack = (stack_t1*)malloc(sizeof(stack_t1));
    stack->actQueue = InitializeQueue();
    stack->suppQueue = InitializeQueue();
    return stack;
}
    
Node* getNode(int value)
{
printf("getNode\n");
Node *newNode = (Node*)malloc(sizeof(Node));
newNode->data = value;
newNode->next = NULL;
return newNode;
}


int isEmpty(queue_t *q)
{
    return (q->size == 0 );
}
void enqueue(queue_t **q, int value)
{   printf("enqueue\n");
	Node *newNode = getNode(value);
	if(isEmpty(*q))
	{
		printf("Empty q.\n");
		(*q)->front = newNode;
		(*q)->rear = newNode;
	}
	else
	{
		(*q)->rear->next = newNode;
		(*q)->rear = newNode;
	}
	((*q)->size)++;
	printf("enqueue\n");
}
    
int dequeue(queue_t **q )
{   printf("dequeue\n");
	if(!isEmpty(*q))
	{
		Node *nodeToDel = (*q)->front;
		int retData = nodeToDel->data;
		(*q)->front = (*q)->front->next;
		((*q)->size)--;
		free(nodeToDel);
		return retData;
	}
	return INT_MIN;
}

int getFront(queue_t *queue)
{
    return queue->front->data;
}
void Push(stack_t1 *stack , int value)
{ 
	printf("Push\n");
	enqueue(&(stack->actQueue), value);
}

int pop(stack_t1 *stack)
{   printf("Pop\n");
	if (isEmpty(stack->actQueue))
	{
		printf("stack underflow.\n");
		exit(1);
	}
	else
	{
		int current_size = stack->actQueue->size;
		while( current_size != 1 ) // Dequeue all elements from ActiveQueue and Enqueue to Supportive Queue except Last item.
		{
			enqueue(&(stack->suppQueue),dequeue(&(stack->actQueue)));
			current_size--;
		}
		/* Rename the Queues */
		queue_t *temp = stack->suppQueue;
		stack->suppQueue  =  stack->actQueue;
		stack->actQueue = temp;
		// Return last remaining elements from the Supportive Queue 
		return dequeue(&(stack->suppQueue));
	}
}

int getTop(stack_t1 *stack)
{   printf("getTop\n");
 if (isEmpty(stack->actQueue))
    {
    printf("stack underflow.\n");
    exit(1);
    }   
    else
    return stack->actQueue->front->data;
}

void PrintStack(stack_t1 *stack)
{   printf("PrintStack\n");
    if(isEmpty(stack->actQueue))
    {
        printf("Stack is Empty.\n");
        exit(1);
    }
    Node *current = stack->actQueue->front;
    printf("Stack is : ");
    while(current)
    {
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
}


int main(void)
{   
    stack_t1 *stack = InitializeStack();
    Push(stack , 4);
    Push(stack , 7);
    Push(stack , 2);
    Push(stack , 6); 
    PrintStack(stack);
    pop(stack);
    PrintStack(stack);
    printf("Stack top is %d \n",getTop(stack));
return 0;
}







    


