//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           09.10.2021
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <string.h>
#include "Book.h"

using namespace std;
namespace sdds
{
	const int MAX_PAGES = 200; //max number of pages

	//if passed data are valid assign it to an object, otherwise set to safe empty state
	Book::Book(const char* name, int chapterNum, const Chapter* chapter)
	{
		if ((!name || !chapter || name[0] == '\0') || chapterNum <= 0) {
			setEmpty();
		}
		else {
			setName(name);
			m_chaptersNumber = chapterNum;
			m_chapters = new Chapter[chapterNum];
			for (int i = 0; i < chapterNum; i++) {
				m_chapters[i] = chapter[i];
			}
		}
	}
	//call function to set to safe emtpy state 
	Book::Book()
	{
		setEmpty();
	}
	//free memory here
	Book::~Book()
	{
		delete[] m_name;
		delete[] m_chapters;
	}
	//add chapter to Book if valid  ( num of pages <= 200 and > 0 )
	Book& Book::addChapter(const char* chapter_name, int noOfPages)
	{
		if (noOfPages > 0 && noOfPages <= MAX_PAGES ) { 
			Chapter* chapterArray = new Chapter[m_chaptersNumber + 1]; //DMA array
			for (int i = 0; i < m_chaptersNumber; i++) {
				chapterArray[i] = m_chapters[i];
			}
			delete[] m_chapters;
			chapterArray[m_chaptersNumber].setName(chapter_name);
			chapterArray[m_chaptersNumber].setPagesNum(noOfPages); 
			m_chaptersNumber++;
			m_chapters = chapterArray;
		}
		return *this;
	}
	//display all formatted data
	void Book::display()const
	{
		if (isValid()) {
			cout << "Book Name: " << m_name << endl;
			cout << "No of Chapters: " << m_chaptersNumber << endl;
			cout.width(51);
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout << "Chapter name";
			cout << "Pages" << endl;
			for (int i = 0; i < m_chaptersNumber; i++) {
				m_chapters[i].display();
			}
		}else {
			cout << "Invalid Book object" << endl;
		}
	}
	//check if object is in safe emtpty state
	bool Book::isEmpty()const
	{
		return (!m_name || !m_chaptersNumber || m_name[0] == '\0' || m_chaptersNumber <= 0); //return true if nullptr
	}
	//set to safe empty state
	void Book::setEmpty()
	{
		m_name = nullptr;
		m_chapters = nullptr;
		m_chaptersNumber = 0;
	}
	//name setter
	void Book::setName(const char* name)
	{
		delete[] m_name;
		if (!name || name[0] == '\0') {
			setEmpty();
		}
		else {
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
		}
	}
	//validate all chapter objects inside this function ( return false if at least one object is invalid )
	bool Book::isValid()const
	{
		int i;
		bool flag = true;
		for (i = 0; i < m_chaptersNumber && flag; i++) {
			m_chapters[i].isInvalid() ? flag = false : flag;
		}
		m_chaptersNumber == 0 ? flag = false : flag;
		return flag;
	}
}