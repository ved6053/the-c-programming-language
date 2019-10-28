#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include "calc.h"
#include<math.h>

#define MAXOP 100 /* max size of operand or operator */
int main()
{
    int type;
    double r=0.0,op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case 'r':
                push(r);
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '%':
                swap();
                push((int)pop() % (int)pop());
                break;
            case 'e':
               // swap();
                push(exp(pop()));
                break;
            case 's':
               // swap();
                push(sin(pop()));
                break;
            case '^':
                swap();
                push(pow(pop(),pop()));
                break;    
            case '-':
                swap();
                push(pop() - pop());
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", r=pop());
                clear();
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}
