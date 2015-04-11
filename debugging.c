/*
* Debugging.c
* This file is including functions that detect innocent user
* and receive all of input information of ghost buster
* it will ask until get correct format
* information such as name, phone number, addreas, type of event, date and time
* and so on
* Created By Siwat Karwlung ID 56070503434 GROUP ERROR404
* Recent Update 30/11/2013 15:09 PM.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "dataFormat.h"
#define MAX_LEN 128

/*
* clearScreen function
* this function is to make screen clearly by new-line feed
* No Argument
* No Return
*
*/

void clearScreen()
    {
    int i = 0;
    for(i=0;i<30;i++)
        {
        printf("\n");
        }
    }

/*
* This function check input to numeric
* input - input string
* return true if input is character
*        false if input is not character
*
*/

int bNumeric(char *input)
    {
    unsigned short i;
    for(i=0;i<strlen(input);i++)/*use loop to check each character if not numeric it will return false*/
        {
        if(!isdigit(input[i])) return 0;
        }
        return 1;
    }

/*
* integerInput function
* this function ask user to get some input in integer 
* by have max and min of limit number
* Argument 	: displayMessage (input) to show user know what program want
*			: min (input) limit of minimum of number
* 			: max (input) limit of maximum of number
* Return the number that user input
*
*/

int integerInput(char *displayMessage,int min, int max)
	{
	char buffer[MAX_LEN];
	char bufferClearNewLine[MAX_LEN];
	int correct = 0;
	int numberOutput = 0;
	while(correct == 0)
		{
		memset(buffer,0,sizeof(buffer));
		memset(bufferClearNewLine,0,sizeof(bufferClearNewLine));
		correct = 1;
		fprintf(stdout,"%s",displayMessage);
		fgets(buffer,sizeof(buffer),stdin);
		sscanf(buffer,"%[^\n]",bufferClearNewLine);
		sscanf(bufferClearNewLine,"%d",&numberOutput);
		if(strlen(bufferClearNewLine) == 0)
			{
			correct = 0;
			}
		else if(!bNumeric(bufferClearNewLine))
			{
			correct = 0;
			}
		else if(numberOutput < min || numberOutput > max)
			{
			correct = 0;
			}
		}
	return numberOutput;
	}

/*
* isLeapYear Function
* this function is to check year is leap year or not
* Argument : input year (integer)
* Return : true if is leap year
* Return : false if is not leap year
*
*/
int isLeapYear(int year)
    {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
    }

/*
* possibleDateTime function
* this function is to check date and time are correct or not
* Argument  : input year (integer)
*           : input month (integer)
*           : input day (integer)
*           : input hour (integer)
*           : input minute (integer)
*
*/
int possibleDateTime(int year,int month,int day,int hour,int minute)
    {
    if(year < 0 || year > 3000)
        {
        return 0;
        }
    else if(month < 1 || month > 12)
        {
        return 0;
        }
    else if(day < 1 || month > 31)
        {
        return 0;
        }
    else if(hour < 0 || hour > 23)
        {
        return 0;
        }
    else if(minute < 0 || minute > 59)
        {
        return 0;
        }
    else if(month == 1 || month == 3 || month == 5  || month == 7
            || month == 8 || month == 10 || month == 12)
        {
        }
    else if(month == 4 || month == 6 || month == 9  || month == 11)
        {
        if(day > 30)
            {
            return 0;
            }
        }
    else
        {
        if(!isLeapYear(year))
            {
            if(day > 28)
                {
                return 0;
                }
            }
        else
            {
            if(day > 29)
                {
                return 0;
                }
            }
        }
    return 1;
    }
