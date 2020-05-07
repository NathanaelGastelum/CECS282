// Nathanael Gastelum
// CECS 282-07
// Prog 4 - Overloading Operators
// 4/18/2020

#ifndef upDate_h
#define upDate_h

#include <string>

using namespace std;

class upDate
{ 
	public:
		upDate();
		upDate(int M, int D, int Y);
		upDate(int J);
		upDate(const upDate &); 
		~upDate();

		void setDate(int M, int D, int Y);
		int getMonth();
		int getDay();
		int getYear();
		string getMonthName();
		string toString();

		static int GetDateCount();
		int julian();

		upDate & operator=(upDate);
		upDate & operator+=(int);
		upDate & operator-=(int);
		upDate operator+(int);
		friend upDate operator+(int, upDate);
		upDate operator-(int);
		int operator-(upDate);

		friend ostream& operator<<(ostream& os, const upDate &);

		upDate & operator++();
		upDate operator++(int);
		upDate & operator--();
		upDate operator--(int);

		bool operator==(upDate);
		bool operator<(upDate);
		bool operator>(upDate);

	private:
		int JD;
		int *dptr;
		static int dateCount;
};
#endif