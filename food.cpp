//#include "food.h"
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include <bits/stdc++.h>
#include<conio.h>
using namespace std;



void mainmenu(void);
void administration(void);

int checkid(int);
int getdata();
void addrecord(void);
void searchrecord(void);
void deleterecord(void);

int add(int,int);
struct menu
{

	//char name[30];
	int id;
	char name[30];
	//char DOB[10];
	int price;
};
struct menu m;

struct employee
{

	char name[30];
	int id;
	//char DOB[10];
	int dd; int mm; int yyyy;
	int YOJ;
	char place[20];
	float salary;
	char department[20];

	int quantity;
};
struct employee e;

//fstream fp,ft,dp,dt;
FILE *fp,*ft,*dp,*dt;

int s;
char findrecord;
int again;
int quantity;
double total=0;
int t;
char password[20]="123321";

int main()
{
	mainmenu();
	return 0;
}


int add(int a, int b)
{
	return a+b;
}

void mainmenu(void)
{
	system("cls");
	cout<<"                           **************************************************************************\n";
	cout<<"                                          WELCOME TO FOOD ORDER MANAGEMENT SYSTEM\n";
	cout<<"                           **************************************************************************\n\n\n";
	cout<<"          1. ADMINISTRATION SECTION--> \n\n          2. CUSTOMER SECTION--> \n\n          3. Exit--> \n\n\n             Enter Your Choice --->";
	int choice;

	cin>>choice;
	if(choice==1)
	{
//	    Password();
		administration();
	}
	else if(choice==2)
	{
		////customer();
//		viewmenu();

    }
	else if(choice==3)
	{
		system("cls");
		cout<<"\n\n\n";
		cout<<"*********************************************************THANK YOU****************************************************************\n";

		cout<<"*************************************************Feeling HUNGRY ? Call or Walk-In***********************************************\n\n";
		exit(0);
	}
	else
	{
		printf("Wrong Input !! PLease Re-enter The Correct Option");
		if(getch())
		mainmenu();
	}



}

void administration(void)
{
	system("cls");
	cout<<"\n\n*************************************************WELCOME TO THE ADMIN SECTION****************************************************\n\n";
	cout<<"          1. Add New Record\n\n          2. Search Record\n\n          3. Delete Record\n\n          4. View Employee Records\n\n          5. View previous orders\n\n          6. Add Food\n\n          7. Delete Food\n\n          8. View Menu\n\n          0. Back To Main Menu \n\n             Enter Your Choice --->";
	int n;
	cin>>n;
    cout<<"\n\n";
	int wait;
	//printf("In progress :");
	/*
	for(wait=0;wait<=10000;wait++)
	{
		cout<<"\rIn progress : "<<wait/100;
	}
	*/
	//cout<<"\n\n";
	if(n==1)
	{
		addrecord();
	}
	else if(n==2)
	{
		searchrecord();
	}
	else if(n==3)
	{
		deleterecord();
	}
	else if(n==4)
	{
		//viewrecord();
	}
		else if(n==5)
	{
		fstream view;
		//char viw;
		string word,filename;
		//view.open("order.txt",ios::out);
		system("cls");
		//while((viw=fgetc(view))!=EOF)
		//{
			//cout<<viw;
		//}

		filename= "order.txt";
		view.open(filename.c_str());
		while(view>>word)
        {
            cout<<word<<endl;
        }
		view.close();
	}
	else if(n==6)
    {
        system("cls");
        //addfood();
    }
    else if(n==7)
    {
        system("cls");
        //deletefood();
    }
    else if(n==8)
    {
        system("cls");
        //viewmenu1();
    }
	else if(n==0)
	{
		system("cls");
		mainmenu();
	}
	else
	{
		printf("Wrong Input !! PLease Re-enter The Correct Option");
		if(getch())
		administration();
	}

}

void addrecord(void)
{
	system("cls");
	//fp=fopen("record.txt","a");
	if(getdata()==1)
	{
	    fp=fopen("record.txt","a");
		fseek(fp,0,SEEK_END);
		fwrite(&e,sizeof(e),1,fp);
		fclose(fp);
		cout<<"\n\n";
		cout<<"The Record Is Successfully Saved ! !\n\n";
		cout<<"Save any more?(Y / N): ";
		if(getch()=='n')
	    	administration();
		else
	    	system("cls");
	    	addrecord();
	}
}




int checkid(int c)  //check whether the record is exist in list or not
{

    int temp=1;
	//rewind(fp);
	//printf("%d",fp);
	fp=fopen("record.txt","r");
	//printf("outside while\n");
	//printf("%d\n",fread(&e,sizeof(struct employee),1,fp));
	//printf("%d",e.id);
	while(fread(&e,sizeof(struct employee),1,fp)==1)
	{
	    if(e.id==c)
        {
            temp=0;  //returns 0 if employee exits
            break;
        }
	}
	return temp; //return 1 if it not
}

int getdata()
{
	//*int t;
	cout<<"        Employee ID :\t";
	cin>>t;
	//printf("%d",checkid(t));
	if(checkid(t)==0)
	{
		cout<<"\n\n";
		cout<<"\a                        The Employee Record Already Exists !!!\a";
		getch();
		administration();
		return 0;
	}
	e.id=t;
	cout<<"        Employee Name : ";
	cin>>e.name;
	cout<<"        Date Of Birth (dd/mm/yyyy) :";
	cin>>e.dd>>e.mm>>e.yyyy;
	cout<<"        Year OF Joining :";
	cin>>e.YOJ;
	cout<<"        Place :";
	cin>>e.place;
	cout<<"        Department :";
	cin>>e.department;
	return 1;
}

