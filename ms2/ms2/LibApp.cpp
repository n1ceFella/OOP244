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

#include "LibApp.h"
using namespace std;
namespace sdds
{
	//display menu title, append menues with menu items 
	LibApp::LibApp()
	{
		m_changed = false;
		m_mainMenu.title("Seneca Library Application");
		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
		m_exitMenu.title("Changes have been made to the data, what would you like to do?");
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
		load();
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
		cout << "Adding new publication to library" << endl;
		if (confirm("Add this publication to library?")) {
			m_changed = true;
			cout << "Publication added" << endl;
		}
	}
	//remove publication message  +  confirm function call
	void LibApp::removePublication()
	{
		cout << "Removing publication from library" << endl;
		search();
		if (confirm("Remove this publication from the library?")) {
			m_changed = true;
			cout << "Publication removed" << endl;
		}
	}
	//check out publications message + confirm funtion call
	void LibApp::checkOutPub()
	{
		search();
		if (confirm("Check out publication?")) {
			m_changed = true;
			cout << "Publication checked out" << endl;
		}
	}
	//search for publications message
	void LibApp::search()
	{
		cout << "Searching for publication" << endl;
	}
	//save publications message
	void LibApp::save()
	{
		cout << "Saving Data" << endl;
	}
	//load publications message
	void LibApp::load()
	{
		cout << "Loading Data" << endl;
	}
	//return piblication publications messages
	void LibApp::returnPub()
	{
		search();
		cout << "Returning publication" << endl;
		cout << "Publication returned" << endl;
		m_changed = true;
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
						case 1: save();
							selection = 0;
							cout << endl << "-------------------------------------------" << endl;
							cout << "Thanks for using Seneca Library Application";
							break;
						case 2: selection = 1;
							break;
						case 0: 
							if(confirm("This will discard all the changes are you sure?")){
								cout << endl << "-------------------------------------------" << endl;
								cout << "Thanks for using Seneca Library Application";
								break;
							}else{
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
}