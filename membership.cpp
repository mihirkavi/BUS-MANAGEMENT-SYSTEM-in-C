//this is the main page program which allows the user to log in

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include "account.h"
#include "DSA_project.h"

//functions declarations
void register_member();
void already_member();
void menu_flow();
void admin_login();
void check_member();

//-----------------------------------------------------------------
//declaration of structure of the student datatype
struct student_info
{
	char name[20];
	char prn[15];
	char password[10];
}students;

//-----------------------------------------------------------------
//this is the main function which displays the very first page after starting the application
int main()
{
	//main menu 
	system("cls");
	
	while(1)
	{
		printf("\n\t  Enter the choice within the following: \n");
		printf("\n\n\n\t\t\t1. Log in");
		printf("\n\n\t\t\t2. Register\n");
		
		switch(getch())
		{
			case '1':
				already_member();
				break;
			case '2':
				register_member();
				break;
			default:
				printf("\nWrong choice");
		}
	}
	getch();
	return 0;
}

//-----------------------------------------------------------------
//this function registers a new member at a time
void register_member()
{
	system("cls");
	printf("\nRegistration");
	printf("\n\n\t\t\tEnter the details as given");
	
	//name
	printf("\n\n\t\t\tEnter Username:\t");
	scanf("%s", students.name);
	
	//check whether the username already taken or not
	char check[15];
	sprintf(filename,"%s.txt", students.name);
	fpstudent=fopen(filename, "r");
	fscanf(fpstudent, "%s", check);
	fclose(fpstudent);
	int compare=strcmp(check,students.name);
	if(compare==0)
	{
		printf("\n\n\t\t\tUsername already taken, please choose another:");
		getch();
		register_member();
	}
	
	//prn
	printf("\n\n\t\t\tEnter prn:\t");
	scanf("%s", students.prn);
	while(1)
	{
		if(strlen(students.prn)<11)//the prn must be eight digit long
		{
			printf("\nInvalid prn, enter prn again:\n");
			scanf("\n%s", students.prn);
		}
		else
		break;
	}
	
	
	//password
	printf("\n\n\t\t\tEnter password:\t");
	scanf("%s", students.password);
	while(1)
	{
		if(strlen(students.password)<6)//the password must be atleast 7 digit long
		{
			printf("\n Too short! Enter password again:\n");
			scanf("\n%s", students.password);
		}
		else
		break;
	}
	
	//displays the credentials just entered by the user
	system("cls");
	printf("\nCheck credentials: ");
	printf("\n\n\t\t\tUSERNAME:\t%s", students.name);
	printf("\n\n\t\t\tPRN:\t%s", students.prn);
	printf("\n\n\t\t\tPASSWORD:\t%s", students.password);
	
	//confirmation
	char y_n;
	printf("\n\n\t\t\tWant to enter again? (y/n)\n");
	if((y_n=getch())=='y')
	register_member();
	else if(y_n=='n')
	{
		system("cls");
		//deliver message
		printf("\nSuccessfully registered!\n");
		printf("\nWelcome, %s!", students.name);
		
		//we have to load the registered details of a member into a new file
		sprintf(filename,"%s.txt", students.name);
		fpstudent=fopen(filename, "a");
		fprintf(fpstudent, "%s", students.name);
		fprintf(fpstudent, "\n%s", students.password);
		fprintf(fpstudent, "\n%s", students.prn);
		fclose(fpstudent);
		//it should redirect to a function which decides the inner access of flow
		menu_flow();
	}
}

