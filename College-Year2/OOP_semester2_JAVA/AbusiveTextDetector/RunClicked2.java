/****************************************************************************
 * TITLE: 	-	Programming Assignment 	- 	Abusive text content detector
 * AUTHOR: 	-	Kingsley Chimezie 		- 	C14468272 
 * DATE: 	-	10/04/16
 ****************************************************************************/


package AbusiveTextDetector;
////////////////////////////////////////////IMPORTS
import java.io.File;
import java.util.ArrayList;
////////////////////////////////////////////IMPORTS


class RunClicked2
{


	//(DO NOT RESET)
	private static ArrayList<String>  		badWordsList 		= new ArrayList<>();		// stores the words from the bad words library file 
	//(DO NOT RESET)
	
	private static int				  		bwTotalWords		= 0;						// stores the total number of words in the bad words library file
	
	private static ArrayList<String> 		chosenFileList		= new ArrayList<>();		// stores the words from the chosen file to be checked for bad words
	private static int				 		cfTotalWords		= 0;						// stores the total number of words in the chosen file
	
	private static ArrayList<String> 		badWordsFoundList	= new ArrayList<>();		// stores the bad words found in the chosen file
	private static int				 		bwCount 			= 0; 						// counts the number of words found in the chosen file
	private static boolean					detected 			= false; 					// Indicates whether the chosen file contains a bad word or not

	
	
	/*------------------- CONSTRUCTOR -------------------*/
	public RunClicked2()
	{
		System.out.println("\n\n<< RUN CLICKED 2 . PROCESS RESULTS: successful >>\n");		// **TESTER PRINT**
	}
	
	
	
	
	/*------------------- RECEIVE A COPY OF BAD WORDS LIST & NO. WORDS COUNTED -------------------*/
	public void giveBadWordsList(ArrayList<String> bwList, int bwAmount)
	{
		badWordsList = bwList;																// store a copy of the words in the bad words library list
		bwTotalWords = bwAmount;															// store a copy of the amount of words in the bad words library list
		
		System.out.println("# PROCESS RESULTS RECEIVED BAD WORDS LIST:\t\t"					// **TESTER PRINT**
							+ badWordsList);
		
		System.out.println("# TOTAL WORDS IN BAD WORDS LIBRARY LIST RECEIVED:\t"			// **TESTER PRINT**
						    + bwTotalWords);												//
	}
	
	
	
	
	/*------------------- RECEIVE A COPY OF CHOSEN FILE PATH, LIST & NO. WORDS COUNTED -------------------*/
	public void giveChosenFileList(File cfPath, ArrayList<String> cfWordsList, int cfWordsAmount)
	{
		
		chosenFileList 	= cfWordsList;														// store a copy of the words in the chosen file words list
		cfTotalWords    = cfWordsAmount;													// store a copy of the amount of words in the chosen file words list
		
		System.out.println("# PROCESS RESULTS RECEIVED CHOSEN FILE LIST:\t\t"				// **TESTER PRINT**
							+ chosenFileList);												//
		
		System.out.println("# TOTAL WORDS IN CHOSEN FILE LIST RECEIVED:\t\t"				// **TESTER PRINT**
							+ cfTotalWords);												//
		
		processResult(cfPath);
	}
	
	
	
	
	/*------------------- PROCESSING RESULTS -------------------*/
	public void processResult(File myFile)
	{
		
		/* THERE IS NO VAILD FILE PATH SELECTED WHEN RUN IS CLICKED */
			if(myFile == null)																	
			{
				System.out.println("** PROCESS RESULT ACCESSED BUT NO FILE PATH SELECTED **");	// **TESTER PRINT**
			}
		
		
		/* THERE IS A VALID FILE PATH SELECTED WHEN RUN IS CLICKED */
			else if(myFile != null)																
			{
				System.out.println("\n** FILE PATH SELECTED: PROCESSING RESULTS **");			// **TESTER PRINT**
				
				
				/* CHECKING CHOSE FILE WORDS LIST FOR BAD WORDS */
					for(String cf : chosenFileList)												// THERE IS A STRING IN CHOSEN FILE LIST
				    {
				        for(String bw : badWordsList)											// THERE IS A STRING IN BAD WORDS LIST
				        {
				            if (cf.contains(bw))												// CHOSEN FILE STRING CONTAINS BAD WORDS STRING
				            {
				            	detected = true;												// a bad word has been detected
				            	badWordsFoundList.add(cf);										// add the bad word to the bad words found list
				            	bwCount++;														// increment bad words counter
				                break;															// exit bad words loop and check next existing string in chosen file list
				            }
				        }
				    }
				
				
					
				/* OUTCOME */
					if(detected == true)	// BAD WORD(S) DETECTED
					{
						System.out.println("\n!!!!!!!!! BAD WORDS FOUND IN CHOSEN FILE !!!!!!!!!");							// **TESTER PRINT**			
						System.out.println(badWordsFoundList);																//
						System.out.println("\n# NUMBER OF BAD WORDS:\t\t" + bwCount);										//
					}
					
					else					// BAD WORD(S) NOT DETECTED
					{
						System.out.println("^_^ ******** NO BAD WORDS WERE FOUND IN THE CHOSEN FILE ******** ^_^");			// **TESTER PRINT**
						System.out.println("\n# NUMBER OF BAD WORDS:\t\t" + bwCount);										//
					}
				
					
					System.out.println("\n\n** CHANGEABLE STATIC VARIABLES RESETTED **\n\n");								// **TESTER PRINT**
					
					
					RunClicked3 result = new RunClicked3();										// instantiate (showResult) object & access showResult()
		            result.showResult(myFile, bwCount, badWordsFoundList);						// give a copy of the no. of bad words and bad words found
				
		            
				/* RESET CHANGEABLE STATIC VARIABLES */
					bwTotalWords = 0;
					
					chosenFileList.clear();
					cfTotalWords = 0;
					
					badWordsFoundList.clear();
					bwCount = 0;
					detected = false;
				
					
				
			
			}//end else
		
		
	}//END getResult()
	
}//END CLASS ShowResult