#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <string.h>
#include "Bank.h"
#include "Account.h"
using namespace std;
namespace sdds
{
	//set data to safe empty state
	void  Bank::setEmpty()
	{
		m_name[0] = 0;
		m_accounts = nullptr;
		m_sizeOfAccountsArray = 0;
		m_addedAccount = 0;
	}
	//check if all member is safe
	bool Bank::isEmpty()const
	{
		return (m_name[0] == 0 && m_accounts == nullptr && m_sizeOfAccountsArray == 0 && m_addedAccount == 0);
	}
	void Bank::initialize(const char* bank_name, int noOfAccounts)
	{
		//check if input data is in appropriate state
		if ((bank_name == nullptr || bank_name[0] == '\0') || noOfAccounts <= 0) {
			setEmpty();
		}
		else {
			strcpy(m_name, bank_name);
			m_sizeOfAccountsArray = noOfAccounts;
			m_accounts = new Account[m_sizeOfAccountsArray];
			m_addedAccount = 0;
		}
	}
	//add new account
	bool Bank::addAccount(int accNo, double balace, int days)
	{
		if (m_addedAccount < m_sizeOfAccountsArray) {
			m_accounts[m_addedAccount].set(accNo, balace, days);
			if (!m_accounts[m_addedAccount].isEmpty()) {
				m_addedAccount++;
				return true;
			}
		}
		return false;
	}
	//free memory
	void Bank::clear()
	{
		delete[] m_accounts;
		m_accounts = nullptr;
	}
	//display all formatted data 
	void Bank::display(bool intrestOnly)const
	{
		if (!isEmpty()) {
			int i;
			int rowNum = 1;
			if (intrestOnly) {
				header(intrestOnly);
				for (i = 0; i < m_addedAccount; i++) {
					if (intrestOnly) {
						if (m_accounts[i].hasInterest()) {
							cout.width(5);
							cout.setf(ios::left);
							cout << rowNum++;
							m_accounts[i].display();
						}
					}
				}
			}
			else {
				header();
				for (i = 0; i < m_addedAccount; i++) {
					cout.width(5);
					cout.setf(ios::left);
					cout << rowNum++;
					m_accounts[i].display();
				}
			}
			footer();
		}
		else {
			cout << "Invalid Bank" << endl;
			return;
		}
	}
	//display header
	void Bank::header(bool interestOnly)const
	{
		if(interestOnly) cout << "INTEREST ONLY LIST!" << endl;
		cout << "----------------------------------------" << endl;
		cout << ">>> " << m_name << " <<<" << endl;
		cout << "----------------------------------------" << endl;
		cout << "Row Accnt No       Balance  Days Interest" << endl;
		cout << "--- ---------- ------------ ---- --------" << endl;
	}
	//diplay footer
	void Bank::footer()const
	{
		cout.precision(2);
		cout << "-----------------------------------------" << endl;
		cout << "              Total interest:  ";
		cout << getTotalInterest() << endl << endl;
	}
	//calculate total interest
	double Bank::getTotalInterest()const
	{
		int i;
		double totalInterest = 0;
		for (i = 0; i < m_addedAccount; i++) {
			totalInterest += m_accounts[i].getInterest();
		}
		return totalInterest;
	}
}