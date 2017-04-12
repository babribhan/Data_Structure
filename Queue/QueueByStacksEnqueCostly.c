/*
   A Queue implementation of Queue by Stacks.
   Babribhan Jangra <babribhan@gmail.com>
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
	int data;
	struct node *next;
}Node;

typedef struct stack
{
	Node *top;
	int size;
}stack_t1;

typedef struct queue
{
	stack_t1 *actStack;
	stack_t1 *suppStack;
}queue_t;
Node* getNode(int value)
{
	Node *newNode  = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}
stack_t1* InitializeStack()
{
	stack_t1 *temp = (stack_t1*)malloc(sizeof(stack_t1));
	temp->top = NULL;
	temp->size = 0;
	return temp;
}
queue_t* InitializeQueue()
{
	queue_t *temp = (queue_t*)malloc(sizeof(queue_t));
	temp->actStack = InitializeStack();
	temp->suppStack = InitializeStack();
	return temp;
}
int isEmpty(stack_t1 *stack)
{
	return (stack->size == 0);
}
void push(stack_t1 **stack , int value)
{
	Node *newNode = getNode(value);
	if(isEmpty(*stack))
	{
		(*stack)->top = newNode; 
	}
	else
	{
		newNode->next = (*stack)->top;
		(*stack)->top = newNode;
	}
	((*stack)->size)++;
}
int  pop(stack_t1 **stack)
{
	if ( isEmpty(*stack))
	{
		printf("Queue is Empty .\n");
		exit(1);
	}
	((*stack)->size)--;  // Make size one lesser.
	Node *nodeToDel = (*stack)->top;
	int data = nodeToDel->data;
	(*stack)->top = (*stack)->top->next;
	free(nodeToDel);
	return data;
}
void Enqueue(queue_t *queue , int item)
{
	// Remove everything from Active Stack and Add to Supportive Stack.
	while(!isEmpty(queue->actStack))
	{
		push(&(queue->suppStack),pop(&(queue->actStack)) ); // Add to Supportive Stack.
	}
	push(&(queue->actStack) , item);
// Move Back everything from Supportive to Active Stack.
	while(!isEmpty(queue->suppStack))
	{
		push(&(queue->actStack) ,pop(&(queue->suppStack)));
	}
}
int Dequeue(queue_t *queue )
{

	return pop(&(queue->actStack));
}
void PrintQ(queue_t *queue)
{
	if (isEmpty(queue->actStack))
	{
		printf("Queue is Empty.\n");
		exit(1);
	}
	Node *current = queue->actStack->top;
	printf("Queue is :");
	while(current)
	{
		printf("%d ",current->data);
		current = current->next;
	}
	printf("\n");
}
int main(void)
{
	queue_t *queue = InitializeQueue();
	Enqueue(queue , 4);
	Enqueue(queue , 1);
	Enqueue(queue , 9);
	Enqueue(queue , 2);
	PrintQ(queue);
        Dequeue(queue);
        PrintQ(queue);
	return 0;
}

