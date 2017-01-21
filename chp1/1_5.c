/*
 * Modify the temperature conversion program to print the table 
 * in reverse order, that is, from 300 degrees to 0
 */

#include <stdio.h>


int main(void)
{
   
   float centi, fahren;
    
   printf("%6s %6s\n", "fahren", "centi" );
   for(fahren = 300; fahren >= 0; fahren -= 20) {
       centi = (5.0 / 9.0) * (fahren - 32);
       printf("%6.0f %6.1f\n", fahren, centi);
   }  

   return 0; 
}
