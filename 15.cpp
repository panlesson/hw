/*
15. Mortgage Payment
Design a class that will determine the monthly payment on a home mortgage.
The monthly payment with interest compounded monthly can be calculated as follows:

Payment = (Loan x (Rate/12) x Term)/(Term - 1)
where
Term = (1 + (Rate / 12))^(12 x Years)

Payment = the monthly payment
Loan = the dollar amount of the loan
Rate = the annual interest rate
Years = the number of years of the loan

The class should have member functions for setting the loan amount, interest rate,
and number of years of the loan. It should also have member functions for returning
the monthly payment amount and the total amount paid to the bank at the end of the
loan period. Implement the class in a complete program.

Input Validation: Do not accept negative numbers for any of the loan values.
*/
#include<iostream>
#include<cmath>
#include<cstdlib>	//for exit function
using namespace std;

class MortgagePayment
{
	private:
		double loan;
		double rate;
		int years;
	public:
		MortgagePayment()		//Constructor
		{
			loan = 0.0;
			rate = 0.0;
			years = 0;
		}
		
		// Member functions
		void setLoan(double loanAmount)
		{
			if (loanAmount > 0){
				loan = loanAmount;
			}	else{
					cout << "Error: Loan amount cannot be 0 or negative.\n";
					exit(EXIT_FAILURE);
				}
		}
	
		void setRate(double annualRate)
		{
			if (annualRate > 0){
				rate = annualRate;
			}	else{
					cout << "Error: Interest rate cannot be 0 or negative.\n";
					exit(EXIT_FAILURE);
				}	
		}
		
		void setYears(int numYears)
		{
			if (numYears > 0){
				years = numYears;
			}	else{
					cout << "Error: Number of years cannot be 0 or negative.\n";
					exit(EXIT_FAILURE);
				}
		}
		
		double calculateMonthlyPayment()
		{

			double term = pow(1 + (rate / 12), 12 * years);
			double payment = (loan * (rate / 12) * term) / (term - 1);
			return payment;
		}
		
		double calculateTotalPayment()
		{
			return calculateMonthlyPayment() * 12 * years;
		}	
};

int main()
{
	MortgagePayment mortgage;
	
	double loanAmount, annualRate;
	int numYears;
	
	cout << "Enter the loan amount: ";
	cin >> loanAmount;
	mortgage.setLoan(loanAmount);
	
	cout << "Enter the annual interest rate (in percentage): ";
	cin >> annualRate;
	mortgage.setRate(annualRate / 100);
	
	cout << "Enter the number of years: ";
	cin >> numYears;
	mortgage.setYears(numYears);
	
	cout << "Monthly Payment: $" << mortgage.calculateMonthlyPayment() << endl;
	cout << "Total Payment: $" << mortgage.calculateTotalPayment() << endl;
	
	return 0;
}
	
