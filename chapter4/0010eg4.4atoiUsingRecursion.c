#include <stdio.h>
#include<stdlib.h>
void printd(int n);
int main(){
    printd(-134567);
    return 0;
}
/* printd: print n in decimal */
void printd(int n)
{
    if (n < 0) {
        putchar('-');
        if (n / 10)
            printd(abs(n / 10));
        putchar(abs(n % 10) + '0');
    }
    else{
      if (n / 10)
        printd(n / 10);
      putchar(n % 10 + '0');
    }
   
}