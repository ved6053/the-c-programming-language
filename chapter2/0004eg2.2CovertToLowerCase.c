#include<stdio.h>
/* lower: convert c to lower case; ASCII only */
int lower(int c);

int atoi(char s[]);
int main(){
    char c;
    printf("Enter a  character\n");
    scanf("%c",&c);
    printf("%c ", lower(c));
    return 0;
}

/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
if (c >= 'A' && c <= 'Z')
return c + 'a' - 'A';
else
return c;
}
