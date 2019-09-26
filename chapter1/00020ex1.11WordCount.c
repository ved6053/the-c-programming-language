#include <stdio.h>
#define IN 1 /*inside word*/
#define OUT 0 //outside word
/* count lines, words, and characters in input */
main()
{
   int c;
   int nw , nl, nc;
   int state=OUT;
   nw=nl=nc=0;
   
   while((c=getchar())!=EOF)
   {
       ++nc;
       if(c=='\n')
       ++nl;
       if(c==' '||c=='\n'||c=='\t')
        state=OUT;
        else if(state==OUT)
        {
            state=IN;
            ++nw;
        }
   }
   printf("Word Count=%d\n", nw);
   printf("New Line=%d\n", nl);
   printf("Character Count=%d\n", nc);
}