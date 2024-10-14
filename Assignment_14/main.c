/*--------------------------------------------------------------------------------
Name : Siddharth Singh
Date : 23/10/2022
Description : Converting infix expression to postfix and evaluating the expression
sample input : 	2 * 3 – 3 + 8 / 4 / (1 + 1)
sample output : Prefix expression : + – * 2 3 3 / / 8 4 + 1 1
                Result : 2               
----------------------------------------------------------------------------------*/

#include "main.h"

void strrev(char *string)
{
    char ch;
    int len = strlen(string);
    for (int i = 0; i < len / 2; i++)
    {
        ch = string[i];
        string[i] = string[len - 1 - i];
        string[len - 1 - i] = ch;
    }
}
int main()
{
    char Infix_exp[50], Prefix_exp[50], ch;
    int choice, result;
    Stack_t stk;
    stk.top = -1;

    printf("Enter the Infix expression : ");
    scanf("%s", Infix_exp);

    strrev(Infix_exp);
    Infix_Prefix_conversion(Infix_exp, Prefix_exp, &stk);
    strrev(Prefix_exp);
    printf("PreFix expression : %s\n", Prefix_exp);

    stk.top = -1;

    strrev(Prefix_exp);
    result = Prefix_Eval(Prefix_exp, &stk);
    printf("\nResult : %d\n", result);
    return 0;
}
