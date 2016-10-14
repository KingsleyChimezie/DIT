/*******************************************
                Programming - Assignment 2

Date:         24th February 2015
Author:     Kingsley Chimezie - C14468272
*******************************************/

#include <stdio.h>
#include <conio.h>                                       // enables  use of the function 'clrscr()', clears any display prior to when the function is called.

#define CODE_SIZE 4                                      // used to defines all code sizes to 4


/*--------------------  PROTOTYPES  --------------------*/
void op1_entercode(int*, int*, int*);                             
int op2_encrypt(int*, int*, int*, int*, int*, int*);              
void compare_codes(int*, int*);                                          
int op3_decrypt(int*, int*);                                                                  
int counter(int*, int*, int*, int*, int*);
int op4_display(int*, int*, int*);
void op5_exit(void);                  

void go2menu(void);                                                     


main()
{
    
    int access_code[CODE_SIZE] = {4,5,2,3};              // stores the default authorised access code 4 5 2 3
    int input_code[CODE_SIZE] = {10,10,10,10};           // used to enter a code. default code is set to 10 10 10 10
    int option;                                          // allows the user to read in a menu option (1-5)  
    int successful, incorrect;                           // increments the number of times a code is entered successfully or incorrectly
    int EncryptDecrypt_flag;                             // flags an enter code when encrypted and compared access code(1) or decrypted(0)
    int counter_flag;                                    // used to flag the successful or incorrect incrementor from counting more than once
    
    
    /* initialising variables to zero */
    option = successful = incorrect = 0;
    counter_flag = EncryptDecrypt_flag = 0;           
    
    
    
    do
    {// run program until option 5 is selected
        
        
        /*-------------------------------------------------------------------  MAIN MENU DISPLAY  -------------------------------------------------------------------*/
        printf("\n>> Please Select & Enter A Number (1 - 5) From The Menu Option Below:\n");
        printf("\n\n 1 - Enter Code"); 
        printf("\n\n 2 - Encrypt Code And Verify If Correct"); 
        printf("\n\n 3 - Decrypt Code");
        printf("\n\n 4 - Display The Number Of Times The Code Was Entered: \n\t(i) Successfully (ii) Incorrectly");         
        printf("\n\n 5 - Exit Program");
        printf("\n\n\n >> ");
        scanf("%d", &option);   // user enters an option number from 1 - 5
        flushall();
        clrscr();
        
        
        
        /*------------------------------------------------------  CALLING FUNCTIONS FOR MENU OPTIONS  ------------------------------------------------------*/
        switch(option)
        {
            case 1: 
            {// call op1_entercode()
                
                
                op1_entercode(input_code, &EncryptDecrypt_flag, &counter_flag);
                option = 0;
                break;
                
                
            }// end case 1:
           
            
            case 2: 
            {// call op2_encrypt()
                
                op2_encrypt(access_code, input_code, &successful, &incorrect, &EncryptDecrypt_flag, &counter_flag);
                option = 0;
                break;
                
            }// end case 2
            
            
            case 3: 
            {// call op3_decrypt()
                
                op3_decrypt(input_code, &EncryptDecrypt_flag);
                option = 0;
                break;
                
            }// end case 3
            
            
            case 4: 
            {// call op4_display()
                
                op4_display(input_code, &successful, &incorrect);
                option = 0;
                break;
                
            }// end case 4
            
            
            case 5:
            {// call function op5_exit()
               
                op5_exit();
                break;
                
            }// end case 5
            
            
            default:
            {// all switch inputs without an assigned case
                
                printf("\n\a>> Error: Invalid Option Entered, Please Try Again.\n");
                go2menu();
                break;
                
            }// end default
            
            
        }// end switch
        
        
    }// end do
    
    
    while(option !=5);
    
    
    getchar();
}// end main()


/******************************************  Implementing op1_entercode()  ******************************************

DESCRIPTION:    This function allows the user to enter 4 single-digit integers and displays the entered digits as a code.

ERROR CHECKS:   This funtion checks for non single-digit integer inputs. Any error will prompt a beep and a display message.

PASSINGS:           input_code, EncryptDecrypt_flag, counter_flag
*******************************************************************************************************************/

void op1_entercode(int *input, int *ED_flag, int *count_flag)
{
    
    int i;  // loop index
    
    
    /*--------------------  Entering digits and checking if they are single-digit integers  --------------------*/
    for(i = 0; i < CODE_SIZE; i++)
    {
        
        
        /* resetting each array element of 'input_code' array to the default 10, 
                to help prompt an error for character inputs */
        *(input + i) = 10;
        
        
        printf("\n >> Please enter 4 single-digit integer numbers between 0-9\n");
        printf("\n >> Enter single-digit #%d: ", i+1);
        scanf("%d", & *(input + i));
        flushall();
        clrscr();
        
        
        while(*(input + i) < 0 || *(input + i) > 9)
        {// digit input is less than 0 or greater than 9
            
            
            printf("\n\a >> Error: Only enter a single-digit integer number between 0-9.");
            printf("\n\n >> Enter single-digit #%d: ", i+1);
            scanf("%d", & *(input + i));
            flushall();
            clrscr();
            
            
        }// end while
     
        
    }// end for
    
    
    /*--------------------  Displaying the entered digits as a 4 digit code.  --------------------*/
    printf("\n >> Your entered code is: ");
    
    for(i = 0; i < CODE_SIZE; i++)
    {// displaying each digit entered
        
        
        printf("%d ", *(input + i));
        
        
    }// end for
    
    
    *ED_flag = 0;       // ED_flag(0) indicates the new entered code is available for encryption
    
    *count_flag = 0;    // count_flag(0) indicates the new entered code is available to count successful or incorrect
    
    
    go2menu();
}// end op1_entercode()





