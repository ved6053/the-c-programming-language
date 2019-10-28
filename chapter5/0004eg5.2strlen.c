#include<stdio.h>
int main(){
    int strlen(char *s);
    printf("%d",strlen("hello, world")); /* string constant */
    return 0;

}
/* strlen: return length of string s */
int strlen(char *s)
{
    int n;
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}