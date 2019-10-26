
#include<stdio.h>
int setbits(int x, int p, int n, int y);
int invert(int x , int p, int n);
int rightrot(int x, int n);
int main(){

    int x=0b01001111;
    int y=0b01000001;
    //011
    //1000
    //111
    printf("%o\n",setbits(x,2,3,y));
    printf("%o\n",invert(0543, 3, 5) );
    printf("%o\n",rightrot(1, 32));
    return 0;
}
/*
Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
position p set to the rightmost n bits of y, leaving the other bits unchanged.
*/
int setbits(int x, int p, int n, int y)
{
    return ((x>>p)&~(~0<<n))|(y&(~0<<n));
}

/*Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.*/

int invert(int x , int p, int n){
    return ~(~0<<n+p)&(~0<<p)^x;
}

/*Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated
to the right by n positions*/
int rightrot(int x, int n)
{
     for(int i=0;i<n;i++)
     x=((x&1)<<31)|((x>>1)&~(~0<<31));
     return x;
}