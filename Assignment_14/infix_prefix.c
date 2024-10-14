#include "main.h"

int Infix_Prefix_conversion(char *Infix_exp, char *Prefix_exp, Stack_t *stk)
{

	int i = 0, j = 0;
	stk = malloc(sizeof(Stack_t)); // creating stack by allocating memory in heap memory

	for (i = 0; Infix_exp[i] != '\0'; i++) // Loop will run till the pointer reaches the null character
	{
		if (Infix_exp[i] >= 'A' && Infix_exp[i] <= 'Z' || Infix_exp[i] >= 'a' && Infix_exp[i] <= 'z' || Infix_exp[i] >= 48 && Infix_exp[i] <= 57)
		{								  // checking if element is operand or not
			Prefix_exp[j] = Infix_exp[i]; // storing operand in postfix array
			j++;
		}

		else if (Infix_exp[i] == '*' || Infix_exp[i] == '/' || Infix_exp[i] == '+' || Infix_exp[i] == '-' || Infix_exp[i] == '^')
		{ // checking if it is an operator
			while (stk->top != -1 && stk->stack[stk->top] != ')' && priority(Infix_exp[i]) < priority(stk->stack[stk->top]))
			{
				// Checking the operator's precedence and then popping the operator from stack
				Prefix_exp[j] = pop(stk);
				j++;
			}
			push(stk, Infix_exp[i]); // calling push operation
		}
		else if (Infix_exp[i] == ')')
			push(stk, Infix_exp[i]); // calling push operation to store open bracket into stack

		else
		{
			while (stk->stack[stk->top] != ')') // runing loop to pop the operator from stack until pointer reaches open bracket
			{
				Prefix_exp[j] = pop(stk); // popping and storing in prefix array
				j++;
			}
			pop(stk); // popping the open bracket from the stack
		}
	}
	while (stk->top != -1) // Storing the leftout operators from stack to prefix array
	{
		Prefix_exp[j] = pop(stk); // calling pop function
		j++;
	}
}
