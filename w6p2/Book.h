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

	//NoOfBookCases set to 132
	//	NoOfShelves set to 7
	//	MaxTitleLen set to 40
	//	MaxAuthorLen set to 25
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
	public:
		Book();
		Book(const char* title, const char* authorName, int bookcaseNumber, int shelfNumber);
		Book(const Book& cnt);
		~Book();
		Book& operator=(const Book& cnt);
		operator bool() const;
		void allocateAndCopyAuthorName(const char* name);
		void allocateAndCopyTitle(const char* name);
		bool isValid(char* title, char* authorName, int bookcaseNum, int shelfNum)const;
		std::istream& read(std::istream& istr);
		//std::ostream& print(std::ostream& ostr, bool toFile = true) const;
		std::ostream& write(std::ostream& ostr, bool onScreen = true)const;
	};
	std::ostream& operator<<(std::ostream& ostr, const Book& cnt);
	std::istream& operator>>(std::istream& istr, Book& cnt);
}
#endif // !SDDS_BOOK_H