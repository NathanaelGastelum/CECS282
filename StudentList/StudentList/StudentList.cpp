#include <stdio.h>
#include <iostream>
#include "myDate.h"

using namespace std;

struct Student
{
	const char *name;
	int id;
	char grade;
	myDate bday;
	string homeTown;
};

void populateStudents(Student *students[]);

int main()
{
	Student *students[10];
	populateStudents(students);

	for (int i = 0; i < 10; i++) {
		cout << students[i]->name;
		cout << students[i]->id;
		cout << students[i]->grade;
		students[i]->bday.display();
		cout << students[i]->homeTown << endl;
	}

    return 0;
}


void populateStudents(Student *students[])
{
	char grades[] = { 'A', 'B', 'C', 'D', 'E', 'F' };

	for (int i = 0; i < 10; i++)
	{
		students[i] = new Student;

		students[i]->name = "New Student";
		students[i]->id = 1000 + i; //TODO Make random
		students[i]->grade = grades[i % 6];
		students[i]->bday = myDate();
		students[i]->homeTown = "Nowhere";
	}
}