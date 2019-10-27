#include<stdio.h>
#include<string.h>
int trim(char s[]);
int main(){
    char s[100]="   hello ved     ";
    trim(s);
    printf("%s", s);
    return 0;
}

/* trim: remove trailing blanks, tabs, newlines */
int trim(char s[])
{
    int n=0;
    while(n<strlen(s)&&(s[n]==' '||s[n]=='\t'||s[n]=='\n'))
      n++;
    int k=n;
    while(k<strlen(s))
         s[k-n]=s[k++];
     s[k]='\0';


    for (n = strlen(s)-1; n >= 0; n--)
    {
        
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;
    }   
    s[n+1] = '\0';
    return n;
}