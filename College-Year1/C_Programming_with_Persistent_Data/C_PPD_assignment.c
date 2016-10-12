/*******************************************
        Program with Persistant Data - Assignment

Date:         2nd May 2015
Author:     Kingsley Chimezie - C14468272
*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX 50          // maximum size of my arrays
#define TEAMS 10        // number of original teams

/*----- Structure to store the record of a single match -----*/
struct teams
{
    char name[MAX];
    int PTS;
    int GF;
    int GA;
    
}DATA;

struct match
{
    char teamA[MAX];
    char teamB[MAX];
    int goalA;
    int goalB;
    
}REC;


/*----- Global Variables -----*/
int bin_size;          // stores the size of a .bin file   
int struct_size;       // stores the size of 1 match structure
int total;             // stores the total amount of match struct
int team_count;         // counts the number of teams struct
int counter;           // loop counter


/*--------------------  Function Prototypes  --------------------*/
void convert_file(void);
void op1_show_table(void);
void op2_new_result(void);
void op3_highest_score(void);
void op4_display_matches(void);
void op5_exit(void);                  
void go2menu(void);                                                     


main()
{
    
    convert_file();          // call function to convert text file to binary
    go2menu();               // call go2menu display function

    
    int option = 0;         //this variable is used to get users menu option
    
    
    do
    {// run program until option 5 is selected
        
        
        /*-------------------------------------------------------------------  MAIN MENU DISPLAY  -------------------------------------------------------------------*/
        printf("\n>> Please Select & Enter A Number (1 - 5) From The Menu Option Below:\n");
        printf("\n\n 1 - Show The Table"); 
        printf("\n\n 2 - Insert A New Result"); 
        printf("\n\n 3 - Display The Highest Scoring Match");
        printf("\n\n 4 - Enter & Display All The Matches Of A Team");         
        printf("\n\n 5 - Exit Program");
        printf("\n\n\n >> ");
        scanf("%d", &option);   // user enters an option number from 1 - 5
        flushall();
        clrscr();
        
        
        
        /*------------------------------------------------------  CALLING FUNCTIONS FOR MENU OPTIONS  ------------------------------------------------------*/
        switch(option)
        {
            case 1: 
            {// call op1_show_table()
                
                op1_show_table();
                option = 0;
                go2menu();
                break;
                
            }// end case 1:
           
            
            case 2: 
            {// call op2_new_result()
                
                op2_new_result();
                option = 0;
                go2menu();
                break;
                
            }// end case 2
            
            
            case 3: 
            {// call op3_highest_score()
                
                op3_highest_score();
                option = 0;
                go2menu();
                break;
                
            }// end case 3
            
            
            case 4: 
            {// call op4_display_matches();
                
                op4_display_matches();
                option = 0;
                go2menu();
                break;
                
            }// end case 4
            
            
            case 5:
            {// call op5_exit()
               
                op5_exit();
                break;
                
            }// end case 5
            
            
            default:
            {// all switch inputs without an assigned case
                
                printf("\n\a>> Error: Invalid Option Entered, Please Try Again.\n");
                option = 0;
                go2menu();
                break;
                
            }// end default
            
            
        }// end switch
        
        
    }// end do
    
    
    while(option != 5);
    
    
    getchar();
}// end main()



