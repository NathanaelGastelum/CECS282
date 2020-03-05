// Nathanael Gastelum
// CECS 282-07
// Prog 2 - myDate Object
// 3/4/2020

#include <stdio.h>
#include <iostream>

#include "MyDate.h"

using namespace std;

int main() {

	MyDate date = MyDate(2, 1, 2020);

	cout << "Today is " << date.dayName() << " ";

	date.display();
	cout << "\n";

	date.increaseDate(1);
	cout << "Tomorrow is ";
	date.display();

	date.decreaseDate(2);
	cout << "Yesterday was the ";
	date.display();
	date.increaseDate(1);

	MyDate xmas = MyDate(12,25,2020);
	cout << "Christmas is " << date.daysBetween(xmas) << " Days away";

	cout << "We are on day " << date.dayOfYear();

	cout << "\n";

	return 0;
}