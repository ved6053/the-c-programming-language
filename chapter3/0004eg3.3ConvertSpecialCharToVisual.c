/*Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab into
visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a
function for the other direction as well, converting escape sequences into the real characters.
*/
#include<stdio.h>
void escape(char s[], char t[]);
void escapeToReal(char s[], char t[]);
int main(){
    char t[]="hello \t ved \n prakash \b singh";
    char s[200];
    char s1[200];
    escape(s,t);
    printf("\n%s\n", s);
    escapeToReal(s1,s);
    printf("\n%s\n", s1);
    return 0;
}
void escape(char s[], char t[])
{
   int j=0;
   for(int i=0;t[i]!='\0';i++)
   {
       switch(t[i])
       {
           case '\t':
                s[j++]='\\';
                s[j++]='t';
            break;
           case '\b':
                s[j++]='\\';
                s[j++]='b';
                break;
            case '\n':
                s[j++]='\\';
                s[j++]='n';
                break;
            case '\r':
                s[j++]='\\';
                s[j++]='r';
                break;
            case '\'':
                s[j++]='\\';
                s[j++]='\'';
                break;
            case '\"':
                s[j++]='\\';
                s[j++]='\"';
                break;
            default:
                s[j++]=t[i];
       }
   }
   s[j]='\0';
}
void escapeToReal(char s[], char t[])
{
    int j=0;
   for(int i=0;t[i]!='\0';i++)
   {
       switch(t[i])
       {
           case '\\':
                switch (t[++i])
                {
                case 't':
                    s[j++]='\t';
                    break;
                case 'n':
                    s[j++]='\n';
                    break;
                case 'r':
                    s[j++]='\r';
                    break;
                case 'b':
                    s[j++]='\b';
                    break;
                case '\'':
                    s[j++]='\'';
                    break;
                case '\"':
                    s[j++]='\"';
                    break;
                }
                break;
            default:
                s[j++]=t[i];
            
       }
   }
   s[j]='\0';
}