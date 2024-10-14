#include "main.h"

int Prefix_Eval(char *prefix_exp, Stack_t *stk)
{
	int op1, op2, Total, i = 0;
	while (prefix_exp[i] != '\0') // Running loop until pointer reaches null character
	{
		if (prefix_exp[i] >= 48 && prefix_exp[i] <= 57) // checking if it is an operand
			push(stk, (prefix_exp[i] - 48));			// storing it in operand stack
		else
		{
			op1 = pop(stk);		   // popping and storing operator in op1 variable
			op2 = pop(stk);		   // popping and storing operator in op2 variable
			switch (prefix_exp[i]) // performing operation
			{
			case '+':
				Total = op1 + op2; // Adding and storing output in total variable
				break;

			case '-':
				Total = op1 - op2; // Subtracting and storing result in total variable
				break;
			case '*':
				Total = op1 * op2; // Multiplying and storing output in total variable
				break;

			case '/':
				Total = op1 / op2; //  Dividing and storing result in total variable
				break;
			}
			push(stk, Total); // calling push to store the result from total vraible to stack
		}
		i++;
	}
	return pop(stk); // popping and returning it to the calling function
}
