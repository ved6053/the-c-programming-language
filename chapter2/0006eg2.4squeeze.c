#include<stdio.h>
void getline(char s[], int size);
void squeeze(char s[], int c);
void sstrcat(char s[], char t[]);
int main(int argc , char **argv )
{
   char s[100];
   printf("Enter the name:\n");
   getline(s, 100);
   sstrcat(s,"Hello, bhai");
   squeeze(s, 'a');
   printf("%s", s);

}
/* squeeze: delete all c from s */
void squeeze(char s[], int c)
{
int i, j;
for (i = j = 0; s[i] != '\0'; i++)
if (s[i] != c)
s[j++] = s[i];
s[j] = '\0';
}
/* strcat: concatenate t to end of s; s must be big enough */
void sstrcat(char s[], char t[])
{
    int i, j;
    i = j = 0;
    while (s[i] != '\0') /* find end of s */
    i++;
    while ((s[i++] = t[j++]) != '\0') /* copy t */
    ;
}
void getline(char s[], int size){
   int c;
   int i=0; 
   while((c=getchar())!='\n'&&i<size)
    s[i++]=c;
    s[i]='\0';
}