/****************************************************************************
 * TITLE: 	-	Programming Assignment 	- 	Abusive text content detector
 * AUTHOR: 	-	Kingsley Chimezie 		- 	C14468272 
 * DATE: 	-	10/04/16
 ****************************************************************************/


package AbusiveTextDetector;
////////////////////////////////////////////IMPORTS
import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;
////////////////////////////////////////////IMPORTS


class RunClicked
{

	
	private ArrayList<String> myFileList	 	= new ArrayList<>();						// Stores words from the chosen file
    private int 			  wordCount			= 0;										// used to count the number of words in chosen file
    
	
	
	/*------------------- CONSTRUCTOR -------------------*/
	public RunClicked()
	{
		System.out.println("<< RUN CLICKED: successfull >>\n");								// **TESTER PRINT**
	}
	
	
	
	/*------------------- SORT CHOSEN FILE -------------------*/
	public void sortFile(File myFile)
	{
		
		
		// THERE IS NO FILE PATH
		if(myFile == null)																	
		{
			System.out.println("** NO FILE PATH SELECTED **");								// **TESTER PRINT**
		}
		
		
		// THERE IS A FILE PATH
		else if(myFile != null)																
		{
			System.out.println("# READ FILE PATH:\t\t" + myFile);							// **TESTER PRINT**
			
			
			
			try
			{
				Scanner sortMyFile = new Scanner(myFile);  									// scanner object for chosen file
	            sortMyFile.useDelimiter("[^A-Za-z0-9'_-]+");								// only accept these char types
				
	            
	            System.out.println("\n# WORDS IN CHOSEN FILE:");							// **TESTER PRINT**
	            while(sortMyFile.hasNext())													// read chosen file word by word
            	{
            		String word = sortMyFile.next();										// store word from chosen file
            		myFileList.add(word);													// add word to chosen file array list
            		wordCount++;															// Count word
            		
            		System.out.println(word);												// **TESTER PRINT**
            		
            	}
				
	            
	            System.out.println("\n# NUMBER OF WORDS:\t\t" + wordCount);					// **TESTER PRINT**
	            
	            System.out.println("\n# WORDS IN CHOSEN FILE ARRAYLIST:\n"					// **TESTER PRINT**
						   + myFileList);
	            
	            
	            RunClicked2 processResult = new RunClicked2();								// instantiate (processResult) object & access giveChosenFileList()
	            processResult.giveChosenFileList(myFile, myFileList, wordCount);			// give a copy of the chosen file's path, list & words counted
	            
	            sortMyFile.close(); 														// CLOSE FILE 
			
	            
			}catch(Exception e)
			 {
				
				System.out.println("** ERROR READING FILE **");								// **TESTER PRINT**
				
			 }//END catch
			
		}//END else if
		
	}//END sortFile
	
}//END CLASS RunClicked