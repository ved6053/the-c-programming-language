/* Write a program to remove all comments from a C program. Don't forget to
handle quoted strings and character constants properly. C comments don't nest. */

#include<stdio.h>


int main(void)
{
  int c;
  int nc=0;
  while((c=getchar())!=EOF)
  {
     
      if(c=='/')
      {
          int c1=getchar();
          if(c1=='*')
          {
          while(!((c=getchar())=='*'&&(c=getchar())=='/'));//multi comments
          }
          else if(c1=='/')
          {
          while((c=getchar())!='\n');//sigle comments 
          putchar(c);
          }
          
      }
      else
      {
      putchar(c);
      }
  }
  return 0;
}
