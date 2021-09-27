//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           13.09.2021
//==============================================

#include <iostream>
#include "drink.h"
#include "util.h"
using namespace std;
using namespace sdds;

int main()
{
    bool done = false;
    loadDrinks();
    cout << "Welcome to the Seneca Vending Machine" << endl << endl;
    while (!done) {
        drinkMenu();
        chooseDrink();
        cout << "\nDo you want to order another drink? (Y)es or (N)o: ";
        done = !confirm();
        cout << endl;
    }
    drinkMenu();
    cout << "\nThank you and come again" << endl;
    return 0;
}