#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dataFormat.h"

int main (int menu)
	{
		char input[32];
		int year = -1;
		int i;
		int correct = 1;
		memset(input,0,sizeof(input));
    	switch (menu)
			{
				case 1: 
					do
					{
						printf("Search by EVENT CODE : ");
						fgets(input,sizeof(input),stdin);
						if (strlen(input)==0 || strlen(input)>10)
							{
								correct = 1;
							}
						else if (input[4] != ':')
							{
								correct = 1;
							}
						else
							{
								for(i=0;i<4;i++)
								{
									if(isdigit(input[i])==0)
									{
										correct = 1;
									}
								}
								for(i=5;i<9;i++)
								{
									if(isdigit(input[i])==0)
									{
										correct = 1;
									}
								}
								correct = 0;
							}
						}while (correct == 1);
					break;
				case 2:
					do
						{
							printf("Search by EVENT YEAR : ");
							fgets(input,sizeof(input),stdin);
							sscanf(input,"%d",&year);
						}while (year < 1 || year > 3000);
					break;
				case 3:
					printf("\t\t Search by DISTRICT \t\t\n");
					checkDistrict(input);
					break;
			}
		printf("Your search %s\n",input);
	}
