__author__ = 'Kingsley Chimezie - C14468272'
'''
TITLE:      Assignment 2
Date:       15/04/16
'''

import  random
import math

# OPTION 3: Paths ######################################################################################
'''This class is used to set paths defined by the user'''
class Paths:

    exit_op2    = False             # used to flag exit or continue option
    paths       = []                # stores all user defined waypoints

    def getPaths(self):
        return self.paths

    def setPaths(self):

     while self.exit_op2 != True:

        try:
            # ENTERING PATH NAME
            name = input(">> Enter path name: ")

            

        except:
            print("\n\n-------------------------------------------------------------------------")
            print("INPUT CANNOT BE PROCESSED, YOU HAVE BEEN BROUGHT BACK TO THE MAIN MENU!")
            print("-------------------------------------------------------------------------\n\n")
            self.exit_op2 = True

        else:
            while True:
                try:
                    # ADD MORE PATHS... USER MUST ENTER YES OR NO (1/2)
                    finished = 0
                    finished = int(input(">> Would you like to add another path? (1 = Yes / 2 = NO): "))

                    # VALID NUMBER, BUT NOT YES OR NO
                    if finished < 1 or finished > 2:
                        while finished != 1 or finished != 2:
                            finished = int(input(">> ERROR! ENTER: 1 for YES / 2 for NO:\t"))

                    # YES
                    elif finished == 1:
                        self.exit_op2 = False
                        print("\n-----------------------------")
                        print("PATH STORED: ", path)
                        print("-----------------------------\n")
                        break

                    # NO
                    elif finished == 2:
                        print("\n\n-------------------------------------------------------------------------")
                        print("PATHS COLLECTIONS: ")
                        print(self.paths)
                        print("-------------------------------------------------------------------------\n\n")
                        self.exit_op2 = True
                        break

                #INVALID NUMBER, NOT YES OR NO
                except:
                    print("\n\nERROR! YOUR LAST INPUT WAS INVALID. PATH HAS BEEN STORED...")
                    print("-------------------------------------------------------------------------")
                    print("PATHS COLLECTIONS: ")
                    print(self.paths)
                    print("-------------------------------------------------------------------------\n\n")
                    self.exit_op2 = True
                    break




# OPTION 2: Waypoints #####################################################################################
'''This class is used to set waypoints defined by the user'''
class Waypoints:

    exit_op2    = False             # used to flag exit or continue option
    waypoints   = []                # stores all user defined waypoints

    def getWaypoints(self):
        return self.waypoints

    def setWaypoints(self):

     while self.exit_op2 != True:

        try:
            # ENTERING WAYPOINT NAME
            name = input(">> Enter waypoint name: ")

            # ENTERING LONGITUDE
            long = float(input(">> Enter Longitude (between: -11.0, -5.0):\t\t"))
            while long < -11 or long > -5:
                long = float(input("\n>> ERROR! ENTER LONGITUDE BETWEEN: -11.0 & -5.0:\t"))

            # ENTERING LATITUDE
            lat = float(input(">> Enter Latitude (between: 51.0, 55.0):\t\t"))
            while lat < 51 or lat > 55:
                lat = float(input("\n>> ERROR! ENTER LATITUDE BETWEEN: 51.0 & 55.0:\t"))

            # ADDING WAYPOINT TO WAYPOINTS LIST
            waypoint = [name, long, lat]            # store entered waypoint
            self.waypoints.append(waypoint)         # store entered waypoint to waypoint list

        except:
            print("\n\n-------------------------------------------------------------------------")
            print("INPUT CANNOT BE PROCESSED, YOU HAVE BEEN BROUGHT BACK TO THE MAIN MENU!")
            print("-------------------------------------------------------------------------\n\n")
            self.exit_op2 = True

        else:
            while True:
                try:
                    # ADD MORE WAYPOINTS... USER MUST ENTER YES OR NO (1/2)
                    finished = 0
                    finished = int(input(">> Would you like to add another waypoint? (1 = Yes / 2 = NO): "))

                    # VALID NUMBER, BUT NOT YES OR NO
                    if finished < 1 or finished > 2:
                        while finished != 1 or finished != 2:
                            finished = int(input(">> ERROR! ENTER: 1 for YES / 2 for NO:\t"))

                    # YES
                    elif finished == 1:
                        self.exit_op2 = False
                        print("\n-----------------------------")
                        print("WAYPOINT STORED: ", waypoint)
                        print("-----------------------------\n")
                        break

                    # NO
                    elif finished == 2:
                        print("\n\n-------------------------------------------------------------------------")
                        print("WAYPOINT COLLECTIONS: ")
                        print(self.waypoints)
                        print("-------------------------------------------------------------------------\n\n")
                        self.exit_op2 = True
                        break

                #INVALID NUMBER, NOT YES OR NO
                except:
                    print("\n\nERROR! YOUR LAST INPUT WAS INVALID. WAYPOINT HAS BEEN STORED...")
                    print("-------------------------------------------------------------------------")
                    print("WAYPOINT COLLECTIONS: ")
                    print(self.waypoints)
                    print("-------------------------------------------------------------------------\n\n")
                    self.exit_op2 = True
                    break



