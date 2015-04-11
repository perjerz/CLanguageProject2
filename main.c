/********************************************

                Main.c
this program stores information about ghost event
such as date and time of event, address, district,
sucession and date and time of investigation
ask user a ghost event information
save all of ghost event information
search ghost event information 
delete ghost event information

Created By
Mr. Siwat Karwlung ID 56070503434
Mr. Saran Kongsungnern ID 56070503433

Group Error 404
*********************************************/
#include <stdio.h>
#include "dataFormat.h"
#include <stdlib.h>
#include <string.h>
void faq();

/*
* Main function
* this function include memory allocation
* load text file , search and delete record ,save text file and menu
* No Argument
* Return 1;
*/
int main()
    {
	char input[64];
	int menu = 0;
	char stringInput;
	int count = 0;
	int deletePos = 0;
	char *token = NULL;
    EVENT_T* event = NULL;
    EVENT_T* addEvent = NULL;
    FILE *pInfile = NULL;
    count = loadCountEvent();/*bring amount of event record*/
    addEvent = (EVENT_T*)realloc(event,count*sizeof(EVENT_T));/*allocate memory depend on amount of event record*/
    if(addEvent == NULL)/*check error allocation*/
        {
        printf("Can't first allocation memory.\n");
        exit(0);
        }
    event = addEvent;/*set address event to memory allocation*/
    loadEventRecord(event,count);/*load each record to event*/
	while(menu!=4)
        {
		printf("---------------------------------------------------------------------\n");
        printf("\t \t||       Ghostbusters      ||\n");
        printf("---------------------------------------------------------------------\n");
        printf("\t \t   1.NEW    RECORD\n");
        printf("\t \t   2.SEARCH RECORD\n");
        printf("\t \t   3.DELETE RECORD\n");
        printf("\t \t   4.EXIT PROGRAM\n");
		printf("---------------------------------------------------------------------\n");
		menu = integerInput("\t Please select your : ",1,4);/*show menu*/
       
        if(menu==1)/*add event record*/
            {
            count ++;/*increase amount of record*/
            addEvent = (EVENT_T*)realloc(event,count*sizeof(EVENT_T));/* reallocate memory new size*/
            if(addEvent == NULL)/*check error again*/
                {
                printf("Can't reallocation memory.\n");
                exit(0);
                }
            event = addEvent;
            inputAllOfEvent(&event[count-1],count-1);/* ask all information of event*/
			printf("---------------------------------------------------------------------\n");
			printf("* Program has successfully create new record\n");
			showEvent (event[count-1]);
            }
        else if(menu==2)
            {
            faq();
            searchRecord (event,count);
            }
        else if(menu==3)
            {
			faq();
            searchRecord (event,count);
			deletePos = integerInput("Please select the record to delete : ",1,count);/*show menu*/
			deletePos --; /*to get real position, we display in 1,2,3... from delete menu but array start with 0*/
			deleteEvent(event,&count,deletePos);
            }
        else if(menu==4)
            {
            saveEvent(event,count);/*save each event record*/
            printf("Thank you for using our program.\n");
            free(addEvent);
            return 0;
            }
        }
    }

void faq()
	{
		printf("---------------------------------------------------------------------\n");
	    printf("||-----------------------------  Note. ----------------------------||\n");
	    printf("||-----------------------   How to search  ------------------------||\n");
	    printf("||-----------------------------------------------------------------||\n");
	    printf("|| There are 3 formats to choose for searching                     ||\n");
	    printf("|| You have to choose between 3 of these to continue               ||\n");
	    printf("||-----------------------------------------------------------------||\n");
		printf("|| 1.Search by type of event                                       ||\n");
	    printf("||   Format:V (Vampire), W (Werewolf), G (Ghost), P (Poltergeist)  ||\n");
	    printf("||   Z (Zombie), P (phi krasue) or O (Other).                      ||\n");
	    printf("|| A single event can have more than onetype, separated by commas  ||\n");
	    printf("|| , e.g. 'V,W,Z'                                                  ||\n");
	    printf("||-----------------------------------------------------------------||\n");
		printf("|| 2.Search by year of event                                       ||\n");
	    printf("||   Format:'yyyy'                                                 ||\n");
	    printf("||-----------------------------------------------------------------||\n");
	    printf("|| 3.Search by district                                            ||\n");
	    printf("||   Format: The menu will appear to select the district in BKK    ||\n");
	    printf("||-----------------------------------------------------------------||\n");
	}
