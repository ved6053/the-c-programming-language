/*Exercise 4-2. Extend atof to handle scientific notation of the form
123.45e-6
where a floating-point number may be followed by e or E and an optionally signed exponent.
*/
#include <ctype.h>
#include<math.h>
#include <stdio.h>
#define MAXLINE 100
int getline(char s[], int lim);
/* rudimentary calculator */
int main()
{
    double sum,satof(char s[]);
    char line[MAXLINE];
    int getline(char line[], int max);
    sum = 0;
    while (getline(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));
    return 0;
}
/* atof: convert string s to double */
double satof(char s[])
{
    double val, power, eval;
    int i, sign,exp;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    if(s[i]=='e'||s[i]=='E')
        printf("E");
        i++;
    exp = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (eval = 0.0; isdigit(s[i]); i++)
        eval = 10.0 * eval + (s[i] - '0');
    val*=pow(10,exp*eval);
    return (sign * val / power);
}
/* getline: get line into s, return length */
int getline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}