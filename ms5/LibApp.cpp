/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: LibApp.cpp
Version 1.0
Author	Volodymyr Labliuk
Revision
-----------------------------------------------------------
Date      Reason
2021/11/14  Preliminary release
2021/11/14  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <fstream>
#include <iostream>
#include <cstring>
#include "LibApp.h"
#include "Menu.h"
#include "PublicationSelector.h"
#include "Book.h"
#include <string>

using namespace std;
namespace sdds
{

	LibApp::LibApp(const char* name)
	{

		int m_numOfPub = 0; //ptrs
		int m_lastRefNum = 0;
		m_pubTypeMenu << "Book" << "Publication";
		m_numOfPub = 0;
		load(name);
		m_changed = false;
		m_mainMenu.title("Seneca Library Application");
		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
		m_exitMenu.title("Changes have been made to the data, what would you like to do?");
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
	}

	//display menu title, append menues with menu items 
	//LibApp::LibApp()
	//{
		//m_changed = false;
		//m_mainMenu.title("Seneca Library Application");
		//m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
		//m_exitMenu.title("Changes have been made to the data, what would you like to do?");
		//m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
		//load();
	//}
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
			cout << "Library is at its maximum capacity!";
		}
		else {
			cout << "Adding new publication to library" << endl;
			int selection = m_pubTypeMenu.run();
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
			cin >> *pub; // NOT READS!!!
			if (!cin) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Aborted!" << endl;
				return;
			}
			else {
				if (confirm("Add this publication to library?")) {
					cout << "Aborted!" << endl;
				}
			}
			if (pub) {
				m_pubPtrs[m_numOfPub]->setRef(++m_lastRefNum);
				m_pubPtrs[m_numOfPub] = pub;
				m_numOfPub++;
				m_changed = true;
				cout << "Publication added" << endl;
			}
			else {
				delete[] pub;
				cout << "Failed to add publication!" << endl;
			}

		}
	}
	//remove publication message  +  confirm function call
	void LibApp::removePublication()
	{
		cout << "Removing publication from library" << endl;
		int ref = search(true);
		if (ref) {
			cout << *getPub(ref) << endl;
			//}
			//getPub(ref)->setRef(0);
			if (confirm("Remove this publication from the library?")) {
				//for (int i = 0; i < m_numOfPub; i++) {
				//	if (m_pubPtrs[i]->getRef() == ref) {
				//		m_pubPtrs[i]->setRef(0);
				//	}
				//}
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
		int ref = search(false, true, false);
		if (ref) {
			cout << *getPub(ref) << endl;
			//}
			if (confirm("Check out publication?")) {
				//for (int i = 0; i < m_numOfPub; i++) {
					//if (m_pubPtrs[i]->getRef() == ref) {
				int membershipNum;
				//CHECK THIS
				do {
					if (!cin) {
						cin.clear();
						cin.ignore(1000, '\n');
					}
					cout << "Enter Membership number: ";
					cin >> membershipNum;
				} while (!cin || (membershipNum < 10000 || membershipNum > 99999));
				getPub(ref)->set(membershipNum);
				//m_pubPtrs[i]->set(membershipNum);//CHECK THIS
			//}
		//}
				m_changed = true;
				cout << "Publication checked out" << endl;
			}

		}
	}
	//search for publications message
	int LibApp::search(bool all, bool checkOut, bool onLoan)
	{
		PublicationSelector pb("Select one of the following found matches:");
		int selection = 0;
		char title[256]{};

		//if (!cin) {
		//	cin.clear();
		//	cin.ignore(1000, '\n');
		//}
	   //NOT READS!!!
		//char garbage[256]{};
		//cin.getline(garbage, 256, '\n');


		//m_pubTypeMenu.title(cout); // display menu title
		selection = m_pubTypeMenu.run();
		if (selection) {
			cout << "Publication Title: ";

			cin.getline(title, 256, '\n');
			switch (selection) { //create function
			case 1:
				if (all) {
					for (int i = 0; i < m_numOfPub; i++) {
						if (m_pubPtrs[i]->type() == 'B' && strstr(*m_pubPtrs[i], title)) {
							pb << m_pubPtrs[i];
						}
					}
					if (pb) {
						pb.sort(); // sort them based on date and title
						int ref = pb.run(); // display the publications and select one
						if (ref) {
							//for (int i = 0; i < m_numOfPub; i++) {
								//if (m_pubPtrs[i]->getRef() == ref) {
									//cout << m_pubPtrs[i] << endl;
								//}
							return ref;

							//cout << "Selected Library Reference Number: " << ref << endl;
							//prnPub(p, 100, ref);
						}
						else {
							cout << "Aborted!" << endl;
						}
					}
					else {
						cout << "No matches found!" << endl;
					}
				}
				else if (checkOut) {
					for (int i = 0; i < m_numOfPub; i++) {
						if (m_pubPtrs[i]->type() == 'B' && strstr(*m_pubPtrs[i], title)) {
							if (!(m_pubPtrs[i]->onLoan())) { //if avalable in lib
								pb << m_pubPtrs[i];
							}
						}
					}
					if (pb) {
						pb.sort(); // sort them based on date and title
						int ref = pb.run(); // display the publications and select one
						if (ref) {
							//for (int i = 0; i < m_numOfPub; i++) {
								//if (m_pubPtrs[i]->getRef() == ref) {
								//	cout << m_pubPtrs[i] << endl;
								//}
							return ref;

						}
						else {
							cout << "Aborted!" << endl;
						}
						//cout << "Selected Library Reference Number: " << ref << endl;
						//prnPub(p, 100, ref);
					}
					else {
						cout << "No matches found!" << endl;
					}
				}
				else if (onLoan) {
					for (int i = 0; i < m_numOfPub; i++) {
						if (m_pubPtrs[i]->type() == 'B' && strstr(*m_pubPtrs[i], title)) {
							if (m_pubPtrs[i]->onLoan()) { //if is not avalable in lib
								pb << m_pubPtrs[i];
							}
						}
					}
					if (pb) {
						pb.sort(); // sort them based on date and title
						int ref = pb.run(); // display the publications and select one
						if (ref) {
							//for (int i = 0; i < m_numOfPub; i++) {
								//if (m_pubPtrs[i]->getRef() == ref) {
								//	cout << m_pubPtrs[i] << endl;
								//}
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
				break;
			case 2:
				if (all) {
					for (int i = 0; i < m_numOfPub; i++) {
						if (m_pubPtrs[i]->type() == 'P' && strstr(*m_pubPtrs[i], title)) {
							pb << m_pubPtrs[i];
						}
					}
					if (pb) {
						pb.sort(); // sort them based on date and title
						int ref = pb.run(); // display the publications and select one
						if (ref) {
							//for (int i = 0; i < m_numOfPub; i++) {
								//if (m_pubPtrs[i]->getRef() == ref) {
									//cout << m_pubPtrs[i] << endl;
								//}
							return ref;

							//cout << "Selected Library Reference Number: " << ref << endl;
							//prnPub(p, 100, ref);
						}
						else {
							cout << "Aborted!" << endl;
						}
					}
					else {
						cout << "No matches found!" << endl;
					}
				}
				else if (checkOut) {
					for (int i = 0; i < m_numOfPub; i++) {
						if (m_pubPtrs[i]->type() == 'P' && strstr(*m_pubPtrs[i], title)) {
							if (!m_pubPtrs[i]->onLoan()) { //if avalable in lib
								pb << m_pubPtrs[i];
							}
						}
					}
					if (pb) {
						pb.sort(); // sort them based on date and title
						int ref = pb.run(); // display the publications and select one
						if (ref) {
							//for (int i = 0; i < m_numOfPub; i++) {
								//if (m_pubPtrs[i]->getRef() == ref) {
								//	cout << m_pubPtrs[i] << endl;
								//}
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
				else if (onLoan) {
					for (int i = 0; i < m_numOfPub; i++) {
						if (m_pubPtrs[i]->type() == 'P' && strstr(*m_pubPtrs[i], title)) {
							if (m_pubPtrs[i]->onLoan()) { //if is not avalable in lib
								pb << m_pubPtrs[i];
							}
						}
					}
					if (pb) {
						pb.sort(); // sort them based on date and title
						int ref = pb.run(); // display the publications and select one
						if (ref) {
							//for (int i = 0; i < m_numOfPub; i++) {
								//if (m_pubPtrs[i]->getRef() == ref) {
								//	cout << m_pubPtrs[i] << endl;
								//}
							return ref;

						}
						else {
							cout << "Aborted!" << endl;
						}
					}
					else {
						cout << "No matches found!" << endl;
					}
					//cout << "Selected Library Reference Number: " << ref << endl;
					//prnPub(p, 100, ref);
				}

				break;
			case 0:
				cout << "Aborted!" << endl;
				break;
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
				fileout << m_pubPtrs[i] << '\n';
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
			//newPub = new Publication();
			//m_pubPtrs[row - 1] = new Publication();

			//if (m_pubPtrs[i]) {
			if (type) {
				filein >> *m_pubPtrs[i];  // *m_pubPtrs[i]
				m_lastRefNum = m_pubPtrs[i]->getRef();
				m_numOfPub++;
				type = {};
			}

			//filein >> m_pubPtrs[row - 1];
			//filein.ignore(1000, '\n');

		}
	}
	//return piblication publications messages
	void LibApp::returnPub()
	{
		cout << "Return publication to the library" << endl;
		int  ref = search(false, false, true);
		if (ref) {
			cout << *getPub(ref) << endl;
			//}
			if (confirm("Return Publication?")) {
				Date today;
				double amountToPay;
				//for (int i = 0; i < m_numOfPub; i++) {
					//if (m_pubPtrs[i]->getRef() == ref) {
						//int dayNum = (today - m_pubPtrs[i]->checkoutDate());
				int dayNum = (today - getPub(ref)->checkoutDate());
				if (dayNum > 15) {
					amountToPay = (dayNum - 15) * 0.5;
					cout << "Please pay $" << amountToPay << " penalty for being " << (dayNum - 15) << " days late!" << endl;
				}
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
						//save();
						selection = 0;
						cout << endl << "-------------------------------------------" << endl;
						cout << "Thanks for using Seneca Library Application";
						break;
					case 2: selection = 1;
						//may be need handle cancel changes here!!!!!!!!!!!!
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
	Publication* LibApp::getPub(int libRef)
	{
		Publication* ret{};
		for (int i = 0;!ret &&  i < m_numOfPub; i++) {  // bad boy you are!
			if (m_pubPtrs[i]->getRef() == libRef) {
				ret = m_pubPtrs[i];
			}
		}
		return ret;
	}

}