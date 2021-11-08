//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           05.11.2021
//==============================================

#define  _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Menu.h"

using namespace std;
namespace sdds
{
	
	//MenuItem class

	MenuItem::MenuItem()
	{

	}

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
	MenuItem::operator bool() const
	{
		return m_itemName && m_itemName[0] != '\0';
	}
	MenuItem::operator char* () const
	{
		return m_itemName;
	}
	std::ostream& MenuItem::write(std::ostream& ostr)const
	{
		if (this) { //if not null
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
		title(menuTitle); //check
	}
	Menu::~Menu()
	{
		unsigned int i;
		for (i = 0; i < m_itemsNum; i++) {
			delete m_items[i];
		}
		delete[] m_title;
	}
	void Menu::title(ostream& ostr) const //check
	{
		if (m_title) {
			ostr << m_title;
		}
	}
	void Menu::title(const char* menuTitle)
	{
		if (menuTitle) {
			delete[] m_title;
			m_title = new char[strlen(menuTitle) + 1];
			strcpy(m_title, menuTitle);
		}
		else {
			delete[] m_title;
			m_title = nullptr;
		}
	}
	void Menu::displayMenu() const { //check formatting
		title(cout); //check
		unsigned int i;
		if (m_title && m_title[0] != '\0') {
			cout << ':' << endl;
		}
		for (i = 0; i < m_itemsNum; i++) {
			cout.width(2);
			cout.setf(ios::right);
			cout << i + 1 << "- " << m_items[i]->m_itemName << endl;
		}
		cout.width(2);
		cout.setf(ios::right);
		cout << " 0- Exit" << endl;
		cout.unsetf(ios::right);

	}

	//unsigned int Menu::run() const
	//{
	//	unsigned int input = 0;
	//	displayMenu();
	//	cout << "> ";
	//	//cin.clear();
	//	do { // do validation in Utils
	//		//cin.setstate(ios::goodbit);
	//		cin.clear();
	//		cin.ignore(10000,'\n');
	//		cin >> input;
	//		if (input < 0 || input > m_itemsNum) {
	//			//cin.setstate(ios::failbit);
	//			cout << "Invalid Selection, try again: " << endl;
	//		}
	//		//if (cin.peek() < 0 || cin.peek() > 9) {
	//		//	cin.setstate(ios::failbit);
	//		//	cout << "Invalid Selection, try again: " << endl;
	//		//}
	//		//if (!cin) {
	//		//	cout << "Invalid Selection, try again: " << endl;
	//		//}

	//	} while (!cin);
	//	cin.clear();
	//	return input;
	//}

	unsigned int Menu::run() const
	{
		unsigned int input = 0;
		if (!cin) {
			cin.clear();
			cin.ignore(sizeof input, '\n');
		}

		displayMenu();
		cout << "> ";
		cin >> input;
	while (!cin || (input < 0 || input > m_itemsNum)) {
		cin.clear();
		cin.ignore(sizeof input, '\n');
		cout << "Invalid Selection, try again: ";
		cin >> input; 
	}
	return input;
	}

	//unsigned int Menu::operator~() const
	//{
	//	unsigned int input = 0;
	//	displayMenu();
	//	//cin.clear();
	//	do { // do validation in Utils
	//		cout << "> ";
	//		cin.setstate(ios::goodbit);
	//		cin.clear();
	//		cin >> input;
	//		//if (cin.peek() < 0 || cin.peek() > 9) {
	//		//	cin.setstate(ios::failbit);
	//		//	cout << "Invalid Selection, try again: " << endl;
	//		//}
	//		if (!cin) {
	//			cout << "Invalid Selection, try again: " << endl;
	//		}

	//	} while (!cin);
	//	cin.clear();
	//	return input;
	//}

	unsigned int Menu::operator~() const {
		unsigned int input = 0;
		displayMenu();
		cout << "> ";
		cin >> input;
		while (!cin || (input < 0 || input > m_itemsNum)) {
			cin.clear();
			cin.ignore(sizeof input, '\n');
			cout << "Invalid Selection, try again: ";
			cin >> input;
		}
		return input;
	}

	Menu& Menu::operator<<(const char* menuitemConent)
	{
		if (m_itemsNum < MAX_MENU_ITEMS) {
			MenuItem* menuItem = new MenuItem(menuitemConent);
			m_items[m_itemsNum] = menuItem; //combine
			m_itemsNum++;
		}
		return *this;
	}
	Menu::operator int() const
	{
		return m_itemsNum;
	}
	Menu::operator unsigned int() const
	{
		return m_itemsNum;
	}
	Menu::operator bool() const
	{
		return m_itemsNum > 0;
	}
	ostream& operator<<(ostream& ostr, Menu& Ro) //check
	{
		//return m_title;
		Ro.title(ostr);
		return ostr;
	}
	const char* Menu::operator[] (int index) const
	{
		return m_items[index % m_itemsNum]->m_itemName;
	}
}