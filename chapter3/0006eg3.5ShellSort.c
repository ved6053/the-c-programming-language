#include<stdio.h>
void shellsort(int v[], int n);
int main(){
    int s[]={6,45,6,8,1,3,2,5};
    shellsort(s,8);
    for(int i=0;i<8;i++)
        printf("%d ", s[i]);
    return 0;
}

/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n)
{
    int gap, i, j, temp;
    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}