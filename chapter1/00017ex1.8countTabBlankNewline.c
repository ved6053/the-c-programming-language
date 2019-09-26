#include <stdio.h>
/*count blanks, tabs, and newlines*/
main()
{
    
    int c, nl, nb, nt;
    nl = 0;
    nb=0;
    nt=0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            ++nl;
        else if(c==' ')
            ++nb;
        else if(c=='\t')
            ++nt,++nb;
    }
    printf("new line =%d\n", nl);
    printf("blanks =%d\n", nb);
    printf("tab space=%d\n", nt);
}