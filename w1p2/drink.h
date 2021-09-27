//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           18.09.2021
//==============================================

#ifndef _244_DRINK_H_ // replace with relevant names
#define _244_DRINK_H_

// Your header file content goes here
namespace sdds
{

	struct Drink
	{
		char name[10];
		int volume;
		double price;
		int quantity;
	};
	void loadDrinksFromFile(const char* filename);
	void drinkMenu();
	void displayDrink(const Drink* drink);
	int chooseDrink();
	bool updateDrink(int sel);
	extern const int MAXDRINKS;
}
#endif