// Nathanael Gastelum
// CECS 282-07
// Prog 3 - Structs
// 3/25/2020

#ifndef MyDate_h
#define MyDate_h

#include <string>

using namespace std;

class myDate
{
public:
	myDate();
	myDate(int M, int D, int Y);

	void display();
	void random();
	string toString();
	void increaseDate(int N);
	void decreaseDate(int N);
	int daysBetween(myDate D);
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