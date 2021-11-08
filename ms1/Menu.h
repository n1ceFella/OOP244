//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           05.11.2021
//==============================================

#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
namespace sdds
{
	const unsigned int MAX_MENU_ITEMS = 20;
	class Menu; //forward declaration

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
		char* m_title{};
		MenuItem m_menuItem;
		MenuItem* m_items[MAX_MENU_ITEMS]{};
		unsigned int m_itemsNum;

	};
	std::ostream& operator<<(std::ostream& ostr, Menu& Ro);
	//std::ostream& operator<<(std::ostream& ostr, const Menu& menu);
	//std::istream& operator>>(std::istream& istr, Menu& menu);
}
#endif