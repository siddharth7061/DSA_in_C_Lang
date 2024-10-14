#include "main.h"

int priority(int opr)
{
	if (opr == '(')
	{
		return 0;
	}
	if (opr == '+' || opr == '-')
	{
		return 1;
	}
	if (opr == '*' || opr == '/')
	{
		return 2;
	}
}

void push(Stack_t *stk, int data)
{
	++(stk->top);
	stk->stack[stk->top] = data;
}
// doubtful
int pop(Stack_t *stk)
{
	if (stk->top == -1)
	{
		return -1;
	}
	else
	{
		return (int)stk->stack[(stk->top)--];
	}
}

int peek(Stack_t *stk)
{
	if (stk->top != -1)
	{
		return stk->stack[stk->top];
	}
	return -1;
}
