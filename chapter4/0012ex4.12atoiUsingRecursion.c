/*
Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa; that is, convert
an integer into a string by calling a recursive routine.
*/
#include <stdio.h>
#include<stdlib.h>
void ratoi(int n, char s[]);
int main(){
  char s[100];

    ratoi(-134567, s);
    printf("%s", s);
    return 0;
}
/* printd: print n in decimal */
void ratoi(int n, char s[])
{
    static int i;
    if (n < 0) {
        s[i++]='-';
        if (n / 10)
            ratoi(abs(n / 10), s);
        s[i++]=abs(n % 10) + '0';
        
    }
    else{
      if (n / 10)
        ratoi(n / 10, s);
      s[i++]=n % 10 + '0';
    }
   s[i]='\0';
}