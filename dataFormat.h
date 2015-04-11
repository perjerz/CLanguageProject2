/***********************************************************
 *
 * dataFormat.h
 * header file that will be the standard type of data to transfer
 * over every .c files
 * Created by ERROR404
 * 21/11/2013
 *
 ***********************************************************
 */

 /* create EVENT_T structure to use between functions */
	typedef struct
	{
		char eventCode[32];
		char date[32];
		char typeOfEvent[16];
		char investDate[32];
		char reportPerson[32];
		char phoneNumber[32];
		char address[128];
		char district[32];
		char result[16];
	}EVENT_T;

/* function that call to show current event */
int showEvent (EVENT_T test);
/* function that check the correction of the name */
int checkName (char *name);
/* function that check the correction of the phone number */
int checkPhoneNumber (char *phone);
/* function that check the correction of the address and district */
int checkAddreas (char *addreas,char *distrcit);
/* function that check the correction of the district */
int checkDistrict (char *district);
/* function that check the correction of the date and time of the event */
int checkDateTimeEvent (char *date);
/* function that check the correction of the date and time of the investigation */
int checkDateTimeInvestigation (char *dateInvestigation,char *dateEvent);
/* function that check the correction of the result */
int checkResult (char *result);
/* function that check the correction of the event */
int checkEventType (char *eventType);
/* function that will check all input data */
int inputAllOfEvent (EVENT_T *event,int index);
/* function that call to search data */
int searchRecord (EVENT_T *allData,int count);
/* function that call to save event */
int saveEvent(EVENT_T *event,int count);
/* function that call to load amount of event */
int loadCountEvent();
/* function that call to load all record of event */
int loadEventRecord(EVENT_T *event,int count);
/* function that call to delete record */
int deleteEvent(EVENT_T* event,int *count,int deletePos);
/* function that call to get integer input from user */
int integerInput(char *displayMessage,int min, int max);

