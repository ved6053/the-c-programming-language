/*Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments of type t.*/
#include<stdio.h>
#define swap(t,x,y) t tmp=x; x=y, y=tmp;
int main()
{
    float x=5, y=15;
    swap(float, x, y);
    printf("%f %f", x,y);
    return 0;
}