// Nathanael Gastelum
// CECS 282-07
// Prog 3 - Structs
// 3/25/2020

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "myDate.h"

using namespace std;

struct Student
{
	char name[20];
	int id;
	char grade;
	myDate bday;
	string homeTown;
};

void populateStudents(Student *students[]);
void sortName(Student *students[]);
void sortID(Student *students[]);
void sortGrade(Student *students[]);
void sortBday(Student *students[]);
void sortTown(Student *students[]);


int main()
{
	Student *students[10];
	populateStudents(students);

	while (true)
	{
		cout << setw(20) << left << "Name";
		cout << setw(13) << left << "Student ID";
		cout << setw(10) << left << "Grade";
		cout << setw(20) << left << "Birthday";
		cout << setw(10) << left << "Home Town" << endl;

		for (int i = 0; i < 10; i++) {
			cout << setw(20) << left << students[i]->name;
			cout << setw(13) << left << students[i]->id;
			cout << setw(10) << left << students[i]->grade;
			cout << setw(20) << left << students[i]->bday.toString();
			cout << setw(10) << left << students[i]->homeTown << endl;
		}

		cout << "\nWelcome to Solitaire Prime!\n"
			<< "1) Display list sorted by Name\n"
			<< "2) Display list sorted by Student ID\n"
			<< "3) Display list sorted by Grade\n"
			<< "4) Display list sorted by Birthday\n"
			<< "5) Display list sorted by Home Town\n"
			<< "6) Exit\n";

		int i;
		cin >> i;

		switch (i)
		{
		case 1:
			sortName(students);
			break;
		case 2:
			sortID(students);
			break;
		case 3:
			sortGrade(students);
			break;
		case 4:
			sortBday(students);
			break;
		case 5:
			sortTown(students);
			break;
		case 6:
			exit(0);

		default:
			cout << "Invalid input";
			break;
		}
	}
    return 0;
}


void populateStudents(Student *students[])
{
	char grades[] = { 'A', 'B', 'C', 'D', 'F' };
	string names[] = { "Clark Kent", "Fred Flintstone", "Sponge Bob", "John Smith", "Jeff Bezos", "Bill Gates", "Bernie Sanders", "Gabe Newell", "Nathanael Gastelum", "Hank Hill" };
	string towns[] = { "Los Angeles", "Barcelona", "San Francisco", "New York", "London", "Jakarta", "Hong Kong", "Singapore", "Long Beach", "Chicago" };

	for (int i = 0; i < 10; i++)
	{
		students[i] = new Student;

		strcpy_s(students[i]->name, names[i].c_str());
		students[i]->id = rand() % 9000 + 1000;
		students[i]->grade = grades[rand() % 5];

		students[i]->bday = myDate();
		students[i]->bday.random();

		students[i]->homeTown = towns[i];
	}
}

void sortName(Student *students[])
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
		{
			if (strcmp(students[i]->name, students[j]->name) < 0)
			{
				Student *temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
		}
	}
}

void sortID(Student *students[])
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
		{
			if (students[i]->id < students[j]->id)
			{
				Student *temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
		}
	}
}

void sortGrade(Student *students[])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (students[i]->grade < students[j]->grade)
			{
				Student *temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
		}
	}
}

void sortBday(Student *students[])
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
		{
			if (students[i]->bday.daysBetween(students[j]->bday) > 0)
			{
				Student *temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
		}
	}
}

void sortTown(Student *students[])
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
		{
			if (students[i]->homeTown.compare(students[j]->homeTown) < 0)
			{
				Student *temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
		}
	}
}