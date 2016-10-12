#!/bin/sh

# Kingsley Chimezie - C14468272
# DT211C Computer Science - Year 2
# Operating Systems & Systems Adminstration
# DATE: 19/01/16


# Adding a loading effect using sleep command
clear
echo ">> Loading Menu..."
sleep 1

#This function is used to hold the result of a seleceted option until the user would like to continue
halt ()
{
    echo "\n\n===============================================================\n\n"
    echo "Press <Return Key> to continue..."
    read x      #wait for an input
}

# While to loop the menu untill the user selects exit
while true
	do
		clear   # Clear screen
		echo "================================= SELECT A MENU OPTION =================================\n"
        echo "(a)       Display username, date and time."
        echo "(b)       Use vi or another editor to edit a file."
        echo "(c)       Show your current shell, home directory, and operating system type."
        echo "(d)       Show your current path setting and current working directory."
        echo "(e)       Show the number of users currently logged."
        echo "(f)       Show the OS version, release number, and kernel version."
        echo "(g)       Show the following:  CPU information, processor model name, speed, uptime."
        echo "(h)       Display all the directories in PATH in an easy-to-read way, i.e., one line per directory."
        echo "(i)       Display the information from the ls –l command in a more user-friendly way."
        echo "(j)       Display a summary of the disk space usage for each directory argument."
        echo "(k)       Exit\n"

        echo "PLEASE ENTER OPTION (a - k) >> \c"            # User input
        read option
        echo "===============================================================\n"
        
        # case is used to switch on a function corresponding to user's selected option
		case $option in
            
            # Display username, date and time
   			a)  
                echo "YOUR USERNAME:\t\t\c"                               # displaying username
                whoami
                echo
                
                echo "THE CURRENT DATE & TIME:\t $(date)"              # displaying date and time
                halt;;
            
			
            # Use vi or another editor to edit a file
            b)  
                echo "Enter an editor (e.g. vi) >>\t\t\t \c"
                read editor                                                 #read editor name
                echo "What would you like to call the file? >>\t \c"
                read new_file                                               # read name of the file
                echo "\n\nOpening editor..."
                sleep 1                                                     #wait 1 dec
                $editor $new_file                                           # print and open editor and file
                halt;;
            
			
            # Show your current shell, home directory, and operating system type
            c)  
                echo "CURRENT SHELL:\t\t $echo $SHELL"                       # Print current shell
                echo "HOME DIRECTORY:\t\t $echo $HOME"                       # Print home directory
                echo
                
                echo "OS TYPE:"
                echo $OSTYPE                                                     # Print OS type
                halt;;  
            
			
            # Show your current path setting and current working directory
            d)  
                echo "CURRENT PATH SETTING:\t\c "                            # Print Path setting
                echo $PATH
                echo
                
                echo "CURRENT WORKING DIRECTORY:\t\c "                         # Print current working directory
                pwd
                halt;;  
            
			
            # Show the number of users currently logged
            e)  
                echo "USERS INFORMATION:\t\t"
                echo
                
                w                                                            # Print users info
                halt;;  
            
			
            # Show the OS version, release number, and kernel version
            f)  
                echo "OS Version:\t\t\c"
                lsb_release -c                                               # Print the OS codename.
                echo "Release Number:\t\t\c"
                lsb_release -r                                               # Print the OS release
                echo
                
                echo "Kernal Version:"
                uname --v                                                    # Print the kernel version.
                halt;;  
            
			
            # Show the following:  CPU information, processor model name, speed, uptime
            g)  
                echo "CPU INFO:"
                lscpu                                                        # Print CPU information.
                echo
                echo
				
				
                echo "CPU MODEL NAME:"
                cat /proc/cpuinfo | grep model name                          # Print processor model name
                echo
                echo
				
				
                echo "CPU SPEED:"
                lscpu | grep MHz                                             # Print processor speed
                echo
                echo
				
				
                echo "CPU UPTIME:"
                ls -l /proc/uptime                                           # Print processor uptime
                halt;;  
            
			
            # Display all the directories in PATH in an easy-to-read way, i.e., one line per directory
            h)  
                # This case will check for a new directory and break to a newline if there is a new directory
                old=$IFS                                                    
                IFS=:                                                       
                printf "%s\n" $PATH                                         
                IFS=$old                                                    
                halt;;  
            
			
            # Display the information from the ls –l command in a more user-friendly way
            i)  
                ls -l
                halt;;  
            
			
            # Display a summary of the disk space usage for each directory argument
            j)  
                echo "FILE SYSTEM DISK SPACE USAGE INFO:"
				echo
                df -a                                                         # Print disk space usage info
                halt;;  
                
				
            # Exit
            k)
                echo "Exiting..."
                echo "\n\n===============================================================\n\n"
                sleep 1                 # wait 1 sec for exiting... loading effect
                clear
                exit 1;;
            
                
            # Error checking for a valid input
            *) 
                
                echo "ERROR! Please select option between: a-k";
                halt;;
              
        esac    # End Case

done                        