/********************************************  Implementing convert_file()  ********************************************

DESCRIPTION:    This function converts of the text file "matches.txt" into a binary file "matches.bin".

********************************************************************************************************************/
void convert_file(void)
{
    
    char read_teamA[MAX];    // used to copy team A into the struct match
    char read_teamB[MAX];    // used to copy team B into the struct match
    int read_goalA;          // used to copy team A's score into the struct match
    int read_goalB;          // used to copy team B's score into the struct match
    
    FILE *filer;             // file pointer to read a file
    FILE *filew;             // file pointer to write a file
    
    
    /*----- opening all files -----*/
    filer = fopen("matches.txt","r");       // opening the read file
    filew = fopen("matches.bin","w+b");     // opening the write file
    
    
    /*----- error checking if the files can open successfully -----*/
    if(filer == NULL)
    {
        printf("\aERROR: Cannot open the file \"matches.txt\"\n");
        fclose(filer);
        getchar();
        exit(1);
    }
    if(filew == NULL)
    {
        printf("\aERROR: Cannot open the file \"matches.bin\"\n");
        fclose(filew);
        getchar();
        exit(1);
    }
    
    else
    {
        
        
        /*----- Loop task: Read the matches.txt file, copy the data & write the data to the binary file -----*/
        while(fscanf(filer, "%[^,] , %[^,] , %d , %d", 
              read_teamA, read_teamB, &read_goalA, &read_goalB) != EOF)
        { // reading matches.txt file
            
            
            {/*----- copying the read data into struct match -----*/
                
                strcpy(REC.teamA, read_teamA);
                strcpy(REC.teamB, read_teamB);
                REC.goalA = read_goalA; 
                REC.goalB = read_goalB;
                
            }// end task chain
            
            
            // writing the copied data to the binary file
            fwrite(&REC,sizeof(REC),1,filew);   
            
        }
        
        
        {/*----- making file calculation -----*/
            
            fseek(filew, 0, SEEK_END);      // seek to end of file
            bin_size = ftell(filew);        // get file size matches.bin
            fseek(filew, 0, SEEK_SET);      // seek back to beginning of file
            
            struct_size = sizeof(REC);      // get the size of 1 struct match REC
            total = bin_size/struct_size;   // get the total amount of struct match REC in the file
            
        }// end task chain
        
        
        puts("\n>> Converted \"matches.txt\" To \"matches.bin\"\n");
        puts("\n======================================================");
        
        printf("\"matches.bin\" Properties:\n");
        printf("\nSize Of The Binary File: \t%d bytes", bin_size);
        printf("\nSize Of 1 Match Structure: \t%d bytes", struct_size);
        printf("\nTotal Number Of Structs: \t%d structs", total);
        
        puts("\n======================================================");
        
        puts("\n >> [Continue...PRESS ENTER]");
        
        
        /*----- closing all files -----*/
        fclose(filer);
        fclose(filew);
        getchar();
        clrscr();
        
        
        /////////////////////////////////////// CONVERSION 2 /////////////////////////////////////
        
        
        char name[MAX];           // stores a teams name
        
        
        FILE *filer;             // file pointer to read a file
        FILE *filew;             // file pointer to write a file
        
        
        /*----- opening all files -----*/
        filer = fopen("teams.txt","r");       // opening the read file
        filew = fopen("teams.bin","w+b");     // opening the write file
        
        
        /*----- error checking if the files can open successfully -----*/
        if(filer == NULL)
        {
            printf("\aERROR: Cannot open the file \"teams.txt\"\n");
            fclose(filer);
            getchar();
            exit(1);
        }
        if(filew == NULL)
        {
            printf("\aERROR: Cannot open the file \"teams.bin\"\n");
            fclose(filew);
            getchar();
            exit(1);
        }
        
        else
        {
            
            
            // scan the text file containing the teams and write to binary
            while(fscanf(filer, "%[^,],", name) != EOF)
            {
                
                strcpy(DATA.name, name);                // copy data into struct
                DATA.PTS = 0;
                DATA.GF = 0;
                DATA.GA = 0;
                
                fwrite(&DATA, sizeof(DATA), 1, filew);  // write to binary file
                
            }
            
            
            {/*----- making file calculation -----*/
                
                fseek(filew, 0, SEEK_END);           // seek to end of file
                bin_size = ftell(filew);             // get file size
                fseek(filew, 0, SEEK_SET);           // seek back to beginning of file
                
                struct_size = sizeof(DATA);           // get the size of struct
                team_count = bin_size/struct_size;         // count number of teams
                
            }// end task chain
            
            
            puts("\n>> Converted \"teams.txt\" To \"teams.bin\"\n");
            puts("\n======================================================");
            
            printf("\"teams.bin\" Properties:\n");
            printf("\nSize Of The Binary File: \t%d bytes", bin_size);
            printf("\nSize Of 1 Match Structure: \t%d bytes", struct_size);
            printf("\nTotal Number Of Structs: \t%d structs", team_count);
            
            puts("\n======================================================");
            
            
            /*----- closing all files -----*/
            fclose(filer);
            fclose(filew);
            
        }//end else
        
        
    }//end main else
    
    
}// end convert()



