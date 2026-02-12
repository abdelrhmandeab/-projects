#include<iostream>
#include<conio.h>
#include<fstream>
#include<iomanip>
#include<cstring>
#include<Windows.h>
using namespace std;

void menu();
void passcode();
void cpasscode();

class one
{
public:
	virtual void get() = 0;
	virtual void show() = 0;
};

class info :public one
{
public:
	char name[50], time[50],all[999];
	int num, age;
	void get() {
		system("cls");
		cin.sync();
		cout << "\n Enter the patient's name : ";
		cin.getline(name, 50);
		cout << "\n Enter the Appointment Time : ";
		cin.getline(time, 50);
		cout << "\n Enter the patient's age : ";
		cin >> age;
		cout << "\n Enter the phone nmuber : ";
		cin >> num;
	}
	void show()
	{
		cout << "\nName : " << name;
		cout << "\nAge : " << age;
		cout << "\n phone number : " << num;
		cout << "\nAppointment time : " << time;
	}
};

class Mayada :public info
{
public:
	info a1;
	void get()
	{
		ofstream out("Mayada.txt", ios::app);
		system("cls");
		cin.sync();
		cout << "\n Enter the patient's name : ";
		cin.getline(name, 50);
		cout << "\n Enter the Appointment Time : ";
		cin.getline(time, 50);
		cout << "\n Enter the patient's age : ";
		cin >> age;
		cout << "\n Enter the phone nmuber : ";
		cin >> num;

		out << "\n patient's name : "<<name;
		out << "\n Appointment Time : "<<time;
		out << "\n Enter the patient's age : "<<age;
		out << "\n phone nmuber : "<<num;
		out.close();
		cout<<"your information has been saved \n\t\t Press any key to continue ";
		getch();
		menu();
	}
	void show()
	{
		ifstream in("Mayada.txt");
		if (!in)
		{
			cout << "\n\nNo data in the file ";
			cout << "\n\n\t\tPress any key to continue : ";
			getch();
			menu();
		}
		else {
			while (!in.eof())
			{
				in.getline(all,999);
				cout<<all<<"\n";
			}
			in.close();
			cout << "Press Enter to continue : ";
			getch();
			menu();

		}
	}

};
/////////////////////////////////////////////////////////////

