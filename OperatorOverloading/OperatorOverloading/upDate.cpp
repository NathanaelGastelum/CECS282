#include "upDate.h"
// Nathanael Gastelum
// CECS 282-07
// Prog 4 - Overloading Operators
// 4/18/2020

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

upDate::upDate()
{
}

upDate::upDate(int M, int D, int Y)
{
}

upDate::upDate(int J)
{
}

upDate::~upDate()
{
}

upDate upDate::operator=(upDate)
{

	return upDate();
}
