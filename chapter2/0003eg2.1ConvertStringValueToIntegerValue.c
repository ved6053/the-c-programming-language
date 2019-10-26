/* atoi: convert s to integer */
#include<stdio.h>
int atoi(char s[]);
int main(){
    char s[100];
    printf("Enter integer number\n");
    scanf("%s",s);
    printf("%d ", atoi(s));
    return 0;
}

int atoi(char s[])
{
    int i, n;
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}