class Ismaiel :public info
{
public:
	info a1;
	void get()
	{
		ofstream out("Ismaiel.txt", ios::app);
		system("cls");
		cin.sync();
		cout << "\n Enter the patient's name : ";
		cin.getline(name, 50);
		cout << "\n Enter the Appointment Time : ";
		cin.getline(time, 50);
		cout << "\n Enter the patient's age : ";
		cin >> age;
		cout << "\n Enter the phone nmuber : ";
		cin >> num;

		out << "\n patient's name : "<<name;
		out << "\n Appointment Time : "<<time;
		out << "\n Enter the patient's age : "<<age;
		out << "\n phone nmuber : "<<num;
		out.close();
		cout<<"your information has been saved \n\t\t Press any key to continue ";
		getch();
		menu();
	}
	void show()
	{
		ifstream in("Ismaiel.txt");
		if (!in)
		{
			cout << "\n\nNo data in the file ";
			cout << "\n\n\t\tPress any key to continue : ";
			getch();
			menu();
		}
		else {
			while (!in.eof())
			{
				in.getline(all,999);
				cout<<all<<"\n";
			}
			in.close();
			cout << "Press Enter to continue : ";
			getch();
			menu();

		}
	}

};
////////////////////////////////////////////////
class Mohamed :public info
{
public:
	info a1;
	void get()
	{
		ofstream out("Mohamed.txt", ios::app);
		system("cls");
		cin.sync();
		cout << "\n Enter the patient's name : ";
		cin.getline(name, 50);
		cout << "\n Enter the Appointment Time : ";
		cin.getline(time, 50);
		cout << "\n Enter the patient's age : ";
		cin >> age;
		cout << "\n Enter the phone nmuber : ";
		cin >> num;

		out << "\n patient's name : "<<name;
		out << "\n Appointment Time : "<<time;
		out << "\n Enter the patient's age : "<<age;
		out << "\n phone nmuber : "<<num;
		out.close();
		cout<<"your information has been saved \n\t\t Press any key to continue ";
		getch();
		menu();
	}
	void show()
	{
		ifstream in("Mohamed.txt");
		if (!in)
		{
			cout << "\n\nNo data in the file ";
			cout << "\n\n\t\tPress any key to continue : ";
			getch();
			menu();
		}
		else {
			while (!in.eof())
			{
				in.getline(all,999);
				cout<<all<<"\n";
			}
			in.close();
			cout << "Press Enter to continue : ";
			getch();
			menu();

		}
	}

};
class staff :public one
{
public:
	char all[999], name[50], pos[50],age[20],sal[30];
	void get()
	{
		ofstream out("staff.txt", ios::app);

			system("cls");
			cin.sync();
			cout << "\nEnter Name : ";
			cin.getline(name,50);
			cout << "\nEnter age : ";
			cin.getline(age, 20);
			cout << "\nEnter salary : ";
			cin.getline(sal, 30);
			cout << "\nEnter working position : ";
			cin.getline(pos, 50);

		out<< "\nName : " <<name;
		out<< "\nAge : " <<age;
		out<< "\nSalary : "<<sal;
		out<< "\nWorking position : " <<pos;

		out.close();
		cout << "Your information has been save \n\t\t Press any key to continue ";
		getch();
		menu();
	}
	void show()
	{
		ifstream in("staff.txt");
		system("cls");
		if (!in)
		{
			cout << "No data in file ";
			cout << "\n\n\t\tPress any key to continue : ";
			getch();
			menu();
		}
		while (!(in.eof()))
		{
			in.getline(name,998);
			cout << name << "\n";
		}
		in.close();
		cout << "\n\n\t\tPress any key to continue : ";
		getch();
		menu();
	}

};
//////////////////////////////////////////
class informaton
{
public:
	void drinfo()
	{
		system("cls");
		system("color F3");
		cout << "\n-------------------------------------------------------------------------------------------------------------\n";
		cout << "\n\n\t\t(Three doctors available) \n\n\t\t[Information and timing are given below]\n";
		cout << "---------------------------------------------------------------------------------------------------------------\n";
		cout << "\t\tDr Available: \n";
		cout << "\t\tDr.Mayada (skin specialist)\n\n";
		cout << "\t\t\t [[Time]]:\n\n";
		cout << "\tMonday To Friday\t\t9AM To 5PM\n";
		cout << "\tSatuday        \t\t9AM TO 1PM\n";
		cout << "\tSunday      \t\t off\n";
		cout << "\n-------------------------------------------------------------------------------------------------------------\n";
		cout << "\t\tDr.Ismaeil (child specialist)\n\n";
		cout << "\t\t\t [[Time]]:\n\n";
		cout << "\tMonday To Friday\t\t2PM To 10PM\n";
		cout << "\tSatuday          \t\t8AM To 1PM\n";
		cout << "\tSunday            \t\t12PM To 9PM\n";
		cout << "\n-------------------------------------------------------------------------------------------------------------\n";
		cout << "\t\tDr.Mohamed (psychiatrist) \n\n";
		cout << "\t\t\t [[Timing]]: \n\n";
		cout << "\tMonday To Friday\t\t8AM To 5PM\n";
		cout << "\tSatuday         \t\t10AM TO 1PM\n";
		cout << "\tSunday         \t\tOff\n";
		cout << "\n-------------------------------------------------------------------------------------------------------------\n";
		cout << "\nPrees Any Key For Continue : ";
		getch();
		menu();
	}
};
/////////////////////////////////////////////////
void call_dr()
{
	system("cls");
	int choice;
	cout << "\n\n\n\t\tPress 1 for Dr.Mayada  \n\n\t\t Press 2 for Dr.Ismaeil \n\n\t\t Press 3 for Dr.Mohamed";
	cin >> choice;
	one* ptr;
	Mayada m;
	Ismaiel i;
	Mohamed mo;
	if (choice == 1)
	{
		ptr = &m;
		ptr->get();
	}
	if (choice == 2)
	{
		ptr = &i;
		ptr->get();
	}
	if (choice == 3)
	{
		ptr = &mo;
		ptr->get();
	}
	else {
		cout << "Sorry invalid choice ";
		getch();
		menu();
	}
}
void display_dr()
{
	system("cls");
	int choice;
	cout << "\n\n\n\t\tPress 1 for Dr.Mayada  \n\n\t\t Press 2 for Dr.Ismaeil \n\n\t\t Press 3 for Dr.Mohamed";
	cin >> choice;
	one* ptr;
	Mayada m;
	Ismaiel i;
	Mohamed mo;
	if (choice == 1)
	{
		ptr = &m;
		ptr->show();
	}
	if (choice == 2)
	{
		ptr = &i;
		ptr->show();
	}
	if (choice == 3)
	{
		ptr = &mo;
		ptr->show();
	}
	else {
		cout << "Sorry invalid choice ";
		getch();
		menu();
	}
}



