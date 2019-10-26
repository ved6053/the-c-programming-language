/*Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
through 9, a through f, and A through F.
*/

#include<stdio.h>
#include<stdlib.h>
int htoi(char s[]);
int pvalue(char c);
int main(){
    char s[100];
    printf("Enter a hex decimal number:\n");
    scanf("%s", s);
    printf("%d",htoi(s));
    return 0;
}
int htoi(char s[]){
    int i=0;
    int n=0;
    if(s[0]=='0'&& (s[1]=='x'|s[1]=='X'))
    i=2;
    while(s[i]!='\0')
    {
        n=n*16+(pvalue(s[i]));
        i++;
    }
    return n;
}
int pvalue(char c){
    if(c>='0'&&c<='9')
    {
         return c-'0';
    }
       
    else if(c>='a'&&c<='f')
    {
        return c-'a'+10;
    }
         
    else if(c>='A'&&c<='F')
    {
        return c-'A'+10;
    }   
    else
    {
       printf("wrong input");
       exit(0);
    }
    

}