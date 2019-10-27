/*Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b
character representation in the string s. In particular, itob(n,s,16) formats s as a
hexadecimal integer in s.*/

#include<stdio.h>
#include<string.h>
#define MAXLINE 1000
 
#define abs(x) ( (x) > 0 ? (x): -(x))
 
void itob(unsigned int n,char s[],int b);
void reverse(char s[]);
 
 
int main(void)
{
    int number;
    char str[MAXLINE];
 
 /* number=-2345645; */
 
    number =0xfffab345;
 
 
    printf("Integer %x printed as\n String:",number);
 
    itob(number,str,16);
 
    printf("%s",str);
 
    return 0;
}
 
void itob(unsigned int n,char s[], int b)
{
    int i,sign;
    i = 0;
    do
    {
        int d=n%b;
        if(d>=10)
            s[i++]=d-10+'a';
        else
            s[i++]= abs(n%b) + '0';
 
    }while((n/=b)!=0);
 
    s[i]='\0';
 
    reverse(s);
}
 
void reverse(char s[])
{
    int c,i,j;
 
    for(i=0,j=strlen(s)-1;i<j;i++,j--)
        c=s[i],s[i]=s[j],s[j]=c;
}