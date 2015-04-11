/********************************************

                Main  Ask
*********************************************/
#include<stdio.h>
void faq();
int main()
{
	char input[64];
	double menu;
	char stringInput;
	while(menu!=4)
	{
	printf("\t-----------------------------\n");
	printf("\t||       Ghostbusters      ||\n");
	printf("\t-----------------------------\n");
	
	printf("\t   1.NEW    RECORD\n");
	printf("\t   2.SEARCH RECORD\n");
	printf("\t   3.DELETE RECORD\n");
	printf("\t   4.EXIT PROGRAM\n");
	printf("Press menu number : ");
	fgets(input,sizeof(input),stdin);
	sscanf(input,"%lf",&menu);
	
	if(menu==1)
	    {
		
	    }
	else if(menu==2)
	    {
	    faq();
	    printf("Search : ");
	    fgets(input,sizeof(input),stdin);
	    sscanf(input,"%s",stringInput);
	    }
	else if(menu==3)
	    {
	
	    }
	else if(menu==4)
	    {
	    printf("Thank you for using our program.\n");
	    return 0;
	    }
	}
}
void faq()
	{
		printf("---------------------------------------------------------------------\n");
	    printf("||-----------------------------  Note. ----------------------------||\n");
	    printf("||-----------------------   How to search  ------------------------||\n");
	    printf("---------------------------------------------------------------------\n");
	    printf("|| 1.Format yyyy:nnnn                                              ||\n");
	    printf("||-where 'yyyy' is the year the event occurred and 'n' is a digit. ||\n");
	    printf("||-----------------------------------------------------------------||\n");
	    printf("|| 2.Format V (Vampire), W (Werewolf), G (Ghost), P (Poltergeist)  ||\n");
	    printf("||   Z (Zombie), P (phi krasue) or O (Other).                      ||\n");
	    printf("||-A single event can have more than onetype, separated by commas  ||\n");
	    printf("|| , e.g. 'V,W,Z'                                                  ||\n");
	    printf("||-----------------------------------------------------------------||\n");
	    printf("|| 3.Format 'yyyy-mm-dd hh:mm'                                     ||\n");
	    printf("||-CE year. Must be later than the date and time of the event.     ||\n");
	    printf("||-----------------------------------------------------------------||\n");
	    printf("|| 4.Format 'first and/or last name'                               ||\n");
	    printf("||-Examples: 'Joe','Henry O'Neill','Louis Van Arple III'           ||\n");
	    printf("||-----------------------------------------------------------------||\n");
	    printf("|| 5.Format '0aa-nnnnnn'                                           ||\n");
	    printf("||-where '0aa' is two or three digitcity or mobile code starting   ||\n");
	    printf("||with zero and 'nnnnnnnn'is six to eight digits of phone number.  ||\n");
	    printf("||-----------------------------------------------------------------||\n");
	    printf("|| 6.Address of event:any format but must begin with a house number||\n");
	    printf("||May contain spaces, numbers,period ('.'),dash('-')or slash'/').  ||\n");
	    printf("||District: must be a valid district of Bangkok. You may check     ||\n");
	    printf("||this, or offer a menu to select.                                 ||\n");
	    printf("||-----------------------------------------------------------------||\n");
	}
