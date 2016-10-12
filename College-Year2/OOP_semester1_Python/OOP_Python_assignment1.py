__author__ = 'Kingsley Chimezie - C14468272'


import csv


###################################### display() ######################################
''' This function is used to find out and display the best and worst months
'''
def display(cal_data, max_input):
    print("\n")


    A = cal_data["AvgPrices"]       # Store the average price
    M = cal_data["Months"]          # Store the Months
    count = 0                       # Loop counter
    line_num = 0                    # Used to display line num


    #ZIP the Average prices and Month dates
    price_month_zipped = dict(zip(A, M))


    #Sort zip by Average prices (lowest to highest)
    price_month = sorted(price_month_zipped.items())


    #amount of prices+months combination (100)
    data_size = len(price_month)-1                      # I took away 1 because indexing starts at 0



    print("\n_______________________________________\n")

    #DISPLAYING WORST 6 MONTHS
    count, line_num = 0, 1

    if max_input is 1:
        print("WORST MONTH:")
    else:
        print("WORST %s MONTHS:" % max_input)

    while count < max_input:
        print("%i\t" % line_num, end="")
        print(price_month[count])
        count += 1
        line_num += 1

    print("\n_______________________________________\n")

    #DISPLAYING BEST 6 MONTHS
    count, line_num = data_size, 0

    if max_input is 1:
        print("BEST MONTH:")
    else:
        print("BEST %s MONTHS:" % max_input)

    while count > data_size-max_input:
        count -= 1
        line_num += 1
        print("%i\t" % line_num, end="")
        print(price_month[count+1])

    print("\n_______________________________________\n")




#################################### calculate() ####################################
'''This function performs the main calculations
   needed to meet the assignment requirements. i.e calculate formulae given.
'''
def calculate(csv_doc):             # pass the read contents of the CSV file


    # VARIABLES #------------------------------------------------------------------------
    line_num = 0					# Used to count lines
    end_month_line = 0              # Stores the line number of the end of the month average

    csv_Date = 0					# Stores the column number for Date
    csv_Volume = 5					# Stores the column number for Volume
    csv_Adj_Close = 6				# Stores the column number for Adjusted Close

    Vol_Total = 0					# Used to sum up the volume total
    Adj_Total = 0.0					# Used to sum up the adjusted close total
    avg_price_total = 0.0           # Used to sum up the average price total

    daily_avg_list = []             # Stores the daily average price per month
    monthly_dates = []              # Stores the date of a month           (format:  mm/yyyy)
    monthly_avg_prices = []         # Stores the average price for a month (format:  0.00)
    # END VARIABLES #------------------------------------------------------------------------



    pre_date = (csv_doc[0][csv_Date])[:]    # Set to latest date in the CSV in 'mm/yyyy' format

    for row in csv_doc:                     # Read the list of the CSVs contents line by line (aka day by day)


        current_date = row[csv_Date][3:]    # Store to the current date on the line (mm/yyyy format)



        '''[FORMULAE] Summing up the average price total using formulae:
            ((v1*c1)+(v2*c2)+(v3*c3)+(v4*c4)...+(vn*cn)) / (v1+v2+v3+v4...+vn)
            where vi is the volume for day i and ci is the adjusted close price for day i.

            The formulae below increments and appends all necessary variables day by day
            The data of the variables used, will reset to the data of a new month.
        '''
        Vol_Total += int(row[csv_Volume])                                               # Summing up the volume total
        Adj_Total += float(row[csv_Adj_Close])                                          # Summing up the adjusted close total

        avg_price_total += float((int(row[csv_Volume]) * float(row[csv_Adj_Close])))    # ((v1*c1)+(v2*c2)+(v3*c3)+(v4*c4)...+(vn*cn))
        avg_price = (avg_price_total / Vol_Total)                                       # / (v1+v2+v3+v4...+vn)

        daily_avg_list.append(avg_price)                                                # Store the average price at this day of the month
        # END [FORMULAE] ****************************************************************



        '''[NEW MONTH] If previous & current date don't match, it IS a new month:
                (1) Stores the average price for previous month
                (2) reset variables used for calculations to the start of the new month's data
        '''
        if not(pre_date in current_date):


            ''' [DON'T STORE FIRST ITERATION] previous date (11/2012) & current date (NULL) don't match.
                However, it is NOT a new month yet, it is the first month.
                From the next entry (10/2012) onwards, it will be a new month
            '''
            if line_num > 0:


                # (1) Stores the average price for previous month
                end_month_line = line_num-1                                                 # Store the line number for the end of the previous month
                monthly_avg_prices.append(round(daily_avg_list[end_month_line], 2))         # Stores the average price for the end of the previous month
                monthly_dates.append(pre_date)
            # END [DON'T STORE FIRST ITERATION] *****************************************


            # (2) reset variables used for calculations to the start of the new month's data
            Vol_Total = int(row[csv_Volume])
            Adj_Total = float(row[csv_Adj_Close])
            avg_price_total = float((int(row[csv_Volume]) * float(row[csv_Adj_Close])))
            pre_date = current_date
        # END [NEW MONTH] ***************************************************************


        line_num += 1                       # line number increments
    # END FOR ****************************************************************************


    ''' [FINAL STORE] Because there are no more new months:
        Stores the last average month date and the last average price to their lists
        Store both lists in a monthly data dictionary
    '''
    monthly_dates.append(pre_date)                                                  # List of all the months dates        (08/2004 - 11/2012)
    monthly_avg_prices.append(round(avg_price, 2))                                  # List of all months average prices   (08/2004 - 11/2012)
    monthly_data = {"Months": monthly_dates, "AvgPrices": monthly_avg_prices}       # Dictionary of all months dates and average prices
    return monthly_data



#################################### readfile() ####################################
''' This function is used to open and read the CSV file'''
def readfile():

    fp = open('googlePrices.csv','r')		# opening the file
    csv_doc = list(csv.reader(fp))[1:]		# read the CSVs Content and store as a list (Excluding column headings)
    return csv_doc						    # Return the list



####################################### MAIN #######################################
if __name__ == '__main__':


    ''' Try get the user to enter a number between 1 and 100
        because there are 100 months. Error if the entry is not between 1 and 100
    '''
    try:
        user_input = int(input("\nHow Many Best And Worst Month(s) Would You Like To View?\n"
                                "Enter A Number Between 1 And 100: "))

        if not user_input in range(1,101):
            exit(1)

    except:
        print("\nPlease Enter A Number Between 1 & 100")
        exit(1)



    csv_data = readfile()					    # Get data from the CSV file (googlePrices.csv)
    calculation_data = calculate(csv_data)		# Use the CSVs data to make the required calculations.
    display(calculation_data, user_input)      # Display the calculations