/*Write a program to check a C program for rudimentary syntax errors like
unmatched parentheses, brackets and braces. Don't forget about quotes, both single and
double, escape sequences, and comments.*/

#include<stdio.h>


int main(void)
{
  int c;
  int nparen=0 , nbraces=0, nbracket=0;
  int status=1;
  while((c=getchar())!=EOF)
  {
     
      if(c=='/')
      {
          status=0;
          int c1=getchar();
          if(c1=='*')
          {
          while(!((c=getchar())=='*'&&(c=getchar())=='/')&&c!=EOF);//multi comments
          if(c!=EOF)
            status=1;
          else
            break;
          }
          else if(c1=='/')
          {
          while((c=getchar())!='\n'&&c!=EOF);//sigle comments
           if(c!=EOF)
            status=1;
          else
            break;
          }
          
      }else if(c=='\'')
      {
          status=0;
         while((c=getchar())!='\''&&c!=EOF)
         {
              if(c=='\\')
              c=getchar();
         }
          if(c!=EOF)
            status=1;
          else
            break;
      }
      else if(c=='\"')
      {
          status=0;
          while((c=getchar())!='\"'&&c!=EOF)
          {
              if(c=='\\')
              c=getchar();
          }  
           if(c!=EOF)
            status=1;
          else
            break;
      }
      else 
      {
        switch(c)
        {
            case '{':
            ++nbraces;
            break;
            case '}':
            --nbraces;
            break;
            case '[':
            ++nbracket;
            break;
            case ']':
            --nbracket;
            break;
            case '(':
            ++nparen;
            break;
            case ')':
            --nparen;
        }
      }
  }
  if(status==1&&nbraces==0&&nbracket==0&&nparen==0)
  {
      printf("adequate cprogram");
  }
  else
  {
      printf("not adequate cprogram");
  }
  return 0;
}
