/* 
Lab Test 2 – Monday, 1st December, 2014
Kingsley Chimezie - C14468272
*/

#include <stdio.h>

#define SIZE 5

main()
{
    float gallons[SIZE];
    float miles[SIZE];
    float mpg[SIZE];
    int i;
    
    for(i = 0; i < SIZE; i++)
    {//Loop for entering the values into each element of the gallons and miles array
        
        printf("\nPlease enter gallons value %d: ", i + 1);
        scanf("%f", & *(gallons + i));
        flushall();
        
        printf("Please enter miles value %d: ", i + 1);
        scanf("%f", & *(miles + i));
        flushall();
        
        *(mpg + i) = (*(miles) / *(gallons));
        
    }//end for
    
    
    printf("\n\n");
    
    
    for(i = 0; i < SIZE; i++)
    {//Loop for printing the mpg of the same element number of gallons and miles array
        
        printf("\nThe mpg for gallons and miles value %d is: %.2f", i + 1, *(mpg + i));
        
    }//end for
    
    getchar();
    
}//end main()
