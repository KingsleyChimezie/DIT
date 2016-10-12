/****************************************************************************
 * TITLE: 	-	Programming Assignment 	- 	Abusive text content detector
 * AUTHOR: 	-	Kingsley Chimezie 		- 	C14468272 
 * DATE: 	-	10/04/16
 ****************************************************************************/

package AbusiveTextDetector;
//////////////////////////////////////////// IMPORTS
import java.awt.*;
//////////////////////////////////////////// IMPORTS



public class Main
{

	
	public static void main(String[] args)
	{
		
		//////////////// START UP EXCEPTION HANDLING ////////////////
		EventQueue.invokeLater(new Runnable()
		{
			public void run()
			{
				try
				{
					// load settings for bad words library text file
					BadWordsLibrary setupLib = new BadWordsLibrary();
					setupLib.sortLibFile();
					
					
					// load startup window frame
					StartWindow frame = new StartWindow();
					frame.setVisible(true);
					
				} catch (Exception e)
				  {
						System.out.println("** ERROR LAUNCHING PROGRAM **");
				  }
			}
			
		});
		////////////////////////////////////////////////////////////
		

	}//End Main()
	
	
}//End CLASS Launcher