/*
* checkName function
* this function input name from reporter. if input is incorrect format, it will ask until correct format.
* first and/or last name (It must keep the space if both are entered). Allow a
* period (".") or an apostrophe ("'") but no other punctuation. Examples: "Joe", "Henry O'Neill",
* "Louis Van Arple III", "Jimmy Jones Jr."
* Argument : input/output reporter name (string)
* Return : true
*
*/
int checkName(char *name)
    {
    int i = 0;
    int correct=0;
    char input[MAX_LEN];/*buffer*/
    char tempName[MAX_LEN];
    while(correct == 0)
        {
        memset(input,0,sizeof(input));/*set text to null*/
        memset(tempName,0,sizeof(tempName));/*set text to null*/
        fprintf(stdout,"Please enter name\n");
        fprintf(stdout,"Examples: \"Joe\", \"Henry O'Neill\", \"Louis Van Arple III\", \"Jimmy Jones Jr.\"\n");
        fprintf(stdout,"Name : ");
        fgets(input,sizeof(input),stdin);/*get input from standard input*/
        sscanf(input,"%[^\n]",tempName);/*get everything from input except \n(new line)*/
        correct = 1; /*status of this name which correct or not but firstly we assume that's correct*/
        if(strlen(tempName) < 1)/*check if no input*/
            {
            correct = 0;
            }
        else if(correct == 1)
            {
            for(i=0;i<strlen(tempName);i++)
                {/*check character of name can't be*/
                if(!(isalpha(tempName[i]) || tempName[i] == '.' || tempName[i] == '\"'
                 || tempName[i] == '\'' || isspace(tempName[i])))
                    {
                    correct = 0;
                    i=strlen(tempName);/*use for exit loop suddenly , nothing to use break*/
                    }
                }
            }
        }
    strcpy(name,tempName);
    return 1;
    }

/*
* checkPhoneNumber function
* This function input phone number of reporter. if input is incorrect format, it will ask until correct format.
* Phone number of person reporting the event, format "0aa-nnnnnn", where "0aa" is two or three digit
* city or mobile code starting with zero, and "nnnnnnnn" is six to eight digits of phone number. For
* example: "085-1235612", "053-230110", "02-4709088". (Note this assumes the phone number is in
* Thailand.)
* Argument : input/output phone (string)
* Return : true
*
*/
int checkPhoneNumber(char *phone)
    {
    int i = 0;
    int correct=0;
    char *pch;
    char countMinus=0;
    char input[MAX_LEN];/*buffer*/
    char tempPhone[MAX_LEN];/*buffer*/
    char correctPhone[MAX_LEN];/*correct phone*/
    while(correct == 0)
        {
        memset(input,0,sizeof(input));/*set text to null*/
        memset(tempPhone,0,sizeof(tempPhone));/*set text to null*/
        memset(correctPhone,0,sizeof(correctPhone));/*set text to null*/
        fprintf(stdout,"Please enter phone number\n");
        fprintf(stdout,"Format: \"0aa-nnnnnn\" or \"0a-nnnnnn\"\n");
        fprintf(stdout,"Examples: \"085-1235612\", \"053-230110\", \"02-4709088\"\n");
        fprintf(stdout,"Phone Number : ");
        fgets(input,sizeof(input),stdin);/*get input from standard input*/
        sscanf(input,"%[^\n]",tempPhone);/*get everything from input except \n(new line)*/
        sscanf(input,"%[^\n]",correctPhone);/*get everything from input except \n(new line)*/
        pch = 0;/*token*/
        correct = 1;
        countMinus = 0;
        for(i=0;i<strlen(tempPhone);i++)/*count symbol character '-'*/
            {
            if(tempPhone[i] == '-')
                {
                countMinus ++;
                }
            }
        if(countMinus != 1)
            {
            correct = 0;/*minus should be 1 for string*/
            }
        pch = strtok(tempPhone,"-");/*split first token to check*/
        if(pch == NULL)/*check have token*/
            {
            correct = 0;
            }
        else if(strlen(pch) < 2 || strlen(pch) > 3)
            {
            correct = 0;/*first token must have 2-3 character*/
            }
        else if(correct == 1)
            {
            if(pch[0] != '0')/*first character must be zero '0'*/
                {
                correct = 0;
                }
            for(i=1;i<strlen(pch) && correct == 1;i++)
                {
                if(!isdigit(pch[i]))/*and the next must be digit*/
                    {
                    correct = 0;
                    i=strlen(pch);
                    }
                }
            }
        if(correct == 1)
            {
            pch = strtok(NULL,"-");/*split token again*/
            }
        if(pch == NULL)
            {
            correct = 0;/*must be not null token*/
            }
        else if(strlen(pch) < 6 || strlen(pch) > 8)
            {
            correct = 0;/*must have length between 6-8*/
            }
        else if(correct == 1)
            {
            for(i=0;i<strlen(pch);i++)
                {
                if(!isdigit(pch[i]))/*all must be digit*/
                    {
                    correct = 0;
                    i=strlen(pch);
                    }
                }
            }
        }
    strcpy(phone,correctPhone);/*copy to input/output argument*/
    return 1;
    }

