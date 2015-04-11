/*************************************************************************************************

 *

 *   Ghostbuster

 * 	 data.c

 *   This program manage will open the file for writing and continued to write to append the old file.

 *

 *   Created by Mr.Thanaphon Phanthachai   Section: C ,ID: 56070503412

 * 				Mr.Siwat Karwlung 			Section: C, ID:56070503434

 *   Project 2 /2013  Group ERROR404

 *

 ************************************************************************************************/

#include <stdio.h>

#include "dataFormat.h"

#include <stdlib.h>

#include <string.h>

/*
* saveEvent function
* this function is to save all of event information 
* to file to store permanent information
* Argument : event (input) all of information of event
*			: count (input) amount of each event record
* Return 1
*/
int saveEvent(EVENT_T *event,int count)
{
    /*read file and write to old file*/
    FILE *pOutFile = NULL;
	int i = 0;
    if((pOutFile = fopen("eventCode.txt","w"))==NULL)
    {
        printf("Can not read file\n");
        exit(0);
    }
    fprintf(pOutFile,"%d\n",count);
    for(i=0;i<count;i++)
		{
		fprintf(pOutFile,"%s|%s|%s|%s|%s|%s|%s|%s|%s\n",
        event[i].eventCode,event[i].date,
        event[i].typeOfEvent,event[i].investDate,
        event[i].reportPerson,event[i].phoneNumber,
        event[i].address,event[i].district,
        event[i].result);
		showEvent(event[i]);
		}
    fclose(pOutFile);
	return 1;
}

/*
* loadCountEvent function
* this function is to load amount of record of event in file
* to allocate memory
* No Argument
* Return count (amount of event record)
*/

int loadCountEvent()
    {
    /*make file and write to file*/
    char buffer[256];
    int count = 0;
    FILE *pInfile = NULL;
    if((pInfile = fopen("eventCode.txt","r"))==NULL)
    {
        printf("Error load count from file\n");
		exit(0);
    }
    fgets(buffer,sizeof(buffer),pInfile);
	sscanf(buffer,"%d",&count);
	fclose(pInfile);
	return count;
    }

/*
* loadEventRecord function
* this function is to load each event record
* to manipulate in program
* Argument : event (input) all of information of event
*			: count (input) amount of each event record
* Return 1
*/

int loadEventRecord(EVENT_T *event,int count)
    {
    FILE *pInfile = NULL;
    if((pInfile = fopen("eventCode.txt","r"))==NULL)
    {
        printf("Error load record from file\n");
        exit(0);
    }
    int checkNumber = 0;
	char buffer[256];
	char eventLine[256];
	char *token = NULL;
    EVENT_T* addEvent = NULL;
    addEvent = (EVENT_T*)calloc(count,sizeof(EVENT_T));
    if(addEvent == NULL)
        {
        printf("Can't first allocation memory.\n");
        exit(0);
        }
	fgets(buffer,sizeof(buffer),pInfile);/*move to record skip count in file*/
    memset(buffer,0,sizeof(buffer));
	memset(eventLine,0,sizeof(eventLine));
    while(fgets(buffer,sizeof(buffer),pInfile) != NULL)
        {/*split each line to each information of event and store in memory*/
    	sscanf(buffer,"%[^\n]",eventLine);
		token = strtok(eventLine,"|");
		strcpy(addEvent[checkNumber].eventCode,token);
		token = strtok(NULL,"|");
		strcpy(addEvent[checkNumber].date,token);
		token = strtok(NULL,"|");
        strcpy(addEvent[checkNumber].typeOfEvent,token);
		token = strtok(NULL,"|");
        strcpy(addEvent[checkNumber].investDate,token);
		token = strtok(NULL,"|");
		strcpy(addEvent[checkNumber].reportPerson,token);
		token = strtok(NULL,"|");
		strcpy(addEvent[checkNumber].phoneNumber,token);
		token = strtok(NULL,"|");
        strcpy(addEvent[checkNumber].address,token);
		token = strtok(NULL,"|");
        strcpy(addEvent[checkNumber].district,token);
		token = strtok(NULL,"|");
		strcpy(addEvent[checkNumber].result,token);
		/*fprintf(stdout,"%s|%s|%s|%s|%s|%s|%s|%s|%s\n",
        addEvent[checkNumber].eventCode,addEvent[checkNumber].date,
        addEvent[checkNumber].typeOfEvent,addEvent[checkNumber].investDate,
        addEvent[checkNumber].reportPerson,addEvent[checkNumber].phoneNumber,
        addEvent[checkNumber].address,addEvent[checkNumber].district,
        addEvent[checkNumber].result);*/
        checkNumber++;/*count amount of information*/
		memset(buffer,0,sizeof(buffer));
		memset(eventLine,0,sizeof(eventLine));
        }
    if(count != checkNumber)
        {
        printf("\a\a\a\a\a\a\a\a\a\a\a");
        printf("**************************************************************\n");
        printf("Error in file ! Amount of event doesn't match first line (amount)\n");
        printf("**************************************************************\n");
        }
    memcpy(event,addEvent,sizeof(EVENT_T)*count);/*bring all of information to output (main)*/
    free(addEvent);
    fclose(pInfile);
	return 1;    
	}

int deleteEvent(EVENT_T* event,int *count,int deletePos)
	{
		int i = 0;
		EVENT_T* addEvent = NULL; 
		addEvent = (EVENT_T*)calloc((*count)+1,sizeof(EVENT_T));
		if(addEvent == NULL) 
		{ 
			printf("Can't reallocation memory.\n"); 
			exit(0); 
		} 
		memcpy(addEvent,event,sizeof(EVENT_T)*((*count)));
		for(i=deletePos;i<(*count)-1;i++) 
		{ 
			memcpy(&addEvent[i],&addEvent[i+1],sizeof(EVENT_T));
			showEvent(addEvent[i]); 
		} 
		(*count) --; 
		memcpy(event,addEvent,sizeof(EVENT_T)*(*count)); 
		free(addEvent);
		/*for(i=0;i<*count;i++) 
			{ 
			showEvent(event[i]); 
			}*/ 
	}
