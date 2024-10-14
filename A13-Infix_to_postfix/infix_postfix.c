#include "main.h"

int Infix_Postfix_conversion(char *Infix_exp, char *Postfix_exp, Stack_t *stk)
{
    char *e = Infix_exp, x, *p = Postfix_exp, n1 = 0, n2 = 0;

    while (e[n2] != '\0')
    {
        if (isalnum(e[n2]))
        {
            p[n1] = e[n2];
            n1++;
        }
        else if (e[n2] == '(')
        {
            push(stk, e[n2]);
        }
        else if (e[n2] == ')')
        {
            while ((x = pop(stk)) != '(')
            {
                p[n1] = e[n2];
                n1++;
            }
        }
        else
        {
            while (priority(stk->stack[stk->top]) >= priority(e[n2]))
            {
                p[n1] = stk->stack[stk->top++];
                n1++;
                pop(stk);
            }
            push(stk, e[n2]);
        }
        n2++;
    }
    while (stk->top != -1)
    {
        p[n1] = stk->stack[stk->top++];
        n1++;
        pop(stk);
    }
    return SUCCESS;
}