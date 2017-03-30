/*
 * Extend atof to handle scientific notation of the form 123.45e-6 where a floating-point number may be 
 * followed by e or E and an optionally signed exponent.
 *
 */

#include <stdio.h>

#define NUM_DIG 64

float atof(char s[]); 
float atof_sci(char s[]);

int main(void)
{
    char s[] = "-16.741";
    printf("The float number is %f\n", atof(s));
    return 0;
}

float atof(char s[])
{
    float int_part, frac_part, p; 
    int i, sign;

    int_part = frac_part = 0.0;
    p = 10.0;
    i = 0;
    sign = 1;
    
    while(s[i] == ' ' || s[i] == '\t') { 
        i++;
    }

    sign = (s[i] == '-') ? -1 : 1;

    if(s[i] == '-' || s[i] == '+') {
        i++;
    } 
    
    while(s[i] != '\0' && s[i] != '.') {
        int_part = int_part * 10 + (s[i] - '0') ;
        i++;
    }

    if(s[i] == '.') {
        i++;
    }

    while(s[i] != '\0') {
        frac_part = frac_part + (s[i] - '0') / p;
        p *= 10.0;
        i++;
    } 
    

    return sign * (int_part + frac_part);
}

float atof_sci(char s[]) 
{ 
    return 0.0;
}
