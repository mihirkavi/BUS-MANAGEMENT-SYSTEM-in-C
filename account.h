//program after the successful login ofthe user

//header files
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//function declarations
void put_money(int money);
void selection(char* name_sign, char* password_sign, char* prn_sign);
void balance();
void recharge();
void schedule();
void ride();
void city_to_SIT();
void SIT_to_city();
void put_history(char bus_type[30], int time);
void start_timer();
void show_history();

//declarations of a file
FILE *fpstudent;
char filename[20];

//global declarations of student details once logged-in
char* name;
char* password;
char* prn;

//-----------------------------------------------------------------
//the first page which will open after login
void selection(char* name_sign, char* password_sign, char* prn_sign)
{
	//globally opening the file for editing
	name=name_sign;
	password=password_sign;
	prn=prn_sign;
	
	sprintf(filename, "%s.txt", name);
	fpstudent=fopen(filename, "a+");
	
	//menu inside the login
	while(1)
	{
		printf("\n\n\n\t\t\t1.Balance");
		printf("\n\n\t\t\t2.Recharge");
		printf("\n\n\t\t\t3.Schedule and catalog");
		printf("\n\n\t\t\t4.Book a ride");
		printf("\n\n\t\t\t5.Booking History");
		printf("\n\n\t\t\t6.Logout\n");
		switch(getch())
		{
			case '1':
				system("cls");
				balance();
				break;
			case '2':
				system("cls");
				recharge();
				break;
			case '3':
				system("cls");
				//it redirects to the main program ie. membership
				//from there it is taken to the DSA_project.h file where the schedule is specified
				return;
				break;
			case '4':
				system("cls");
				ride();
				break;
			case '5':
				show_history();
				break;	
			case '6':
				system("cls");
				exit(0);
				break;
			default:
				printf("\nWrong choice! Enter again\n"); 
		}
	}
}

//-----------------------------------------------------------------
//funciton to check the balance
void balance()
{
	int money=0; 
	system("cls");
	printf("\n\n\t\t\tYour balance is:\n");
	
	//going to the desired position
	int size_skip=( strlen(name) + strlen(password) + strlen(prn) ); //to setting the cursor to the balance place
	fseek(fpstudent, (size_skip+5), SEEK_SET); //now it is set to the prn of the student 
	fscanf(fpstudent, "\n%d", &money);//reading the amount of balance
	printf("\n\n\t\t\t%d", money); //printing the balance of the studenton screen
	
	getch();
	system("cls");
	
	
}

//-----------------------------------------------------------------
//menu to recharge
void recharge()
{
	int money;
	printf("\nEnter the amount to be recharged:\t");
	scanf("\n\n\t\t\t%d", &money);
	printf("\n\n\t\t\t1.Confirm");
	printf("\n\n\t\t\t2.Put again\n");
	printf("\n\n\t\t\t3.Go back");
	
	switch(getch())
	{
		case '1':
			put_money(money);
			break;
		case '2':
			recharge();
			break;
		case '3':
			system("cls");
			return;
			break;
		default:
			system("cls");
			printf("\nWrong choice");
			recharge();
	}
}

//-----------------------------------------------------------------
//this function is used for booking a ride and making payment
void ride()
{
	//first we have to provide the catalog again so that the user chooses from the buses
	printf("\n\tChoose the bus from following:\n");
	printf("\n\n\t\t\t1. Buses from SIT to city");
	printf("\n\n\t\t\t2. Buses from city to SIT");
	switch(getch())
	{
		case '1':
			system("cls");
			SIT_to_city();
			break;
		case '2':
			system("cls");
			city_to_SIT();
			break;
		default:
			printf("\nEnter the choice within specified!\n");
			system("cls");
			ride();
	}
}

//-----------------------------------------------------------------
//program to put money in the file of the student
void put_money(int money)
{
	//entering login credentials in place of card credentials
	char password_try[20];
	printf("\n\n\t\t\tEnter your card number (password for demonstration):\t");
	scanf("%s", password_try);
	
	//checking credentials again:
	int check=strcmp(password, password_try);
	if(check!=0)
	{
		system("cls");
		printf("\n\n\t\t\tWrong password! Try again!:\t");
		put_money(money);
	}
	else
	{
		//updating the balance
		int bal=0;
		int size_skip=( strlen(name) + strlen(password) + strlen(prn) ); //to setting the cursor to the balance place
		fseek(fpstudent, (size_skip+5), SEEK_SET); //now it is set to the prn of the student 
		fscanf(fpstudent, "\n%d", &bal);
		
		bal=bal+money;
		
		fclose(fpstudent);
		fpstudent=fopen(filename, "r+");
		fseek(fpstudent, (size_skip+5), SEEK_SET); 
		fprintf(fpstudent, "\n%d ", bal);
		fclose(fpstudent);
		fpstudent=fopen(filename, "a+");
		
		//delivery message
		printf("\n\n\t\t\tTransaction successfull");
		printf("\n\n\t\t\tNow available balance:\t%d", bal);
		getch();
		system("cls");
	}
}

