/*
13. Tossing Coins for a Dollar
For this assignment, you will create a game program using the Coin class
from Programming Challenge 12. The program should have three instances of
the Coin class: one representing a quarter, one representing a dime, and
one representing a nickel.

When the game begins, your starting balance is $0. During each round of
the game, the program will toss the simulated coins. When a coin is tossed,
the value of the coin is added to your balance if it lands heads-up.
For example, if the quarter lands headsup, 25 cents is added to your balance.
Nothing is added to your balance for coins that land tails-up. The game is over
when your balance reaches $1 or more. If your balance is exactly $1, you win
the game. You lose if your balance exceeds $1.
*/
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Coin
{
	private:
		string sideUp;
	public:
		Coin()
		{
			srand(static_cast<unsigned int>(time(0)));
			toss();
		}
		
		void toss()
		{
			int randomNum = rand() % 2;
	
			if (randomNum == 0){
				sideUp = "Heads";
			}	else{
					sideUp = "Tails";
				}
		}
		
		string getSideUp() const
		{
			return sideUp;
		}
};

int main()
{
	Coin quarter, dime, nickel;
	double balance = 0.0;
	unsigned int ctr = 1;
	
	cout << "Welcome to Tossing Coins for a Dollar!\n\n";
	
	while (balance < 1.0) {
		cout << "Press Enter for the next toss...";
		cin.ignore(100, '\n'); //this essentially makes the program wait for user input
		cout << "\nToss " << ctr++ << endl;

		quarter.toss();
		dime.toss();
		nickel.toss();

		cout << "Quarter: " << quarter.getSideUp() << endl;
		cout << "Dime: " << dime.getSideUp() << endl;
		cout << "Nickel: " << nickel.getSideUp() << endl;

		if (quarter.getSideUp() == "Heads"){
			balance += 0.25;
		}
		if (dime.getSideUp() == "Heads"){
			balance += 0.10;
		}
		if (nickel.getSideUp() == "Heads"){
			balance += 0.05;
		}
		
		cout << "Current balance: $" << balance << '\n' << endl;
	}
	
	if (balance == 1.0){
		cout << "Congratulations! You won the game!";
	}	else {
			cout << "You lost the game.";
		}
	
	return 0;
}
