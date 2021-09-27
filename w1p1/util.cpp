//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           13.09.2021
//==============================================

#include "util.h"

using namespace std;
namespace sdds {
	bool confirm()
	{
		char choice = cin.get();
		clearBuffer();
		return choice == 'Y';
	}

	void clearBuffer()
	{
		while (cin.get() != '\n');
	}
}