void searchrecord(void)
{
	system("cls");
	char findrecord='f';
    int d;
    cout<<"\n\n**************************************************Search Employees Record********************************************************\n\n";
    cout<<"                  1. Search By ID\n";
    cout<<"                  2. Search By Name\n\n";
    cout<<"                  Enter Your Choice---> ";
    fp=fopen("record.txt","r"); //open file for reading propose
    rewind(fp);   //move pointer at the begining of file
    switch(getch())
    {
	  case '1':
		{
	    	system("cls");
	    	cout<<"\n\n****************************************************Search Record By ID**********************************************************\n\n";
	    	cout<<"                Enter The Employee ID : ";
	    	cin>>d;
	    	cout<<"\n\n";
			cout<<"Searching........";
	    	while(fread(&e,sizeof(e),1,fp)==1)
	    	{
				if(e.id==d)
				{
		    		cout<<"\n\n...................................................The Record is available.....................................................\n\n\n";
                    cout<<"       ID : "<<e.id<<endl<<endl;
                    cout<<"       Name : "<<e.name<<endl<<endl;
                    cout<<"       Date OF Birth : "<<e.dd<<"/"<<e.mm<<"/"<<e.yyyy<<endl<<endl;
                    cout<<"       Year Of Joining :"<<e.YOJ<<endl<<endl;
                    cout<<"       Department :"<<e.department<<endl<<endl;
                    cout<<"       Place :"<<e.place<<endl<<endl;
				    findrecord='t';
				}

            }
            if(findrecord!='t')  //checks whether conditiion enters inside loop or not
            {
                cout<<"\aNo Record Found\a";
                cout<<endl<<endl;
            }
            cout<<"Try Another Search ? (y/n)";
            if(getch()=='y')
            searchrecord();
            else
            administration();
            break;
        }
        case '2':
        {
            char s[15];
            system("cls");
            cout<<"\n\n**************************************************Search Employees By Name*******************************************************\n\n";
            cout<<"               Enter Employee Name : ";
            cin>>s;
            int d=0;
            while(fread(&e,sizeof(e),1,fp)==1)
            {
                if(strcmp(e.name,(s))==0) //checks whether a.name is equal to s or not
                {
                    cout<<"\n\n...................................................The Record is available.....................................................\n\n\n";
                    cout<<"       ID : "<<e.id<<endl<<endl;
                    cout<<"       Name : "<<e.name<<endl<<endl;
                    cout<<"       Date OF Birth : "<<e.dd<<"/"<<e.mm<<"/"<<e.yyyy<<endl<<endl;
                    cout<<"       Year Of Joining :"<<e.YOJ<<endl<<endl;
                    cout<<"       Department :"<<e.department<<endl<<endl;
                    cout<<"       Place :"<<e.place<<endl<<endl;
                    d++;
                }

            }
            if(d==0)
            {
                cout<<"\aNo Record Found\a";
            }
            cout<<"Try Another Search ? (Y/N)";
            if(getch()=='y')
            searchrecord();
            else
            administration();
            break;
        }
        default :
        getch();
        searchrecord();
    }
    fclose(fp);
}

void deleterecord(void)
{
	system("cls");
    int d;
    char another='y';
    findrecord='f';
    while(another=='y')  //infinite loop
    {
	system("cls");
	cout<<"                Enter The Employee ID To Delete :";
	cin>>d;
	fp=fopen("record.txt","r+");
	rewind(fp);
	while(fread(&e,sizeof(e),1,fp)==1)
	{
	    if(e.id==d)
	    {
			cout<<endl<<endl;
			cout<<"\n\n..............................................The Employee Record Is Available...................................................\n\n"<<endl<<endl;
			cout<<"               Employee Name Is "<<e.name<<endl<<endl;
			findrecord='t';
	    }
	}
	if(findrecord!='t')
	{
	    cout<<"\n\n............................................No record is found modify the search.................................................\n\n"<<endl<<endl;
	    if(getch())
	    administration();
	}
	if(findrecord=='t' )
	{
	    cout<<"Do You Want To Delete THe Record ? (Y/N) ";
	    if(getch()=='y')
	    {
			ft=fopen("test1.txt","w");  //temporary file for delete
			rewind(fp);
			while(fread(&e,sizeof(e),1,fp)==1)
			{
		    	if(e.id!=d)
		    	{
					fseek(ft,0,SEEK_CUR);
					fwrite(&e,sizeof(e),1,ft); //write all in tempory file except that
		    	}                              //we want to delete
			}
			fclose(ft);
			fclose(fp);
			remove("record.txt");
			rename("test1.txt","record.txt"); //copy all item from temporary file to fp except that
			fp=fopen("record.txt","r");    //we want to delete
			if(findrecord=='t')
			{
                cout<<"        THE RECORD IS SUCCESSFULLY DELETED.\n\n";
		    	cout<<"        Delete Another Record ? (Y/N) : ";
			}
	    }
		else
		administration();
		fflush(stdin);
		another=getch();
	}
    }
administration();
}
