#include <stdio.h>
#include "myDate.h"

using namespace std;

int main()
{
	Student *students[10];
	populateStudents(students);

    return 0;
}

struct Student
{
	char *name;
	int id;
	char grade;
	myDate bday;
	string homeTown;
};
void populateStudents(Student *ptr[])
{
	for (int i = 0; i < 10; i++) {
		ptr[i] = new Student;
	}
}