#ifndef SDDS_BANK_H
#define SDDS_BANK_H
#include "Account.h"
namespace sdds
{
	class Bank
	{
	private: 
		char m_name[31];
		int m_sizeOfAccountsArray;
		int m_addedAccount;
		Account* m_accounts;
		void setEmpty();
		bool isEmpty()const;
		void header(bool interestOnly = false)const;
		void footer()const;

	public:
		void initialize(const char* bank_name, int noOfAccounts);
		void display(bool intrestOnly = false)const;
		void clear();
		bool addAccount(int accNo, double balace, int days);
		double getTotalInterest() const;
	};
}
#endif // !SDDS_BOOK_H