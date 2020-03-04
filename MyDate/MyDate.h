// Nathanael Gastelum
// CECS 282-07
// Prog 2 - myDate Object
// 3/4/2020

#ifndef MyDate_h
#define MyDate_h

#include <string>

using namespace std;

class MyDate
{
public:
	MyDate();
	MyDate(int M, int D, int Y);

	void display();
	void increaseDate(int N);
	void decreaseDate(int N);
	int daysBetween(MyDate D);
	int getMonth();
	int getDay();
	int getYear();
	int dayOfYear();
	string dayName();

private:
	int month, day, year;
	int JD;
};
#endif