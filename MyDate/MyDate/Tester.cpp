// Nathanael Gastelum
// CECS 282-07
// Prog 2 - myDate Object
// 3/4/2020

#include <stdio.h>
#include <iostream>

#include "MyDate.h"

using namespace std;

int Greg2Julian(int month, int day, int year);
void Julian2Greg(int JD, int & month, int & day, int & year);

int main() {

	MyDate date = MyDate(3, 3, 2020);

	date.display();
	cout << "\n";
	cout << date.dayName();

	cout << "\n";

	return 0;
}