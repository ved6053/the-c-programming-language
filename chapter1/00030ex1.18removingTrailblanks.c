#include <stdio.h>
#define MAXLINE 1000 
/* maximum input line length */
int getLine(char s[], int lim);
void removeTrailBlanks(char s[]);
/*remove trailing blanks and tabs from each line of input, and
to delete entirely blank lines */
main()
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
       {
         removeTrailBlanks(line);
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
void removeTrailBlanks(char s[])
{
    int i, j;
    char s1[MAXLINE];
    i=0;
    j=0;
    while(s[i]==' '||s[i]=='\t'||s[i]=='\n')
    i++;
    while(s[i]!='\0')
    s1[j++]=s[i++];
    j--;
    while(s1[j]==' '||s1[j]=='\t'||s1[j]=='\n')
    j--;
    s1[j+1]='\0';
    for(i=0;s1[i]!='\0';i++)
    s[i]=s1[i];
    s[i]='\0';
}
