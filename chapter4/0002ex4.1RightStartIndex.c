/*Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost
occurrence of t in s, or -1 if there is none.*/
#include <stdio.h>
#include<string.h>
#define MAXLINE 1000 /* maximum input line length */
int getline(char line[], int max);
int strindex(char source[], char searchfor[]);
char pattern[] = "ould"; /* pattern to search for */
/* find all lines matching pattern */
int main()
{
    char line[MAXLINE];
    while (getline(line, MAXLINE) > 0)
        printf("%d\n", strindex(line, pattern));
           
    return 0;
}
/* getline: get line into s, return length */
int getline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k;
    for (i=strlen(s)-1; i>=0; i--) {
        for (j=i, k=strlen(t)-1; k>=0 && s[j]==t[k]; j--, k--)
            ;
        if (k==-1)
            return i-strlen(t)+1;
    }
    return -1;
}