/******************************************  Implementing op1_show_table()  ******************************************

DESCRIPTION:    This function reads the binary file of matches and shows the league table.
                            *NB - I was unable to implement this function properly.

********************************************************************************************************************/
void op1_show_table(void)
{
    
    int i;                    // loop index

    
    FILE *fpr1;                              // file pointer to read a file
    FILE *fpr2;                              // file pointer to read a file
    
    fpr1 = fopen("teams.bin","r+b");            // opening the read file
    fpr2 = fopen("matches.bin","r+b");       // opening the read file
    
    
    /*----- error checking if the files can open successfully -----*/
    if(fpr1 == NULL)
    {
        printf("\aERROR: Cannot open the file \"teams.bin\" for reading\n");
        fclose(fpr1);
        getchar();
        exit(1);
    }
    if(fpr2 == NULL)
    {
        printf("\aERROR: Cannot open the file \"matches.bin\" for reading\n");
        fclose(fpr2);
        getchar();
        exit(1);
    }
    
    else
    {
        
        
        {/*----- making file calculation -----*/
            
            fseek(fpr1, 0, SEEK_END);      // seek to end of file
            bin_size = ftell(fpr1);        // get file size
            fseek(fpr1, 0, SEEK_SET);      // seek back to beginning of file
            
            struct_size = sizeof(DATA);      // get the size of struct REC
            team_count = bin_size/struct_size;   // get the total amount of struct REC in the .bin file
            
        }// end task chain
        
        
        {/*----- making file calculation -----*/
            
            fseek(fpr2, 0, SEEK_END);      // seek to end of file
            bin_size = ftell(fpr2);        // get file size
            fseek(fpr2, 0, SEEK_SET);      // seek back to beginning of file
            
            struct_size = sizeof(REC);      // get the size of struct REC
            total = bin_size/struct_size;   // get the total amount of struct REC in the .bin file
            
        }// end task chain
        
        
        counter = 0;    //reset counter
        
        
        printf("\n>> LEAGUE TABLE");
        printf("\n==========================================================================\n");
        
        
        /*----- calculating match points, goals scored & goals conceded -----*/
        for(i = 0; i < team_count; i++)
        {// loop through "teams.bin" file
            
            
            fread(&DATA, sizeof(DATA), 1, fpr1);       // read the binary file once
            
            
            while(counter < total)
            {// loop through "matches.bin" file
                
                
                fread(&REC, sizeof(REC), 1, fpr2);     // read the binary file once
                
                
                if(strcmp(DATA.name, REC.teamA) == 0)
                {// team name matches team A
                    
                    
                    DATA.GF = DATA.GF + REC.goalA;      // add goalA to scored goals
                    DATA.GA = DATA.GA + REC.goalB;      // add goalB to conceded goals
                    
                    
                    /* calculating points */
                    if(REC.goalA > REC.goalB)
                    {// win
                        
                        DATA.PTS = DATA.PTS + 3;        // add 3 points
                        
                    }
                    if(REC.goalA == REC.goalB)
                    {// draw
                        
                        DATA.PTS = DATA.PTS + 1;        // add 1 point
                        
                    }
                    
                }
                
                if(strcmp(DATA.name, REC.teamB) == 0)
                {// team name matches team B
                    
                    
                    DATA.GF = DATA.GF + REC.goalB;      // add goalB to scored goals
                    DATA.GA = DATA.GA + REC.goalA;      // add goalA to conceded goals
                    
                    
                    /* calculating points */
                    if(REC.goalB > REC.goalA)
                    {// win
                        
                        DATA.PTS = DATA.PTS + 3;        // add 3 points
                        
                    }
                    if(REC.goalB == REC.goalA)
                    {// draw
                        
                        DATA.PTS = DATA.PTS + 1;        // add 1 point
                        
                    }
                    
                }
                
                counter++;
            }
            
            
            printf("\n#%d  %s:"
                   "\nPTS \tGF \tGA"
                   "\n%d  \t%d \t%d\n",
                   i+1, DATA.name, DATA.PTS, DATA.GF, DATA.GA);
            
        }
        
        
        /*----- closing all files -----*/
        fclose(fpr1);
        fclose(fpr2);
        
        
    }//end else
    
    
}// end op1_show_table()



