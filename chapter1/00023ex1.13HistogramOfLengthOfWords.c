#include <stdio.h>
#define IN 1 /*inside word*/
#define OUT 0 //outside word
/* Write a program that prints its input one word per line. */
main()
{
   int c;
   int nw=0;
   int state=OUT;
   int i;
   while((c=getchar())!=EOF)
   {
     
       if((c==' '||c=='\n'||c=='\t'))
           state=OUT;
        else if(state==OUT)
        {
            state=IN;
            if(nw!=0)
            for(i=20;i>nw;i--)
            putchar('>');
            for(i=0;i<nw;i++)
            putchar('#');
            nw=0;
            putchar('\n');
            putchar(c);
            ++nw;
        }
        else
        {
        putchar(c);
        ++nw;
        }
   }
  if(nw!=0) 
  for(i=20;i>nw;i--)
    putchar('>');
  for(i=0;i<nw;i++)
    putchar('#');
}