//-----------------------------------------------------------------
//function which displays the catalog of out-going buses
void SIT_to_city()
{
	//displaying
	printf("\na. * City bus (hostellites HBC)       : 08:00");
	printf("\n\nb. * City bus (hostellites HTC)       : 08:30");
	printf("\n\nc. * City bus (hostellites HBC)       : 11:00");
	printf("\n\nd. * City bus (hostellites HTC)       : 11:30");
	printf("\n\ne. * City bus (hostellites HBC)       : 14:00");
	printf("\n\nf. * City bus (hostellites HTC)       : 14:10");
	printf("\n\ng. * City bus (day scholars Hadapsar) : 16:45");
	printf("\n\nh. * City bus (day scholars Hinjewadi): 16:45");
	printf("\n\ni. * City bus (day scholars KP)       : 16:45");
	printf("\n\nj.* City bus (day scholars Wakadwadi) : 16:45");
	printf("\n\nk.* City bus (hostellites HBC)        : 17:00");
	printf("\n\nl.* City bus (hostellites HTC)        : 17:30");
	printf("\n\nm.* City bus (hostellites HBC)        : 18:00");
	printf("\n\nn.* City bus (hostellites HTC)        : 18:00");
	
	//first checking the balance before leting user to choose the bus
	int bal=0;
	int size_skip=( strlen(name) + strlen(password) + strlen(prn) ); //to setting the cursor to the balance place
	fseek(fpstudent, (size_skip+5), SEEK_SET); //now it is set to the prn of the student 
	fscanf(fpstudent, "\n%d", &bal);
	
	//condition which checks whether the balance is too low or not
	if(bal<0)
	{
		printf("\n\n\t\t\tInsufficient balance to book the bus!\n");
		printf("\n\n\t\t\tRedirecting to the main menu:\n");
		getch();
		system("cls");
		return;
	}
	
	//part of the function which lets the user to choose the bus
	//this is then passed into a file in the history
	int time;
	char bus_type1[]="city_HBC_out";
	char bus_type2[]="city_HTC_out";
	char Hadapsar[]="Hadapsar_out";
	char Hinjewadi[]="Hinjewadi_out";
	char KP[]="KP_out";
	char Wakadwadi[]="Wakadwadi_out";
	printf("\n\nEnter the bus to board");
	switch(getch())
	{
		case 'a':
			put_history(bus_type1, 800);
			break;
		case 'b':
			put_history(bus_type2, 830);
			break;
		case 'c':
			put_history(bus_type1, 1100);
			break;
		case 'd':
			put_history(bus_type2, 1130);
			break;
		case 'e':
			put_history(bus_type1, 1400);
			break;
		case 'f':
			put_history(bus_type2, 1410);
			break;
		case 'g':
			put_history(Hadapsar, 1645);
			break;
		case 'h':
			put_history(Hinjewadi, 1645);
			break;
		case 'i':
			put_history(KP, 1645);
			break;
		case 'j':
			put_history(Wakadwadi, 1645);
			break;
		case 'k':
			put_history(bus_type1, 1700);
			break;
		case 'l':
			put_history(bus_type2, 1730);
			break;
		case 'm':
			put_history(bus_type1, 1800);
			break;
		case 'n':
			put_history(bus_type2, 1800);
			break;
		default:
			system("cls");
			printf("Enter the choice within!");
			SIT_to_city();
	}
}

