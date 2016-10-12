/****************************************************************************
 * TITLE: 	-	Programming Assignment 	- 	Abusive text content detector
 * AUTHOR: 	-	Kingsley Chimezie 		- 	C14468272 
 * DATE: 	-	10/04/16
 ****************************************************************************/


package AbusiveTextDetector;


////////////////////////////////////////////IMPORTS


class ExitProgram extends StartWindow
{private static final long serialVersionUID = 1L;				//Default Serial version ID

	public ExitProgram()
	{
		System.out.println("____________________________________________________________________");
		System.out.println("<< EXIT PROGRAM: successful >>\n");
		System.out.println("____________________________________________________________________");
		
	}
	
	public void exit()
	{
		System.exit(0);	
		
	}
	
}// END CLASS ExitProgram