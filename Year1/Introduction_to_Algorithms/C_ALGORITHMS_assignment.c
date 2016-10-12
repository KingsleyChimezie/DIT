/*******************************************
Introduction to Algorithms - Assignment 1

Date:         13th April 2015
Author:     Kingsley Chimezie - C14468272
*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*----- N values -----*/
#define N1 4
#define N2 1600
#define N3 2400
#define N4 3200
#define N5 4000


/*--------------- Prototypes ---------------*/
void Bubble_Sort_Algorithm(int *, int, int *, int *);
void Improved_Bubble_Sort_Algorithm(int *, int, int *, int *);

main()
{
    
    int VALUE1_ARRAY[N1] = {0};                                 //stores the values for N = 800
    int VALUE2_ARRAY[N2] = {0};                                 //stores the values for N = 1600 
    int VALUE3_ARRAY[N3] = {0};                                 //stores the values for N = 2400
    int VALUE4_ARRAY[N4] = {0};                                 //stores the values for N = 3200
    int VALUE5_ARRAY[N5] = {0};                                 //stores the values for N = 4000
    
	int compare1, compare2, compare3, compare4, compare5;       //used to count when a comparison is made
    int swap1, swap2, swap3, swap4, swap5;                      //used to count when a swap is made
    int i;
    
    /*initialising variables */
    compare1 = compare2 = compare3 = compare4 = compare5 = 0;
    swap1 = swap2 = swap3 = swap4 = swap5 = 0;
    

    /////////////////////////////////////// Bubble Sort Algorithm  ///////////////////////////////////////
    
    /*------------------------------ Testing N = 800 ------------------------------*/
    for(i = 0; i < N1; i++)
    {// sorting array in reverse order from N
        
        VALUE1_ARRAY[i] = N1 - i;
        
    }
    
    // call Bubble_Sort_Algorithm
    Bubble_Sort_Algorithm(VALUE1_ARRAY, N1, &compare1, &swap1);
    
    
    /*------------------------------ Testing N = 1600 ------------------------------*/
    for(i = 0; i < N2; i++)
    {// sorting array in reverse order from N
        
        VALUE2_ARRAY[i] = N2 - i;
      
    }
    
    // call Bubble_Sort_Algorithm
    Bubble_Sort_Algorithm(VALUE2_ARRAY, N2, &compare2, &swap2);
    
    
    /*------------------------------ Testing N = 2400 ------------------------------*/
    for(i = 0; i < N3; i++)
    {// sorting array in reverse order from N
        
        VALUE3_ARRAY[i] = N3 - i;
      
    }
    
    // call Bubble_Sort_Algorithm
    Bubble_Sort_Algorithm(VALUE3_ARRAY, N3, &compare3, &swap3);
    
    
    /*------------------------------ Testing N = 3200 ------------------------------*/
    for(i = 0; i < N4; i++)
    {// sorting array in reverse order from N
        
        VALUE4_ARRAY[i] = N4 - i;
      
    }
    
    // call Bubble_Sort_Algorithm
    Bubble_Sort_Algorithm(VALUE4_ARRAY, N4, &compare4, &swap4);
    
    
    /*------------------------------ Testing N = 4000 ------------------------------*/
    for(i = 0; i < N5; i++)
    {// sorting array in reverse order from N
        
        VALUE5_ARRAY[i] = N5 - i;
      
    }
    
    // call Bubble_Sort_Algorithm
    Bubble_Sort_Algorithm(VALUE5_ARRAY, N5, &compare5, &swap5);
    
    
    
    /*------------------------------ Displaying Bubble Sort Table of Values  ------------------------------*/
    printf("Bubble Sort Table Of Values:\n");
    printf("\nN:                 \t%d\t%d\t%d\t%d\t%d\n", N1, N2, N3, N4, N5);
    printf("\nNo. of Comparisons:\t%d\t%d\t%d\t%d\t%d", compare1, compare2, compare3, compare4, compare5);
    printf("\nNo. of Swaps:      \t%d\t%d\t%d\t%d\t%d", swap1, swap2, swap3, swap4, swap5);
    
    
    
    
    ///////////////////////////////////////  Improved Bubble Sort Algorithm  ///////////////////////////////////////
    
    
    /* Reset variables */
    compare1 = compare2 = compare3 = compare4 = compare5 = 0;
    swap1 = swap2 = swap3 = swap4 = swap5 = 0;
    
    
    /*------------------------------ Testing N = 800 ------------------------------*/
    for(i = 0; i < N1; i++)
    {// sorting array in reverse order from N
        
        VALUE1_ARRAY[i] = rand() % (2*N2);
        
    }
    
    // call funtion
    Improved_Bubble_Sort_Algorithm(VALUE1_ARRAY, N1, &compare1, &swap1);
    
    
    /*------------------------------ Testing N = 1600 ------------------------------*/
    for(i = 0; i < N2; i++)
    {// sorting array in reverse order from N
        
        VALUE2_ARRAY[i] = rand() % (2*N2);
      
    }
    
    // call funtion
    Improved_Bubble_Sort_Algorithm(VALUE2_ARRAY, N2, &compare2, &swap2);
    
    
    /*------------------------------ Testing N = 2400 ------------------------------*/
    for(i = 0; i < N3; i++)
    {// sorting array in reverse order from N
        
        VALUE3_ARRAY[i] = rand() % (2*N3);
      
    }
    
    // call funtion
    Improved_Bubble_Sort_Algorithm(VALUE3_ARRAY, N3, &compare3, &swap3);
    
    
    /*------------------------------ Testing N = 3200 ------------------------------*/
    for(i = 0; i < N4; i++)
    {// sorting array in reverse order from N
        
        VALUE4_ARRAY[i] = rand() % (2*N4);
      
    }
    
    // call funtion
    Improved_Bubble_Sort_Algorithm(VALUE4_ARRAY, N4, &compare4, &swap4);
    
    
    /*------------------------------ Testing N = 4000 ------------------------------*/
    for(i = 0; i < N5; i++)
    {// sorting array in reverse order from N
        
        VALUE5_ARRAY[i] = rand() % (2*N5);
      
    }
    
    // call funtion
    Improved_Bubble_Sort_Algorithm(VALUE5_ARRAY, N5, &compare5, &swap5);
    
    
    
    /*------------------------------ Displaying Table of Values  ------------------------------*/
    printf("\n\n\n\nImproved Bubble Sort Table Of Values:\n");
    printf("\nN:                 \t%d\t%d\t%d\t%d\t%d\n", N1, N2, N3, N4, N5);
    printf("\nNo. of Comparisons:\t%d\t%d\t%d\t%d\t%d", compare1, compare2, compare3, compare4, compare5);
    printf("\nNo. of Swaps:      \t%d\t%d\t%d\t%d\t%d", swap1, swap2, swap3, swap4, swap5);
    
    
    getchar();
}// end main()



