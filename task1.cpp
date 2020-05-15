#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void generate_test()
{
	srand(time(NULL));
	int var;
	var = rand() % 2 + 1;
	cout << "Variant ¹" << var << "." << endl;	
	const int size = 10;
	int pool[size];
	for (int i = 0; i < size; i++)
		pool[i] = rand() % 100;
	cout << "¹1. You have a singly linked list of " << size << " elements:" << endl;
	for (int i = 0; i < size; i++)
		cout << pool[i] << " ";
	int x, y;
	x = rand() % 11;
	cout << endl<< "Please explain how you would:" << endl
		<< "a. insert the element with the index " << x << ":" << endl;
	x = rand() % 10;
	cout << "b. delete the element with the index " << x << ":"<< endl;
	x = rand() % 10;
	y = rand() % 10;
	cout << "c. swap the " << x << "th and the " << y << "th elements." << endl;
	for (int i = 0; i < size; i++)
		pool[i] = rand() % 100;
	cout << "¹2. You have a doubly linked list of " << size << " elements:" << endl;
	for (int i = 0; i < size; i++)
		cout << pool[i] << " ";
	x = rand() % 11;
	cout << endl << "Please explain how you would:" << endl
		<< "a. insert the element with the index " << x << ":" << endl;
	x = rand() % 10;
	cout << "b. delete the element with the index " << x << ":" << endl;
	x = rand() % 10;
	y = rand() % 10;
	cout << "c. swap the " << x << "th and the " << y << "th elements." << endl;
	cout << "¹3. You have a binary search tree:" << endl;
	switch (var)
	{
	case 1:
	{
		ifstream tree("tree_ver1.txt");
		string temp;
		while (!tree.eof())
		{
			getline(tree, temp);
			cout << temp << endl;
		}
	}
	break;
	case 2:
	{
		ifstream tree("tree_ver2.txt");
		string temp;
		while (!tree.eof())
		{
			getline(tree, temp);
			cout << temp << endl;
		}
	}
	break;
	case 3:
	{
		ifstream tree("tree_ver3.txt");
		string temp;
		while (!tree.eof())
		{
			getline(tree, temp);
			cout << temp << endl;
		}
	}
	break;
	}
	cout << "a. check if the tree is correct. If it is not, edit the tree accordingly:" << endl;
	switch (var)
	{
	case 1:
	{
		cout << "b. explain how you would delete the number 55 from the tree:" << endl
			<< "c. explain how you would insert it back in the tree:" << endl;
	}
	break;
	case 2:
	{
		cout << "b. explain how you would delete the number 10 from the tree:" << endl
			<< "c. explain how you would insert it back in the tree:" << endl;
	}
	break;
	case 3:
	{
		cout << "b. explain how you would delete the number 13 from the tree:" << endl
			<< "c. explain how you would insert it back in the tree:" << endl;
	}
	break;
	}
	cout << "¹4. You have a postfix expression:" << endl
		<< "x 4 + 2 * 6 - 2 / x -" << endl;
	cout << "Calculate the result if x = ";
	switch (var)
	{
	case 1:
	{
		cout << "3:" << endl;
	}
	break;
	case 2:
	{
		cout << "7:" << endl;
	}
	break;
	case 3:
	{
		cout << "1:" << endl;
	}
	break;
	}
}

void show_answers()
{
	ifstream answers("test_answers.txt");
	string temp;
	while (!answers.eof())
	{
		getline(answers, temp);
		cout << temp << endl;
	}
}