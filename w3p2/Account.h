#ifndef SDDS_ACCOUNT_H
#define SDDS_ACCOUNT_H
namespace sdds
{
	class Account
	{
	private:
		int m_accNum;
		double m_balance;
		double m_interest;
		int m_daysOnLoan;
		void setEmpty();
		double interest();
	public:
		void set(int, double, int);
		bool isEmpty();
		bool hasInterest();
		void display();
		double getInterest();
	};
}
#endif // !SDDS_BOOK_H