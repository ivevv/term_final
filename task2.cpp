#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct tm * timeinfo;
time_t tstamp;

struct final
{
	char name[20];
	char surname[20];
	char patronym[20];
	int group;
	int id;
	int fgrade;
	int egrade;
	string check;
};

void create_data()
{
	final student;
	cout << "Surname:" << endl;
	cin >> student.surname;
	cin.clear();
	cout << "Name:" << endl;
	cin >> student.name;
	cin.clear();
	cout << "Patronym:" << endl;
	cin >> student.patronym;
	cin.clear();
	cout << "Group:" << endl;
	cin >> student.group;
	cin.clear();
	cout << "Index:" << endl;
	cin >> student.id;
	cin.clear();
	cout << "Term final grade:" << endl;
	cin >> student.fgrade;
	if ((student.fgrade > 200) || (student.fgrade < 0))
	{
		cout << "Incorrect input! Please try again." << endl;
		create_data();
	}
	else
	{
		time(&tstamp);
		timeinfo = localtime(&tstamp);
		student.check = asctime(timeinfo);
		ofstream database;
		database.open("task2.txt", ios::app);
		if (!database.is_open())
			cout << "Saving error! Access to the database was denied." << endl;
		else
		{
			database << student.surname << " " << student.name << " " << student.patronym << endl
				<< student.group << endl << student.id << endl
				<< student.fgrade << endl << student.check;
			database.close();
			cout << "Student info is saved in the database." << endl;
		}
	}
};

int count_students()
{
	ifstream database("task2.txt");
	if (database.is_open())
	{
		int temp = 0;
		string data;
		while (!database.eof())
		{
			getline(database, data);
			temp++;
		}
		database.close();
		int n;
		n = temp / 5;
		return n;
	}
	else return 0;
}

void delete_data()
{
	ifstream database("task2.txt");
	if (!database.is_open())
		cout << "Access to the database was denied." << endl;
	else
	{
		int size;
		size = count_students();
		if (size == 0)
			cout << "The database is empty." << endl;
		else
		{
			final *student = new final[size];
			string fix;
			for (int i = 0; i < size; i++)
			{
				database >> student[i].surname >> student[i].name >> student[i].patronym;
				database >> student[i].group >> student[i].id >> student[i].fgrade;
				getline(database, fix, '\n');
				getline(database, student[i].check, '\n');
			}
			database.close();
			int delete_g, delete_i;
			cout << "Enter the group and index number of student whose info needs to be deleted." << endl;
			cout << "Group:" << endl;
			cin >> delete_g;
			cin.clear();
			cout << "Index:" << endl;
			cin >> delete_i;
			cin.clear();
			int found = 2147483647;
			for (int i = 0; i < size; i++)
			{
				if ((student[i].group == delete_g) && (student[i].id == delete_i))
					found = i;
			}
			if (found == 2147483647)
			{
				cout << "Error! Can't find this student.";
				cout << endl << "Please try again." << endl;
				delete_data();
			}
			else
			{
				ofstream newdatabase;
				newdatabase.open("task2.txt");
				if (!newdatabase.is_open())
					cout << endl << "Saving error! Access to the database was denied." << endl;
				else
				{
					for (int i = 0; i < found; i++)
					{
						newdatabase << student[i].surname << " " << student[i].name << " " << student[i].patronym << endl
							<< student[i].group << endl << student[i].id << endl
							<< student[i].fgrade << endl << student[i].check << endl;
					}
					for (int i = (found + 1); i < size; i++)
					{	
						newdatabase << student[i].surname << " " << student[i].name << " " << student[i].patronym << endl
							<< student[i].group << endl << student[i].id << endl
							<< student[i].fgrade << endl << student[i].check << endl;
					}
						newdatabase.close();
						cout << "The info has been deleted." << endl;
				}
			}
			delete[] student;
		}
	}
}

void show_grade(int x, int y)
{
	ifstream database("task2.txt");
	if (!database.is_open())
		cout << "Access to the database was denied." << endl;
	else
	{
		int size;
		size = count_students();
		if (size == 0)
			cout << "The database is empty." << endl;
		else
		{
			final *student = new final[size];
			string fix;
			for (int i = 0; i < size; i++)
			{
				database >> student[i].surname >> student[i].name >> student[i].patronym;
				database >> student[i].group >> student[i].id >> student[i].fgrade;
				getline(database, fix, '\n');
				getline(database, student[i].check, '\n');
			}
			database.close();
			int temp = 0;
			for (int i = 0; i < size; i++)
			{
				if ((student[i].fgrade >= x) && (student[i].fgrade <= y))
				{
					cout << student[i].group << " " << student[i].id << " "
						<< student[i].surname << " " << student[i].name << " " << student[i].patronym << endl;
					temp++;
				}
			}
			if (temp == 0)
				cout << "There aren't such students in the database." << endl;
			delete[] student;
		}
	}
}

void show_data()
{
	cout << "Show students who got:" << endl << "1. A;" << endl << "2. B;" << endl
		<< "3. C;" << endl << "4. F." << endl;
	int start1;
	cin >> start1;
	cin.clear();
	switch (start1)
	{
	case 1:
	{
		show_grade(170, 200);
	}
	break;
	case 2:
	{
		show_grade(140, 169);
	}
	break;
	case 3:
	{
		show_grade(100, 139);
	}
	break;
	case 4:
	{
		show_grade(0, 99);
	}
	break;
	default:
	{
		cout << "Invalid input! Try again." << endl;
		show_data();
	}
	break;
	}
}
