/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.h
Version 1.0
Author	Volodymyr Labliuk
Revision History
-----------------------------------------------------------
Date      Reason
2021/11/8  Preliminary release
2021/11/8  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
namespace sdds
{
	const unsigned int MAX_MENU_ITEMS = 20;

	class MenuItem
	{
		friend class Menu;
		char* m_itemName{}; //class member

		//constructors and desctructors
		MenuItem();
		MenuItem(const char* itemName);
		~MenuItem();
		MenuItem(const MenuItem& item) = delete;

		//overloaded operators and types
		MenuItem& operator=(int value) = delete;
		operator bool() const;
		operator char* () const;

		//fucntions
		std::ostream& write(std::ostream& ostr)const;
	};

	class Menu
	{
	public:
		//constructors and desctructors
		Menu();
		Menu(const char* title);
		~Menu();
		Menu(const Menu& item) = delete;

		//overloaded operators and types
		Menu& operator=(int value) = delete;
		operator bool() const;
		unsigned int operator~() const;
		unsigned int run() const;
		const char* operator[] (int index) const;
		operator int() const;
		operator unsigned int() const;
		Menu& operator<<(const char* menuitemConent);

		//fucntions
		void title(std::ostream& ostr) const;
		void title(const char* menuTitle);
		void displayMenu() const;
	private:
		MenuItem m_menuItem;
		MenuItem* m_items[MAX_MENU_ITEMS]{};
		unsigned int m_itemsNum;

	};
	std::ostream& operator<<(std::ostream& ostr, Menu& Ro);
}
#endif