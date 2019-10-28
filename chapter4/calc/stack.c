#include <stdio.h>
#include "calc.h"
#define MAXVAL 100 /* maximum depth of val stack */
static int sp = 0; /* next free stack position */
static double val[MAXVAL]; /* value stack */
/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}
/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
    return 0.0;
    }
}
double top(void)
{
    if(sp>0)
        return val[sp-1];
      else 
        printf("error: stack empty\n");
    return 0.0;
}
void swap(void)
{
    if(sp>1)
    {
        double tmp;
        tmp=val[sp-1], val[sp-1]=val[sp-2], val[sp-2]=tmp;
    }
}
void clear(void){
    sp=0;
}