/******************************************  Implementing op2_new_result()  ******************************************

DESCRIPTION:    This function inserts a new result into "matches.bin", 
                                by asking the user to insert team A, team B, Goals A, Goals B.

********************************************************************************************************************/
void op2_new_result(void)
{
    
    char new_teamA[MAX];     // used to copy team A into the struct match
    char new_teamB[MAX];     // used to copy team B into the struct match
    int new_goalA;           // used to copy team A's score into the struct match
    int new_goalB;           // used to copy team B's score into the struct match
    
    
    FILE *filer;                              // file pointer to read a file
    filer = fopen("matches.bin","a+b");       // opening the read file
    
    
    /*----- error checking if the files can open successfully -----*/
    if(filer == NULL)
    {
        printf("\aERROR: Cannot open the file \"matches.bin\" for reading\n");
        fclose(filer);
        getchar();
        exit(1);
    }
    
    else
    {
        
        {/*----- making file calculation -----*/
            
            fseek(filer, 0, SEEK_END);      // seek to end of file
            bin_size = ftell(filer);        // get file size
            fseek(filer, 0, SEEK_SET);      // seek back to beginning of file
            
            struct_size = sizeof(REC);      // get the size of struct REC
            total = bin_size/struct_size;   // get the total amount of struct REC in the .bin file
            
        }// end task chain
        
        
        {/*----- entering new result data -----*/
            
            printf("\n>> Please Enter A New Result");
            printf("\n==========================================================================");
            
            printf("\n\n >> Enter Team A: ");
            gets(new_teamA);
            
            printf("\n\n >> Enter Team B: ");
            gets(new_teamB);
            
            printf("\n\n >> Enter Team A's Score: ");
            scanf("%d", &new_goalA);
            
            printf("\n\n >> Enter Team B's Score: ");
            scanf("%d", &new_goalB);
            
            clrscr();
            
        }// end task chain
        
        
        {/*----- copying the entered new result data into struct match -----*/
            
            strcpy(REC.teamA, new_teamA);
            strcpy(REC.teamB, new_teamB);
            REC.goalA = new_goalA; 
            REC.goalB = new_goalB;
            
        }// end task chain
        
        
        //write entered new result data in struct match to the beginning of the file
        fwrite(&REC, sizeof(REC), 1, filer);    
        
        
        printf("\n>> Your New Result Has Been Entered!");
        printf("\n==========================================================================\n");
        
        printf("\n>> Your New Result is:\n\n");
        printf("%s %d - %d %s", REC.teamA, REC.goalA, REC.goalB, REC.teamB);
        
        
        /*----- closing all files -----*/
        fclose(filer);
        getchar();
        
        
    }//end else
    
    
}// end op2_new_result()



/*****************************************  Implementing op3_highest_score()  *****************************************

DESCRIPTION:    This function displays the match with the highest number of goals scored.

********************************************************************************************************************/
void op3_highest_score(void)
{
    
    int *ptr_scores;                         // used to store the total goals scored in each match
    int highest;                             // stores the highest number of goals scored
    int i;                                   // loop index
    
    FILE *filer;                             // file pointer
    filer = fopen("matches.bin","r+b");      // opening the file in read binary mode
    
    
    /*----- error checking if the file can open successfully -----*/
    if(filer == NULL)
    {
        printf("\aERROR: Cannot open the file \"matches.bin\"\n");
        fclose(filer);
        getchar();
        exit(1);
    }
    
    else
    {
        
        {/*----- making file calculation -----*/
            
            fseek(filer, 0, SEEK_END);      // seek to end of file
            bin_size = ftell(filer);        // get file size
            fseek(filer, 0, SEEK_SET);      // seek back to beginning of file
            
            struct_size = sizeof(REC);      // get the size of struct REC
            total = bin_size/struct_size;   // get the total amount of struct REC in the .bin file
            
        }// end task chain
        
        
        // dynamically allocating array of memory
        ptr_scores = (int *)calloc( total, sizeof(int));
        
        
        /*----- Loop task: Read the matches.bin file, store the total score of each match -----*/
        for(counter = 0; counter < total; counter++)
        {
            
            fread(&REC, sizeof(REC), 1, filer);
            
            ptr_scores[counter] = (REC.goalA + REC.goalB);
            
        }
     
        
        {/*----- checking for the highest scoring match -----*/
            
            highest = ptr_scores[0];
            
            for(i = 0; i < total; i++)
            {
                
                if(highest < ptr_scores[i])
                {
                    
                    highest = ptr_scores[i];
                    
                }
                
            }
            
        }// end task chain
        
        
        {/*Read the matches.bin file
                     check for match(es) with the highest number of goal scored
                     display the matches
                    */
            
            fseek(filer, 0, SEEK_SET);      // seek to the beginning of the file
            
            
            printf("\n>> Highest Number Of Goals Scored In A Match: %d", highest);
            printf("\n==========================================================================\n");
            printf("\n\n>> Match(es) With The Highest Number Goals Scored:\n\n");
            
            
           
            for(counter = 0; counter < total; counter++)
            {
                
                fread(&REC, sizeof(REC), 1, filer);
                
                if((REC.goalA + REC.goalB) == highest)
                {// if goalA + goalB equals highest
                    
                    printf("%s %d - %d %s", REC.teamA, REC.goalA, REC.goalB, REC.teamB);
                    
                }
            }
            
        }// end task chain
        
        
        /*----- closing all files -----*/
        free(ptr_scores);
        fclose(filer);
        
        
    }//end else
    
    
}// end op3_highest_score() 



