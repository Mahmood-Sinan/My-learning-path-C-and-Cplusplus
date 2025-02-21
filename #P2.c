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
#include "fileIO.h"
enum stat{security_check,boarding,departed};
//you should call displayMenu(); whenever you want to ask for user input, remember you still have to ask for user input, this function just prints the menu

//Delare all your UDFs here (just the prototypes)
void scanfi(fi *info);
void addatend(fi** addofheadptr,fi info);
void printfi(fi* headptr);
void addatbegin(fi** addofheadptr,fi info);
void addbetween(fi *headptr,char* search,fi info);
void deletebyid(fi *headptr,char* search);
void deletefirst(fi** addofheadptr);
void deletelast(fi* headptr);
//changed
void saveintxt(fi* headptr);
void readintxt(fi** addofheadptr);
void saveinbin(fi* headptr);
void readinbin(fi** addofheadptr);
void dlt(fi** addofheadptr);
char* enumconverter(enum stat st);

//WRITE YOUR CODE HERE

//changed change function declaration, passing args in main
int main()
{
    int choice=0;
    fi info;
    fi* headptr=NULL;
    char search[10];
    do{
        displayMenu();
        scanf("%d",&choice);
        switch(choice){
            case 1:
                scanfi(&info);
                addatbegin(&headptr,info);
                break;
            case 2:
                printf("Enter the Flight ID to add flight after:");
                scanf("%9s",search);
                scanfi(&info);
                addbetween(headptr,search,info);
                break;
            case 3:
                scanfi(&info);
                addatend(&headptr,info);
                break;
            case 4:
                printf("Enter the Flight ID to delete:");
                scanf("%9s",search);
                deletebyid(headptr,search);
                break;
            case 5:
                deletefirst(&headptr);
                break;
            case 6:
                deletelast(headptr);
                break;
            case 7:
                printfi(headptr);
                break;
            case 8:
                break;
            case 9:
                saveintxt(headptr);
                break;
            case 10:
                readintxt(&headptr);
                break;
            case 11:
                saveinbin(headptr);
                break;
            case 12:
                readinbin(&headptr);
                break;
            case 13:
                dlt(&headptr);
                break;
        }
    }while(choice!=8);
    return 0;
}
//Define all your UDFs here (function definintion corresponding to the prototypes you gave before main)
void scanfi(fi *info){
    int temp=0;
    printf("\nFlight ID:");
    scanf("%9s",info->fid);
    printf("Departure time:");
    scanf("%d%d%d",&(info->dtime[0]),&(info->dtime[1]),&(info->dtime[2]));
    printf("Arrival time:");
    scanf("%d%d%d",&(info->atime[0]),&(info->atime[1]),&(info->atime[2]));
    printf("Departure airport:");
    scanf("%3s",info->dport);
    printf("Arrival airport:");
    scanf("%3s",info->aport);
    printf("Number of Passengers:");
    scanf("%d",&info->nump);
    printf("Flight status:");
    scanf("%d",&temp);
    switch(temp){
        case 0:
        strcpy(info->fstat,"security_check");
        break;
        case 1:
        strcpy(info->fstat,"boarding");
        break;
        case 2:
        strcpy(info->fstat,"departed");
        break;
    }
    printf("\n");
    
}
void addatend(fi** addofheadptr,fi info){
    fi *temp=NULL,*ptr=NULL;
    if(*addofheadptr==NULL){
        *addofheadptr=(fi*)malloc(sizeof(fi));
        (*addofheadptr)->next=NULL;
        temp=*addofheadptr;
        ptr=temp;
        **addofheadptr=info;
    }
    else{
        temp=*addofheadptr;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        ptr=(fi*)malloc(sizeof(fi));
        ptr->next=NULL;
        temp->next=ptr;
        temp=ptr;
        *temp=info;
    }
}
void printfi(fi* iterator){
    while(iterator!=NULL){
        printf("\nFlight ID:%s\n",iterator->fid);
        printf("Departure time:%02d:%02d:%02d\n",iterator->dtime[0],iterator->dtime[1],iterator->dtime[2]);
        printf("Arrival time:%02d:%02d:%02d\n",iterator->atime[0],iterator->atime[1],iterator->atime[2]);
        printf("Departure airport:%s\n",iterator->dport);
        printf("Arrival airport:%s\n",iterator->aport);
        printf("Number of passengers:%d\n",iterator->nump);
        if(!strcmp(iterator->fstat,"security_check")){
            printf("Flight status:%s\n\n",enumconverter(security_check));
        }
        else if(!strcmp(iterator->fstat,"boarding")){
            printf("Flight status:%s\n\n",enumconverter(boarding));
        }
        else if(!strcmp(iterator->fstat,"departed")){
            printf("Flight status:%s\n\n",enumconverter(departed));
        }
        iterator=iterator->next;
    }
}
void addatbegin(fi** addofheadptr,fi info){
    fi* ptr=NULL;
    ptr=(fi*)malloc(sizeof(fi));
    *ptr=info;
    ptr->next=*addofheadptr;
    *addofheadptr=ptr;
}

