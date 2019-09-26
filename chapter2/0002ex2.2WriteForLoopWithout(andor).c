/*
for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
s[i] = c;
Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||.
*/
#include <stdio.h>

int main(void) {
    int lim=100;
    char s[100], c;
	for (int i=0; i < lim-1 ;++i)
        {
             if((c=getchar()) == '\n')
               break;
             else if(c == EOF)
               break;
             else
               s[i] = c;
        }
    printf("%s" , s);
	return 0;
}

