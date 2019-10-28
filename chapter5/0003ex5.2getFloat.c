/*
Exercise 5-2. Write getfloat, the floating-point analog of getint. What type does getfloat
return as its function value?
*/
#include <ctype.h>
#include <stdio.h>
#define BUFSIZE 100
#define SIZE 10
int getch(void);
void ungetch(int);
int main(){
    float  array[SIZE];
    int n, getfloat(float *);
    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
    ;
    for(n=0;n<SIZE;n++)
    printf("%0.1f ", array[n]);
    return 0;
}
static char buf[BUFSIZE]; /* buffer for ungetch */
static int bufp = 0; /* next free position in buf */
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

/* getint: get next integer from input into *pn */
int getfloat(float *pn)
{
    int c, sign, pow=1;
    while (isspace(c = getch())) /* skip white space */
    ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10*(*pn) + (c - '0');
    if(c=='.')
     c=getch();
    for (; isdigit(c); c = getch())
    {
         *pn = 10*(*pn) + (c - '0'); 
         pow*=10;
    }
       
    *pn= sign*(*pn)/pow;
    if (c != EOF)
        ungetch(c);
    return c;
}