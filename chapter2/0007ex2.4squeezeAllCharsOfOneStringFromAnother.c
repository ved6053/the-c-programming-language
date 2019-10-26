/*Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in
s1 that matches any character in the string s2.*/
#include<stdio.h>
void squeeze(char s1[], char s2[]);
int main()
{
   char s1[100];
   char s2[]="hello bhai";
   printf("Enter the name:\n");
   scanf("%s", s1);
   squeeze(s1,s2);
   printf("%s", s1);

}
/* squeeze: delete all char of s2  from s1 */
void squeeze(char s1[], char s2[] )
{
    int i, j;
    
    for (i =j=0; s1[i] != '\0'; i++)
    {
        int found=0;
        int k=0;
        while(s2[k]!='\0')
         if(s2[k++]==s1[i])
            found=1;
        if(found==0)
            s1[j++]=s1[i];
    }
    s1[j] = '\0';
}