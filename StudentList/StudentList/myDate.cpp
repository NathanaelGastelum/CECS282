// Nathanael Gastelum
// CECS 282-07
// Prog 3 - Structs
// 3/25/2020

#include "myDate.h"
#include <iostream>
#include <sstream>

using namespace std;

int Greg2Julian(int month, int day, int year)
{
	int I = year;
	int J = month;
	int K = day;
	int JD= K-32075+1461*(I+4800+(J-14)/12)/4+367*(J-2-(J-14)/12*12)/12-3*((I+4900+(J-14)/12)/100)/4;
	return JD;
}

void Julian2Greg(int JD, int & month, int & day, int & year)
{
	int L = JD + 68569;
	int N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	int I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	int J = 80 * L / 2447;
	int K = L - 2447 * J / 80;
	L = J / 11;
	J = J + 2 - 12 * L;
	I = 100 * (N - 49) + I + L;

	year = I;
	month = J;
	day = K;
}

myDate::myDate()
{
	month = 5;
	day =  11;
	year = 1959;
}

myDate::myDate(int M, int D, int Y)
{
	JD = Greg2Julian(M, D, Y);
	Julian2Greg(JD, month, day, year);

	if (month == M && day == D && year == Y);
	else
	{
		month = 5;
		day = 11;
		year = 1959;
		JD = Greg2Julian(month, day, year);
	}
}

void myDate::display()
{
	string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	cout << months[month - 1] << " " << day << ", " << year;
}

void myDate::random()
{
	myDate start = myDate(01, 01, 1999);
	myDate end = myDate(12, 31, 2004);
	this->JD = (rand() % start.daysBetween(end)) + start.JD;
	Julian2Greg(JD, month, day, year);
}

string myDate::toString()
{
	string months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	stringstream buffer;
	buffer << months[month - 1] << " " << day << ", " << year;
	return buffer.str();
}

void myDate::increaseDate(int N)
{
	JD += N;
	Julian2Greg(JD, month, day, year);
}

void myDate::decreaseDate(int N)
{
	JD -= N;
	Julian2Greg(JD, month, day, year);
}

int myDate::daysBetween(myDate D)
{
	JD = Greg2Julian(month, day, year);
	return Greg2Julian(D.month, D.day, D.year) - JD;
}

int myDate::getMonth()
{
	return month;
}

int myDate::getDay()
{
	return day;
}

int myDate::getYear()
{
	return year;
}

int myDate::dayOfYear()
{
	return JD - Greg2Julian(1, 1, year) + 1;
}

string myDate::dayName()
{
	string days[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	return days[JD % 7];
}