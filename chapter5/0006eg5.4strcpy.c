#include<stdio.h>

void astrcpy(char *s, char *t);
void pstrcpy(char *s, char *t);
void istrcpy(char *s, char *t);
int astrcmp(char *s, char *t);
int pstrcmp(char *s, char *t);
int main(){
    char s[100];
    char t[]="hello world";
    istrcpy(s,t);
    s[0]='v';
    printf("%s %d", s, pstrcmp(s,t));
    return 0;
}
/* strcpy: copy t to s; array subscript version */
void astrcpy(char *s, char *t)
{
    int i;
    i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}
/* strcpy: copy t to s; pointer version */
void pstrcpy(char *s, char *t)
{
    int i;
    i = 0;
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}
/* strcpy: copy t to s; pointer version 2 */
void istrcpy(char *s, char *t)
{
    while (*s++ = *t++)
    ;
}
/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int astrcmp(char *s, char *t)
{
    int i;
    for (i = 0; s[i] == t[i]; i++)
    if (s[i] == '\0')
        return 0;
    return s[i] - t[i];
}
/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int pstrcmp(char *s, char *t)
{
    for ( ; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}