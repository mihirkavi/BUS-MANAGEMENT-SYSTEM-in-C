//program to display the route and schedule of the buese

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//function declaration
int menu_schedule(char* name_sign, char* password_sign, char* prn_sign);
void source_destination();
void current_city_bus_to();
void current_city_bus_from();
void symbus();
void symbus_up();
void symbus_down();

//global declarations of credentials after login
char* name1;
char* password1;
char* prn1;

//file variables declarations
FILE *fpstudent1;
char* filename1;

//time variable declarations


//-----------------------------------------------------------------
//program to implement the procedure of the management of buses
int menu_schedule(char* name_sign, char* password_sign, char* prn_sign)
{

	//globally declaring all credentials within
	name1=name_sign;
	password1=password_sign;
	prn1=prn_sign;
	
	//opening the file once within the .h file
	sprintf(filename1, "%s.txt", name1);
	fpstudent1=fopen(filename1, "a+");
	fprintf(fpstudent1, "\nHello");
	
	//menu to access the route and schedule
	
	{
		system("cls");
		printf("\n\t\t\tEnter the choice within the following: ");
		printf("\n\n\t\t\t1. Find current bus");
		printf("\n\n\n\t\t\t2. Go back\n");
		
		switch(getch())
		{
			case '1':
				system("cls");
				while(1)
				{
					printf("\n\n\t\t\t1. Buses from SIT to city");
					printf("\n\n\t\t\t2. Buses from city to SIT");
					printf("\n\n\t\t\t3. Buses within university (symbus)");
					printf("\n\n\t\t\t4. Go Back\n");
					switch(getch())
					{
						case '1':
							current_city_bus_from();
							break;
						case '2':
							current_city_bus_to();
							break;
						case '3':
							symbus();
							break;
						case '4':
							return 0;
							break;
						default:
							printf("\nWrong choice Enetr again!\n");
					}
				}
				break;
			case '2':
				//this action leads to the main program
				return 0;
				break;
			default:
				printf("\n\n\t\t\tWrong choice! enter again\n");
				
		}
	}
}

//-----------------------------------------------------------------
//write a function which checks the current time and decides which buses to display

//from SIT to the city
void current_city_bus_from()
{
	system("cls");
	printf("\n\t\t\tBuses from SIT to city from NOW:\n\n");
	int time_now;
	time_t rawtime;
	struct tm*  time_;
	time(&rawtime);
	time_ = localtime(&rawtime);
	printf("\nTIME:\t%d:%d", time_->tm_hour, time_->tm_min);
	time_now=( (time_->tm_hour*100) + time_->tm_min );
	
	//showing the buses sequentially according to the time
	if(time_now<=800)
	printf("\n* City bus (hostellites HBC)       : 08:00");
	if(time_now<=830)
	printf("\n* City bus (hostellites HTC)       : 08:30");
	if(time_now<=1100)
	printf("\n* City bus (hostellites HBC)       : 11:00");
	if(time_now<=1130)
	printf("\n* City bus (hostellites HTC)       : 11:30");
	if(time_now<=1400)
	printf("\n* City bus (hostellites HBC)       : 14:00");
	if(time_now<=1410)
	printf("\n* City bus (hostellites HTC)       : 14:10");
	if(time_now<=1645)
	printf("\n* City bus (day scholars Hadapsar) : 16:45");
	if(time_now<=1645)
	printf("\n* City bus (day scholars Hinjewadi): 16:45");
	if(time_now<=1645)
	printf("\n* City bus (day scholars KP)       : 16:45");
	if(time_now<=1645)
	printf("\n* City bus (day scholars Wakadwadi): 16:45");
	if(time_now<=1700)
	printf("\n* City bus (hostellites HBC)       : 17:00");
	if(time_now<=1730)
	printf("\n* City bus (hostellites HTC)       : 17:30");
	if(time_now<=1800)
	printf("\n* City bus (hostellites HBC)       : 18:00");
	if(time_now<=1800)
	printf("\n* City bus (hostellites HTC)       : 18:00");
	if(time_now>1800)
	printf("\n\n\t\t\t-------NO BUS AVAILABLE-------");
	getch();
	system("cls");

}

//-----------------------------------------------------------------
//from city to the SIT
void current_city_bus_to()
{
	system("cls");
	printf("\n\t\t\tBuses from city to SIT from NOW:\n\n");
	int time_now;
	time_t rawtime;
	struct tm*  time_;
	time(&rawtime);
	time_ = localtime(&rawtime);
	printf("\nTIME:\t%d:%d", time_->tm_hour, time_->tm_min);
	time_now=( (time_->tm_hour*100) + time_->tm_min );
	
	//showing the buses sequentially according to the time
	if(time_now<=845)
	printf("\n* City bus (hostellites HBC)       : 08:45");
	if(time_now<=900)
	printf("\n* City bus (hostellites HTC)       : 09:00");
	if(time_now<=915)
	printf("\n* City bus (day scholars Hadapsar) : 09:15");
	if(time_now<=915)
	printf("\n* City bus (day scholars Hinjewadi): 09:15");
	if(time_now<=915)
	printf("\n* City bus (day scholars KP)       : 09:15");
	if(time_now<=915)
	printf("\n* City bus (day scholars Wakadwadi): 09:15");
	if(time_now<=1730)
	printf("\n* City bus (hostellites HTC)       : 17:30");
	if(time_now<=1900)
	printf("\n* City bus (hostellites HTC)       : 19:00");
	if(time_now<=2100)
	printf("\n* City bus (hostellites HBC)       : 21:00");
	if(time_now<=2100)
	printf("\n* City bus (hostellites HBC)       : 21:00");
	if(time_now<=2100)
	printf("\n* City bus (hostellites HTC)       : 21:00");
	if(time_now<=2100)
	printf("\n* City bus (hostellites HTC)       : 21:00");
	if(time_now<=2110)
	printf("\n* City bus (hostellites HTC)       : 21:10");
	if(time_now>2110)
	printf("\n\n\t\t\t-------NO BUS AVAILABLE-------");
	getch();
	system("cls");
	
}

