#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Library.h"
#include "Book.h"
using namespace std;
namespace sdds
{
	//set all members to safe empty state
	void Library::setEmpty()
	{
		m_name[0] = 0;
		m_books = nullptr;
		m_sizeOfBooksArray = 0;
		m_addedBooks = 0;
	}
	//check if all member is safe
	bool Library::isEmpty()const
	{
		return (m_name[0] == 0 && m_books == nullptr && m_sizeOfBooksArray == 0 && m_addedBooks == 0);
	}
	//print header
	void Library::header(const char* title)const
	{
		cout << "------------------------------------------------------------------------------" << endl;
		cout << "*****  " << m_name << "  *****" << endl;
		cout << title << endl;
		cout << "------------------------------------------------------------------------------" << endl;
		cout << "Row Book title                                       SKU     loan days penalty" << endl;
		cout << "--- ------------------------------------------------ ------- --------- -------" << endl;
	}
	//print footer
	void Library::footer()const
	{
		cout << "------------------------------------------------------------------------------" << endl;
	}
	//initialize all members and new DMA array
	void Library::initialize(const char* name, int noOfBooks)
	{
		//check if input data is in appropriate state
		if ((name == nullptr || name[0] == '\0') || noOfBooks <= 0) {
			setEmpty();
		}
		else {
			strcpy(m_name, name);
			m_sizeOfBooksArray = noOfBooks;
			m_books = new Book[m_sizeOfBooksArray];
			m_addedBooks = 0;
		}
	}
	//add book to array, check its state and iterate book numbers
	bool Library::addBook(const char* book_title, int sku, int loanDays)
	{
		if (m_addedBooks < m_sizeOfBooksArray) {
			m_books[m_addedBooks].set(book_title,sku,loanDays);
			if (!m_books[m_addedBooks].isEmpty()) {
				m_addedBooks++;
				return true;
			}
		}
		return false;
	}
	//free memory here
	void Library::clear()
	{
		delete[] m_books;
		m_books = nullptr;
	}
	//format and display all books according to search keyword as an argument
	void Library::display(const char* substr)
	{
		bool flag = false;
		if (!isEmpty()) {
			int i;
			int rowNum = 1;
			cout << ">>> Searching for: \"";
			cout << substr;
			cout << "\" <<<" << endl;
			header("Substring search");
			for (i = 0; i < m_addedBooks; i++) {
				if (m_books[i].subTitle(substr)) {
					cout.fill(' ');
					cout.width(4);
					cout.setf(ios::left);
					cout << rowNum++;
					m_books[i].display();
					flag = true;
				}
			}
			if (!flag) {
				cout << "No book title contains \"" << substr << "\"" << endl;
			}
			footer();
		}
		else {
			cout << "Invalid Library" << endl;
			return;
		}
	}
	//format and display all books depending on overdue status
	void Library::display(bool overdueOnly)const
	{
		if (!isEmpty()) {
			int i;
			int rowNum = 1;
			if (overdueOnly) {
				header("Overdue Books");
				for (i = 0; i < m_addedBooks; i++) {
					if (overdueOnly) {
						if (m_books[i].hasPenalty()) {
							cout.width(4);
							cout.setf(ios::left);
							cout << rowNum++;
							m_books[i].display();
						}
					}
				}
			}
			else {
				header("Books on Loan");
				for (i = 0; i < m_addedBooks; i++) {
							cout.width(4);
							cout.setf(ios::left);
							cout << rowNum++;
							m_books[i].display();
				}
			}
			footer();
		}else {
			cout << "Invalid Library" << endl;
			return;
		}
	}
}