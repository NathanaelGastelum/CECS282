// Nathanael Gastelum
// CECS 282-07
// Prog 4 - Overloading Operators
// 4/18/2020

#include "upDate.h"
#include <sstream>

int Greg2Julian(int month, int day, int year)
{
	int I = year;
	int J = month;
	int K = day;
	int JD = K - 32075 + 1461 * (I + 4800 + (J - 14) / 12) / 4 + 367 * (J - 2 - (J - 14) / 12 * 12) / 12 - 3 * ((I + 4900 + (J - 14) / 12) / 100) / 4;
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

ostream & operator<<(ostream & os, const upDate & date)
{
	os << date.dptr[0] << "/" << date.dptr[1] << "/" << date.dptr[2];
	return os;
}

int upDate::dateCount = 0;

upDate::upDate()
{
	dateCount++;
	dptr = new int[3];
	dptr[0] = 5;
	dptr[1] = 11;
	dptr[2] = 1959;
	JD = Greg2Julian(dptr[0], dptr[1], dptr[2]);
}

upDate::upDate(int M, int D, int Y)
{
	dateCount++;
	dptr = new int[3];
	JD = Greg2Julian(M, D, Y);
	Julian2Greg(JD, dptr[0], dptr[1], dptr[2]);

	if (dptr[0] == M && dptr[1] == D && dptr[2] == Y);
	else
	{
		dptr[0] = 5;
		dptr[1] = 11;
		dptr[2] = 1959;
		JD = Greg2Julian(dptr[0], dptr[1], dptr[2]);
	}
}

upDate::upDate(int J)
{
	dateCount++;
	dptr = new int[3];
	JD = J;
	Julian2Greg(JD, dptr[0], dptr[1], dptr[2]);
}

upDate::upDate(const upDate & date)
{
	dateCount++;
	dptr = new int[3];
	dptr[0] = date.dptr[0];
	dptr[1] = date.dptr[1];
	dptr[2] = date.dptr[2];
	JD = Greg2Julian(date.dptr[0], date.dptr[1], date.dptr[2]); 
}

upDate::~upDate()
{
	dateCount--;
}

void upDate::setDate(int M, int D, int Y)
{
	JD = Greg2Julian(M, D, Y);
	Julian2Greg(JD, dptr[0], dptr[1], dptr[2]);

	if (dptr[0] == M && dptr[1] == D && dptr[2] == Y);
	else
	{
		dptr[0] = 5;
		dptr[1] = 11;
		dptr[2] = 1959;
		JD = Greg2Julian(dptr[0], dptr[1], dptr[2]);
	}
}

int upDate::getMonth()
{
	return dptr[0];
}

int upDate::getDay()
{
	return dptr[1];
}

int upDate::getYear()
{
	return dptr[2];
}

string upDate::getMonthName()
{
	string months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	return months[JD % 12];
}

string upDate::toString()
{
	string months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	stringstream buffer;
	buffer << months[dptr[0] - 1] << " " << dptr[1] << ", " << dptr[2];
	return buffer.str();
}

int upDate::GetDateCount()
{
	return dateCount;
}

int upDate::julian()
{
	return this->JD;
}

upDate & upDate::operator=(upDate date)
{
	this->setDate(date.dptr[0], date.dptr[1], date.dptr[2]);
	this->JD = Greg2Julian(dptr[0], dptr[1], dptr[2]);
	return *this;
}

upDate & upDate::operator+=(int x)
{
	this->JD += x;
	Julian2Greg(JD, dptr[0], dptr[1], dptr[2]);
	return *this;
}

upDate & upDate::operator-=(int x)
{
	this->JD -= x;
	Julian2Greg(JD, dptr[0], dptr[1], dptr[2]);
	return *this;
}

upDate upDate::operator+(int x)
{
	return upDate(*this) += x;
}

upDate operator+(int x, upDate date)
{
	return date.JD += x;
}

upDate upDate::operator-(int x)
{
	return  upDate(*this) -= x;
}

int upDate::operator-(upDate date)
{
	return this->JD - date.JD;
}

upDate & upDate::operator++()
{
	++this->JD;
	Julian2Greg(JD, dptr[0], dptr[1], dptr[2]);
	return *this;
}

upDate upDate::operator++(int)
{
	upDate temp(*this);
	operator++();
	return temp;
}

upDate & upDate::operator--()
{
	--this->JD;
	Julian2Greg(JD, dptr[0], dptr[1], dptr[2]);
	return *this;
}

upDate upDate::operator--(int)
{
	upDate temp(*this);
	operator--();
	return temp;
}

bool upDate::operator==(upDate date)
{
	return this->JD == date.JD;
}

bool upDate::operator<(upDate date)
{
	return this->JD < date.JD;
}

bool upDate::operator>(upDate date)
{
	return date < *this;
}