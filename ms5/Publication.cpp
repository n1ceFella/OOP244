//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           03.12.2021
//==============================================

/* Citation and Sources...
Final Project Milestone 5
Module: Publication
Filename: Publication.cpp
Version 1.1
Author	Volodymyr Labliuk
Revision read function changed
-----------------------------------------------------------
Date      Reason
2021/12/03  Preliminary release
2021/12/03  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <cstring>
#include <iostream>
#include <ctime>
#include "Publication.h"
#include "Streamable.h"
#include "Utils.h"
using namespace std;
namespace sdds
{
	Publication::Publication() : Streamable()
	{
		m_membership = 0;
		m_libRef = -1;
	}
	//check if io is part of console stream
	bool Publication::conIO(ios& io)const
	{
		return (&io == &cin || &io == &cout);
	}
	ostream& Publication::write(ostream& os) const
	{
		//display data if os is console stream
		if (conIO(os)) {
			os << "| " << m_shelfID << " | ";
			os.setf(ios::left);
			for (unsigned int i = 0; i < strlen(m_title) && i < SDDS_TITLE_WIDTH; i++) {
				
				//print dots after last title character
				if (i == strlen(m_title) - 1) {
					os.fill('.');
					os.width(SDDS_TITLE_WIDTH - strlen(m_title) + 1);
					os << m_title[i];
				}
				else {
					os << m_title[i];
				}
			}
			os.unsetf(ios::left);
			os.fill(' ');
			if (m_membership == 0) {
				os << " | " << " N/A " << " | ";
			}
			else {
				os << " | " << m_membership << " | ";
			}

			m_date.write(os);
			os << " |";
		}
		//display data if os is file stream
		else {
			os << type() << "	" << m_libRef << "	" << m_shelfID << "	" << m_title << "	" << m_membership << "	";
			m_date.write(os);
		}
		return os;
	}
	istream& Publication::read(istream& is)
	{
		//temporary locat variables
		int membership = 0;
		int libRef = 0;
		char shelfID[SDDS_SHELF_ID_LEN + 1]{};
		char* title{};
		Date date;
		//read console input
		if (conIO(is)) {

			cout << "Shelf No: ";
			is.getline(shelfID, SDDS_SHELF_ID_LEN + 1, '\n');
			if (strlen(shelfID) < 4) {
				is.setstate(ios::failbit);
			}
			//read title dynamically
			cout << "Title: ";
			title = dynRead(is); //utils

			//read date
			cout << "Date: ";
			is >> date;
		}
		//read file input
		else {
			is >> libRef;
			is.ignore();
			is.getline(shelfID, SDDS_SHELF_ID_LEN + 1, '	');
			if (strlen(shelfID) != 4) {
				is.setstate(ios::failbit);
			}
			//read title dynamically
			title = dynRead(is,'\t');//utils

			is >> membership;
			is.ignore();
			//read date
			is >> date;
		}
		//check data if valid
		if (!date) {
			is.setstate(ios::failbit);
			
		}
		//assign all data if valid
		if (is) {
			delete[] m_title;
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
			delete[] title;
			strcpy(m_shelfID, shelfID);
			set(membership);
			m_date = date;
			setRef(libRef);
		}
		else {
			delete[] title;
		}
		return is;
	}
	Publication::operator bool() const
	{
		return m_title || m_shelfID[0];
	}
	//copy constructor
	Publication::Publication(const Publication& Ro)
	{
		if (Ro) {
			*this = Ro;
		}
	}

	Publication& Publication::operator=(const Publication& Ro)
	{
		//here we check if its not self assignment and if Ro is not null
		if ((this != &Ro) && Ro) {
			m_date = Ro.m_date;
			setRef(Ro.m_libRef);
			m_membership = Ro.m_membership;
			strcpy(m_shelfID, Ro.m_shelfID);
			delete[] m_title;
			m_title = new char[strlen(Ro.m_title) + 1];
			strcpy(m_title, Ro.m_title);
		}
		return *this;
	}
	Publication::~Publication()
	{
		delete[] m_title;
	}
	//check if member id within range (5 digits)
	void Publication::set(int member_id)
	{
		if (member_id < 10000 || member_id > 99999) {
			m_membership = 0;
		}
		else {
			m_membership = member_id;
		}
	}
	//set libRef
	void Publication::setRef(int value)
	{
		m_libRef = value;
	}
	//set date to current date
	void Publication::resetDate()
	{
		m_date = Date();
	}
	char Publication::type()const 
	{
		return 'P';
	}
	//check if publication is on load
	bool Publication::onLoan()const
	{
		return m_membership != 0;
	}
	//return check out date
	Date Publication::checkoutDate()const
	{
		return m_date;
	}
	//check if string contains substring
	bool Publication::operator==(const char* title)const
	{
		return strstr(m_title, title);
	}
	//return publication title
	Publication::operator const char* ()const
	{
		return m_title;
	}
	//libRef getter
	int Publication::getRef()const
	{
		return m_libRef;
	}
}