#include <iostream>

using namespace std;
//task 1
void generate_test();
void show_answers();
//task 2
void create_data();
void delete_data();
void show_data();
//task3
struct final;
struct exam;
exam *head = NULL;
final *student;
int lsize = 0;
void create_list(exam *&head, final *&student, int &size);
void grade_students(exam *head, final *&student, int size);


void menu()
{
	cout << "Term final by Ivanchuk Eugenia 9894." << endl;
	cout << "Task ¹1:" << endl
		<< "1. Generate a test;" << endl << "2. Show test answers;" << endl;
	cout << "Task ¹2:" << endl
		<< "3. Add info about a student;" << endl << "4. Delete info about a student;" << endl
		<< "5. Show grades." << endl;
	cout << "Task ¹3:" << endl
		<< "6. Create a list of students who are taking the exam;" << endl
		<< "7. Grade the exam." << endl;
	int start0;
	cin >> start0;
	cin.clear();
	switch (start0)
	{
	case 1:
	{
		generate_test();
		menu();
	}
	break;
	case 2:
	{
		show_answers();
		menu();
	}
	break;
	case 3:
	{
		create_data();
		menu();
	}
	break;
	case 4:
	{
		delete_data();
		menu();
	}
	break;
	case 5:
	{
		show_data();
		menu();
	}
	case 6:
	{
		create_list(head, student, lsize);
		menu();
	}
	case 7:
	{
		grade_students(head, student, lsize);
		menu();
	}
	break;
	default:
	{
		cout << "Invalid input!";
	}
	break;
	}
}

int main()
{
	setlocale(0, "");
	menu();
	return 0;
}