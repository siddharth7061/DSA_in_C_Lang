
#include "main.h"

int Postfix_Eval(char *postfix_exp, Stack_t *stk)
{
	int op1, op2, Total, i = 0;
	while (postfix_exp[i] != '\0') // Evaluate expression till pointer reaches null character
	{
		if (postfix_exp[i] >= 48 && postfix_exp[i] <= 57) // Checking if it is an operand
		{
			push(stk, (postfix_exp[i] - 48)); // calling push operation
		}
		else
		{
			op2 = pop(stk); // calling pop function and saving the operator in a variable
			op1 = pop(stk); // calling pop function and saving operator in another variable
			switch (postfix_exp[i])
			{
			case '+':
				Total = op1 + op2; // Adding and storing output in variable total
				break;

			case '-':
				Total = op1 - op2; // Subtracting and storing result in total variable
				break;
			case '*':
				Total = op1 * op2; // multiplying and storing output in variable total
				break;

			case '/':
				Total = op1 / op2;  // Dividing and storing output in variable total
				break;
			}
			push(stk, Total); // pushing operator to stack
		}
		i++;
	}
	return pop(stk); // pop the result and return
}
