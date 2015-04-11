#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dataFormat.h"

int findRecord (EVENT_T *allData,int count,char *input,int menu);
int searchRecord (EVENT_T *allData,int count)
	{
		char input[32];
		int year = -1;
		int i;
		int menu = 0;
		int correct = 1;
		
		menu = integerInput("PLEASE INSERT TYPE OF DATA : ",1,3);
		 printf("---------------------------------------------------------------------\n");
    	switch (menu)
			{
				case 1:
					printf("\t\t Search by TYPE OF EVENT \t\t\n");
					 printf("---------------------------------------------------------------------\n");
					checkEventType (input);
					break;
				case 2:
					printf("\t\t Search by YEAR OF EVENT \t\t\n");
					 printf("---------------------------------------------------------------------\n");
					do
					{
					memset(input,0,sizeof(input));
					printf("PLEASE INSERT YEAR OF EVENT : ");
					fgets(input,sizeof(input),stdin);
					sscanf(input,"%d",&year);
					}while (year < 0 || year > 3000);
					sscanf(input,"%s",input);
					break;
				case 3:
					memset(input,0,sizeof(input));
					printf("\t\t Search by DISTRICT \t\t\n");
					 printf("---------------------------------------------------------------------\n");
					checkDistrict(input);
					break;
			}
		 printf("---------------------------------------------------------------------\n");
		printf("SEARCH QUERY : %s\n",input);
		printf("---------------------------------------------------------------------\n");
		findRecord (allData,count,input,menu);
	}
int findRecord (EVENT_T *allData,int count,char *input,int menu)
	{
		int i = 0;
		int index = 0;
		char *typeOfGhost;
		char *eventYear;
		for (i = 0; i < count; i++)
		{
			if (menu == 1)
			{
				
				typeOfGhost = strstr(allData[i].typeOfEvent,input);
				if (typeOfGhost != NULL)
				{
					printf("* %02d: Found '%s' in record NO. %02d\n", index+1 ,input,i+1);
					showEvent (allData[i]);
					index++;
				}
			}
			else if (menu == 2)
			{
				eventYear = strstr(allData[i].date,input);
				if (eventYear != NULL)
				{
					printf("* %02d: Found '%s' in record NO. %02d\n", index+1 ,input,i+1);
					showEvent (allData[i]);
					index++;
				}
			}
			else
			{
				if (strcmp(allData[i].district,input) == 0)
				{
					 
					printf("* %02d: Found '%s' in record NO. %02d\n", index+1 ,input,i+1);
					showEvent (allData[i]);
					index++;
				}
			}
		}
		printf("* Number of result : %2d\n",index);
		 printf("---------------------------------------------------------------------\n");
	}
