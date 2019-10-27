#include <ctype.h>
#include<stdio.h>
int atoi(char s[]);
int main(){
    printf("%d", atoi("-00679"));
    return 0;
}
/* atoi: convert s to integer; version 2 */
int atoi(char s[])
{
    int i, n=0, sign;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
    ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') /* skip sign */
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');

    return sign * n;
}