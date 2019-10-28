/*Exercise 4-10. An alternate organization uses getline to read an entire input line; this makes
getch and ungetch unnecessary. Revise the calculator to use this approach.*/
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include<math.h>
#define MAXLINE 100

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
int getline(char line[],int limit);

int li= 0;  /* input line index */
char line[MAXLINE];  /* one input line */

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
int getop(char s[])
{
    int i, c;
     if(line[li] == '\0')
        if(getline(line,MAXLINE) == 0)
            return EOF;
        else
            li =0;
    while ((s[0] = c =line[li++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
   
    if (!isdigit(c) && c != '.'&&c!='-')
        return c; /* not a number */
    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c =line[li++]));
    if(c=='-')
      if(isdigit(s[++i] = c = line[li++]));
      else 
        return '-';
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = line[li++]));
   
     if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c =line[li++]));
    s[i] = '\0';
    return NUMBER;
}

/* getline: get line into s, return length */
int getline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}