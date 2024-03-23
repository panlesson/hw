/*
17. Cash Register
Design a CashRegister class that can be used with the InventoryItem
class discussed in this chapter. The CashRegister class should perform the following:
1. Ask the user for the item and quantity being purchased.
2. Get the item’s cost from the InventoryItem object.
3. Add a 30% profit to the cost to get the item’s unit price.
4. Multiply the unit price times the quantity being purchased to get the purchase subtotal.
5. Compute a 6% sales tax on the subtotal to get the purchase total.
6. Display the purchase subtotal, tax, and total on the screen.
7. Subtract the quantity being purchased from the onHand variable of the InventoryItem
class object.

Implement both classes in a complete program. Feel free to modify the InventoryItem
class in any way necessary.

Input Validation: Do not accept a negative value for the quantity of items being purchased.
*/
#include<iostream>
#include<iomanip>
#include "InventoryItem.h"
using namespace std;

class CashRegister {
	private:
		InventoryItem item;
	public:
		CashRegister(InventoryItem i) : item(i) {} //Constructor
	
		void processPurchase(int quantity)
		{
			double itemCost = item.getCost();
			double unitPrice = itemCost * 1.3;
			double subtotal = unitPrice * quantity;
			double salesTax = subtotal * 0.06;
			double total = subtotal + salesTax;
	
			cout << fixed << setprecision(2);
			cout << "Purchase Subtotal: $" << subtotal << endl;
			cout << "Sales Tax (6%): $" << salesTax << endl;
			cout << "Total: $" << total << endl;
	
			int currentUnits = item.getUnits();
			item.setUnits(currentUnits - quantity);
		}
};

int main()
{
	string description;
	double cost;
	int units;

	cout << "Enter item description: ";
	getline(cin, description);

	cout << "Enter item cost: $";
	cin >> cost;

	cout << "Enter number of units: ";
	cin >> units;

	InventoryItem item(description, cost, units);	//Creating InventoryItem object

	CashRegister register1(item);	  //Creating CashRegister object

	int quantity;
	cout << "Enter quantity being purchased: ";
	cin >> quantity;
	while (quantity <= 0)
	{
		cout << "Invalid input. Please enter a positive value." << endl;
		cin >> quantity;
	}

	register1.processPurchase(quantity);	// Processing the purchase

	return 0;
}