//-----------------------------------------------------------------
//this is menu to display the current symbuses
void symbus()
{
	printf("\n\n\n\t\t\t1. From Hill Base to Hill top");
	printf("\n\n\t\t\t2. From Hill top to Hill Base");
	printf("\n\n\n\t\t\t3. Go back");
	switch(getch())
	{
		case '1':
			symbus_up();
			break;
		case '2':
			symbus_down();
			break;
		case '3':
			system("cls");
			//go back to the bus schedule selection
			return;
			break;
		default:
			printf("\nWrong choice Enter again!:\n");
			symbus();
	}
}

//-----------------------------------------------------------------
//symbus from hill base to hill top
void symbus_up()
{
	system("cls");
	printf("\n\t\t\tBuses from HILL-BASE to HILL-TOP from NOW:\n\n");
	int time_now;
	time_t rawtime;
	struct tm*  time_;
	time(&rawtime);
	time_ = localtime(&rawtime);
	printf("\nTIME:\t%d:%d", time_->tm_hour, time_->tm_min);
	time_now=( (time_->tm_hour*100) + time_->tm_min );
	
	//showing the buses sequentially according to the time
	if(time_now<=800)
	printf("\n\n* HBC : 08:00");
	if(time_now<=900)
	printf("\n\n* HBC : 09:00");
	if(time_now<=1000)
	printf("\n\n* HBC : 10:00");
	if(time_now<=1100)
	printf("\n\n* HBC : 11:00");
	if(time_now<=1200)
	printf("\n\n* HBC : 12:00");
	if(time_now<=1500)
	printf("\n\n* HBC : 15:00");
	if(time_now<=1600)
	printf("\n\n* HBC : 16:00");
	if(time_now<=1700)
	printf("\n\n* HBC : 17:00");
	if(time_now<=1830)
	printf("\n\n* HBC : 18:30");
	if(time_now<=1930)
	printf("\n\n* HBC : 19:30");
	if(time_now<=2030)
	printf("\n\n* HBC : 20:30");
	if(time_now<=2130)
	printf("\n\n* HBC : 21:30");
	if(time_now<=2230)
	printf("\n\n* HBC : 22:30");
	if(time_now<=2330)
	printf("\n\n* HBC : 23:30");
	if(time_now>2330)
	printf("\n\n\t\t\t-------NO BUS AVAILABLE-------");
	getch();
	system("cls");
}

//-----------------------------------------------------------------
//symbus from hill top to hill base
void symbus_down()
{
	system("cls");
	printf("\n\t\t\tBuses from HILL-TOP to HILL-BASE from NOW:\n\n");
	int time_now;
	time_t rawtime;
	struct tm*  time_;
	time(&rawtime);
	time_ = localtime(&rawtime);
	printf("\nTIME:\t%d:%d", time_->tm_hour, time_->tm_min);
	time_now=( (time_->tm_hour*100) + time_->tm_min );
	
	//showing the buses sequentially according to the time
	if(time_now<=830)
	printf("\n\n* HBC : 08:30");
	if(time_now<=930)
	printf("\n\n* HBC : 09:30");
	if(time_now<=1030)
	printf("\n\n* HBC : 10:30");
	if(time_now<=1130)
	printf("\n\n* HBC : 11:30");
	if(time_now<=1300)
	printf("\n\n* HBC : 13:00");
	if(time_now<=1530)
	printf("\n\n* HBC : 15:30");
	if(time_now<=1630)
	printf("\n\n* HBC : 16:30");
	if(time_now<=1730)
	printf("\n\n* HBC : 17:30");
	if(time_now<=1800)
	printf("\n\n* HBC : 18:00");
	if(time_now<=1900)
	printf("\n\n* HBC : 19:00");
	if(time_now<=2000)
	printf("\n\n* HBC : 20:00");
	if(time_now<=2100)
	printf("\n\n* HBC : 21:00");
	if(time_now<=2200)
	printf("\n\n* HBC : 22:00");
	if(time_now<=2300)
	printf("\n\n* HBC : 23:00");
	if(time_now>2300)
	printf("\n\n\t\t\t-------NO BUS AVAILABLE-------");
	getch();
	system("cls");
}
