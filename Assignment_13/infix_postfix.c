

#include "main.h"

int Infix_Postfix_conversion(char *Infix_exp, char *postfix_exp, Stack_t *stk)
{
	int i = 0, j = 0;
	stk = malloc(sizeof(Stack_t));
	for (i = 0; Infix_exp[i] != '\0'; i++) // Taking input till it reaches null character '/0'
	{
		if (Infix_exp[i] >= 'A' && Infix_exp[i] <= 'Z' || Infix_exp[i] >= 'a' && Infix_exp[i] <= 'z' || Infix_exp[i] >= 48 && Infix_exp[i] <= 57) // checking if operand or operator
		{
			postfix_exp[j] = Infix_exp[i]; // copying postfix to infix
			j++;
		}

		else if (Infix_exp[i] == '*' || Infix_exp[i] == '/' || Infix_exp[i] == '+' || Infix_exp[i] == '-' || Infix_exp[i] == '^')
		{
			if (stk->top == -1) // checking stack space and pushing in to infix array
				push(stk, Infix_exp[i]);
			else
			{
				while (stk->top != -1 && stk->stack[stk->top] != '(' && priority(Infix_exp[i]) <= priority(stk->stack[stk->top]))
				{
					// While loop to check the precedence of operators
					postfix_exp[j] = pop(stk); // calling pop function
					j++;
				}
				push(stk, Infix_exp[i]);
			}
		}
		else if (Infix_exp[i] == '(') // pushing in stack when open bracket found
			push(stk, Infix_exp[i]);

		else
		{
			while (stk->stack[stk->top] != '(') // calling pop function and storing it in postfx array
			{
				postfix_exp[j] = pop(stk);
				j++;
			}
			pop(stk);
		}
	}
	while (stk->top != -1) // Storing remaining operators from stack to postfix array till null character found
	{
		postfix_exp[j] = pop(stk); // calling pop function
		j++;
	}
}