# OPTION 1: CurrentLoc ######################################################################################
''' This class randomly sets the current location of the GPS '''
class  CurrentLoc:

    ''' this function sets the current location '''
    def setCurrentLoc(self):
        long = random.uniform(-11.0, -5.0)
        lat = random.uniform(51.0, 55.0)

        self.CurrentLocation = ( long, lat)

        print("\n\n---------------------------------------------------------------")
        print("Current Location ",
              "\nLONG:\t%.2f " % self.CurrentLocation[0],
              "\nLAT:\t%.2f " % self.CurrentLocation[1])
        print("---------------------------------------------------------------\n\n")

    ''' this function returns the current location that has been set'''
    def getCurrentLoc(self):
        return self.CurrentLocation




# Main ######################################################################################
if __name__ == "__main__":

    current_loc = 0.0

    while True:  # KEEP RUNNING PROGRAM UNTIL EXIT.

        menu_opt = 0      # stores users option input
        print("==================================== MAIN MENU ====================================")
        print("1 - Set & Retrieve The Current Location.")
        print("2 - Set/retrieve Waypoints")
        print("3 - Save/Retrieve Named Paths")
        print("4 - Distance Between Waypoint & Current Location")
        print("5 - Direction Between Waypoint & Current Location")
        print("6 - Exit")

        try:                                                                    # Try - get the user to enter a valid menu option number.
            menu_opt = int(input("\n>> Enter A Menu Option Number: "))
        except:                                                                 # EXCEPTION - invalid menu option number.
            print("\nERROR: Please Enter A Number Between 1 & 6")
            menu_opt = 0
        else:

            #MENU OPTION 1
            if menu_opt == 1:
                op1 = CurrentLoc()                                              # Instantiating menu option 1 object
                op1.setCurrentLoc()                                             # setting current location
                current_loc = op1.getCurrentLoc()                               # storing current location


            #MENU OPTION 2
            elif menu_opt == 2:
                op2 = Waypoints()                                               # Instantiating menu option 2 object
                try:
                    entry = int(input(">> enter '1' to set waypoints / '2' to view waypoints:\t"))

                    if entry == 1:
                        op2.setWaypoints()                                              # set waypoints
                    elif entry == 2:
                        print("-------------------------------------------------------------------------")
                        print("WAYPOINT COLLECTIONS: ")
                        print(op2.getWaypoints())                                       # view current user defined waypoints
                        print("-------------------------------------------------------------------------\n\n")
                    else:
                        print("\n\nERROR! Invalid entry\n\n")

                except:
                    print("\n\nERROR! Invalid entry\n\n")


            #MENU OPTION 3
            elif menu_opt == 3:
                op2 = Paths()                                               # Instantiating menu option 3 object
                try:
                    entry = int(input(">> enter '1' to save a path / '2' to view paths:\t"))

                    if entry == 1:
                        op2.setPaths()                                              # set waypoints
                    elif entry == 2:
                        print("-------------------------------------------------------------------------")
                        print("PATHS COLLECTIONS: ")
                        print(op2.getPaths())                                       # view current user defined waypoints
                        print("-------------------------------------------------------------------------\n\n")
                    else:
                        print("\n\nERROR! Invalid entry\n\n")

                except:
                    print("\n\nERROR! Invalid entry\n\n")


            #MENU OPTION 4
            elif menu_opt == 4:
                print("\n\n 4 entered")


            #MENU OPTION 5
            elif menu_opt == 5:
                print("\n\n 5 entered")


            #MENU OPTION 6
            elif menu_opt == 6:
                print("\n\n PROGRAM TERMINATED")
                exit(0)

            else:
                print("\nERROR: Please Enter A Number Between 1 & 6")