/*******************************************  Implementing op2_encrypt()  *******************************************

DESCRIPTION:    This function encrypts the entered code from 'op1_entercode()' and it encrypts the code using an algorithm.

ERROR CHECKS:   This funtion checks if a code was ever entered before encryption and if a code was already encrypted.
*                             Any error will prompt a beep and a display message.

PASSINGS:           access_code, input_code, successful, incorrect, EncryptDecrypt_flag, counter_flag
*******************************************************************************************************************/

int op2_encrypt(int *access, int *input, int *SUC, int *INC, int *ED_flag,  int *count_flag)
{
    
    int i;      // loop index
    int temp;   // used to swap digits

    
    /*--------------------  Checking if a code was ever entered before the encryption process  --------------------*/
    if(*(input + 0) == 10)
    {// first element of 'input' array is still at the default '10'
        
        
        printf("\n\a >> ERROR: Please enter a code first.");
        
        
        go2menu();
        return 0;   // exit op2_encrypt()
    }// end if
    
    
    /*--------------------  Checking if the entered code was already encrypted  --------------------*/
    else if(*ED_flag == 1)
    {// ED_flag is 1, this indicates an encrypted code
        
        
        printf("\n\a >> ERROR: Your code is already encrypted."
                "\n\n >> Decrypt your code to verify again.");
        
        
        go2menu();
        return 0;   // exit op2_encrypt()
    }// end if

    
    /*--------------------  Encrypt the entered code with the algorithm  --------------------*/
    else
    {
        ///////////////////////////////////////////////////////////////////
        /*------------------------------  Swapping digits  ------------------------------*/
        temp = *(input + 0);                    // temp = 1st
        *(input + 0) = *(input + 2);            // 1st = 3rd
        *(input + 2) = temp;                    // 3rd = temp (1st)
        temp = *(input + 1);                    // temp = 2nd
        *(input + 1) = *(input + 3);            // 2nd = 4th
        *(input + 3) = temp;                    // 4th = temp (2nd)
        
        
        for(i = 0; i < CODE_SIZE; i++)
        {// performing algorithm calculations
            
            
            *(input + i) = *(input + i) + 1;    // add 1 to digit
            
            
            if(*(input + i) == 10)              // digit is 10
            {
                
                *(input + i) = 0;               // change digit to 0
                
                
            }// end if
            
            
        }// end for
        ///////////////////////////////////////////////////////////////////
        
        
    }// end else
    
    
    *ED_flag = 1;                                       // ED_flag(1) indicates the entered code is encrypted
    
    
    compare_codes(access, input);                       // call compare_codes()
    
    
    counter(access, input, SUC, INC, count_flag);       //call counter()
    
    
    return 0;                                           // exit op2_encrypt()
}// end op2_encrypt()





/******************************************  Implementing compare_codes()  ******************************************

DESCRIPTION:    This function compares the encrypted entered code with the default access code (4523)

ERROR CHECKS:   This funtion checks if the 2 code match or not and then displays a message.

PASSINGS:           access_code, input_code
*******************************************************************************************************************/

void compare_codes(int *access, int *input)
{
    
    /*--------------------  Comparing the encrypted entered code with the access code  --------------------*/
    if(*(input + 0) == *(access + 0) && *(input + 1) == *(access + 1) &&
       *(input + 2) == *(access + 2) && *(input + 3) == *(access + 3))
    {// entered encrypted code matches the access code
        
        
        printf("\n CORRECT ACCESS CODE ENTERED ");
        go2menu();
        
        
    } // end if
    
    
    else
    {// entered encrypted code does not matche the access code
        
        
        printf("\n INCORRECT ACCESS CODE ENTERED ");
        go2menu();
        
        
    }// end else

    
}// end compare_codes()





/********************************************  Implementing op3_decrypt()  ********************************************

DESCRIPTION:    This function decrypts the encrypted entered code using the encryption algorithm in reverse.

ERROR CHECKS:   This funtion checks if a code was ever entered before decryption and if a code was already decrypted.
*                             Any error will prompt a beep and a display message.

PASSINGS:           input_code, EncryptDecrypt_flag
********************************************************************************************************************/

