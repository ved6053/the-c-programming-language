/*Exercise 2-1. Write a program to determine the ranges of char, short, int, and long
variables, both signed and unsigned, by printing appropriate values from standard headers
and by direct computation. Harder if you compute them: determine the ranges of the various
floating-point types
*/

#include<stdio.h>
#include<limits.h>
#include<float.h>
int main()
{
    printf("Range of signed char(%d , %d)\n", CHAR_MIN , CHAR_MAX);
    printf("Range of unsigned char(%d , %d)\n", 0 , UCHAR_MAX);
    printf("Range of signed short(%d , %d)\n", SHRT_MIN , SHRT_MAX);
    printf("Range of unsigned short(%d , %d)\n", 0 , USHRT_MAX);
    printf("Range of signed int(%d , %d)\n", INT_MIN , INT_MAX);
    printf("Range of unsigned int(%u , %u)\n", 0 , UINT_MAX);
    printf("Range of signed long(%ld , %ld)\n", LONG_MIN , LONG_MAX);
    printf("Range of unsigned long(%lu , %lu)\n", 0 , ULONG_MAX);
    printf("Range of float( %.10e ,  %.10e)\n", FLT_MIN , FLT_MAX);
    printf("Range of double( %.10e ,  %.10e)\n", DBL_MIN , DBL_MAX);
    return 0;
}