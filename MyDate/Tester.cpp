// Nathanael Gastelum
// CECS 282-07
// Prog 2 - myDate Object
// 3/4/2020

#include <stdio.h>
#include <iostream>

#include "myDate.h"

using namespace std;

int main() {

	myDate blankTest = myDate();
	myDate date = myDate(3, 4, 2020);
	blankTest.display();

	cout << "Today is " << date.dayName() << " ";

	date.display();
	cout << "\n";

	date.increaseDate(1);
	cout << "Tomorrow is ";
	date.display();
	cout << "\n";

	date.decreaseDate(2);
	cout << "Yesterday was the ";
	date.display();
	date.increaseDate(1);
	cout << "\n";

	myDate xmas = myDate(12,25,2020);
	cout << "Christmas is " << date.daysBetween(xmas) << " Days away\n";

	cout << "We are on day " << date.dayOfYear() << " of this year";

	cout << "\n";

	return 0;
}