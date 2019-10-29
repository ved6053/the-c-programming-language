/*Exercise 5-3. Write a pointer version of the function strcat that we showed in Chapter 2:
strcat(s,t) copies the string t to the end of s.

Exercise 5-4. Write the function strend(s,t), which returns 1 if the string t occurs at the
end of the string s, and zero otherwise.

Exercise 5-5. Write versions of the library functions strncpy, strncat, and strncmp, which
operate on at most the first n characters of their argument strings. For example,
strncpy(s,t,n) copies at most n characters of t to s.
*/
#include<stdio.h>
#include<stdlib.h>
void pstrcat(char *s, char *t);
int astrend(char *s, char *t);
int astrncmp(char *s, char *t, int n);
void astrncpy(char *s, char *t, int n);
void astrncat(char *s, char *t, int n);
int main(){
    char s[]="world";
    char t[]="hello world";
    astrncpy(s,t,20);
    printf("%s %d", s, astrncmp(s,t,20));
    return 0;
}
void pstrcat(char *s, char *t){
    for(;*s;s++);
    for(;*s=*t;s++,t++);

}
int astrend(char *s, char *t){
     char *p=s, *q=t;
     for(;*p;p++);
     for(;*q;q++);
    while(*p==*q)
     {
          if(q==t)
            return 1;
         --p, --q;
        
           
     } ;
    return 0;
}
int astrncmp(char *s, char *t, int n)
{
    int i;
    for (i = 0;s[i]&&t[i]; i++)
    if(i>=n)
    {
        printf("array size out of bound");
        exit(0);
    }
    for (i = 0; (s[i] == t[i])&&i<=n; i++)
    if (s[i] == '\0')
        return 0;
   
    return s[i] - t[i];
}
void astrncpy(char *s, char *t, int n)
{
     int i;
    for (i = 0;s[i]&&t[i]; i++)
    if(i>=n)
    {
        printf("array size out of bound");
        exit(0);
    }
    while (*s++ = *t++)
    ;
}
void astrncat(char *s, char *t, int n){
      int i;
    for (i = 0;s[i]&&t[i]; i++)
    if(i>=n)
    {
        printf("array size out of bound");
        exit(0);
    }
    for(;*s;s++);
    for(;*s=*t;s++,t++);

}