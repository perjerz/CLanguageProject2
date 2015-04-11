#include<stdio.h>
#include<string.h>
#include<dataFormat.h>
void main()
{
EVENT_T enter;
char input[64];
enter.eventCode;
enter.date;
enter.time;
enter.typeOfEvent;
enter.investDate;
enter.investTime;
enter.reportPerson;
enter.phoneNumber;
enter.address;
enter.district;
enter.result;
printf("*******  Record Event  *******\n");
printf("\n");
printf("* EVENT CODE
       t : ");
fgets(input,sizeof(input),stdin);
sscanf(input,"%s",enter.eventCode);
printf("* DATE                     : ");
fgets(input,sizeof(input),stdin);
sscanf(input,"%s",enter.date);
printf("* TIME                     : ");
fgets(input,sizeof(input),stdin);
sscanf(input,"%s",enter.time);
printf("* TYPE OF EVENT            : ");
fgets(input,sizeof(input),stdin);
sscanf(input,"%s",enter.typeOfEvent);
printf("* INVESTIGATE DATE         : ");
fgets(input,sizeof(input),stdin);
sscanf(input,"%s",enter.investDate);
printf("* INVESTIGATE TIME         : ");
fgets(input,sizeof(input),stdin);
sscanf(input,"%s",enter.investTime);
printf("* REPORTER'S NAME          : ");
fgets(input,sizeof(input),stdin);
sscanf(input,"%s",enter.reportPerson);
printf("* REPORTER'S PHONE NUMBER  : ");
fgets(input,sizeof(input),stdin);
sscanf(input,"%s",enter.phoneNumber);
printf("* ADDRESS                  : ");
fgets(input,sizeof(input),stdin);
sscanf(input,"%s",enter.address);
printf("* DISTRICT                 : ");
fgets(input,sizeof(input),stdin);
sscanf(input,"%s",enter.district);
printf("* RESULT                   : ");
fgets(input,sizeof(input),stdin);
sscanf(input,"%s",enter.result);

}
