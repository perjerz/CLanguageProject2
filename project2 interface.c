/********************************************

                Main  Ask
*********************************************/
#include<stdio.h>
int i = 0;
int index = 0;
EVENT_T event[2];
int main()
{
char input[64];
double menu;
while(menu!=4)
    {
    printf("\t---------------------------------------------\n");
    printf("\t||               Ghostbusters              ||\n");
    printf("\t||   Who're you gonna call? Ghostbusters!  ||\n");
    printf("\t---------------------------------------------\n");
    printf("\n");
    printf("\t  1.Record");
    printf("   2.search");
    printf("   3.Delete");
    printf("   4.Exit\n");
    printf("\n");
    printf("Press menu number : ");
    fgets(input,sizeof(input),stdin);
    sscanf(input,"%lf",&menu);
    clearScreen();
    if(menu==1)
        {
        you must use calloc or malloc to create information event depend on amout of it;
        memset(event,0,sizeof(event));
        for(i=0;i<sizeof(event)/sizeof(EVENT_T);i++)
            {
            EVENT_T* calloc(sizeof(),sizeof(EVENT_T));
            inputAllOfEvent(&event[i],&index);
            }
        }
    else if(menu==2)
        {
        printf("---------------------------------------------------------------------\n");
        printf("||-------------------------- Search Type --------------------------||\n");
        printf("---------------------------------------------------------------------\n");
        printf("|| 1.Event type                                                    ||\n");
        printf("|| 2.Event year                                                    ||\n");
        printf("|| 3.District                                                      ||\n");
        printf("||-----------------------------------------------------------------||\n");
        printf("\n");
        searchRecord();
        }
    else if(menu==3)
        {
        printf("---------------------------------------------------------------------\n");
        printf("||--------------------  Search For Delete. ------------------------||\n");
        printf("---------------------------------------------------------------------\n");
        printf("|| 1.Event type                                                    ||\n");
        printf("|| 2.Event year                                                    ||\n");
        printf("|| 3.District                                                      ||\n");
        printf("||-----------------------------------------------------------------||\n");
        searchRecord();

        }
    else if(menu==4)
        {
        return 0;
        }
    }
}