/*
* checkAddreas function
* This function input addreas of event. if input is incorrect format, it will ask until correct format.
* Address of event: any format but must begin with a house number. May contain spaces, numbers,
* period ("."), dash ("-") or slash ("/").
* Argument  : input/output addreas (string)
*			: input/output district (string)
* Return : true
*
*/
int checkAddreas(char *addreas,char *district)
    {
    char input[MAX_LEN];/*buffer*/
    char tempAddreas[MAX_LEN];/*buffer*/
    char correctAddreas[MAX_LEN];/*correct address*/
    char fullHouseNo[MAX_LEN];
    memset(correctAddreas,0,sizeof(correctAddreas));/*set text to null*/
    int correct=0;/*status of format*/
    int countSlash = 0;/*to count minus symbol and find positon of slash*/
    int i = 0;
    char *token;
    while(correct == 0)
        {
        countSlash = 0;
        correct = 1;
        memset(input,0,sizeof(input));/*set text to null*/
        memset(tempAddreas,0,sizeof(tempAddreas));/*set text to null*/
        memset(fullHouseNo,0,sizeof(fullHouseNo));/*set text to null*/
        fprintf(stdout,"Please enter house number\n");
        fprintf(stdout,"Examples: \"197/2\" \"128\"\n");
        fprintf(stdout,"House number : ");
        fgets(input,sizeof(input),stdin);/*get input from standard input*/
        sscanf(input,"%[^\n]",tempAddreas);/*get everything from input except \n(new line)*/
        sscanf(input,"%[^\n]",fullHouseNo);/*get everything from input except \n(new line)*/
        if(strlen(tempAddreas) < 1 || strlen(tempAddreas) > 7)/*check null input (press enter only) or more than 7*/
            {
            correct = 0;
            }
        for(i=0;correct == 1 && i < strlen(tempAddreas);i++)/*loop to count slash*/
            {
            if(tempAddreas[i] == '/')
                {
                countSlash ++;
                }
            }
        if(countSlash > 1)/*house no. must contain 1 slash*/
            {
            correct = 0;
            }
        else if(tempAddreas[0] == '/')/*house no. must not begin with slash*/
            {
            correct = 0;
            }
        if(countSlash == 1)
            {
            token = strtok(tempAddreas,"/");/*split token by slash*/
            if(token == NULL)/*first token must not be null*/
                {
                correct = 0;
                }
            else if(strlen(token) < 1 || strlen(token) > 3)/*length of token must between 1 - 3*/
                {
                correct = 0;
                }
            for(i=0;correct == 1 && i<strlen(token);i++)/*it must contain digit */
                {
                if(!isdigit(token[i]))/*so we check it*/
                    {
                    correct = 0;
                    i=strlen(token);
                    }
                }
            token = strtok(NULL,"/");/*split last token*/
            if(token == NULL)/*token must not be null*/
                {
                correct = 0;
                }
            else if(strlen(token) < 1 || strlen(token) > 3)/*token length must be between 1 - 3*/
                {
                correct = 0;
                }
            for(i=0;correct == 1 && i<strlen(token);i++)/*it must contain digit*/
                {
                if(!isdigit(token[i]))/*so we check it*/
                    {
                    correct = 0;
                    i=strlen(token);
                    }
                }
            }
        else
            {
            if(strlen(tempAddreas) > 3)/*check null input (press enter only) or more than 7*/
                {
                correct = 0;
                }
            for(i=0;correct == 1 && i<strlen(tempAddreas);i++)/*it must contain digit*/
                {
                if(!isdigit(tempAddreas[i]))/*so we check it*/
                    {
                    correct = 0;
                    i=strlen(tempAddreas);
                    }
                }
            }
        }
    clearScreen();
    countSlash = 0;
    strcat(correctAddreas,fullHouseNo);/*insert house number*/
    correct = 0;
    while(correct == 0)
        {
        correct = 1;
        memset(input,0,sizeof(input));/*set text to null*/
        memset(tempAddreas,0,sizeof(tempAddreas));/*set text to null*/
        fprintf(stdout,"Please enter road \n");
        fprintf(stdout,"Examples: \"Charoenrat Road\"\n");
        fprintf(stdout,"Road : ");
        fgets(input,sizeof(input),stdin);/*get input from standard input*/
        sscanf(input,"%[^\n]",tempAddreas);/*get everything from input except \n(new line)*/
        if(strlen(tempAddreas) < 1)/*check null input (press enter only)*/
            {
            correct = 0;
            }
        for(i=0;correct == 1 && i<strlen(tempAddreas);i++)/* road contain alphabet, space, minus, dot and digit*/
            {
            if(!isalpha(tempAddreas[i]) && !isdigit(tempAddreas[i]) && tempAddreas[i] != '.'
            && tempAddreas[i] != '-' && tempAddreas[i] != ' ')/*so we check it*/
                {
                correct = 0;
                i=strlen(tempAddreas);
                }
            }
        }
    clearScreen();
    strcat(correctAddreas,",");/*insert comma*/
    strcat(correctAddreas,tempAddreas);/*insert road*/
    correct = 0;
    while(correct == 0)
        {
        correct = 1;
        memset(input,0,sizeof(input));/*set text to null*/
        memset(tempAddreas,0,sizeof(tempAddreas));/*set text to null*/
        fprintf(stdout,"Please enter Sub-District \n");
        fprintf(stdout,"Examples: \"Thungkru\"\n");
        fprintf(stdout,"Sub-District : ");
        fgets(input,sizeof(input),stdin);/*get input from standard input*/
        sscanf(input,"%[^\n]",tempAddreas);/*get everything from input except \n(new line)*/
        if(strlen(tempAddreas) < 1)/*check null input (press enter only)*/
            {
            correct = 0;
            }
        for(i=0;correct == 1 && i<strlen(tempAddreas);i++)/* road contain alphabet, space, minus, dot and digit*/
            {
            if(!isalpha(tempAddreas[i]) && tempAddreas[i] != '.'
            && tempAddreas[i] != ' ')/*so we check it*/
                {
                correct = 0;
                i=strlen(tempAddreas);
                }
            }
        }
    clearScreen();
    strcat(correctAddreas,",");/*insert comma*/
    strcat(correctAddreas,tempAddreas);/*insert sub-district*/
    memset(tempAddreas,0,sizeof(tempAddreas));/*set text to null*/
    checkDistrict(tempAddreas);/*bring district to string*/
	strcpy(district,tempAddreas);
    strcat(correctAddreas,",");/*insert comma*/
    strcat(correctAddreas,tempAddreas);/*insert district in Bangkok*/
    strcat(correctAddreas,",");/*insert comma*/
    strcat(correctAddreas,"Bangkok");/*insert Bangkok*/
    strcat(correctAddreas,",");/*insert comma*/
    correct = 0;
    int postalCode = 0;
    clearScreen();
    while(correct == 0)
        {
        correct = 1;
        memset(input,0,sizeof(input));/*set text to null*/
        memset(tempAddreas,0,sizeof(tempAddreas));/*set text to null*/
        fprintf(stdout,"Please enter Postal Code (In Bangkok, 10000-11000) \n");
        fprintf(stdout,"Examples: \"10110\"\n");
        fprintf(stdout,"Postal code : ");
        fgets(input,sizeof(input),stdin);/*get input from standard input*/
        sscanf(input,"%[^\n]",tempAddreas);/*get everything from input except \n(new line)*/
        sscanf(tempAddreas,"%d",&postalCode);/*get everything from input except \n(new line)*/
        if(strlen(tempAddreas) != 5)/*check null input (press enter only)*/
            {
            correct = 0;
            }
        for(i=0;correct == 1 && i<strlen(tempAddreas);i++)/* road contain alphabet, space, minus, dot and digit*/
            {
            if(!isdigit(tempAddreas[i]))/*so we check it*/
                {
                correct = 0;
                i=strlen(tempAddreas);
                }
            }
        if(correct = 1)
            {
            if(postalCode < 10000 || postalCode > 11000)/*postal code in Bangkok must be beetween 10000-11000*/
                {
                correct = 0;
                }
            }
        }
    strcat(correctAddreas,tempAddreas);/*insert postal code*/
    strcpy(addreas,correctAddreas);/*bring correct address to output*/
    printf("%s\n",addreas);
    return 1;
    }

