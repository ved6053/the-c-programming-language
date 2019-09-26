#include <stdio.h>
#define IN 1 /*inside word*/
#define OUT 0 //outside word
/* Write a program that prints its input one word per line. */
main()
{
   int c;
   int nw , nl, nc;
   int state=OUT;
   while((c=getchar())!=EOF)
   {
     
       if((c==' '||c=='\n'||c=='\t'))
           state=OUT;
        else if(state==OUT)
        {
            state=IN;
            putchar('\n');
            putchar(c);
        }
        else
        {
        putchar(c);
        }
   }
  
}