//-----------------------------------------------------------------
//function which displays the catalog of in-coming buses
void city_to_SIT()
{
	//displaying
	printf("\n\na. * City bus (hostellites HBC)       : 08:45");
	printf("\n\nb. * City bus (hostellites HTC)       : 09:00");
	printf("\n\nc. * City bus (day scholars Hadapsar) : 09:15");
	printf("\n\nd. * City bus (day scholars Hinjewadi): 09:15");
	printf("\n\ne. * City bus (day scholars KP)       : 09:15");
	printf("\n\nf. * City bus (day scholars Wakadwadi): 09:15");
	printf("\n\ng. * City bus (hostellites HBC)       : 17:30");
	printf("\n\nh. * City bus (hostellites HTC)       : 19:00");
	printf("\n\ni. * City bus (hostellites HBC)       : 21:00");
	printf("\n\nj. * City bus (hostellites HTC)       : 21:00");
	printf("\n\nk. *  City bus (hostellites HBC)      : 21:00");
	printf("\n\nl. *  City bus (hostellites HTC)      : 21:00");
	printf("\n\nm.*  City bus (hostellites HBC)       : 21:00");
	
	//first checking the balance before leting user to choose the bus
	int bal=0;
	int size_skip=( strlen(name) + strlen(password) + strlen(prn) ); //to setting the cursor to the balance place
	fseek(fpstudent, (size_skip+5), SEEK_SET); //now it is set to the prn of the student 
	fscanf(fpstudent, "\n%d", &bal);
	
	//condition which checks whether the balance is too low or not
	if(bal<0)
	{
		printf("\n\n\t\t\tInsufficient balance to book the bus!\n");
		printf("\n\n\t\t\tRedirecting to the main menu:\n");
		getch();
		system("cls");
		return;
	}
	
	//part of the function which lets the user to choose the bus
	//this is then passed into a file in the history
	int time;
	char bus_type1[]="city_HBC_in";
	char bus_type2[]="city_HTC_in";
	char Hadapsar[]="Hadapsar_in";
	char Hinjewadi[]="Hinjewadi_in";
	char KP[]="KP_in";
	char Wakadwadi[]="Wkdwdi_in";
	printf("\n\nEnter the bus to board");
	switch(getch())
	{
		case 'a':
			put_history(bus_type1, 845);
			break;
		case 'b':
			put_history(bus_type2, 900);
			break;
		case 'c':
			put_history(Hadapsar, 915);
			break;
		case 'd':
			put_history(Hinjewadi, 915);
			break;
		case 'e':
			put_history( KP, 915);
			break;
		case 'f':
			put_history(Wakadwadi, 915);
			break;
		case 'g':
			put_history(bus_type1, 1730);
			break;
		case 'h':
			put_history(bus_type2, 1900);
			break;
		case 'i':
			put_history(bus_type1, 21);
			break;
		case 'j':
			put_history(bus_type2, 1645);
			break;
		case 'k':
			put_history(bus_type1, 1700);
			break;
		case 'l':
			put_history(bus_type2, 1730);
			break;
		case 'm':
			put_history(bus_type1, 1800);
			break;
		default:
			system("cls");
			printf("Enter the choice within!");
			city_to_SIT();
	}
}

//-----------------------------------------------------------------
//function which records the history of buses of a user
void put_history(char bus_type[30], int time)
{
	//the part which puts the above as a history entry
	fclose(fpstudent);
	fpstudent=fopen(filename, "a+");
	fprintf(fpstudent, "\n\n\n");
	fprintf(fpstudent, "\n%s\t%d:%d", bus_type, (time/100), (time%100));
	fclose(fpstudent);
	fpstudent=fopen(filename, "a+");
	start_timer();
}

//-----------------------------------------------------------------
//this starts the timer of the pc to evaluate money to be cut
void start_timer()
{
	
	int start_time, end_time, time_travelled;
	printf("\n\n\t\t\tSwipe the card to board the bus (press any key for demonstration):\t");
	getch();
	system("cls");
	printf("\nYou have boarded the bus");
	printf("\nSwipe the card to depart (press any key for demonstration)");
	//starting the timer of the time.h
	start_time=clock();
	getch();
	end_time=clock();
	time_travelled= ( ( end_time - start_time ) / CLOCKS_PER_SEC );
	if(time_travelled==0)
	{
		printf("\n\n0 record time, no evaluation!");
		start_timer();
	}
	else
	{
		printf("\nThe time elapsed in travelling:\t%d seconds", time_travelled);
		getch();
		int evaluation=(100*time_travelled);
		printf("\nBill:\nRs.%d", evaluation);
		evaluation=(-1)*evaluation;
		//calling the function for opening the file and editing the payment balance
		put_money(evaluation);
	}
}

//-----------------------------------------------------------------
//function to show the booking history
void show_history()
{
	system("cls");
	int bal=0;
	int sr_no=0;
	char bus_type[10], colon;
	int time, time1; 
	int size_skip=( strlen(name) + strlen(password) + strlen(prn) ); //to setting the cursor to the balance place
	fseek(fpstudent, (size_skip+5), SEEK_SET); //now it is set to the prn of the student 
	fscanf(fpstudent, "%d", &bal);
	printf("\nCheck balance: %d\n", bal);
	printf("\n\nHistory of buses you have traveled in:\n");
	printf("\n\nBUS-TYPE DEPARTURE-TIME\n\n");
	while( !feof(fpstudent) )
   {
      fscanf(fpstudent,"%s%d%c%d", bus_type, &time, &colon, &time1);
      printf("%d)\t%s %d:%d", ++sr_no, bus_type, time, time1);
      printf("\n\n");
   }
   getch();
   system("cls");
}