/*
* checkDistrict function
* This function input district in menu from reporter. if input is incorrect ,it will ask until correct.
* District: must be a valid district of Bangkok. You may check this, or offer a menu to select.
* Argument : input/output addreas (string)
* Return : true *
*/

int checkDistrict(char *district)
    {
    /*char *provinceDatabase[] =
        {
        "Amnat Charoen","Ang Thong","Bangkok","Bueng Kan","Buriram","Chachoengsao","Chainat","Chaiyaphum","Chanthaburi","Chiang Mai",
"Chiang Rai","Chonburi","Chumphon","Kalasin","Kamphaeng Phet","Kanchanaburi","Khon Kaen","Krabi","Lampang","Lamphun","Loei",
"Lopburi","Mae Hong Son","Maha Sarakham","Mukdahan","Nakhon Nayok","Nakhon Pathom","Nakhon Phanom","Nakhon Ratchasima",
"Nakhon Sawan","Nakhon Si Thammarat","Nan","Narathiwat","Nong Bua Lamphu","Nong Khai City","Nonthaburi","Pathum Thani","Pattani",
"Phang NgaPhatthalung","Phayao","Phetchabun","Phetchaburi","Phichit","Phitsanulok","Phra Nakhon Si Ayutthaya","Phrae","Phuket",
"Prachinburi","Prachuap Khiri Khan","Ranong","Ratchaburi","Rayong","Roi Et","Sa Kaeo","Sakon Nakhon","Samut Prakan","Samut Sakhon",
"Samut Songkhram","Saraburi","Satun","Sing Buri","Sisaket","Songkhla","Sukhothai","Suphan Buri","Surat Thani","Surin","Tak","Trang",
"Trat","Ubon Ratchathani","Udon Thani","Uthai Thani","Uttaradit","Yala","Yasothon"
        };*/
    char *districtDatabase[] =
        {
            "Bang Bon","Bang Kapi","Bang Khae","Bang Khen","Bang Kho Laem","Bang Khun Thian","Bang Na","Bang Phlat","Bang Rak",
            "Bang Sue","Bangkok Noi","Bangkok Yai","Bueng Kum","Chatuchak","Chom Thong","Din Daeng","Don Mueang","Dusit",
            "Huai Khwang","Khan Na Yao","Khlong Sam Wa","Khlong San","Khlong Toei","Lak Si","Lat Krabang","Lat Phrao",
            "Min Buri","Nong Chok","Nong Khaem","Pathum Wan","Phasi Charoen","Phaya Thai","Phra Khanong","Phra Nakhon",
            "Pom Prap Sattru Phai","Prawet","Rat Burana","Ratchathewi","Sai Mai","Samphanthawong","Saphan Sung","Sathon",
            "Suan Luang","Taling Chan","Thawi Watthana","Thon Buri District","Thung Khru","Wang Thonglang","Watthana","Yan Nawa"
        };
    int districtNo=0;/*index of district to identify in database*/
    int i = 0;
    int correct=0;/*status of district*/
    char input[MAX_LEN];/*buffer*/
    char tempDistrict[MAX_LEN];/*buffer*/
    while(correct == 0)
        {
        memset(input,0,sizeof(input));/*set text to null*/
        memset(tempDistrict,0,sizeof(tempDistrict));/*set text to null*/
        fprintf(stdout,"Please enter number of district\n");
        for(i=0;i<50;i++)/*show all district in menu*/
            {
            fprintf(stdout,"%d)%s\t",i+1,districtDatabase[i]);
            if((i+1)%3==0 && i != 0)
                {
                fprintf(stdout,"\n");
                }
            }
        fprintf(stdout,"\nDistrict No. : ");
        fgets(input,sizeof(input),stdin);/*get input from standard input*/
        sscanf(input,"%[^\n]",tempDistrict);/*get everything from input except \n(new line)*/
        sscanf(input,"%d",&districtNo);
        correct = 1 ;
        if(strlen(tempDistrict) < 1 || strlen(tempDistrict) > 2)/*district must 1-2 character*/
            {
            correct = 0;
            }
        else if(!bNumeric(tempDistrict))/*must be digit only*/
            {
            correct = 0;
            }
        else if(districtNo < 1 || districtNo > 50)/*between 1 - 50*/
            {
            correct = 0;
            }
        }
    strcpy(district,districtDatabase[districtNo-1]);/*bring district from database to output argument*/
    return 1;
    }

