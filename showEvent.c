/****************************
 *
 * showEvent.c
 * Function that show the current data
 * Created by ERROR 404 
 * 25/11/2013
 *
 *************************
 */
#include <stdio.h>
#include "dataFormat.h"

/* can be change later */
int showEvent (EVENT_T test)
	{
		printf("---------------------------------------------------------------------\n");
		printf("* EVENT CODE                : %s\n",test.eventCode);
		printf("* DATE AND TIME             : %s\n",test.date);
		printf("* TYPE OF EVENT             : %s\n",test.typeOfEvent);
		printf("* INVESTIGATE DATE AND TIME : %s\n",test.investDate);
		printf("* REPORTER'S NAME           : %s\n",test.reportPerson);
		printf("* REPORTER'S PHONE NUMBER   : %s\n",test.phoneNumber);
		printf("* ADDRESS                   : %s\n",test.address);
		printf("* DISTRICT                  : %s\n",test.district);
		printf("* RESULT                    : %s\n",test.result);
		printf("---------------------------------------------------------------------\n");
	}