void addbetween(fi *headptr,char* search,fi info){
    fi* temp=headptr,*ptr=NULL;;
    while(!(temp==NULL||strcmp(temp->fid,search)==0)){
        temp=temp->next;
    }
    if(temp!=NULL){
        ptr=(fi*)malloc(sizeof(fi));
        *ptr=info;
        ptr->next=temp->next;
        temp->next=ptr;
    }
}
void deletebyid(fi *temp,char* search){
    fi* temp1=temp;
    while(strcmp(temp->fid,search)!=0){
        temp1=temp;
        temp=temp->next;
    }
    temp1->next=temp->next;
    free(temp);
}
void deletefirst(fi** addofheadptr){
    fi* temp=(*addofheadptr);
    *addofheadptr=(*addofheadptr)->next;
    printf("Flight at beginning deleted successfully\n");
    free(temp);
}
void deletelast(fi* temp){
    fi* temp1=temp;
    while((temp->next)!=NULL){
        temp1=temp;
        temp=temp->next;
    }
    temp1->next=NULL;
    free(temp);
}
char* enumconverter(enum stat st){
    switch(st){
        case security_check:
        return "security_check";
        case boarding:
        return "boarding";
        case departed:
        return "departed";
        default : return NULL;
    }
}
//changed
void saveintxt(fi* headptr){
    FILE* fp;
    fp=fopen("mydata.txt","w");
    fi*temp=headptr;
    while(temp!=NULL){
        fprintf(fp,"%s %d %d %d %d %d %d %s %s %d %s\n",temp->fid,temp->dtime[0],temp->dtime[1],temp->dtime[2],temp->atime[0],temp->atime[1],temp->atime[2],temp->dport,temp->aport,temp->nump,temp->fstat);
        temp=temp->next;
    }
    fclose(fp);
}
//changed
void readintxt(fi** addofheadptr){
    FILE* fp;
    fp=fopen("mydata.txt","r");
    fi temp;
    fi* last=NULL;
    while(!feof(fp)){
        fscanf(fp,"%s %d %d %d %d %d %d %s %s %d %s",temp.fid,&temp.dtime[0],&temp.dtime[1],&temp.dtime[2],&temp.atime[0],&temp.atime[1],&temp.atime[2],temp.dport,temp.aport,&temp.nump,temp.fstat);
        fi* ptr=(fi*)malloc(sizeof(fi));
        *ptr=temp;
        ptr->next=NULL;
        if(*addofheadptr==NULL){
            *addofheadptr=ptr;
        }
        else{
            last->next=ptr;
        }
        last=ptr;
    }
    fclose(fp);
    deletelast(*addofheadptr);
    // fi *temp=NULL,*ptr=NULL;
    // fi finfo;
    // finfo.next=NULL;
    // while(!feof(fp)){
    //     fscanf(fp,"%s ",finfo.fid);
    //     fscanf(fp,"%d %d %d ",&(finfo.dtime[0]),&(finfo.dtime[1]),&(finfo.dtime[2]));
    //     fscanf(fp,"%d %d %d ",&(finfo.atime[0]),&(finfo.atime[1]),&(finfo.atime[2]));
    //     fscanf(fp,"%s ",finfo.dport);
    //     fscanf(fp,"%s ",finfo.aport);
    //     fscanf(fp,"%d ",&(finfo.nump));
    //     fscanf(fp,"%s ",finfo.fstat);
    //     if(*addoflhead==NULL){
    //         *addoflhead=(fi*)malloc(sizeof(fi));
    //         (*addoflhead)->next=NULL;
    //         **addoflhead=finfo;
    //     }
    //     else{
    //         temp=*addoflhead;
    //         while(temp->next!=NULL){
    //             temp=temp->next;
    //         }
    //         ptr=(fi*)malloc(sizeof(fi));
    //         ptr->next=NULL;
    //         temp->next=ptr;
    //         temp=ptr;
    //         *temp=finfo;
    //     }
    // }
}
//changed
void saveinbin(fi* headptr){
    FILE* fp;
    fp=fopen("mydata.bin","wb");
    fi *temp=headptr;
    while(temp!=NULL){
        fwrite(temp,sizeof(fi),1,fp);
        temp=temp->next;
    }
    fclose(fp);
    // while(headptr!=NULL){
    //     fwrite(headptr->fid,sizeof(char),10,fp);
    //     fwrite(headptr->dtime,sizeof(int),3,fp);
    //     fwrite(headptr->atime,sizeof(int),3,fp);
    //     fwrite(headptr->dport,sizeof(char),4,fp);
    //     fwrite(headptr->aport,sizeof(char),4,fp);
    //     fwrite(&(headptr->nump),sizeof(int),1,fp);
    //     fwrite(headptr->fstat,sizeof(char),15,fp);
    //     headptr=headptr->next;
    // }
    // fclose(fp);
}
//changed
void readinbin(fi** addofheadptr){
    FILE* fp;
    fp=fopen("mydata.bin","rb");
    fi temp;
    fi* last=NULL;
    while(!feof(fp)){
        fread(&temp,sizeof(fi),1,fp);
        // fread(temp.fid,sizeof(char),10,fp);
        // fread(temp.dtime,sizeof(int),3,fp);
        // fread(temp.atime,sizeof(int),3,fp);
        // fread(temp.dport,sizeof(char),4,fp);
        // fread(temp.aport,sizeof(char),4,fp);
        // fread(&(temp.nump),sizeof(int),1,fp);
        // fread(temp.fstat,sizeof(char),15,fp);
        fi* ptr=(fi*)malloc(sizeof(fi));
        *ptr=temp;
        ptr->next=NULL;
        if(*addofheadptr==NULL){
            *addofheadptr=ptr;
        }
        else{
            last->next=ptr;
        }
        last=ptr;
    }
    fclose(fp);
    deletelast(*addofheadptr);
    // fi *temp=NULL,*ptr=NULL;
    // fi finfo;
    // finfo.next=NULL;
    // while(!feof(fp)){
    //     fread(finfo.fid,sizeof(char),10,fp);
    //     fread(finfo.dtime,sizeof(int),3,fp);
    //     fread(finfo.atime,sizeof(int),3,fp);
    //     fread(finfo.dport,sizeof(char),4,fp);
    //     fread(finfo.aport,sizeof(char),4,fp);
    //     fread(&(finfo.nump),sizeof(int),1,fp);
    //     fread(finfo.fstat,sizeof(char),15,fp);
    //     if(*addoflhead==NULL){
    //         *addoflhead=(fi*)malloc(sizeof(fi));
    //         (*addoflhead)->next=NULL;
    //         temp=*addoflhead;
    //         ptr=temp;
    //         **addoflhead=finfo;
    //     }
    //     else{
    //         temp=*addoflhead;
    //         while(temp->next!=NULL){
    //             temp=temp->next;
    //         }
    //         ptr=(fi*)malloc(sizeof(fi));
    //         ptr->next=NULL;
    //         temp->next=ptr;
    //         temp=ptr;
    //         *temp=finfo;
    //     }
    // }
    //fclose(fp);
}
//changed
void dlt(fi** addofheadptr){
    // fi* temp=*addofheadptr;
    // fi* temp1=NULL;
    // while(temp!=NULL){
    //     temp1=temp->next;
    //     free(temp);
    //     temp=temp1;
    // }
    // *addofheadptr=NULL;
    fi *current=*addofheadptr,*next=NULL;
    while(current!=NULL){
        next=current->next;
        free(current);
        current=next;
    }
    *addofheadptr=NULL;
}
//END OF YOUR CODE