/////////////////////////////////////////////////////
void menu()
{
	system("cls");
	system("color FC");
		cout << "\n";
		cout << "\n";


		cout << "\t\t             Hospital Management System      \n";
		cout << "\t\t             ~~~~~~~~~~~~~~~~~~~~~~~~~~      \n";

		cout << "\n-----------------------------------------------------------------------------------------\n";
			cout << "\t\t    Please select any option             \n";


		cout << "\n\n\t1-\tPress 1 For Available doctor information\n\n";
		cout<<"\t2-\tPress 2 for doctor appointment \n\n";
		cout<<"\t3-\tPrees 3 for saving staff information\n\n";
		cout<<"\t4-\tPrees 4 for checking patient appointment Menu: \n\n ";
		cout<<"\t5-\tPrees 5 for checking staff information Menu: \n\n";
		cout<<"\t6-\tPrees 6 to Change or create password :\n\n";
		cout<<"\t7-\t[Prees 7 for Logout]\n";
		cout << "\n----------------------------------------------------------------------------------------\n";
		cout << "\n\n\tPlease enter your choice : ";
		informaton a1;
		one* ptr;
		staff a2;
		Ismaiel a3;
		int a;
		cin >> a;
		if (a == 1)
		{
			a1.drinfo();
		}
		else if (a == 2)
		{
			call_dr();
		}
		else if (a == 3)
		{
			ptr = &a2;
			ptr->get();
		}
		else if(a==4)
        {
            display_dr();
		}
		else if (a == 5)
		{
			ptr = &a2;
			ptr->show();
		}
		else if (a == 6)
		{
			cpasscode();
		}
		else if (a == 7)
		{
			passcode();
		}
		else
		{
			cout << "Sorry invalid choice ";
		}
}
void passcode()
{
    system("cls");
	char p1[50],p2[50],p3[50];
	system("color Fc");
	ifstream in("password.txt");
	{
		cin.sync();
		cout << "\n\n\n\n\n\n\n\n\t\tEnter the password : ";
		cin.getline(p1, 50);
		in.getline(p2, 50);
		if(strcmp(p2,p1)==0)
		{
			menu();
		}
		else
		{
			cout << "\n\n\t\tIncorrect passcode,please try again\n";
			Sleep(999);
			passcode();
		}
	}
	in.close();
 }
void cpasscode()
{
	char n[50];
	system("cls");
	ofstream out("password.txt");
	{
		cin.sync();
		cout << "\n\n\n\n\t\tEnter the new password : ";
		cin.getline(n, 50);
		out << n;
	}
	out.close();
	cout << "\n\n New password has been saved : ";
	getch();
	menu();
}
int main()
{
	passcode();
	system("pause");
}
