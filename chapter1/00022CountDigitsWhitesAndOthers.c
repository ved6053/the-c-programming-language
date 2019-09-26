#include <stdio.h>
/* count digits, white space, others */
main()
{
   int c;
   int nDigits[10], i;
   int nWhites, nOthers;
   for(i=0;i<10;i++)
        nDigits[i]=0;
    nWhites=nOthers=0;
   while((c=getchar())!=EOF)
   {
     if(c>='0'&&c<='9')
        ++nDigits[c-'0'];
      else if(c==' '||c=='\t'||c=='\n')
        ++nWhites;
      else
        ++nOthers;
      
   }
   printf("Digits=\n");
   for(i=0;i<10;i++)
   printf("%d=>%d\n", i, nDigits[i]);
   printf("Whites=%d\n",nWhites);
   printf("Others=%d\n", nOthers);
}