/*
* checkDateTimeEvent function
* This function input date of event from reporter. if input is incorrect format, it will ask until correct format.
* format "yyyy-mm-dd hh:mm", CE year. Note that this is a different date
* format from some of the other projects! You should not allow the user to modify this value once it
* has been entered and validated (because the event code depends on this property). Must not be in the
* future!
* Argument : input/output date (string)
* Return : true
*
*/

int checkDateTimeEvent(char *date)
    {
    time_t rawtime;/*use these for get current time*/
    struct tm * timeinfo;
    char currentTime[MAX_LEN];
    int cYear,cMonth,cDay,cHour,cMin;/*current date and time*/
    int iYear,iMonth,iDay,iHour,iMin;/*event date and time*/
    //fprintf(stdout,"%d-%d-%d %d:%d\n",cYear,cMonth,cDay,cHour,cMin);
    int correct=0;
    char input[MAX_LEN];/*buffer*/
    char tempDate[MAX_LEN];/*buffer*/
    while(correct == 0)
        {
        memset(currentTime,0,sizeof(currentTime));/*set text to null*/
        memset(input,0,sizeof(input));/*set text to null*/
        memset(tempDate,0,sizeof(tempDate));/*set text to null*/
        fprintf(stdout,"Please enter date and time of event (Not in the future)\n");
        fprintf(stdout,"Format: \"yyyy-mm-dd hh:mm\"\n");
        fprintf(stdout,"Examples: \"2012-10-29 00:00\"\n");
        fprintf(stdout,"Date and Time of Event : ");
        fgets(input,sizeof(input),stdin);/*get input from standard input*/
        sscanf(input,"%[^\n]",tempDate);/*get everything from input except \n(new line)*/
        sscanf(tempDate,"%d-%d-%d %d:%d",&iYear,&iMonth,&iDay,&iHour,&iMin);
        //fprintf(stdout,"%.4d-%.4d-%.4d %.2d:%.2d\n",iYear,iMonth,iDay,iHour,iMin);
        correct = 1;
        time (&rawtime);
        timeinfo = localtime (&rawtime);/*get current time*/
        strftime(currentTime,MAX_LEN,"%Y-%m-%d %H:%M",timeinfo);/*bring time into format string in pattern of example above*/
        sscanf(currentTime,"%d-%d-%d %d:%d",&cYear,&cMonth,&cDay,&cHour,&cMin);/*convert string value into integer*/
        if(strlen(tempDate) != 16)/*event date length must be 16*/
            {
            correct = 0;
            }
        else if(!isdigit(tempDate[0]) || !isdigit(tempDate[1]) || !isdigit(tempDate[2]) || !isdigit(tempDate[3]))
            {/*check year is only digit*/
            correct = 0;
            }
        else if(tempDate[4] != '-' || tempDate[7] != '-' || tempDate[10] != ' ' || tempDate[13] != ':')
            {/*check symbol between digit is correct*/
            correct = 0;
            }
        else if(!isdigit(tempDate[5]) || !isdigit(tempDate[6]) || !isdigit(tempDate[8])
                || !isdigit(tempDate[9]) || !isdigit(tempDate[11]) || !isdigit(tempDate[12])
                || !isdigit(tempDate[14]) || !isdigit(tempDate[15]))
            {/*check another digit such as day ,month and hour is correct*/
            correct = 0;
            }
        else if(!possibleDateTime(iYear,iMonth,iDay,iHour,iMin))
            {/*check possible event date*/
            correct = 0;
            }
        else if(iYear > cYear)/*date and time of event must no be in the future*/
            {
            correct = 0;
            }
        else if(iYear == cYear)
            {
            if(iMonth > cMonth)
                {
                correct = 0;
                }
            else if(iMonth == cMonth)
                {
                if(iDay > cDay)
                    {
                    correct = 0;
                    }
                else if(iDay == cDay)
                    {
                    if(iHour > cHour)
                        {
                        correct = 0;
                        }
                    else if(iHour == cHour)
                        {
                        if(iMin > cMin)
                           {
                               correct = 0;
                           }
                        }
                    }
                }
            }
        }
    strcpy(date,tempDate);/*bring correct format event date to output argument*/
    return 1;
    }

