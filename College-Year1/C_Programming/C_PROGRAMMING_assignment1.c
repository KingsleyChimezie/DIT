/*******************************************
    Programming - Assignment 1
    Author: Kingsley Chimezie - C14468272
    Date: 13/11/14
*******************************************/

#include <stdio.h>
#include <conio.h> // enables the function: 'clrscr();' which clears any display prior to when the function is called.



#define PIN_SIZE 4
#define ASTRISKS 23

main ()
{
    //declaring variables
    int option;         // allows the user to read in a designated menu option (1-4)
    int success_v;      // increments when PIN verification is successful
    int fail_v;         // increments when PIN verification is not successful
    int success_c;      // increments when PIN change is successful
    int fail_c;         // increments when PIN change is not successful
    int array_match;    // Used to check if each element between multiple arrays match
    
    
    // initialising variables
    option = success_v = fail_v = success_c = fail_c = 0;
    
    
    // declaring & initialising variables with arrays
    int current_pin[PIN_SIZE] = {1,2,3,4}; 
    int input_pin[PIN_SIZE] = {0};
    int change_pin[PIN_SIZE] = {0};
    
    
    do
    {
        /***************************************    MAIN MENU DISPLAY SECTION   ***************************************/
        printf("\n");
        
        // display 23 astrisks before the main menu heading
        for(int h = 0; h < ASTRISKS; h++) 
        {
            printf("*");
        }// end for
        
        printf(" ATM >> PIN SETTINGS >> MAIN MENU "); // main menu heading
        
        
        // display 23 astrisks after
        for(int h = 0; h < ASTRISKS; h++)
        {
            printf("*");
        }// end for
        
        
        printf("\n\n Please Select A Number From The Menu Options:\n");
        printf("\n\n 1. Enter PIN and Verify Correct"); 
        printf("\n\n 2. Change PIN"); 
        printf("\n\n 3. Display The Number Of Times The PIN Was Entered \n\t(i) Successfully (ii) Incorrectly"); 
        printf("\n\n 4. Exit Program");
        printf("\n\n\n >> ");
        scanf("%d", &option); // user inputs an option number from 1 - 4
        flushall();
        clrscr();
        
        
        switch(option)
        {
            /***************************************** OPTION 1 *****************************************/
            case 1:
            {// Enter PIN and verify correct
                
                
                for(int i = 0; i < PIN_SIZE; i++) 
                {// loop stores the users input of 4-digits 
                    
                    printf("\n SELECTED >> Enter PIN and Verify Correct\n\n");
                    printf("\n >> Enter The Current 4-Digit PIN:\n\n");
                    printf("\n >> Digit %d: ", i+1);
                    scanf("%d", &input_pin[i]);
                    flushall();
                    clrscr();
                    
                    
                    if( input_pin[i] == current_pin[i]) 
                    {// each element of the users input and current PIN match
                        
                        array_match = 0;
                        
                    }// end if
                    
                    else
                    {// if any one element not match
                        
                        array_match = 1;
                        
                    }// end else
                    
                }//end for    
                
                
                if(array_match == 0)
                {// all PIN digits matched. PIN verification is correct
                    
                    success_v++;
                    printf("\n >> PIN Verification Successful! Correct PIN Entered.\n");
                    printf("\n\n---------- (Press ENTER To Return To The Main Menu) ----------\n"); 
                    getchar();
                    clrscr();
                    break;
                    
                }// end if
                
                else 
                {// PIN verification is incorrect
                    
                    fail_v++;
                    printf("\n >> PIN Verification Unsuccessful! Incorrect PIN entered!\n");
                    printf("\n\n---------- (Press ENTER To Return To The Main Menu) ----------\n");  
                    getchar();
                    clrscr();
                    break;
                    
                }//end else
                
            }//end case 1:
            
            
            /***************************************** OPTION 2 *****************************************/
            case 2:
            {//Change PIN
                
                for(int i = 0; i < PIN_SIZE; i++) 
                {//loop stores the users first PIN input
                    
                    printf("\n SELECTED >> Change PIN\n\n");
                    printf("\n >> Enter A New 4-digit PIN:\n\n");
                    printf("\n >> Digit %d: ", i+1);
                    scanf("%d", &input_pin[i]);
                    flushall();
                    clrscr();
                    
                }// end for
                
                
                for(int i = 0; i < PIN_SIZE; i++) 
                {// loop stores the Re-entery PIN input 
                    
                    printf("\n SELECTED >> Change PIN\n\n");
                    printf("\n >> Re-enter The New 4-digit PIN:\n\n");
                    printf("\n >> Digit %d: ", i+1);
                    scanf("%d", &change_pin[i]);
                    flushall();
                    clrscr();
                    
                    
                    if(input_pin[i] == change_pin[i])
                    {// each element of the first & re-entry input match
                        
                        array_match = 0;
                        current_pin[i] = change_pin[i];
                        
                    }// end if
                    
                    else 
                    {// if any one element do not match
                        
                        array_match = 1;
                        
                    }// end else
                    
                } // end for
                
                
                if(array_match == 0)
                {// all PIN digits matched. PIN change sucessful
                    
                    success_c++;
                    printf("\n >> Current PIN Has Been Sucessfully Changed!\n");
                    printf("\n\n---------- (Press ENTER To Return To The Main Menu) ----------\n");
                    getchar();
                    clrscr();
                    break;
                    
                }// end if
                
                else
                {// PIN change unsucessful
                    
                    fail_c++;
                    printf("\n >> PIN Did Not Match! Please Try Again.\n");
                    printf("\n\n---------- (Press ENTER To Return To The Main Menu) ----------\n");
                    getchar();
                    clrscr();
                    break;
                    
                }//end else 
                
            }// end case 2:
            
            
            /***************************************** OPTION 3 *****************************************/
            case 3: 
            {//Display the number of times the PIN was entered (i) Successfully (ii) Incorrectly
                
                printf("\n SELECTED >> Display The Mumber Of Times The PIN Was Entered \n\t\t(i) Successfully (ii) Incorrectly\n\n");
                printf("\n >> The number Of times PIN Verification Was Entered:\n");
                printf("\n >> Sucessfully\t[%d Times]\n", success_v);
                printf("\n >> Incorrectly\t[%d Times]\n", fail_v);
                
                printf("\n\n >> The Number Of Times PIN Change Was Entered:\n");
                printf("\n >> Sucessfully\t[%d Times]\n", success_c);
                printf("\n >> Incorrectly\t[%d Times]\n", fail_c);
                printf("\n\n---------- (Press ENTER To Return To The Main Menu) ----------\n");
                getchar();
                clrscr();
                break;
                
            }//end case 3
            
            
            /***************************************** OPTION 4 *****************************************/
            case 4:
            {//  Exit Program
                
                printf("\n >> ********** TRANSACTION COMPLETED! **********\n");
                break;
                
            }//end case 4
            
            
            /***************************************** DEFAULT  *****************************************/
            default:
            { // All switch inputs without an assigned case:
                
                printf("\n >> ***** Error! Invalid Option Entered, Please Try Again. *****\n");
                printf("\n\n---------- (Press ENTER To Return To The Main Menu) ----------\n");
                getchar();
                clrscr();
                break;
                
            }//end default
            
        }//end switch
        
    }//end do
    
    while(option !=4);
    
    getchar();
    
}//end main()