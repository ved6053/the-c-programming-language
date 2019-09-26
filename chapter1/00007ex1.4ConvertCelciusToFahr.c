#include <stdio.h>
/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300 */
main()
{
    float fahr, celsius;
    int lower, upper, step;
    lower = 0; /* lower limit of temperature scale */
    upper = 300; /* upper limit */
    step = 20; /* step size */
    celsius= lower;
    printf("Celsius\tFahr\n");
    while (celsius <= upper) {
        fahr = (9.0/5.0) * (celsius)+32;
        printf("%7.0f\t%4.2f\n", celsius, fahr);
        celsius = celsius + step;
    }
}