/*
* checkDateTimeInvestigation function
* This function input date of investigation from reporter. if input is incorrect format, it will ask until correct format.
* format "yyyy-mm-dd hh:mm", CE year. Must be later than the date
* and time of the event.
* Argument : input/output dateInvestigation (string)
*          : input dateEvent (string)
* Return : true
*
*/

int checkDateTimeInvestigation(char *dateInvestigation,char *dateEvent)
    {
    int eYear,eMonth,eDay,eHour,eMin;
    int iYear,iMonth,iDay,iHour,iMin;
    sscanf(dateEvent,"%d-%d-%d %d:%d",&eYear,&eMonth,&eDay,&eHour,&eMin);/*convert event date string to each date and time*/
    int correct=0;
    char input[MAX_LEN];/*buffer*/
    char tempDateInvestigation[MAX_LEN];
    while(correct == 0)
        {
        memset(input,0,sizeof(input));/*set text to null*/
        memset(tempDateInvestigation,0,sizeof(tempDateInvestigation));/*set text to null*/
        fprintf(stdout,"Please enter date and time of event (Must be after event date and time)\n");
        fprintf(stdout,"Format: \"yyyy-mm-dd hh:mm\"\n");
        fprintf(stdout,"Examples: \"2012-10-29 12:00\"\n");
        fprintf(stdout,"Date and Time of Investigation : ");
        fgets(input,sizeof(input),stdin);/*get input from standard input*/
        sscanf(input,"%[^\n]",tempDateInvestigation);/*get everything from input except \n(new line)*/
        sscanf(tempDateInvestigation,"%d-%d-%d %d:%d",&iYear,&iMonth,&iDay,&iHour,&iMin);
        correct = 1;
        if(strlen(tempDateInvestigation) != 16)/*investigation date length must be 16*/
            {
            correct = 0;
            }
        else if(!isdigit(tempDateInvestigation[0]) || !isdigit(tempDateInvestigation[1])
                || !isdigit(tempDateInvestigation[2]) || !isdigit(tempDateInvestigation[3]))
            {/*check year is digit*/
            correct = 0;
            }
        else if(tempDateInvestigation[4] != '-' || tempDateInvestigation[7] != '-'
                || tempDateInvestigation[10] != ' ' || tempDateInvestigation[13] != ':')
            {/*check symbol is correct*/
            correct = 0;
            }
        else if(!isdigit(tempDateInvestigation[5]) || !isdigit(tempDateInvestigation[6])
                || !isdigit(tempDateInvestigation[8]) || !isdigit(tempDateInvestigation[9])
                || !isdigit(tempDateInvestigation[11]) || !isdigit(tempDateInvestigation[12])
                || !isdigit(tempDateInvestigation[14]) || !isdigit(tempDateInvestigation[15]))
            {/*check month, year and time is correct format*/
            correct = 0;
            }
        else if(!possibleDateTime(iYear,iMonth,iDay,iHour,iMin))
            {/*check possible date and time*/
            correct = 0;
            }
        else if(iYear < eYear)/*date and time of investigation must be after date and time event*/
            {
            correct = 0;
            }
        else if(iYear == eYear)
            {
            if(iMonth < eMonth)
                {
                correct = 0;
                }
            else if(iMonth == eMonth)
                {
                if(iDay < eDay)
                    {
                    correct = 0;
                    }
                else if(iDay == eDay)
                    {
                    if(iHour < eHour)
                        {
                        correct = 0;
                        }
                    else if(iHour == eHour)
                        {
                        if(iMin < eMin)
                           {
                               correct = 0;
                           }
                        }
                    }
                }
            }
        }
    strcpy(dateInvestigation,tempDateInvestigation);/*bring correct format to output*/
    return 1;
    }

