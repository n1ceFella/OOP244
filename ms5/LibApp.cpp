//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           03.12.2021
//==============================================

/* Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: LibApp.cpp
Version 1.0
Author	Volodymyr Labliuk
Revision
-----------------------------------------------------------
Date      Reason
2021/12/03  Preliminary release
2021/12/03  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include "LibApp.h"
#include "Menu.h"
#include "PublicationSelector.h"
#include "Book.h"

using namespace std;
namespace sdds
{

	LibApp::LibApp(const char* name):
		m_pubTypeMenu("Choose the type of publication:"), 
		m_mainMenu("Seneca Library Application"),
		m_exitMenu("Changes have been made to the data, what would you like to do?")
	{
		strcpy(m_pubFileName, name);
		m_changed = false;
		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
		m_pubTypeMenu << "Book" << "Publication";
		m_lastRefNum = 0;
		m_numOfPub = 0;
		load(m_pubFileName);
	}

	LibApp::~LibApp()
	{
		for (int i = 0; i < m_numOfPub; i++) {
			delete m_pubPtrs[i];
		}

	}
	//create menu with confirmation menu items, and get user input
	bool LibApp::confirm(const char* message)
	{
		Menu yesMenu(message);
		yesMenu << "Yes";
		return (yesMenu.run() == 1);
	}
	//add new publication message + confirm publication function call
	void LibApp::newPublication()
	{

		if (m_numOfPub == SDDS_LIBRARY_CAPACITY) {
			cout << "Library is at its maximum capacity!" << endl;
		}
		else {
			cout << "Adding new publication to the library" << endl;
			int selection = m_pubTypeMenu.run();
			if (selection) {
				Publication* pub{};

				if (selection == 1) {
					pub = new Book;
				}
				else if (selection == 2) {
					pub = new Publication;
				}
				else if (selection == 0) {
					return;
				}
				cin >> *pub;
				if (!cin) {
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Aborted!" << endl;
					return;
				}
				else {
					if (confirm("Add this publication to the library?")) {
						if (*pub) {
							pub->setRef(++m_lastRefNum);
							m_pubPtrs[m_numOfPub] = pub;
							m_numOfPub++;
							m_changed = true;
							cout << "Publication added" << endl;
						}
						else {
							delete pub;
							cout << "Failed to add publication!" << endl;
						}
					}
					else {
						cout << "Aborted!" << endl;
					}
				}
			}
			else {
				cout << "Aborted!" << endl;
			}
		}
	}
	//remove publication message  +  confirm function call
	void LibApp::removePublication()
	{
		cout << "Removing publication from the library" << endl;
		int ref = search(true,true);
		if (ref) {
			cout << *getPub(ref) << endl;
			if (confirm("Remove this publication from the library?")) {
				getPub(ref)->setRef(0);
				m_changed = true;
				cout << "Publication removed" << endl;
			}
		}
	}
	//check out publications message + confirm funtion call
	void LibApp::checkOutPub()
	{
		cout << "Checkout publication from the library" << endl;
		int ref = search(true, false);
		if (ref) {
			cout << *getPub(ref) << endl;
			if (confirm("Check out publication?")) {
				int membershipNum;
				cout << "Enter Membership number: ";
				cin >> membershipNum;
				while(!cin || (membershipNum < 10000 || membershipNum > 99999))
				{
					if (!cin) {
						cin.clear();
						cin.ignore(1000, '\n');
					}
					cout << "Invalid membership number, try again: ";
					cin >> membershipNum;
					cin.ignore();
				}
				getPub(ref)->set(membershipNum);
				m_changed = true;
				cout << "Publication checked out" << endl;
			}

		}
	}
	//search for publications message
	int LibApp::search(bool checkOut, bool onLoan)
	{
		PublicationSelector pb("Select one of the following found matches:");
		int selection = 0;
		char title[256]{};
		char type{};

		selection = m_pubTypeMenu.run();
		selection == 1 ? type = 'B' : type = 'P';
		if (selection) {
			cout << "Publication Title: ";
			cin.getline(title, 256, '\n');
			//show all records
				if (checkOut && onLoan) {
					for (int i = 0; i < m_numOfPub; i++) {
						if (m_pubPtrs[i]->type() == type && strstr(*m_pubPtrs[i], title)) {
							pb << m_pubPtrs[i];
						}
					}
					if (pb) {
						pb.sort(); // sort them based on date and title
						int ref = pb.run(); // display the publications and select one
						if (ref) {
							return ref;
						}
						else {
							cout << "Aborted!" << endl;
						}
					}
					else {
						cout << "No matches found!" << endl;
					}
				}
				//show all available
				else if (checkOut) {
					for (int i = 0; i < m_numOfPub; i++) {
						if (m_pubPtrs[i]->type() == type && strstr(*m_pubPtrs[i], title)) {
							if (!(m_pubPtrs[i]->onLoan())) { //if avalable in lib
								pb << m_pubPtrs[i];
							}
						}
					}
					if (pb) {
						pb.sort(); // sort them based on date and title
						int ref = pb.run(); // display the publications and select one
						if (ref) {
							return ref;
						}
						else {
							cout << "Aborted!" << endl;
						}
					}
					else {
						cout << "No matches found!" << endl;
					}
				}
				//show all unavailable
				else if (onLoan) {
					for (int i = 0; i < m_numOfPub; i++) {
						if (m_pubPtrs[i]->type() == type && strstr(*m_pubPtrs[i], title)) {
							if (m_pubPtrs[i]->onLoan()) { //if is not avalable in lib
								pb << m_pubPtrs[i];
							}
						}
					}
					if (pb) {
						pb.sort(); // sort them based on date and title
						int ref = pb.run(); // display the publications and select one
						if (ref) {
							return ref;
						}
						else {
							cout << "Aborted!" << endl;
						}
					}
					else {
						cout << "No matches found!" << endl;
					}
				}
		}
		return 0;
	}
	//save publications message
	void LibApp::save(const char* fileName)
	{
		cout << "Saving Data" << endl;
		ofstream fileout(fileName);
		for (int i = 0; i < m_numOfPub; i++) {
			if (m_pubPtrs[i]->getRef() != 0) {
				fileout << *m_pubPtrs[i] << endl;
			}
		}
		fileout.close();
	}
	//load publications message
	void LibApp::load(const char* fileName)
	{
		cout << "Loading Data" << endl;
		ifstream filein(fileName);
		char type{};
		for (int i = 0; filein; i++) {
			filein >> type;
			filein.ignore();
			if (type == 'P')
				m_pubPtrs[i] = new Publication;
			else if (type == 'B')
				m_pubPtrs[i] = new Book;
			if (type == 'P' || type == 'B') {
				filein >> *m_pubPtrs[i];
				m_lastRefNum = m_pubPtrs[i]->getRef();
				m_numOfPub++;
				type = {};
			}
		}
	}
	//return piblication publications messages
	void LibApp::returnPub()
	{
		cout << "Return publication to the library" << endl;
		int  ref = search(false, true);
		if (ref) {
			cout << *getPub(ref) << endl;
			if (confirm("Return Publication?")) {
				Date today;
				double amountToPay;
				int dayNum = (today - getPub(ref)->checkoutDate());
				if (dayNum > 15) {
					amountToPay = (dayNum - 15) * 0.5;
					cout << "Please pay $" << setprecision(2) << fixed << amountToPay << " penalty for being " << (dayNum - 15) << " days late!" << endl;
				}
				getPub(ref)->set(0);
			}

			cout << "Publication returned" << endl;
			m_changed = true;
		}

	}
	//handle all user input
	void LibApp::run()
	{
		unsigned int selection = 0;
		do {
			selection = m_mainMenu.run();
			switch (selection) {
			case 1: newPublication();
				break;
			case 2: removePublication();
				break;
			case 3: checkOutPub();
				break;
			case 4: returnPub();
				break;
			case 0:
				if (m_changed) {
					selection = m_exitMenu.run();
					switch (selection) {
					case 1:
						save(m_pubFileName);
						selection = 0;
						cout << endl << "-------------------------------------------" << endl;
						cout << "Thanks for using Seneca Library Application";
						break;
					case 2: selection = 1;
						break;
					case 0:
						if (confirm("This will discard all the changes are you sure?")) {
							cout << endl << "-------------------------------------------" << endl;
							cout << "Thanks for using Seneca Library Application";
							break;
						}
						else {
							selection = 1;
						}
					}
				}
				else {
					cout << endl << "-------------------------------------------" << endl;
					cout << "Thanks for using Seneca Library Application";

				}
			}
			cout << endl;
		} while (selection);
	}
	//get publication with liv ref
	Publication* LibApp::getPub(int libRef)
	{
		Publication* ret{};
		for (int i = 0;!ret &&  i < m_numOfPub; i++) {
			if (m_pubPtrs[i]->getRef() == libRef) {
				ret = m_pubPtrs[i];
			}
		}
		return ret;
	}
}