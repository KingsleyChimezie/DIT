/* Lab Test 1 – Monday, 3rd November, 2014
Kingsley Chimezie - C14468272
*/

#include <stdio.h>
main()
{
    int input;
    
    //displays instructions for the user to input a year
    printf("Please enter a year: ");
    input = 0;
    scanf("%d", &input);
    
    //checks whether the users year input is a leap year or not
    if((input%4) ==0 || (input%100) ==0 || (input%400) ==0)
    {
        printf("\n\n%d is a leap year.", input);
    }
    else
    {
        printf("\n\n%d is NOT leap year.", input);
    }
    
    flushall();
    getchar();
}
