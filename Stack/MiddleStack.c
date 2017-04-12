/*******************************************************************
 *
 * A Program to have  access of middle element of Stack.
 *******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
typedef struct stack
{
	int top;
	unsigned max_size;
	int *arr;
}Stack;

Stack* createStack(unsigned max_size)
{
	Stack *stack = (Stack*)malloc(sizeof(Stack));
	stack->top = -1;
	stack->max_size = max_size;
	stack->arr = malloc(stack->max_size*sizeof(int));
	return stack;

}

int isFull(Stack *stack)
{
	return stack->top == stack->max_size;
}

int isEmpty(Stack *stack)
{

	return stack->top == -1;
}
void push(Stack *stack , int item)
{
	if ( isFull(stack))
	{
		printf("ERROR : Stack Overflow.\n");
		return ;
	}
	stack->arr[++stack->top] = item;
	printf("item <%d> is Pushed to stack.\n",item);
}

int pop(Stack *stack)
{
	if ( isEmpty(stack))
	{
		printf("ERROR : Stack underflow.\n");
		return INT_MIN;

	}
        printf("item <%d> is Popped from the stack.\n",stack->arr[stack->top]);
	return stack->arr[stack->top--];
}

int getTop(Stack *stack)
{
	if ( isEmpty(stack))
	{
		printf("ERROR : Stack underFlow.\n");
		return INT_MIN;
	}
	return stack->arr[stack->top];
}
void insertAtBottom(Stack *stack , int item )
{
	if( isEmpty(stack))
	{
		push(stack ,item);
	}
	else 
	{
		int temp = pop(stack);
			insertAtBottom(stack ,item);
		push(stack,temp);
	}


}
void reverse(Stack *stack)
{
	if (!isEmpty(stack))
	{
		int temp = pop(stack);
		reverse(stack);
		insertAtBottom(stack , temp);

	}
}

void printStack(Stack *stack )
{
	int size = stack->top;
	while ( size >= 0 )
	{
		printf("%d ",stack->arr[size--]);
	}

}
int main()
{
	Stack *stack = createStack(100);
	push(stack ,5);
	push(stack ,4);
	push(stack ,3);
	push(stack ,2);
	push(stack ,1);
	printf("Top of stack is <%d> .\n",stack->top);
	printStack(stack);
        reverse(stack);
	printStack(stack);
//	printf("<%d> is popped from the stack.\n",pop(stack));
	return 0;


}
