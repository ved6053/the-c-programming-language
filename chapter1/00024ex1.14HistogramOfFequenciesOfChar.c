#include <stdio.h>
/*print a histogram of the frequencies of different characters
in its input.*/
main()
{
   int c;
   int clist[100];
   int nlist[100];
   int count=-1;
   int i, j;
   while((c=getchar())!=EOF)
   {
     int found=0;
     for(i=0;i<=count;i++)
     {
         if(clist[i]==c)
         {
             found=1;
             ++nlist[i];
         }
     }
     if(found==0)
     {
      ++count;
      clist[count]=c;
      nlist[count]=1;
     }
   }
  for(i=0;i<=count;i++)
  {
      if(clist[i]=='\t')
      printf("\\t=>");
      else if(clist[i]=='\n')
      printf("\\n=>");
      else
      printf("%2c=>", clist[i]);
      for(j=0;j<nlist[i];j++)
      putchar('#');
      putchar('\n');
  }
}