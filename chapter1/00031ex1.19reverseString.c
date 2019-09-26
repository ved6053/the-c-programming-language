#include <stdio.h>
#define MAXLINE 1000 
/* maximum input line length */
int getLine(char s[], int lim);
void reverse(char s[]);
/*Write a function reverse(s) that reverses the character string s. Use it to
write a program that reverses its input a line at a time. */
main()
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
       {
         reverse(line);
         printf("%s\n",line);  
       }
    return 0;
}
/* getline: read a line into s, return length */
int getLine(char s[],int lim)
{
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* remove blank of given string*/
void reverse(char s[])
{
    int i, j;
    char r[MAXLINE];
    i=0;
    j=0;
    while(s[i]!='\0')
    i++;
    i--;
    while(i>=0)
    r[j++]=s[i--];
    r[j]='\0';
    for(i=0;r[i]!='\0';i++)
    s[i]=r[i];
    s[i]='\0';
}