//-----------------------------------------------------------------
//this is the function which manages the members login
void already_member()
{
	system("cls");
	
	//string to compare with the registered string
	char name_sign[20];
	char password_sign[20];
	
	//prompt to enter the credentials to sign-in
	printf("\nMember sign in");
	printf("\n\n\t\t\tUSERNAME:\t");
	scanf("%s", name_sign);//signin name
	
	//this is to check whether the member has registered or not
	//opening the file of the member:
	char read_text[20];
	sprintf(filename, "%s.txt", name_sign);
	fpstudent=fopen(filename, "r");
	
	fscanf(fpstudent,"%s", read_text);
	
	//condition of lack of existance of file
	int check=strcmp(name_sign, read_text);
    if(check!=0)
    {
    	printf("\n\n\t\t\tYou have not registered!");
    	printf("\n\n\t\t\tDo you want to register? (y/n)");
    	if(getch()=='y')
    	register_member();
    	else
    	system("cls");
    	return;
	}
	
	
	
	printf("\n\n\t\t\tPASSWORD:\t");
	scanf("%s", password_sign);//signin password
	
	//now we are going to check the entered credentials
	int check1, check2;
	char name[20], password[20], prn_sign[20]; //variables to store the read value
	
	//opening the file of the user
	sprintf(filename,"%s.txt", name_sign);
	fpstudent=fopen(filename,  "r");
	fscanf(fpstudent,"%s", name);
	fscanf(fpstudent,"%s", password);
	fscanf(fpstudent,"%s", prn_sign);
	fclose(fpstudent);//closing the file
	
	//compare whether the login is a normal login or an admin
	int compare=strcmp("admin", name_sign);
	if(compare==0)
	admin_login();
	
	//comparing with the names and password of the file
	check1=strcmp(name, name_sign);//to check the sign in name
	check2=strcmp(password, password_sign);//to check the sign in password
	
	if(check1==0 && check2==0)
	{
		system("cls");
		printf("\nLog in successfull");
		printf("\n\n\t\t\tWELCOME %s!", name_sign);
		//first we should set the global variables with above
		strcpy(students.name, name_sign);
		strcpy(students.password, password_sign);
		strcpy(students.prn, prn_sign);
		//it should redirect to a function which decides the inner access of flow
		menu_flow();
	}
	else
	{
		system("cls");
		printf("\nWrong credentials!");
		printf("\n\n\t\t\t1.Register");
		printf("\n\n\t\t\t2.Back\n");
		
		switch(getch())
		{
			case '1': 
				register_member();
				break;
			case '2':
				already_member();
				break;
			default:
				printf("Wrong choice!");
		}	
	}
}

//-----------------------------------------------------------------
//this function decides the flow of how to access the menu further
void menu_flow()
{
	//the funciton selection and menu_schedule can only be called by the main program
	selection(students.name, students.password, students.prn);
	//again the case where it has to access the schedule
	menu_schedule(students.name, students.password, students.prn);
	system("cls");
	menu_flow();
}

//-----------------------------------------------------------------
//this is the function which enables various operations for the admin
void admin_login()
{
	system("cls");
	printf("\n\n\t\t\t----ADMIN LOGIN----");
	printf("\n\n\t\t\t1.Check member's Info");
	printf("\n\n\t\t\t2.User's menu");
	printf("\n\n\n\t\t\t3.Log-out\n");
	switch(getch())
	{
		case '1':
			system("cls");
			check_member();
			break;
		case '2':
			//this redirects it to the normal member login
			break;
		case '3':
			system("cls");
			exit(0);
		default:
			printf("\n\n\t\t\tEnter the choice within:");
			admin_login();
	}
}

//-----------------------------------------------------------------
//this is the function which allows the admin to check the details of members
void check_member()
{
	char name[20], read_text[20];
	int sr_no=0;
	char bus_type[10], colon;
	int time, time1;
	
	printf("\n\n\t\t\tEnter the Name of the person:\t");
	scanf("%s", name);
	
	//opening the file of the member:
	sprintf(filename, "%s.txt", name);
	fpstudent=fopen(filename, "r");
	
	fscanf(fpstudent,"%s", read_text);
	
	//condition of lack of existance of file
	int check=strcmp(name, read_text);
    if(check!=0)
    {
    	printf("\n\n\t\t\tNo such directory found!");
    	check_member();
	}
	
    printf("\n\n\t\t\tUSERNAME:%s", read_text);
    
    fscanf(fpstudent,"%s", read_text);
    //printf("\n\n\t\t\t%s", read_text);
	
	fscanf(fpstudent,"%s", read_text);
    printf("\n\n\t\t\tPRN:%s", read_text);
      
    fscanf(fpstudent,"%s", read_text);
    printf("\n\n\t\t\tBALANCE:%s", read_text);
    
    printf("\n\nShowing the history of the user:\n\n");
      
	while( !feof(fpstudent) )
   {
	fscanf(fpstudent,"%s%d%c%d", bus_type, &time, &colon, &time1);
    printf("%d)\t%s %d:%d", ++sr_no, bus_type, time, time1);
    printf("\n\n");
   }
   char y_n;
   printf("\n\n\t\t\tCheck another member? (y/n)");
   if( ( y_n=getch() )=='y')
   check_member();
   
   system("cls");
   admin_login();
}
