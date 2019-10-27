#include <string.h>
#include<stdio.h>
/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
       c = s[i], s[i] = s[j], s[j] = c;
    }
}
int main(){
    char s[]="madam";
    reverse(s);
    printf("%s",s );
    return 0;
}