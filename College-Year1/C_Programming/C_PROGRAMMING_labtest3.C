/* Lab Test 3 – Thursday, 19th February, 2015
Kingsley Chimezie - C14468272
*/

#include<stdio.h>
#define SIZE 5

//Prototypes
float convert_temp (float []);
void in_Kelvin (float*);

main()
{
    float Celsius[SIZE] = {0};
    int i;
    float average = 0;
    
    printf("Enter %d temps\n", SIZE);
    
    for(i = 0; i < SIZE; i++)
    {
        scanf("%f", &Celsius[i]);
        flushall();
    }
    
    average = convert_temp(Celsius);
    
    printf("\nThe average Celsius temp is: %.2f", average);
    
    in_Kelvin(&average);
    
    printf("\nThe average Celsius in Kelvin is: %.2f", average);
    
    getchar();
}

float convert_temp (float Celsius_array[])
{
    float Farenheit[SIZE];
    float average = 0;
    float sum = 0;
    int i;
    
    for(i = 0; i < SIZE; i++)
    {
        Farenheit[i] = ((Celsius_array[i]*9)/5) + 32;
    }
    
    for(i = 0; i < SIZE; i++)
    {
        printf("\n%fF and %fC", Farenheit[i], Celsius_array[i]);
    }
    
    for(i = 0; i < SIZE; i++)
    {
        sum = sum + Celsius_array[i];
    }
    
    average = sum/SIZE;
    
    return(average);
}

void in_Kelvin (float* ptr)
{
    *ptr = *ptr + 273;
}