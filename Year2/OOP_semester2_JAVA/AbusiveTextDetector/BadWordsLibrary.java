/****************************************************************************
 * TITLE: 	-	Programming Assignment 	- 	Abusive text content detector
 * AUTHOR: 	-	Kingsley Chimezie 		- 	C14468272 
 * DATE: 	-	10/04/16
 ****************************************************************************/


package AbusiveTextDetector;
////////////////////////////////////////////IMPORTS
import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;
////////////////////////////////////////////IMPORTS


class BadWordsLibrary
{

	private static File defaultLibFilePath = new File("BadWordsLibrary.txt");						// Set bad words library text file to current working directory
    
	private static ArrayList<String> badWordsList 		= new ArrayList<>();								// Stores words from bad words library file
    private int 			 		 wordCount			= 0; 
	
	
	/*------------------- CONSTRUCTOR -------------------*/
	public BadWordsLibrary()
	{
		System.out.println("<< BAD WORDS LIBRARY: successfull >>\n");									// **TESTER PRINT**
	}
	
	
	
	/*------------------- SORT BAD WORDS LIBRARY FILE -------------------*/
	public void sortLibFile()
	{
		
		/* RESET CHANGEABLE STATIC VARIABLES */
			badWordsList.clear();
			wordCount = 0;
		
			
			
		// THERE IS NO BAD WORDS LIBRARY TEXT FILE
		if(!defaultLibFilePath.exists())																	
		{
			System.out.println("** ERROR: MISSING DEFAULT BAD WORDS LIBRARY TEXT FILE PATH **:");	// **TESTER PRINT**
			System.out.println(defaultLibFilePath.getAbsolutePath());								// **TESTER PRINT**
			
			
			// CREATE A NEW BLANK DEFAULT BAD WORDS LIBRARY TEXT FILE
			try
			{
				
				PrintWriter newLibrary = new PrintWriter(defaultLibFilePath.toString());			// instantiate PrintWriter object
				
				System.out.println("# NEW DEFAULT BAD WORDS LIBRARY TEXT FILE PATH CREATED:\n"		// **TESTER PRINT**
						   + defaultLibFilePath.getAbsolutePath());									//
				
				newLibrary.close();																	// CLOSE FILE
			}
			catch(Exception ex)
			{
				System.out.println("\n** ERROR CREATING NEW BAD WORDS LIBRARY TEXT FILE PATH **:");	// **TESTER PRINT**
			}
		}
		
		
		
		// THERE IS A DEFAULT BAD WORDS LIBRARY TEXT FILE
		else if(defaultLibFilePath.exists())																
		{
			System.out.println("# DEFAULT BAD WORDS LIBRARY TEXT FILE PATH AVAILABLE:\n"			// **TESTER PRINT**
							   + defaultLibFilePath.getAbsolutePath());								//
			
			try
			{
				Scanner sortFile = new Scanner(defaultLibFilePath); 								// scanner object for bad words library file
	            sortFile.useDelimiter("[^A-Za-z0-9'_-]+");											// only accept these char types
				
	            
	            System.out.println("\n# WORDS IN LIBRARY TEXT FILE:");								// **TESTER PRINT**
	            while(sortFile.hasNext())															// read chosen file word by word
            	{
            		String word = sortFile.next();													// store word from bad words library file
            		badWordsList.add(word);															// add word to bad words library file array list
            		wordCount++;																	// Count word
            		
            		System.out.println(word);														// **TESTER PRINT**
            		
            	}
				
	            
	            System.out.println("\n# NUMBER OF WORDS:\t\t" + wordCount);							// **TESTER PRINT**
	            
	            System.out.println("\n# WORDS STORED IN BAD WORDS LIBRARY ARRAYLIST:\n"				// **TESTER PRINT**
						   + badWordsList);
	            
	            
	            RunClicked2 giveToResult = new RunClicked2();										// instantiate ShowResult object to get bad words library list
	            giveToResult.giveBadWordsList(badWordsList, wordCount);								// give a copy of bad words list & words count to ShowResult Class
	            
	            
	            sortFile.close(); 																	// CLOSE FILE 
			
	            
			}catch(Exception e)
			 {
				
				System.out.println("** ERROR READING FILE **");										// **TESTER PRINT**
				
			 }//END catch
			
			
		}//END else if(libFilePath.exists())	
				
	}//END sortLibFile



	/*------------------- GETTERS -------------------*/
	public static File getDefaultLibFilePath()
	{
		return defaultLibFilePath;
	}
    public static ArrayList<String> getBadWordsList()
	{
		return badWordsList;
	}


	/*------------------- setters -------------------*/
	public static void setBadWordsList(ArrayList<String> newBadWordsList)
	{
		BadWordsLibrary.badWordsList = newBadWordsList;
	}
    
   
    
	
}//END CLASS BadWordsLib