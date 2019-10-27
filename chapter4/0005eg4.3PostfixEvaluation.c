/*
Exercise 4-3. Given the basic framework, it's straightforward to extend the calculator. Add the
modulus (%) operator and provisions for negative numbers.

Exercise 4-4. Add the commands to print the top elements of the stack without popping, to
duplicate it, and to swap the top two elements. Add a command to clear the stack.

Exercise 4-5. Add access to library functions like sin, exp, and pow. See <math.h>

Exercise 4-6. Add commands for handling variables. (It's easy to provide twenty-six variables
with single-letter names.) Add a variable for the most recently printed value.

*/
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include<math.h>
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100 /* maximum depth of val stack */
#define BUFSIZE 100
int getop(char []);
void push(double);
double pop(void);
double top(void);
void swap(void);
void clear(void);
/* reverse Polish calculator */
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

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */
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
int getch(void);
void ungetch(int);
/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
   
    if (!isdigit(c) && c != '.')
        return c; /* not a number */
    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()));
    if(c=='-')
      if(isdigit(s[++i] = c = getch()));
      else 
        return '-';
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()));
   
     if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