/****************************************  Implementing op4_display_matches()  ****************************************

DESCRIPTION:    This function reads the binary file and displays all the matches relating to a team name chosen by the user.

********************************************************************************************************************/
void op4_display_matches(void)
{
    
    char input[MAX];                         // used to get the users input    
    int flag = 0;                            // used for error checking
    int match_count = 0;                     // counts the number of relating matches
    
    FILE *filer;                             // file pointer
    filer = fopen("matches.bin","r+b");      // opening the file in read binary mode
    
    
    /*----- error checking if the file can open successfully -----*/
    if(filer == NULL)
    {
        printf("\aERROR: Cannot open the file \"matches.bin\"\n");
        fclose(filer);
        getchar();
        exit(1);
    }
    
    else
    {
        
        {/*----- making file calculation -----*/
            
            fseek(filer, 0, SEEK_END);      // seek to end of file
            bin_size = ftell(filer);        // get file size
            fseek(filer, 0, SEEK_SET);      // seek back to beginning of file
            
            struct_size = sizeof(REC);      // get the size of struct REC
            total = bin_size/struct_size;   // get the total amount of struct REC in the .bin file
            
        }// end task chain
        
        
        printf("\n>> Please Enter The Name Of A Team: ");
        gets(input);
        clrscr();
        
        
        printf("\n>> Displaying Matches Relating To The Entered Team Name: \"%s\"", input);
        printf("\n==========================================================================\n");
        
        
        /*----- Loop task: Read the matches.bin file, check for and display matches relating to input -----*/
        for(counter = 0; counter < total; counter++)
        {
            
            fread(&REC, sizeof(REC), 1, filer);
            
            if(strstr(REC.teamA, input) != NULL || strstr(REC.teamB, input) != NULL)
            {// entered name relates to teamA or teamB
                
                printf("%s %d - %d %s", REC.teamA, REC.goalA, REC.goalB, REC.teamB);
                
                match_count++;
                
                flag = 1;
                
            }
            
        }
        
        
        /*----- error checking if there are any relating matches relating to the entered team name -----*/
        if(flag == 0)
        {
            
            printf("\n\n>> There Are No Matches Relating To The Entered Team Name: \"%s\"", input);
            
        }
        else
        {
            
            printf("\n\n>> %d Match(es) Relate To The Entered Team Name: \"%s\""
               , match_count, input);
            
        }
        
        
        /*----- closing all files -----*/
        fclose(filer);
        
        
    }//end else
    
    
}// end op4_display_matches()



/**********************************************  Implementing op5_exit()  **********************************************

DESCRIPTION:    This function terminates the program, prompts a beep and a display message.

********************************************************************************************************************/
void op5_exit(void)
{
    
    printf("\n\n*****************************");
    printf("\a \"PROGRAM TERMINATED\" \a");
    printf("*****************************");
    
    
}// end op5_exit()



/**********************************************  Implementing go2menu()  **********************************************

DESCRIPTION:    This function displays an instruction for returning to the main menu after completing a menu option.

********************************************************************************************************************/

void go2menu(void)
{
    printf("\n\n*********************");
    printf(" \"Press ENTER To View The Main Menu\" ");
    printf("*********************");
    getchar();
    clrscr();
    
}//end go2menu()