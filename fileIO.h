/*
DO NOT MODIFY ANY PART OF THE CODE EXCEPT BETWEEN THE COMMENTS "WRITE YOUR CODE HERE" 
AND "END OF YOUR CODE"

Problem Statement: WAP to manage a linked list of `FlightInfo` structures to store flight details and manage flight operations such as adding, deleting, and displaying flight information. DO NOT USE ARRAYS, IF FOUND USING ARRAYS YOU WILL GET ZERO IN THIS LAB + GRADE PANELTY.

Instructions:
- You are required to declare and manage a linked list of `FlightInfo` structures to store flight details and manage operations.
- Use the enumerated type `Status` to represent flight status, which should be input by the user as:
   - `0` for `security_check`
   - `1` for `boarding`
   - `2` for `departed`

STRUCTURE:
Name of the structure: FlightInfo
MEMBERS:
- flightID: alpha-numeric of up to 9 characters
- departureTime: HH MM SS (assume appropriate data type based on description below, but it must be an array also HH should be between 0 and 23 and MM and SS must be between 0 and 59)
- arrivalTime: HH MM SS (assume appropriate data type based on description below, but it must be an array)
- departureAirport: 3-letter airport code
- arrivalAirport: 3-letter airport code
- numPassengers: the number of passengers on that flight
- flightStatus: Enum of three possible values (security_check, boarding, departed) (Note: may be a good idea to ceate a small function to print correspondig string to each status)
- next: A pointer to the next `FlightInfo` structure (used for linked list)

Purpose of main():
1. It should display a menu-driven interface that allows the user to enter the menu option until user enters 8 (option to exit the program):
   - If user enters option 1-6 program shoudl call appropriate UDF and perform the desired operation.
   - If the user enter option number 7, you rprogmra should display the details of all flights in the linked list in a desired format (look at the desired input/output, and by now you should know about it).
   - If user enters option number 8, your program should Exit
   - For any option other than opton 8, program should perform the operation and again ask for the user input from the menu
   
   
You can display the menu shown below by calling already implemented function displayMenu(). 
After displaying the menu, you should ask for the user input to make a choice of the operation to perform.

Flight Management System:
1. Add Flight at Beginning
2. Add Flight after Flight ID
3. Add Flight at End
4. Delete a Flight by ID
5. Delete First Flight
6. Delete Last Flight
7. Display All Flights
8. Exit

You must implement the following UDFs, all to be called from `main()` only:

UDF 1 specifications:
Purpose: Adds a flight at the beginning of the linked list (reember this is a spacial case!!! should see more stars!!!!).
name: addFlightAtBeginning
arguments: 
- argument 1: A pointer (think about it, what kind of pointer shoudl thsi be) to the head of the linked list
- argument 2: The flight information entered by the user (structure type)

UDF 2 specifications:
Purpose: Adds a flight after a specified flight ID.
name: addFlightAfterFlightNo
arguments: 
- argument 1: A pointer to the head of the linked list
- argument 2: The flight ID after which the new flight should be added
- argument 3: The flight information entered by the user (structure type)

UDF 3 specifications:
Purpose: Adds a flight at the end of the linked list.
name: addFlightAtEnd
arguments:
- argument 1: A pointer to the head of the linked list
- argument 2: The flight information entered by the user (structure type)

UDF 4 specifications:
Purpose: Deletes a flight by flight ID.
name: deleteFlight
arguments:
- argument 1: A pointer to the head of the linked list
- argument 2: The flight ID to delete (string)

UDF 5 specifications:
Purpose: Deletes the first flight in the linked list.
name: deleteFirstFlight
arguments: A pointer (think about it, what kind of pointer shoudl thsi be) to the head of the linked list

UDF 6 specifications:
Purpose: Deletes the last flight in the linked list.
name: deleteLastFlight
arguments: A pointer to the head of the linked list

UDF 7 specifications:
Purpose: Displays all flight details from the linked list.
name: displayAllFlights
arguments: A pointer to the head of the linked list

UDF 8 specifications:
Purpose: this UDF should get user inputs for the argument passed.
name: choose appropriate name
arguments: structure pointer
return type: void

UDF 9 specifications:
Purpose: this UDF should print all the details of the linked list
name: choose appropriate name
arguments: 
argument 1: A pointer to the head of the linked list
return type: void

UDF 10 specifications:
Purpose: this UDF should save all the linksed list data in human readable (Text) format to the file named mydata.txt
name: choose appropriate name
arguments: 
argument 1: A pointer to the head of the linked list
return type: void

UDF 11 specifications:
Purpose: this UDF should read all data from the file named mydata.txt (note: you used UDF 10 to stoer the data in this file, with this UDF you will read those saved data) and create linked list from that data as you read from the file
name: choose appropriate name
arguments: 
argument 1: A pointer (think about it, what kind of pointer shoudl thsi be) to the head of the linked list, you can add the date to begining or end of the list as you wish
return type: void

UDF 12 specifications:
Purpose: this UDF should save all the linksed list data in binary format to the file named mydata.bin
name: choose appropriate name
arguments: 
argument 1: A pointer to the head of the linked list
return type: void

UDF 13 specifications:
Purpose: this UDF should read all data from the file named mydata.bin (note: you used UDF 12 to stor3 the data in this file, with this UDF you will read those saved data) and create linked list from that data as you read from the file
name: choose appropriate name
arguments: 
argument 1: A pointer (think about it, what kind of pointer shoudl thsi be) to the head of the linked list, you can add the date to begining or end of the list as you wish
return type: void

UDF 14 specifications:
Purpose: this UDF should delete all the nodes in the linked list and free memory for all of them
name: choose appropriate name
arguments: 
argument 1: A pointer (think about it, what kind of pointer shoudl thsi be) to the head of the linked list, you can add the date to begining or end of the list as you wish, you can reuse existing functions or write additional ones as you wish
return type: void

Note: If required you can craete any number of additional UDFs to make your code more modular and manageable
=======================================================================================================================

Expected Program Input Example:

Flight Management System:
1. Add Flight at Beginning
2. Add Flight after Flight ID
3. Add Flight at End
4. Delete a Flight by ID
5. Delete First Flight
6. Delete Last Flight
7. Display All Flights
8. Exit
Enter your choice: 1

Enter Flight ID: A123
Enter Departure Time (HH MM SS): 12 30 00
Enter Arrival Time (HH MM SS): 15 45 00
Enter Departure Airport (3-letter code): JFK
Enter Arrival Airport (3-letter code): LAX
Enter Number of Passengers: 150
Enter Flight Status (0 = security_check, 1 = boarding, 2 = departed): 1
Flight added at the beginning successfully!

Flight Management System:
1. Add Flight at Beginning
2. Add Flight after Flight ID
3. Add Flight at End
4. Delete a Flight by ID
5. Delete First Flight
6. Delete Last Flight
7. Display All Flights
8. Exit
Enter your choice: 7

FlightID   Departure Time  Arrival Time  Departure Airport  Arrival Airport  Passengers  Status
A123       12:30:00        15:45:00      JFK                LAX              150         boarding



Note: Remember we do not care if all fields are aligned proerly or not, we do care about the expected output format except spaces and constant words/sentences.
=======================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct flightinfo{
    char fid[10];
    int dtime[3];
    int atime[3];
    char dport[4];
    char aport[4];
    int nump;
    char fstat[15];
    struct flightinfo *next;
}fi;
    
    
    
//you should call displayMenu(); whenever you want to ask for user input, remember you still have to ask for user input, this function just prints the menu
void displayMenu()
{
    printf("Flight Management System:\n");
    printf("1. Add Flight at Beginning\n");
    printf("2. Add Flight after Flight ID\n");
    printf("3. Add Flight at End\n");
    printf("4. Delete a Flight by ID\n");
    printf("5. Delete First Flight\n");
    printf("6. Delete Last Flight\n");
    printf("7. Display All Flights\n");
    printf("8. Exit\n");
    printf("9. Save Flight Info from the liniked list as text (human readable form) to mydata.txt File\n");
    printf("10. Load Flight Info from mydata.txt File to the linked list\n");
    printf("11. Save Flight Info from the liniked list as BINARY data to mydata.bin File\n");
    printf("12. Load Flight Info from mydata.bin File to the linked list\n");
    printf("13. Delete the linked list (delete all the nodes and free memory)\n");
}