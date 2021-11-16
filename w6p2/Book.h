//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           23.10.2021
//==============================================

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
namespace sdds
{
	const int MaxTitleLen = 40;
	const int MaxAuthorLen = 25;
	const int NoOfBookCases = 132;
	const int NoOfShelves = 7;
	class Book
	{
	private:
		char* m_title{};
		char* m_authorName{};
		int m_bookcaseNumber;
		int m_shelfNumber;
		void setEmpty();
		void set(const char* title, const char* authorName, int bookcaseNumber, int shelfNumber);
		void extractChar(std::istream& istr, char ch) const;
		void allocateAndCopyAuthorName(const char* name);
		void allocateAndCopyTitle(const char* name);
	public:
		Book();
		Book(const char* title, const char* authorName, int bookcaseNumber, int shelfNumber);
		Book(const Book& book);
		~Book();
		Book& operator=(const Book& book);
		operator bool() const;
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr, bool onScreen = true)const;
	};
	std::ostream& operator<<(std::ostream& ostr, const Book& book);
	std::istream& operator>>(std::istream& istr, Book& book);
}
#endif // !SDDS_BOOK_H