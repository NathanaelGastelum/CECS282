#ifndef upDate_h
#define upDate_h

#include <string>

class upDate
{ 
	public:
		upDate();
		upDate(int M, int D, int Y);
		upDate(int J);
		upDate D2(D1); // copy constructor
		upDate D3 = D2; // also copy constructor – initialize D3 to be copy of D2
		~upDate();

		upDate operator=(upDate);		
		void setDate(int M, int D, int Y);
		int getMonth();
		int getDay();
		int getYear();
		string getMonthName();

	private:

};
#endif