/*
* checkResult function
* This function input sucession of ghoust killed in menu type from reporter until correct choice.
* Result: one of "Success", "Failure" or "Unknown"
* Argument : input/output result (string)
* Return : true
*
*/

int checkResult(char *result)
    {
    char *status[] = {"Success","Failure","Unknown"};
    int choice=0;
	choice = integerInput("Please enter number of result\n1)Success 2)Failure 3)Unknown\nResult Number : ",1,3);
    strcpy(result,status[choice-1]);/*bring result to output*/
    return 1;
    }
/*
* checkEventType function
* This function input type of event
* Types of event: V (Vampire), W (Werewolf), G (Ghost), P (Poltergeist) (unseen ghost that throws
* objects around), Z (Zombie), P (phi krasue) or O (Other). A single event can have more than one
* type, separated by commas, e.g. "V,W,Z" for a combination of a vampire, a werewolf and a zombie.
* it will ask until correct format
* Argument  : input/output eventType (string) (no comma)
* Return    : true
*/

int checkEventType(char *eventType)
    {
    char input[MAX_LEN];
    int i =0;
    int correct = 0;
    char eventTemp[MAX_LEN];
    char eventClearComma[MAX_LEN];/*event string that clear comma*/
    while(correct == 0)
        {
        memset(input,0,sizeof(input));
        memset(eventTemp,0,sizeof(eventTemp));
        fprintf(stdout,"Please enter type of event\n");
        fprintf(stdout,"Types of event: V (Vampire), W (Werewolf), G (Ghost)\n");
        fprintf(stdout,"P (Poltergeist)(unseen ghost that throws objects around)\n");
        fprintf(stdout,"Z (Zombie), P (phi krasue) or O (Other).\n");
        fprintf(stdout,"Examples : \"V,W,Z\", \"V\", \"Z,W\"\n");
        fprintf(stdout,"Type of Event : ");
        correct = 1;
        fgets(input,sizeof(input),stdin);/*get input from standard input*/
        sscanf(input,"%[^\n]",eventTemp);
        if(strlen(eventTemp) < 1)/*must not be null input*/
            {
            correct = 0;
            }
        else if(eventTemp[strlen(eventTemp)-1] == ',')/*the last character must not be ',' comma*/
            {
            correct = 0;
            }
        else if(correct == 1)
        {
            for(i=0;i<strlen(eventTemp);i++)/*detect wrong format*/
                {
                if(i % 2 == 0)/*character is always even array order so we check is correct format*/
                    {
                    if(!isupper(eventTemp[i]) || !(eventTemp[i] == 'V' || eventTemp[i] == 'W' || eventTemp[i] == 'G' || eventTemp[i] == 'P' || eventTemp[i] == 'Z' || eventTemp[i] == 'O'))
                        {
                        correct = 0;
                        i=strlen(eventTemp);
                        }
                    }
                else
                    {/*another is comma so we check also*/
                    if(eventTemp[i] != ',')
                        {
                        correct = 0;
                        i=strlen(eventTemp);
                        }
                    }
                }
            }
        }
    /*delete all of comma*/
    int j=0;
    for(i=0;i<strlen(eventTemp);i++)
        {
        if(isupper(eventTemp[i]))
            {
            eventClearComma[j] = eventTemp[i];
            j++;
            }
        }
    eventClearComma[j] = 0;/*and the last is terminator*/
    strcpy(eventType,eventClearComma);/*bring event type to output*/
    return 1;
    }

