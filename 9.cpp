/*
9. Population
In a population, the birth rate and death rate are calculated as follows:
Birth Rate = Number of Births ÷ Population
Death Rate = Number of Deaths ÷ Population

For example, in a population of 100,000 that has 8,000 births and
6,000 deaths per year,the birth rate and death rate are:
Birth Rate = 8,000 ÷ 100,000 = 0.08
Death Rate = 6,000 ÷ 100,000 = 0.06

Design a Population class that stores a population, number of births,
and number of deaths for a period of time. Member functions should
return the birth rate and death rate. Implement the class in a program.
Input Validation: Do not accept population figures less than 1,
or birth or death numbers less than 0.
*/
#include<iostream>
using namespace std;

class Population
{
	private:
		int population;
		int numBirths;
		int numDeaths;
	public:
		Population(int pop, int births, int deaths) //Constructor
		{
			population = pop;
			numBirths = births;
			numDeaths = deaths;
		}
		
		double calculateBirthRate() const
		{
			return static_cast<double>(numBirths) / population;
		}
		
		double calculateDeathRate() const
		{
			return static_cast<double>(numDeaths) / population;
		}
};

int main()
{
	int population, birth, death;
	
	cout << "Enter the population: ";
	cin >> population;
	while(population < 1){
		cout << "Population cannot be less than 1, enter again: ";
		cin >> population;
	}
	
	cout << "Enter the number of births: ";
	cin >> birth;
	while(birth < 0){
		cout << "Number of births cannot be less than 0, enter again: ";
		cin >> birth;
	}
	
	cout << "Enter the number of deaths: ";
	cin >> death;
	while(death < 0){
		cout << "Number of deaths cannot be less than 0, enter again: ";
		cin >> death;
	}
	
	Population pop(population, birth, death);
	
	cout << "\nPopulation: " << population << endl;
	cout << "Birth Rate: " << pop.calculateBirthRate() << endl;
	cout << "Death Rate: " << pop.calculateDeathRate() << endl;
	
	return 0;
}

