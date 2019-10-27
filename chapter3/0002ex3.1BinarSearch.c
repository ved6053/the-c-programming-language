/*Exercise 3-1. Our binary search makes two tests inside the loop, when one would suffice (at
the price of more tests outside.) Write a version with only one test inside the loop and measure
the difference in run-time.*/
#include<stdio.h>
int binsearch(int x, int v[], int n);
int main()
{
    int a[]={1,6,7, 9 , 10, 11,15,17};
    printf("%d", binsearch(8, a , 8));
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <=high) {
        mid = (low+high)/2;
        if (x==v[mid])
            return mid;
        x<v[mid]?high=mid-1:low=mid+1;
    }
    return -1; /* no match */
}