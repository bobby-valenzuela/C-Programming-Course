/*
    Please write a C-program that reads a decimal number representing a temperature in degrees Celsius and prints out the corresponding temperature in degrees Fahrenheit with 1 decimal place. Here is the conversion formula:
    Temperature (°F) = Temperature (°C) × 9.0 / 5.0 + 32.0

    Examples
    Input: 192
    Output:377.6
*/

#include <stdio.h>
int main(void) {
    double temp,temp_f;
    
    // input Celsius temp
    scanf("%lf", &temp);
    
    // output Fahrenheit temp with one decimal place 
    temp_f = temp*9.0/5.0+32.0;
    printf("%.1lf\n", temp_f);
    
    return 0;
}

/*
    Something I learned: If we start by making 'temp' an int, we end up multiplying and int and a double (when calculating temp_f).
    This results in some rounding to the nearest even in some cases (for example, 1.99 might result in 2 when printed).
    Best to keep all data types as floats (or doubles) if thats the data type we're expecting anyway.
*/
