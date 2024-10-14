#include "main.h"

int priority(char opr)
{
    int prec;

	// Categorised the operators in cases with rankings saved in prec variable
    switch(opr)
    {
	case '^':
	    prec = 3;
	    break;
	case '*':
	case '/':
	    prec = 2;
	    break;
	case '+':
	case '-':
	    prec = 1;
	    break;

	default :
	    prec = 0;
	    break;
    }
    return prec;
}


void push(Stack_t *stk, int data)
{
    ++(stk -> top);
    stk -> stack[stk -> top] = data;
}

char pop(Stack_t *stk)
{
    char x;
    if (stk -> top != -1)
    {
	x = stk -> stack[stk -> top];
    	--(stk -> top);
    }
    return x;
}

int peek(Stack_t *stk)
{
    if (stk -> top != -1)
    {
	return stk -> stack[stk -> top];
    }
    return -1;
}

