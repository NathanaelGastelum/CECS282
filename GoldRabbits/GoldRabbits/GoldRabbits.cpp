// Nathanael Gastelum
// CECS 282-07
// Prog 5 - Gold Rabbits
// 5/6/2020

#include<iostream>
#include<time.h>
#include<iomanip>
#include<string>
#include<vector>
#include<map>

using namespace std;

// BigInt header
class BigInt 
{
private:
	vector<char> cVector;
	bool isInt;

public:
	BigInt();
	BigInt(string);
	BigInt(int);

	void print();

	friend ostream& operator<<(ostream& os, const BigInt &);

	friend BigInt operator+(BigInt, BigInt);
	friend BigInt operator-(BigInt, BigInt);
	friend BigInt operator-(BigInt, int);
	friend BigInt operator++(BigInt &, int);

	friend bool operator==(const BigInt & lhs, const BigInt & rhs);
	bool operator==(int);
	friend bool operator<(const BigInt &, const BigInt &);
	friend bool operator>(const BigInt &, const BigInt &);
	friend bool operator<=(const BigInt &, int);
};

BigInt goldRabbits(BigInt);
void pause() { cout << "Press Enter to continue..."; getchar(); }

int main()
{
	BigInt B1("123456789123456789123456789123456789");
	BigInt B2(B1); 
	BigInt MAX(INT_MAX);
	cout << "B1:" << B1 << "\nB2:" << B2 << "\nMAX:" << MAX << endl;
	pause(); 
	cout << "\nB1:";
	B1.print(); 
	cout << endl; 
	pause();

	for(BigInt i=0; i<=3000; i++)	// uncomment this
//	for(int i=0; i<=3000; i++)		// comment this out
	{
		cout << "\ngoldRabbits("<< i <<") = " << goldRabbits(i);
	}
	cout << endl;
	pause();
	
	cout<< "\nThis is the value of goldRabbits(3000)\n\n";
	BigInt gR3000 =  goldRabbits(BigInt(3000));
	gR3000.print();
	cout << endl;
	pause();
}

// this is the goldRabbits function
BigInt goldRabbits(BigInt n)
{
	if (n == 0 || n == 1)
		return BigInt(1);

	static map<BigInt, BigInt> rabbitMap;
	rabbitMap[BigInt(0)] = 1;
	rabbitMap[BigInt(1)] = 1;

	rabbitMap[n] = rabbitMap[n - 1] + rabbitMap[n - 2];

	return rabbitMap[n];
}

BigInt::BigInt()
{
}

BigInt::BigInt(string s)
{
	//TODO check if there's a better way to store this to avoid casting when printing
	isInt = false;
	for (auto rit = s.rbegin(); rit != s.rend(); rit++)
	{
		cVector.push_back(*rit);
	}
}

BigInt::BigInt(int i)
{
	isInt = true;
	while (i > 9)
	{ 
		int digit = i % 10;
		cVector.push_back(digit);
		i /= 10;
	}
	cVector.push_back(i);
}

void BigInt::print()
{
	if (isInt) 
	{
		for (auto rit = cVector.rbegin(); rit != cVector.rend(); rit++)
			cout << (int) *rit;
	}
	else
	{
		for (auto rit = cVector.rbegin(); rit != cVector.rend(); rit++)
			cout << *rit;
	}
}

BigInt operator+(BigInt lhs, BigInt rhs)
{
	BigInt sum;
	if (lhs.cVector.size() > rhs.cVector.size()) {
		sum = lhs;
		rhs.cVector.resize(lhs.cVector.size(), 0);
	}
	else {
		sum = rhs;
		lhs.cVector.resize(rhs.cVector.size(), 0);
	}

	int carry = 0;
	for (int i = 0; i < sum.cVector.size(); i++)
	{
		char temp = lhs.cVector[i] + rhs.cVector[i] + carry;
		carry = 0;
		if (temp > 9) {
			temp %= 10;
			carry = 1;
		}
		sum.cVector[i] = temp;
	}
	if (carry) sum.cVector.push_back(carry);
	return sum;
}

BigInt operator-(BigInt lhs, BigInt rhs)
{
	BigInt dif = lhs;
	rhs.cVector.resize(lhs.cVector.size(), 0);

	int carry = 0;
	for (int i = 0; i < dif.cVector.size(); i++)
	{
		carry = 0;
		if (lhs.cVector[i] < rhs.cVector[i])
		{
			carry = 10;
			int count = 1;
			while (lhs.cVector[i + count] == 0)
			{
				count++;
			}
			lhs.cVector[i + count]--;
			for (count--; count > 0; count--) 
			{
				lhs.cVector[i + count] = 9;
			}
		}
		char temp = (lhs.cVector[i] + carry) - rhs.cVector[i];
		
		dif.cVector[i] = temp;
	}

	while (dif.cVector.size() > 1 && dif.cVector.back() == 0) {
		dif.cVector.pop_back();
	}

	return dif;
}

BigInt operator-(BigInt integer, int i)
{
	return integer - BigInt(i);
}

BigInt operator++(BigInt & integer, int i)
{
	integer = integer + BigInt(1);
	return integer;
}

bool operator==(const BigInt & lhs, const BigInt & rhs)
{
	if (lhs.cVector.size() != rhs.cVector.size())
		return false;

	auto rRit = rhs.cVector.rbegin();
	for (auto lRit = lhs.cVector.rbegin(); lRit != lhs.cVector.rend(); lRit++)
	{
		if (*lRit != *rRit) {
			return false;
		}
		rRit++;
	}
	return true;
}

bool BigInt::operator==(int i)
{
	return (*this - BigInt(i)) == BigInt(0);
}

bool operator<(const BigInt & lhs, const BigInt & rhs)
{
	if (lhs == rhs)
		return false;
	if (lhs.cVector.size() != rhs.cVector.size())
		return lhs.cVector.size() < rhs.cVector.size();

	auto rRit = rhs.cVector.rbegin();
	for (auto lRit = lhs.cVector.rbegin(); lRit != lhs.cVector.rend(); lRit++)
	{
		if (*rRit < *lRit)
			return false;
		rRit++;
	} 
	return true;
}

bool operator>(const BigInt & lhs, const BigInt & rhs)
{
	return rhs < lhs;
}

bool operator<=(const BigInt & lhs, int rhs)
{
	return !(lhs > BigInt(rhs));
}

ostream & operator<<(ostream & os, const BigInt & integer)
{
	if (integer.isInt)
	{
		// return scientific notation after 12 characters
		if (integer.cVector.size() > 12)
		{
			auto rit = integer.cVector.rbegin();
			os << (int)*rit << '.';
			for (rit = integer.cVector.rbegin() + 1; rit != integer.cVector.rbegin() + 11; rit++)
				os << (int) *rit;
			os << "e" << integer.cVector.size() - 1;
		}
		else
		{
			for (auto rit = integer.cVector.rbegin(); rit != integer.cVector.rend(); rit++)
				os << (int)*rit;
		}
	}
	else
	{
		if (integer.cVector.size() > 12)
		{
			auto rit = integer.cVector.rbegin();
			os << *rit << '.';
			for (rit = integer.cVector.rbegin() + 1; rit != integer.cVector.rbegin() + 11; rit++)
				os << *rit;
			os << "e" << integer.cVector.size() - 1;
		}
		else
		{
			for (auto rit = integer.cVector.rbegin(); rit != integer.cVector.rend(); rit++)
				os << *rit;
		}
	}
	return os;
}