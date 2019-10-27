/*Exercise 3-4. In a two's complement number representation, our version of itoa does not
handle the largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why not.

Modify it to print that value correctly, regardless of the machine on which it runs.
number = -2147483648 would fail at n =-n,because the max value of integer is 2147483647

modifying itoa to handle these situations. 
sign is stored as  the number itself, absolute value of each digit is stored in the string and 
while loop is tested not for 0

*/
#include<stdio.h>
#include<string.h>
#define MAXLINE 1000
 
#define abs(x) ( (x) > 0 ? (x): -(x))
 
void itoa(int n,char s[]);
void reverse(char s[]);
 
 
int main(void)
{
    int number;
    char str[MAXLINE];
 
 /* number=-2345645; */
 
    number = -2147483648;
 
 
    printf("Integer %d printed as\n String:",number);
 
    itoa(number,str);
 
    printf("%s",str);
 
    return 0;
}
 
void itoa(int n,char s[])
{
    int i,sign;
 
    sign=n; 
 
    i = 0;
 
    do
    {
        s[i++]= abs(n%10) + '0';
 
    }while((n/=10)!=0);
 
    if( sign < 0)
        s[i++]='-';
 
    s[i]='\0';
 
    reverse(s);
}
 
void reverse(char s[])
{
    int c,i,j;
 
    for(i=0,j=strlen(s)-1;i<j;i++,j--)
        c=s[i],s[i]=s[j],s[j]=c;
}