/*
* generateEventCode function
* This function is to generate code of event
* format "yyyy:nnnn", where 'yyyy' is the year the event occurred and 'n' is a digit. For
* example, "2012:0198" Your program should generate this code when you first create the record.
* Argument  : input/output eventCode (string)
*           : input/output index (integer) to count event
* Return    : true
*/
int generateEventCode(char *eventCode,int index)
    {
    time_t rawtime;
    struct tm * timeinfo;
    char cYear[8];
    memset(cYear,0,sizeof(cYear));
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime(cYear,MAX_LEN,"%Y",timeinfo);
    sprintf(eventCode,"%s:%.4d",cYear,index);/*generate event code from year and index*/
    return 1;
    }
/*
* inputAllOfEvent function
* this function include all of input function
* such as name, phone number, addreas, type of event, date and time
* and so on to make teammate create main easily.
* Argument : event (EVENT_T structure ) all of information in structure
*          : index (pointer integer)to generate code respectively.
* Return true
*/
int inputAllOfEvent (EVENT_T *event,int index)
    {
    generateEventCode(event->eventCode, index);/*no need to increasing index because in function add ups also*/
    clearScreen();
    checkDateTimeEvent(event->date);
    clearScreen();
    checkName(event->reportPerson);
    clearScreen();
    checkPhoneNumber(event->phoneNumber);
    clearScreen();
    checkAddreas(event->address,event->district);
    clearScreen();
    /*checkDistrict(event->district);
    clearScreen();*/
    checkDateTimeInvestigation(event->investDate,event->date);
    clearScreen();
    checkResult(event->result);
    clearScreen();
    checkEventType(event->typeOfEvent);
    return 1;
    }
