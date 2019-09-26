#include <stdio.h>
/*Write a program to copy its input to its output, replacing each string of one or
more blanks by a single blank*/
main()
{
    int c;
    while((c=getchar())!=EOF)
        if(!(c=='\t'||c==' '||c=='\n'))
            putchar(c);
}