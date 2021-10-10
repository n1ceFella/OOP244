//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           09.10.2021
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <string.h>
#include "Chapter.h"

using namespace std;
namespace sdds
{
	Chapter::Chapter(const char* name, int pagesNum)
	{
		if ((!name || name[0] == '\0') || pagesNum <= 0) {
			setEmpty();
		}
		else {
			setName(name);
			m_pagesNumber = pagesNum;
		}
	}
	Chapter::Chapter()
	{
		setEmpty();
	}
	//here we discard Chapter name value
	Chapter::~Chapter()
	{
		m_name[0] = '\0';
	}
	// display formatted data
	void Chapter::display()const
	{
		cout.unsetf(ios::right);
		cout.fill('.');
		cout.width(50);
		cout.setf(ios::left);
		cout << m_name;
		cout.unsetf(ios::left);
		cout.fill(' ');
		cout.width(4);
		cout.setf(ios::right);
		cout << m_pagesNumber << endl;
	}
	//set data to safe empty state
	void Chapter::setEmpty()
	{
		m_name[0] = '\0';
		m_pagesNumber = -1;
	}
	//name setter
	void Chapter::setName(const char* name)
	{
		m_name[0] = '\0';
		if (!name|| name[0] == '\0') {
			setEmpty();
		}
		else {
			strcpy(m_name, name);
		}
	}
	// page number setter
	void Chapter::setPagesNum(int pages)
	{
		m_pagesNumber = pages;
	}
	//validate data
	bool Chapter::isInvalid()
	{
		return (m_name[0] == '\0' || m_pagesNumber == -1);
	}
}