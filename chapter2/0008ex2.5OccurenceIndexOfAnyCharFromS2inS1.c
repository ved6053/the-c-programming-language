/*
Exercise 2-5. Write the function any(s1,s2), which returns the first location in a string s1
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
(The standard library function strpbrk does the same job but returns a pointer to the
location.)
*/
#include<stdio.h>
int any(char s1[], char s2[] );
int main()
{
   char s1[100];
   char s2[]="hello bhai";
   printf("Enter the name:\n");
   scanf("%s", s1);
   printf("index value : %d", any(s1,s2));

}
/* any: find index of first char in s1  from s2 */
int any(char s1[], char s2[] )
{
    int i, j;
    
    for (i =j=0; s1[i] != '\0'; i++)
    {
        int found=0;
        int k=0;
        while(s2[k]!='\0')
         if(s2[k++]==s1[i])
            found=1;
        if(found==1)
            return i;
    }
    return -1;
}