//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           07.10.2021
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <string.h>
#include "Country.h"

using namespace std;
namespace sdds
{
	const int MAX_CITY = 20; //maximum number of cities

	//overloaded default constructor with set to safe state function
	Country::Country()
	{
		setEmpty();
	}
	//overloaded constructor
	Country::Country(const char* name, int noOfCity, const City* cities)
	{
		//validate input and set to safe empty state if not valid, otherwise assign to passed data
		if ((name == nullptr || cities == nullptr || name[0] == '\0') || (noOfCity <= 0 || noOfCity > 20)) {
			setEmpty();
		} else{
			setName(name);
			m_noOfCity = noOfCity;
			m_city = new City[m_noOfCity];
			for (int i = 0; i < m_noOfCity; i++) {
				m_city[i] = cities[i];
			}
		}
	}
	//we free memory here
	Country::~Country()
	{
		delete[] m_name;
		delete[] m_city;
	}
	//set to safe empty state
	void Country::setEmpty()
	{
		m_name = nullptr;
		m_city = nullptr;
		m_noOfCity = 0;
	}
	//name setter
	void Country::setName(const char* name)
	{
		delete[] m_name;
		if (name == nullptr || name[0] == '\0') {
			delete[] m_city;
			setEmpty();
		}
		else {
			char* newName = new char[strlen(name) + 1];
			m_name = newName;
			strcpy(m_name, name);
		}
	}
	//add city to DMA array and repoint array of cities to newly allocated array
	Country& Country::addCity(const City& c)
	{
		if (!c.isEmpty()) {
			City* cityArray = new City[m_noOfCity + 1];
			for (int i = 0; i < m_noOfCity; i++) {
				cityArray[i] = m_city[i];
			}
			delete[] m_city;
			cityArray[m_noOfCity] = c;
			m_noOfCity++;
			m_city = cityArray;
		}
		return *this;
	}
	//add population to city
	Country& Country::migrate(int people)
	{
		for (int i = 0; i < m_noOfCity; i++) {
			m_city[i].addPopulation(people);
		}
		return *this;
	}
	//check is name is valid (not null ptr)
	bool Country::isEmpty()const
	{
		return (m_name == nullptr);
	}
	//display all formatted data
	void Country::display()const
	{
		if (isEmpty()) {
			cout << "Invalid country object" << endl;
		}
		else {
			cout << "Country Name: " << m_name << endl;
			cout << "No of city: " << m_noOfCity << endl;
			cout.width(32);
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout << "City name";
			cout << "Population" << endl;
			for (int i = 0; i < m_noOfCity; i++) {
				m_city[i].display();
			}
		}
	}
}