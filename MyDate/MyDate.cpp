// Nathanael Gastelum
// CECS 282-07
// Prog 2 - myDate Object
// 3/4/2020

#include "MyDate.h"
#include <iostream>

using namespace std;

int Greg2Julian(int month, int day, int year)
{
	return day - 32075 + 1461 * (year + 4800 + (month - 14) / 12) / 4 + 367 * (month - 2 - (month - 14) / 12 * 12)
			/ 12 - 3 * ((year + 4900 + (month - 14) / 12) / 100) / 4;
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

MyDate::MyDate()
{
	MyDate(5, 11, 1959);
}

MyDate::MyDate(int M, int D, int Y)
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

void MyDate::display()
{
	string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	cout << months[month - 1] << " " << day << ", " << year;
}

void MyDate::increaseDate(int N)
{
	JD += N;
	Julian2Greg(JD, month, day, year);
}

void MyDate::decreaseDate(int N)
{
	JD -= N;
	Julian2Greg(JD, month, day, year);
}

int MyDate::daysBetween(MyDate D)
{
	return Greg2Julian(D.month, D.day, D.year) - JD;
}

int MyDate::getMonth()
{
	return month;
}

int MyDate::getDay()
{
	return day;
}

int MyDate::getYear()
{
	return year;
}

int MyDate::dayOfYear()
{
	return JD - Greg2Julian(1, 1, year);
}

string MyDate::dayName()
{
	string days[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	return days[JD % 7];
}