int op3_decrypt(int *input, int *ED_flag)
{
    
    int i;      // loop index
    int temp;   // used to swap digits
    
    
    /*--------------------  Checking if a code was ever entered before the decryption process  --------------------*/
    if(*(input + 0) == 10)
    {// first element of 'input' array is still at the default '10'
        
        
        printf("\n\a >> ERROR: Please enter a code first.");
        
        
        go2menu();
        return 0;   // exit op3_decrypt()
    }// end if
    
    
    /*-------------------- checking if code was already decrypted --------------------*/
    else if(*ED_flag == 0)
    {// ED_flag is 0, this indicates a decrypted code
        
        
        printf("\n\a >> ERROR: Your code is already decrypted.");
        
        
        go2menu();
        return 0;   // exit op3_decrypt()
    }// end if
    
    
    /*--------------------  Decrypt the entered code with the algorithm  --------------------*/
    else
    {
        ///////////////////////////////////////////////////////////////////
        for(i = 0; i < CODE_SIZE; i++)
        {// performing algorithm calculations
            
            
            *(input + i) = *(input + i) - 1;    // subtract 1 to digit
            
            
            if(*(input + i) == -1)              // digit is -1
            {
                
                *(input + i) = 9;               // change digit to 9
                
                
            }// end if
            
            
        }// end for
        
        
        /*------------------------------  Swapping digits  ------------------------------*/
        temp = *(input + 0);                    // temp = 1st
        *(input + 0) = *(input + 2);            // 1st = 3rd
        *(input + 2) = temp;                    // 3rd = temp (1st)
        temp = *(input + 1);                    // temp = 2nd
        *(input + 1) = *(input + 3);            // 2nd = 4th
        *(input + 3) = temp;                    // 4th = temp (2nd)
        //////////////////////////////////////////////////////////////////
        
        
        *ED_flag = 0;  //  ED_flag(0) indicates the entered code is decrypted
        
        
        printf("\n >> Your code is now decrypted.");
       
        
        go2menu();
        return 0;   // exit op3_decrypt()        
    }// end else
    
    
}// end op3_decrypt()





/**********************************************  Implementing counter()  **********************************************

DESCRIPTION:    This function increments the number of times an encrypted entered code was successful or incorrect.

ERROR CHECKS:   This funtion checks if an encrypted entered code was ever successful or incorrect.

PASSINGS:           access_code, input_code, successful, incorrect, counter_flag
********************************************************************************************************************/

int counter(int *access, int *input, int *SUC, int *INC, int *count_flag)
{
    
    
    /*--------------------  Checking if the encrypted code has ever incremented successful or incorrect  --------------------*/
    if(*count_flag == 0)
    {// counter_flag is at 0, increment successful or incorrect
        
        
        /*--------------------  Incrementing success, if the code matches the access code  --------------------*/
        if(*(input + 0) == *(access + 0) && *(input + 1) == *(access + 1) &&
           *(input + 2) == *(access + 2) && *(input + 3) == *(access + 3))
        {
            
            (*SUC)++;           // add 1 to successfully
            
            *count_flag = 1;    // flag(1) indicates the current entered code increments successful only once
            
            
        } // end inner if
        
        
        /*---------------  Incrementing incorrect, if the code does not match the access code  ---------------*/
        else
        {
            
            (*INC)++;           // add 1 to incorrectly
            
            *count_flag = 1;    // flag(1) indicates the current entered code increments incorrect only once
            
            
        }// end inner else
        
        
    }//end if

    
    return 0;   // exit counter()
}// end counter()





/********************************************  Implementing op4_display()  *********************************************

DESCRIPTION:    This function displays the number of times an encrypted entered code was entered successfully or incorrectly.

ERROR CHECKS:   This funtion checking if a code was ever entered before the display process.
*                             Any error will prompt a beep and a display message.

PASSINGS:           input_code, successful, incorrect
********************************************************************************************************************/

int op4_display(int *input, int *SUC, int *INC)
{
    
    
    /*--------------------  Checking if a code was ever entered before the display process  --------------------*/
    if(*(input + 0) == 10)
    {// first element of 'input' array is still at the default '10'
        
        
        printf("\n\a >> ERROR: Please enter a code first.");
        
        
        go2menu();
        return 0;   // exit op4_display()
    }// end if
    
    
    /*--------------------  Displays information  --------------------*/
    printf("\n >> The number of times the code was entered");
    printf("\n\n >> Sucessfully:\t%d Time(s)", *SUC);
    printf("\n\n >> Incorrectly:\t%d Time(s)", *INC);
    
    
    go2menu();
    return 0;   // exit op4_display()
}// end op4_display()





/**********************************************  Implementing op5_exit()  **********************************************

DESCRIPTION:    This function terminates the program, prompts a beep and a displays message.

********************************************************************************************************************/

void op5_exit(void)
{
    
    printf("\n\n\n*****************************");
    printf("\a \"PROGRAM TERMINATED\" \a");
    printf("*****************************");
    
    
}// end op5_exit()





/**********************************************  Implementing go2menu()  **********************************************

DESCRIPTION:    This function displays an instruction for returning to the main menu after completing a menu option.

********************************************************************************************************************/

void go2menu(void)
{
    printf("\n\n\n*********************");
    printf(" \"Press ENTER To View The Main Menu\" ");
    printf("*********************");
    getchar();
    clrscr();
    
}//end stars()