/*
 * Rewrite the temperature conversion program of Section 1.2 to 
 * use a function for conversion.
 */

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

float fahren_to_celsius(float fahre);

int main(void) 
{
    float fahre, celsius; 
    
    printf("%8s %8s\n", "fahre", "celsius");
    for(fahre = LOWER; fahre <= 300; fahre += 20) {
        celsius = fahren_to_celsius(fahre);
        printf("%8.0f %8.1f\n", fahre, celsius);
    }

    return 0;
}

/*
 * Convert Fahrenheit to Celsius
 * C = (5/9) * (F-32)
 */
float fahren_to_celsius(float fahre)
{
    
    return (5.0 / 9.0) * (fahre - 32);
     
}
