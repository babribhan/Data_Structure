/*******************************************************************
*
* A Program to implment stack By using Array.
* Babribhan Jangra <babribhan@gmail.com>
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

int isOperand(char ch)
{
return (ch >= 'a' && ch <= 'z'|| ch >= 'A' && ch <= 'Z');

}
int precedence(char ch)
{
  switch(ch)
  {
    case '+':
    case '-':
      return 1;

    case '*':
    case '/':
      return 2;
    case '^' :
      return 3;
  }
  return -1;
}
int  inFixToPostFix(char *exp)
{

  int i , k;
  Stack *stack = createStack(strlen(exp)); // Create stack of capacity equal to exp length.
  if ( !stack ) return -1;// See if Stack was successfully created or Not.

  for ( i =0 , k= -1 ; exp[i] ;i++)
  {
    // IF OPERAND THEN OUTPUT IT
    if ( isOperand(exp[i]))
      exp[++k] = exp[i];

    else if ( exp[i] =='(')
      push(stack ,exp[i]);

    else if ( exp[i] == ')' )
    {
      while ( !isEmpty(stack ) && getTop(stack) !=  '(')
        exp[++k] = pop(stack);
      if ( !isEmpty(stack ) && getTop(stack) !=  '(')
        return -1 ;
      else
        pop(stack);
    }
    else // OPERATOR
    {
      while ( !isEmpty(stack ) &&  precedence(exp[i]) <= precedence(getTop(stack)))
        exp[++k] = pop (stack);
      push(stack,exp[i]);



    }


  }
  while ( !isEmpty(stack ) )
  {
    exp[++k] = pop(stack);
  }
  exp[++k] = '\0';
  printf("%s\n",exp);
 return 0;
}
int main()
{
  Stack *stack = createStack(100);
  push(stack ,20);
  push(stack ,30);
  push(stack ,40);

  printf("<%d> is popped from the stack.\n",pop(stack));
  printf("Top of stack is <%d> .\n",getTop(stack));
        char exp[] ="A+B*(C^D-E)^(F+G*H)-I";
        inFixToPostFix(exp);
  return 0;
