#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <string.h>
#include "Account.h"
using namespace std;
namespace sdds
{
	//NoOfDays x (InterestRate/NumberOfDaysInAYear) x AccountBalance

	const int INTEREST_PERIOD = 30; //The Interest - free payment period
	const double INTEREST_RATE = 0.285; //The Interest rate (annually)

	//set data on new account
	void Account::set(int accNum, double balance, int days)
	{
		if (accNum > 0 && balance > 0 && days > 0) {
			m_accNum = accNum;
			m_balance = balance;
			m_daysOnLoan = days;
			if (hasInterest()) {
				m_interest = interest();
			}
			else m_interest = 0;
		}
		else setEmpty();
	}
	//set all Account data to safe empty state
	void Account::setEmpty()
	{
		m_accNum = 0;
		m_balance = 0;
		m_daysOnLoan = 0;
		m_interest = 0;
	}
	//check if data is empty
	bool Account::isEmpty()
	{
		return (m_accNum == 0 && m_balance == 0 && m_daysOnLoan == 0);
	}
	//calculate interest
	double Account::interest()
	{
		return ((double)m_daysOnLoan * ((double)INTEREST_RATE / 365) * m_balance);
	}
	//check if account have to pay interest
	bool Account::hasInterest()
	{
		return (m_daysOnLoan > INTEREST_PERIOD);
	}
	//display all foramted account data
	void Account::display()
	{
		if (!isEmpty()) {
			cout.width(12);
			cout.setf(ios::fixed);
			cout << m_accNum;
			cout.setf(ios::right);
			cout.precision(2);
			cout.width(10);
			cout << m_balance;
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout.width(2);
			cout << " ";
			cout << m_daysOnLoan;
			if (hasInterest()) {
				cout.width(10);
				cout.setf(ios::right);
				cout.precision(2);
				cout << m_interest;
				cout.precision(6);
			}
			else if (m_daysOnLoan < 10) {
				cout.width(3);
				cout << " ";
			}
			else {
				cout.width(2);
				cout << " ";
			}
			cout.unsetf(ios::right);
			cout << endl;
		}
	}
	//getter to access m_interest private member
	double Account::getInterest()
	{
		return m_interest;
	}
}