/* 
   A Stack Implementation which return minimum element in O(1) Time.
   Babribhan Jangra < babribhan@gmail.com>
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_SIZE 100

int actualStack[MAX_SIZE];
int topActual = -1;

int auxStack[MAX_SIZE];
int topAux = -1 ;

int isAuxEmpty()
{
	return (topAux == -1);
}
int isAuxFull()
{
	return (topAux == MAX_SIZE);
}
int isEmpty()
{
	return (topActual == -1);
}
int isFull()
{
	return (topActual == MAX_SIZE);
}
int getTopOfAux()
{
	if (isAuxEmpty())
	{
		return INT_MIN;
	}
	return auxStack[topAux];
}
void PushToAux(int item)
{
	if (isAuxFull())
	{
		printf("Stack overflow.\n");
		exit(1);
	}
	else
		auxStack[++topAux] = item;

}

int  PopFromAux()
{
	if (isAuxEmpty())
	{
		return INT_MIN;
	}
	return auxStack[topAux--];
}

void Push(int item)
{
	if (isFull())
	{
		printf("Stack overflow.\n");
		exit(1);
	}
	actualStack[++topActual] = item;
	if (isAuxEmpty())
	{
		PushToAux(item);
	} 
	else
	{
		if ( item < getTopOfAux()) 
		{
			PushToAux(item);
		}
		else 
		{
			PushToAux(getTopOfAux());
		}
	}
}
int Pop()
{
	if (isEmpty())
	{
		printf("Stack underflow.\n");
		exit(1);
	}
	return actualStack[topActual--];
}
int getTopOfActual()
{
	if ( isEmpty())
	{
		return INT_MIN;
	}
	return actualStack[topActual];
}
void PrintStack()
{
	if ( isEmpty())
	{
		printf("Stack is Empty.\n");
		exit(1);
	}
	else
	{
		int index =0;
		while( index <= topActual )
		{
			printf("%d ",actualStack[index++]);
		}
		printf("\n");
	}

}
int main(void)
{
Push(34);
Push(4);
Push(14);
Push(22);
Push(39);
Push(41);
Push(3);
PrintStack();
printf("Minimum elements in the stack is : %d \n",getTopOfAux());

return 0;
}
