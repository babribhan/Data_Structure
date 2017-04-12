#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct dlnode
{
struct dlnode *next;
struct dlnode *prev;
int data;
}Node;

typedef struct stack_node
{
Node *top;
Node *mid;
int size;
}Stack;

Node* InitializeNode(int value)
{
Node *temp = (Node*)malloc(sizeof(Node));
temp->next = temp->prev = NULL;
temp->data = value;
return temp;
}
int isEmpty(Stack *stack)
{
return (stack->top == NULL);

}

void InitializeStack(Stack **stack)
{
*stack = (Stack*)malloc(sizeof(Stack));
(*stack)->top = NULL;
(*stack)->mid = NULL;
(*stack)->size = 0;
}
void Push(Stack **stack , int value)
{
     
	Node *newNode = InitializeNode(value);
	(*stack)->size++;
	if (isEmpty(*stack))
	{
		(*stack)->top = newNode;
		(*stack)->mid = newNode;
	} 
	else
	{
		newNode->next = (*stack)->top;
		(*stack)->top->prev = newNode;
		(*stack)->top = newNode;
		if ( (*stack)->size & 1 )
		{
			(*stack)->mid = (*stack)->mid->prev;
		}
	}
}

void Pop(Stack **stack )
{
	if (isEmpty(*stack))
	{
		printf("Stack underflow.\n");
		exit(1);
	}
	else
	{
		Node *nodeToDelete = (*stack)->top;
		(*stack)->top = (*stack)->top->next;
		(*stack)->top->prev = NULL;
		(*stack)->size--;
		if ( !((*stack)->size & 1))
		{
			(*stack)->mid = (*stack)->mid->next;
		}
		free(nodeToDelete);	
	}

}
void deleteMid(Stack **stack )
{
	if (isEmpty(*stack))
	{
		printf("Stack underflow.\n");
		exit(1);
	}
	else
	{
		Node *nodeToDelete = (*stack)->mid;
		(*stack)->mid->prev->next = (*stack)->mid->next;
		(*stack)->mid->next->prev = (*stack)->mid->prev;
		(*stack)->size--;
		(*stack)->mid = nodeToDelete->prev;
		free(nodeToDelete);
	}
}

int getMiddle(Stack *stack)
{
	if (isEmpty(stack))
	{
		return INT_MIN;
	}
	else
	{
		return  stack->mid->data;
	}
}
void PrintStack(Stack *stack)
{
	if (isEmpty(stack))
	{
		printf("Stack is Empty.\n");
		exit(1);
	}
	Node *current = stack->top;
	printf("Stack is : ");
	while (current)
	{
		printf("%d ",current->data);
		current = current->next;
	}
	printf("\n");
}
int main(void)
{
Stack *stack  =NULL;
InitializeStack(&stack);
Push(&stack,5);
Push(&stack,2);
Push(&stack,7);
Push(&stack,1);
Push(&stack,4);
Push(&stack,8);
PrintStack(stack);
printf("Middle of Stack is %d \n",getMiddle(stack));
deleteMid(&stack);
PrintStack(stack);
printf("Middle of Stack is %d \n",getMiddle(stack));

return 0;
}
















