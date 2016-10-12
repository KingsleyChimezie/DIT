/****************************************************************************
 * TITLE: 	-	Programming Assignment 	- 	Abusive text content detector
 * AUTHOR: 	-	Kingsley Chimezie 		- 	C14468272 
 * DATE: 	-	10/04/16
 ****************************************************************************/

package AbusiveTextDetector;
//////////////////////////////////////////IMPORTS
import javax.swing.JFileChooser;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.io.File;
//////////////////////////////////////////IMPORTS

 
public class BrowseClicked extends JFileChooser
{private static final long serialVersionUID = 1L;												// Default Serial version ID
	
	
	//CLASS VARIABLES
	private File filePathExists;
	
	
	
	/*------------------- CONSTRUCTOR -------------------*/
	public BrowseClicked()
	{
      System.out.println("<< BROWSE CLICKED: successfull >>\n");									// **TESTER PRINT**
    }
	


	/*------------------- RUN FILE CHOOSER -------------------*/
	public void runFileChooser()
	{
		
		File currentDir;																		// stores the current working directory when file chooser opens
		File filePath;																			// stores the path for a the selected file
		int flag = 1; 																			// used to check whether a user entered an existing file path
		
		
	
			/* Filter the file chooser to only text files */
			FileNameExtensionFilter fileFilter = new FileNameExtensionFilter(".txt", "txt");
			setFileFilter(fileFilter);
			//
			
			
			
		while(flag == 1)																		// while file does not exist
		{	
			currentDir = new File(System.getProperty("user.dir"));								// Get current working directory
			System.out.println("# CURRENT DIR:\t\t\t" + currentDir);							// **TESTER PRINT**
		   
			
			setCurrentDirectory(currentDir);													// set file chooser to current directory
			int selected = showOpenDialog(this);												// open file chooser on current directory + store the selected file's code
		   
		   
			
			if (selected == APPROVE_OPTION)														// user chose a file from file chooser
			{
				filePath = getSelectedFile();													// store the path for the selected file
				System.out.println("# SELECTED FILE:\t\t" + filePath.getAbsolutePath());		// **TESTER PRINT**
	
				if (filePath.exists() == false)													// path for the selected file does not exist
				{
					System.out.println("\n** YOUR SELECTION IS INVALID! **");					// **TESTER PRINT**
					flag = 1; 																	// continue loop: invalid selection
				}
				else if(!filePath.getName().toLowerCase().endsWith(".txt"))						// selected file is not a text file
				{
					System.out.println("\n** PLEASE SELECT A TEXT FILE! **");					// **TESTER PRINT**
				}
				
				else if (filePath.exists() == true) 											// path for the selected file exists
				{
					if(filePath.getName().toLowerCase().endsWith(".txt"))						// selected file is a text file
					{
					    filePathExists = filePath;												// storing selected file path				
					    System.out.println("\n** YOUR SELECTION IS VALID **");					// **TESTER PRINT**
					    System.out.println("# STORED SELECTED FILE PATH:\t"						// **TESTER PRINT**
		    					+ filePathExists.getAbsolutePath());
					    flag = 0;																// exit loop: valid selection
					}
				}
				
			}//END if APPROVE_OPTION
			
			else																				// user canceled or closed file chooser		
			{
				System.out.println("\n** NO SELECTION MADE **");								// **TESTER PRINT**
				flag = 0;																		// exit loop: nothing was chosen
				
			}
		
		}//while
		
	}// END runFileChooser()

	
	
	
	/*------------------- GETTERS -------------------*/
	public File getFilePathExists()
	{
		return filePathExists;
	}
	
	
}//END CLASS BrowseClicked