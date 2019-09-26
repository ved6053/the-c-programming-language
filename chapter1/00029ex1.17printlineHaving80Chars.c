#include <stdio.h>
#define MAXLINE 1000 
/* maximum input line length */
int getLine(char s[], int lim);
void copy(char to[], char from[]); 
int strLength(char s[]);
/* print the longest input line */
main()
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
        if (len > 80) {
           printf("%s\n", line);
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

/* length of given string*/
int strLength(char s[])
{
    int i;
    for(i=0;s[i]!='\0';i++);
    
    return i;
}
