/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
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

#define  _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Menu.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
	
	//MenuItem class

	MenuItem::MenuItem(){}

	MenuItem::MenuItem(const char* itemName)
	{
		if (itemName) {
			delete[] m_itemName;
			m_itemName = new char[strlen(itemName) + 1];
			strcpy(m_itemName, itemName);
		}
		else {
			delete[] m_itemName;
			m_itemName = nullptr;
		}
	}
	MenuItem::~MenuItem()
	{
		delete[] m_itemName;
	}
	//check if object is valid
	MenuItem::operator bool() const
	{
		return m_itemName && m_itemName[0] != '\0';
	}
	//return item name
	MenuItem::operator char* () const
	{
		return m_itemName;
	}
	//print item name
	std::ostream& MenuItem::write(std::ostream& ostr)const
	{
		if (this) {
			ostr << m_itemName;
		}
		return ostr;
	}

	//End of MenuItem class

	Menu::Menu()
	{
		m_itemsNum = 0;
	}

	Menu::Menu(const char* menuTitle)
	{
		m_itemsNum = 0;
		title(menuTitle);
	}
	Menu::~Menu()
	{
		unsigned int i;
		for (i = 0; i < m_itemsNum; i++) {
			delete m_items[i];
		}
	}
	//menu title getter
	void Menu::title(ostream& ostr) const
	{
		if (m_menuItem.m_itemName) {
			ostr << m_menuItem.m_itemName;
		}
	}
	//menu title setter (DMA)
	void Menu::title(const char* menuTitle)
	{
		if (menuTitle) {
			delete[] m_menuItem.m_itemName;
			m_menuItem.m_itemName = new char[strlen(menuTitle) + 1];
			strcpy(m_menuItem.m_itemName, menuTitle);
		}
		else {
			delete[] m_menuItem.m_itemName;
			m_menuItem.m_itemName = nullptr;
		}
	}
	//display formatted data
	void Menu::displayMenu() const {
		title(cout);
		unsigned int i;
		if (m_menuItem.m_itemName && m_menuItem.m_itemName[0] != '\0') {
			cout << endl;
		}
		cout.setf(ios::right);
		for (i = 0; i < m_itemsNum; i++) {
			cout.width(2);
			cout << i + 1 << "- " << m_items[i]->m_itemName << endl;
		}
		cout.width(2);
		cout << " 0- Exit" << endl;
		cout.unsetf(ios::right);

	}
	//get validated input from keyboard
	unsigned int Menu::run() const
	{
		unsigned int input = 0;
		if (!cin) {
			cin.clear();
			cin.ignore(1000, '\n');
		}
		displayMenu();
		cout << "> ";
		input = getInt(input, m_itemsNum); //validate input
		return input;
	}
	//get validated input from keyboard
	unsigned int Menu::operator~() const {
		unsigned int input = 0;
		if (!cin) {
			cin.clear();
			cin.ignore(1000, '\n');
		}
		displayMenu();
		cout << "> ";
		input = getInt(input , m_itemsNum);  //validate input
		return input;
	}
	//insert items to menu
	Menu& Menu::operator<<(const char* menuitemConent)
	{
		if (m_itemsNum < MAX_MENU_ITEMS) {
			MenuItem* menuItem = new MenuItem(menuitemConent);
			m_items[m_itemsNum++] = menuItem;
		}
		return *this;
	}
	// return number of items
	Menu::operator int() const
	{
		return m_itemsNum;
	}
	// return unsigned number of items
	Menu::operator unsigned int() const
	{
		return m_itemsNum;
	}
	// check if menu is empty
	Menu::operator bool() const
	{
		return m_itemsNum > 0;
	}
	//print title
	ostream& operator<<(ostream& ostr, Menu& Ro)
	{
		Ro.title(ostr);
		return ostr;
	}
	//return menu item name by index 
	const char* Menu::operator[] (int index) const
	{
		return m_items[index % m_itemsNum]->m_itemName;
	}
}