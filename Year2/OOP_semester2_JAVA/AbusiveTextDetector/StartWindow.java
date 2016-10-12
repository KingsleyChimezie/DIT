/****************************************************************************
 * TITLE: 	-	Programming Assignment 	- 	Abusive text content detector
 * AUTHOR: 	-	Kingsley Chimezie 		- 	C14468272 
 * DATE: 	-	10/04/16
 ****************************************************************************/


package AbusiveTextDetector;
////////////////////////////////////////// IMPORTS
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;

import javax.swing.*;
import javax.swing.border.BevelBorder;
import javax.swing.border.TitledBorder;
////////////////////////////////////////// IMPORTS



class StartWindow extends JFrame implements ActionListener
{private static final long serialVersionUID = 1L;											// Default Serial version ID


	
	// ATTRIBUTES
	private File myFile;
	
	
	private JPanel 			panel1, panel2, panel3;
	private JButton 		btnRun, btnBrowse, btnAdd, btnRemove, btnExit;
	private JTextField 		dirPath, badWords;
	private JLabel			lblCommaInstruct;

	
	
	//MAIN CONSTRUCTOR
	public StartWindow()
	{
		
		
		/*-------------------------------------- JFRAME --------------------------------------*/
		setTitle("Abusive Text Detector - by Kingsley Chimezie");
		setSize(600, 600);
		setLocationRelativeTo(null);
		setResizable(false);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		getContentPane().setLayout(null);
		

	

		/*-------------------------------------- JPANEL1 --------------------------------------*/
		//PANEL 1 SETUP
		panel1 = new JPanel();																		// Instantiating object
		panel1.setBorder(new TitledBorder(null, "Check A Text File For Bad Words: "));				// setting panel border and text
		panel1.setBounds(10, 30, 574, 100);															// setting panel boundaries
		getContentPane().add(panel1);																// adding content pane to panel
		panel1.setLayout(new BorderLayout(0, 0));													// setting layout to border layout
		add(panel1);
		
			
			/*--- JBUTTON_BROWSE ---*/
			btnBrowse = new JButton("Browse...");
			btnBrowse.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
			btnBrowse.addActionListener(this);														// Listen for action
			panel1.add(btnBrowse, BorderLayout.CENTER);
			
			
			/*--- JBUTTON_RUN ---*/
			btnRun = new JButton("Run");
			btnRun.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
			btnRun.addActionListener(this);															// Listen for action
			panel1.add(btnRun, BorderLayout.EAST);
			
			
			/*--- JTEXT_FIELD_DIR_PATH ---*/
			dirPath = new JTextField();
			dirPath.setEditable(false);
			dirPath.setColumns(10);
			dirPath.addActionListener(this);														// Listen for action
			panel1.add(dirPath, BorderLayout.SOUTH);												//Add to panel 1: align bottom

			
	
		/*-------------------------------------- JPANEL2 --------------------------------------*/
		//PANEL 2 SETUP
		panel2 = new JPanel();
		panel2.setAutoscrolls(true);
		panel2.setBorder(new TitledBorder(null, "Edit Abusive Word Library [Add or Remove]: "));
		panel2.setBounds(10, 160, 574, 250);
		panel2.setLayout(null);
		getContentPane().add(panel2);
		add(panel2);
		
			
			/*--- JLABEL_ADD_REMOVE_INSTRUCTION ---*/
			lblCommaInstruct = new JLabel("Seperate your words with a space or comma.");
			lblCommaInstruct.setBounds(150, 60, 280, 40);
			panel2.add(lblCommaInstruct);
			
			
			/*--- JBUTTON_ADD ---*/
			btnAdd = new JButton("Add");
			btnAdd.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
			btnAdd.setBounds(10, 114, 89, 23);												// setting button bounds
			btnAdd.addActionListener(this);													// Listen for action
			panel2.add(btnAdd);																// add add button to panel 2
			
			
			/*--- JTEXT_FIELD_BAD_WORDS ---*/
			badWords = new JTextField();													// Instantiating Object
			badWords.setBounds(109, 92, 356, 66);											// text field boundary
			badWords.setColumns(10);														// set column to 10px
			badWords.addActionListener(this);												// Listen for action
			panel2.add(badWords);															// add text field to panel3
			
			
			
			/*--- JBUTTON_REMOVE ---*/	
			btnRemove = new JButton("Remove");												// Instantiating "Remove" JButton object
			btnRemove.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));			// Set cursor on REMOVE button to hand
			btnRemove.setBounds(475, 114, 89, 23);											// setting bound area for panel 2
			btnRemove.addActionListener(this);												// Listen for EXIT button action
			panel2.add(btnRemove);															// add remove button to panel 2
		
	
	/*-------------------------------------- JPANEL3 --------------------------------------*/
		panel3 = new JPanel();																// Instantiating "Panel" JPanel object
		panel3.setBorder(new BevelBorder(BevelBorder.RAISED));								// setting raised bevel to panel 3
		panel3.setBounds(10, 448, 574, 100);												// setting bound area for panel 3
		getContentPane().add(panel3);														// adding content pane to panel 3
		panel3.setLayout(new BorderLayout(0, 0));											// setting panel 3 layout to null
		add(panel3);																		// Panel 3 added to Start Window JFrame
		
		
			/*--- JBUTTON_EXIT ---*/
			btnExit = new JButton("EXIT");													// Instantiating "EXIT" JButton object
			btnExit.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));				// Set cursor on exit button to hand
			btnExit.addActionListener(this);												// Listen for EXIT button action
			panel3.add(btnExit, BorderLayout.CENTER);										// set border layout + add to panel3

		
	}
	
	
	/*****************************  ACTIONS PERFORMED OVERRIDE  *****************************/
	@Override
	public void actionPerformed(ActionEvent e)
	{

		if (e.getSource() == btnBrowse)
		{System.out.println("\n\n/*------------------ BROWSE BUTTON CLICKED ------------------*/");									// **TESTER PRINT**
			
			
			/* Instantiate BrowseClicked Object & access runFileChooser() */
				BrowseClicked getFile = new BrowseClicked();
				getFile.runFileChooser();
				
				
			/* if a selected file path exists, display in dirPath */
				if(getFile.getFilePathExists() != null)
				{	
					myFile = getFile.getFilePathExists();
					dirPath.setText(myFile.getAbsolutePath());
				}
				
		}//END btnBrowse
		
		
		
		else if (e.getSource() == btnRun)
		{System.out.println("\n\n/*------------------- RUN BUTTON CLICKED -------------------*/");									// **TESTER PRINT**
			
			/* Instantiate RunClicked Object & access sortFile() */
				RunClicked runFile = new RunClicked();
				runFile.sortFile(myFile);
		
		}//END btnRun
		
		
		
		else if (e.getSource() == btnAdd)
		{System.out.println("\n\n/*------------------- ADD BUTTON CLICKED -------------------*/");									// **TESTER PRINT**
		
			String input = badWords.getText();
			
			/* Instantiate EditBadWords Object & access addBadWords() */
				AddRemoveWords add = new AddRemoveWords();
				add.addBadWords(input);
		
				//CLEAR TEXTFIELD
				badWords.setText("");
				
		}//END btnAdd
		
		
		
		else if (e.getSource() == btnRemove)
		{System.out.println("\n\n/*------------------- REMOVE BUTTON CLICKED -------------------*/");									// **TESTER PRINT**
			
			String input = badWords.getText();
			
			/* Instantiate EditBadWords Object & access removeBadWords() */
				AddRemoveWords remove = new AddRemoveWords();
				remove.removeBadWords(input);
			
				//CLEAR TEXTFIELD
				badWords.setText("");
			
		}//END btnRemove
		
		
		
		else if (e.getSource() == btnExit)
		{System.out.println("\n\n/*------------------- EXIT BUTTON CLICKED -------------------*/");									// **TESTER PRINT**
			
		
			/* Instantiate ExitProgram Object & access exit() */
				ExitProgram exitEvent = new ExitProgram();
				exitEvent.exit();
		
		}//END btnExit
		
		
		/*------------------- OTHERS -------------------*/
		else
		{System.out.println("This action does not have any further functionalities.");
		
		
		}
		
		
	}//end actionPerformed()


}//End CLASS StartWindow