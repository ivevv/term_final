#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

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

int count_students();

struct exam
{
	string surname;
	int group;
	exam *next;
	exam *prev;
};

exam * make_head(string surname, int group)
{
	exam *head = new exam;
	head->surname = surname;
	head->group = group;
	head->next = NULL;
	head->prev = NULL;
	return head;
}

void add_student(string surname, int group, exam *head)
{
	exam *node = new exam;
	node->surname = surname;
	node->group = group;
	node->next = NULL;
	exam *temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = node;
	node->prev = temp;
}

void create_list(exam *&head, final *&student, int &size)
{
	ifstream database("task2.txt");
	if (!database.is_open())
		cout << "Access to the database was denied." << endl;
	else
	{
		size = count_students();
		if (size == 0)
			cout << "The database is empty." << endl;
		else
		{
			student = new final[size];
			string fix;
			for (int i = 0; i < size; i++)
			{
				database >> student[i].surname >> student[i].name >> student[i].patronym;
				database >> student[i].group >> student[i].id >> student[i].fgrade;
				getline(database, fix, '\n');
				getline(database, student[i].check, '\n');
			}
			database.close();
			string temp;
			temp = student[0].surname;
			head = make_head(temp, student[0].group);
			temp.clear();
			for (int i = 1; i < size; i++)
			{
				temp = student[i].surname;
				add_student(temp, student[i].group, head);
				temp.clear();
			}
			exam *temp1 = head;
			for (int i = 0; i < size; i++)
			{
				cout << temp1->group << " " << temp1->surname << endl;
				temp1 = temp1->next;
			}
		}
	}
}

void grade_students(exam *head, final *&student, int size)
{
	if (head == NULL)
	{
		cout << "You need to create a list first!" << endl;
	}
	else
	{
		bool check = false;
		cout << "Please give each student a grade (from 1 to 5)." << endl;
		exam *temp = head;
		for (int i = 0; i < size; i++)
		{
			cout << temp->group << " " << temp->surname << ":" << endl;
			
			cin >> student[i].egrade;
			cin.clear();
			temp = temp->next;
			if ((student[i].egrade <= 0) || (student[i].egrade > 5))
			{
				cout << "Invalid input!";
				check = true;
				break;
			}

		}
		if (check != true)
		{
			ofstream database;
			database.open("task3.txt");
			if (!database.is_open())
				cout << endl << "Saving error! Access to the database was denied." << endl;
			else
			{
				for (int i = 0; i < size; i++)
				{
					database << student[i].surname << " " << student[i].name << " " << student[i].patronym << endl
						<< student[i].group << endl << student[i].id << endl
						<< student[i].egrade << endl;
				}
				database.close();
				cout << "The info has been saved." << endl;
			}
		}
	}
}