#include<stdio.h>
int bitcount(unsigned x);
int main()
{
    int i=0xfabcdef2;
    printf("%d", bitcount(i));
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}