/****************************************************************************
 * TITLE: 	-	Programming Assignment 	- 	Abusive text content detector
 * AUTHOR: 	-	Kingsley Chimezie 		- 	C14468272 
 * DATE: 	-	10/04/16
 ****************************************************************************/


package AbusiveTextDetector;
////////////////////////////////////////////IMPORTS
import java.io.File;
import java.util.ArrayList;
import javax.swing.JOptionPane;
////////////////////////////////////////////IMPORTS

class RunClicked3
{

	public RunClicked3()
	{
		
		System.out.println("\n\n<< RUN CLICKED 3 . RUN CLICKED 2 . SHOW RESULTS: successful >>\n");		// **TESTER PRINT**
		
	}
	
	public void showResult(File chosenFile, int badWordsTotal, ArrayList<String> badWordsFound)
	{
		
		//DISPLAY IF THERE IS A BAD WORD
		if(badWordsTotal > 0)
		{
			
			JOptionPane.showMessageDialog
			( null, 
					
				"    FILE PATH CHECKED:              " + chosenFile
			  + "\n\n\n"
			  + "      BAD WORDS FOUND:              " + badWordsFound
			  + "\n\n\n"
			  + "      BAD WORDS TOTAL:              " + badWordsTotal
			  
			  ,"BAD WORDS RESULT:",
			  JOptionPane.INFORMATION_MESSAGE
			);
			
		}
		
		//DISPLAY IF THERE IS NOT A BAD WORD
		else
		{
			JOptionPane.showMessageDialog
			( null, 
					
				"FILE PATH CHECKED:              " + chosenFile
			  + "\n\n\n"
			  + "NO BAD WORDS FOUND"
			  
			  ,"BAD WORDS RESULT:",
			  JOptionPane.INFORMATION_MESSAGE
			);
		}
		
		
		System.out.println(">>> FILE CHECKED:\t" 		+ chosenFile.getName());						// **TESTER PRINT**
		System.out.println(">>> BAD WORDS FOUND:\t"		+ badWordsFound);								//
		System.out.println(">>> BAD WORDS TOTAL:\t" 	+ badWordsTotal);								//
	
	}//END showResult()
	
}// END CLASS ExitProgram


