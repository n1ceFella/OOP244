//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           13.09.2021
//==============================================

#ifndef _244_DRINK_H_ // replace with relevant names
#define _244_DRINK_H_

#include <iostream>
#include <iomanip>
// Your header file content goes here
namespace sdds{

	const int MAXDRINKS = 5;
	
	struct Drink
	{
		char name[10];
		int volume;
		double price;
		int quantity;
	};
	void loadDrinks();
	void drinkMenu();
	void displayDrink(const Drink* drink);
	int chooseDrink();
	bool updateDrink(int sel);
	
}
#endif