/**********************************************  Bubble_Sort_Algorithm  *********************************************

DESCRIPTION:    This function uses the bubble sort algorthrim to sort an array.

PASSINGS:           VALUE5_ARRAY, N5, compare5, swap5
*******************************************************************************************************************/
void Bubble_Sort_Algorithm(int *array, int array_size, int *comparison, int *swapped)
{
    
	int i, j, temp;

	for (i = (array_size - 1); i >= 1; i--)     
    {// pass number (last index of array to sort)
        
        (*comparison)++;    //count comparisons
        
        for (j = 0; j < i; j++)
        {
            
            if(array[j] > array[j+1])
            {// current element is greater than the next: swap the numbers
                
                temp = array[j+1];         
                array[j+1] = array[j];
                array[j] = temp;
                (*swapped)++;   //count swaps
                
            }// end if
            
        }// end inner for
        
    }// end outer for
    
}//end Bubble_Sort_Algorithm



/*****************************************  Improved_Bubble_Sort_Algorithm  *****************************************

DESCRIPTION:    This function uses the improved bubble sort algorthrim to sort an array.

PASSINGS:           VALUE5_ARRAY, N5, compare5, swap5
*******************************************************************************************************************/
void Improved_Bubble_Sort_Algorithm(int *array, int array_size, int *comparison, int *swapped)
{
    
    int i, j, temp, swap_flag;
    
    
    for (i = array_size - 1; i >= 1; i--)
    {// pass number (last index of array to sort)
        
        swap_flag = 0;                  // indicates no swap
        
       for (j = 0; j < i; j++)
       {
           
            if(array[j] > array[j+1])
            {// current element is greater than the next: swap the numbers
                
                temp = array[j+1];
                array[j+1] = array[j];   
                array[j] = temp;
                swap_flag = 1;          // indicates swap
                (*swapped)++;           //count swaps
                
            }// end inner if
            
        }// end inner for
        
        (*comparison)++;    //count comparisons
        
        if(swap_flag == 0)	   
        {// no swap occurred.
            
            break;
            
        }// end if
        
        
        
    }// end for
    
}// end Improved_Bubble_Sort_Algorithm