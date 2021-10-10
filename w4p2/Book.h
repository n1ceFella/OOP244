//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           09.10.2021
//==============================================

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include "Chapter.h"
namespace sdds
{
	class Book
	{
	public:
		Book(const char* name, int chapterNum, const Chapter* chapter);
		Book();
		~Book();
		bool isEmpty()const;
		void setEmpty();
		void setName(const char* name);
		Book& addChapter(const char* chapter_name, int noOfPages);
		void display()const;
		bool isValid()const;
	private:
		char* m_name = nullptr;
		int m_chaptersNumber;
		Chapter* m_chapters = nullptr;
	};
}
#endif // !SDDS_BOOK_H