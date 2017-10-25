#!/bin/bash


# C14468272 - Kingsley Chimezie
# DT211C/4 - Dublin Institute of Technology
# Systems Integration - Assignment 1
# 25 October 2017

NOTICE="WELCOME "$USER

while :

    # These two functions were implemented for DRY purposes
    function line_brk() {
        echo "-----------------------------------------------------"
        echo
    }
    function continue() {
        echo
        echo
        echo "- Press enter to continue... "
    }
    
    # Function for logout
    function logoff() {
        pkill -KILL -u $USER
    }
    

    do
        clear
        echo NOTICE: "$NOTICE"
        line_brk
        echo
        echo "Enter 'pw' to print all info of current working directory."
        echo "Enter 'ifc' to print all info of first network interface (eth0)."
        echo "Enter 'dt' to print unformatted date & time (+%Y%m%d%H%M%S)"
        echo "Enter 'ud' to print userID, groupID, username, groupname, iNode"
        echo "Enter 'c' Change NOTICE message"
        echo "Enter 'q' to logout"
        echo
        echo -n "Enter Option: "

        read opt

        case $opt in

            pw)line_brk
                pwd -LP
                continue
                read enterKey;;

            ifc)line_brk
                ifconfig -a eth0
                continue
                read enterKey;;

            dt)line_brk
                date +%Y%m%d%H%M%S
                continue
                read enterKey;;

            ud)line_brk
                INODE=$(ls -id -i /home) 
                echo "$UID,$(id -g),$USER,$(id -g -n),${INODE//[!0-9]/}"
                continue
                read enterKey;;

            c)
                read -p "enter custom note: " msg
                NOTICE=$msg
                continue
                read enterKey;;

            q)
                clear
                echo "Logged out as user: $USER"
                logoff
                read enterKeyy;;
                
            *)line_brk
                echo "Invalid option!";
                continue
                read enterKey;;

    esac #endcase

done #end while