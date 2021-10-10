#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <string.h>
#include "Book.h"
using namespace std;
namespace sdds
{
		const double PENALTY = 1.5; // Penalty in dollars for each day a book's return is overdue
		const int MAXLOAN = 15; // Maximum number of days to loan a book witout penalty.
		//set safe empty state to all members
		void Book::setEmpty()
		{
			m_title[0] = 0;
			m_SKU = 0;
			m_daysOnLoan = 0;
		}
		//apply penalty fine according to overdue days
		double Book::penalty()
		{
			return ((double)m_daysOnLoan - (double)MAXLOAN) * (double)PENALTY;
		}
		//object setter(modifier)
		void Book::set(const char* title, int sku, int daysOnLoan)
		{
			if (title != nullptr && title[0] != '\0' && sku > 0 && daysOnLoan > 0) {
				strcpy(m_title, title);
				m_SKU = sku;
				m_daysOnLoan = daysOnLoan;
			}
			else setEmpty();
		}
		//check if object state is safe empty
		bool Book::isEmpty()
		{
			return (m_title[0] == 0 && m_SKU == 0 && m_daysOnLoan == 0);
		}
		//check if there are overdue days
		bool Book::hasPenalty()
		{
			return (m_daysOnLoan > MAXLOAN);
		}
		//check if string contains substring
		bool Book::subTitle(const char* substring)
		{
			char* position = nullptr;
			position = strstr(m_title, substring);
			if (position == nullptr) {
				return false;
			}
			return true;
		}
		//display formatted data
		void Book::display()
		{
			if (!isEmpty()) {
				cout.fill(' ');
				cout.width(49);
				cout.setf(ios::left);
				cout << m_title;
				cout.width(8);
				cout << m_SKU;
				cout.width(10);
				cout << m_daysOnLoan;
				if (hasPenalty()) {
					cout.width(7);
					cout.setf(ios::right);
					cout.setf(ios::fixed);
					cout.precision(2);
					cout << penalty();
					cout.precision(6);
				}
				cout.unsetf(ios::right);
				cout << endl;
			}
			else cout << "Invalid library book" << endl;
		}
}