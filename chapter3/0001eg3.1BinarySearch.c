
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
        if (x < v[mid])
            high = mid -1;
        else if (x > v[mid])
            low = mid+1;
        else /* found match */
            return mid;
        
    }
    return -1; /* no match */
}