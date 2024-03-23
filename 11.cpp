/*
11. Payroll
Design a PayRoll class that has data members for an employee’s
hourly pay rate, number of hours worked, and total pay for the
week. Write a program with an array of seven PayRoll objects.
The program should ask the user for the number of hours each
employee has worked and will then display the amount of gross
pay each has earned.

Input Validation: Do not accept values greater than 60 for the
number of hours worked.
*/
#include<iostream>
using namespace std;

class Payroll
{
	private:
		int work;
		double rate;
		double total;
	public:
		Payroll()
		{
			work = 0;
			rate = 0.0;
			total = 0.0;
		}
		void setWork(int);
		void setRate(double);
		void setTotal();
		void loopcout() const;
};

void Payroll::setWork(int x)
{
	work = x;
}
		
void Payroll::setRate(double x)
{
	rate = x;
}

void Payroll::setTotal()
{
	total = rate * work;
}

void Payroll::loopcout() const
{
	cout << total;
}


int main()
{
	const int SIZE{7};
	Payroll x[SIZE];
	
	for (int i{0}; i < SIZE; ++i)
	{
		int hours{0};
		double rate{0.0};
	
		cout << "Enter pay rate for employee " << (i + 1) << ": $";
		cin >> rate;
		x[i].setRate(rate);
		
		cout << "Enter hours worked for employee " << (i + 1) << ": ";
		cin >> hours;
		while (hours > 60)
		{
			cout << "Enter a number less or equal than 60: ";
			cin >> hours;
		}
		
		x[i].setWork(hours);
		x[i].setTotal();
	}
	
	cout << "\nGross pay for each employee:\n";
	for (int i{0}; i < SIZE; ++i)
	{
		cout << "Employee " << (i + 1) << ": $";
		x[i].loopcout();
		cout << endl;
	}	
	
	return 0;
}
