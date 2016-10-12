/****************************************************************************
 * TITLE: 	-	Programming Assignment 	- 	Abusive text content detector
 * AUTHOR: 	-	Kingsley Chimezie 		- 	C14468272 
 * DATE: 	-	10/04/16
 ****************************************************************************/


package AbusiveTextDetector;
////////////////////////////////////////////IMPORTS
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import javax.swing.JOptionPane;
////////////////////////////////////////////IMPORTS

class AddRemoveWords extends BadWordsLibrary
{

	
	/*------------------- CONSTRUCTOR -------------------*/
	public AddRemoveWords()
	{
		System.out.println("<< EDIT BAD WORDS: successfull >>\n");													// **TESTER PRINT** 
	}

	
	
	/*------------------- ADD BAD WORD -------------------*/
	public void addBadWords(String words)
	{
		
		if(words.isEmpty())																							// NO WORDS ENTERED
		{
			JOptionPane.showMessageDialog
			(null, "PLEASE ENTER SOME TEXT\n\n", "ERROR", JOptionPane.ERROR_MESSAGE);								// show error message
		}
		else
		{
			try
			{	
				
				
				FileWriter fw = new FileWriter(getDefaultLibFilePath().getAbsolutePath(), true);					// file writer
				BufferedWriter bw = new BufferedWriter(fw);															// file buffer
				
				bw.append(words); bw.newLine();																		// add words to bad words file to a newline
				bw.close();																							// CLOSE FILE
				
				
				
				JOptionPane.showMessageDialog																		// show words added	
				(null, "YOU ADDED:\n\n" + words, "WORDS ADDED TO LIBRARY", JOptionPane.INFORMATION_MESSAGE);		//		
				
				

				System.out.println("# WORDS ADDED TO BAD WORDS LIBRARY:\t" + words);									// **TESTER PRINT**
				
			
				System.out.println("\n\n\n\n<<<<< LIBRARY REFRESHED >>>>>");
				sortLibFile();																						// REFRESH BAD WORDS LIBRARY
				
				
			} catch (IOException e)
				{
				
					System.out.println("** ERROR! UNABLE TO ADD TO BAD WORDS LIBRARY **");
				
				}
			
			
		}//END else
			
	}//END addBadWords()
	
	
	
	/*------------------- REMOVE BAD WORD -------------------*/
	public void removeBadWords(String words)
	{
		

		if(words.isEmpty())																						// NO WORDS ENTERED
		{
			JOptionPane.showMessageDialog
			(null, "PLEASE ENTER SOME TEXT\n\n", "ERROR", JOptionPane.ERROR_MESSAGE);							// show error message
		}
		
		else
		{
			
			
			/**************************************************************************************************************
			 * REFERENCE: 		http://stackoverflow.com/questions/5360209/how-to-delete-a-specific-string-in-a-text-file
			 * BY:				BalusC
			 * DATE:			Mar 19 '11 at 5:16
			 * 
			 * The technique used in the following try function has been referenced above.
			 * The code enabled me to remove words from the bad words library.
			 * 
			 * HOW IT WORKS:	A copy of the original library is created. The original file is read line by line,
			 * 					if a line contains a string entered, the string on that line is removed from the original file
			 * 					and the line is written to the copy file. When the end of file is reached,
			 * 					the original file is deleted and the copy file takes the original name. Thus making it
			 * 					the new original name.
			 *************************************************************************************************************/
				try
				{	
					File originalFile = getDefaultLibFilePath();
					File copyFile = File.createTempFile("tempFile", ".txt", originalFile.getParentFile());
					String Remove = words;
					
					
					BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(originalFile)));
					
					PrintWriter writer = new PrintWriter(new OutputStreamWriter(new FileOutputStream(copyFile)));
					
					for (String line; (line = reader.readLine()) != null;) 
					{
					    line = line.replace(Remove, "");
					    
					    writer.println(line);
					}
					
					reader.close();
					writer.close();
					
					originalFile.delete();
					copyFile.renameTo(originalFile);
					
					
				} catch (IOException e)
				{
					
					System.out.println("** ERROR! UNABLE TO REMOVE FROM BAD WORDS LIBRARY **");
					
				}
			
			
			
			JOptionPane.showMessageDialog																		// show words removed
			(null, "YOU REMOVED:\n\n" + words, "WORDS REMOVED FROM LIBRARY", JOptionPane.INFORMATION_MESSAGE);	//	
			
			
			
			System.out.println("\n\n\n\n<<<<< LIBRARY REFRESHED >>>>>");
			sortLibFile();																						// REFRESH BAD WORDS LIBRARY
			
			
			//RESETS
			//list.clear();
			//newList.clear();
		

		}//END else

		
	}//END removeBadWords()
	
}//END class
