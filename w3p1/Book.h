#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
namespace sdds
{
	class Book
	{
	private:
		char m_title[51];
		int m_SKU;
		int m_daysOnLoan;
		void setEmpty();
		double penalty();
	public:
		void set(const char*, int, int);
		bool isEmpty();
		bool hasPenalty();
		bool subTitle(const char*);
		void display();
	};
}
#endif // !SDDS_BOOK_H