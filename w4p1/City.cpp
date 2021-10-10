//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           07.10.2021
//==============================================

// Workshop 2:
// Version: 0.9
// Date: 2021/09/17
// Description:
// This file tests the DIY section of your workshop
/////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <string.h>
#include "City.h"
using namespace std;
namespace sdds
{
	const int POPULATION = 20000; //max population of a city

	//overloaded default constructor with safe to empty state function
	City::City()
	{
		setEmpty();
	}
	//overloaded constructor where we validate and assign data
	City::City(const char* name, int population)
	{
		if ((name == nullptr || name[0] == '\0') || population < 0) {
			setEmpty();
		}
		else {
			setCityName(name);
			m_population = population;
		}
	}
	//set to safe empty state
	void City::setEmpty()
	{
		m_cityName[0] = '\0';
		m_population = -1;
	}
	//city name setter
	void City::setCityName(const char* name)
	{
		if (name == nullptr) {
			m_cityName[0] = '\0';
		}
		else {
			strcpy(m_cityName, name);
		}
	}
	//city population setter
	void City::setPopulation(int population)
	{
		if (population < POPULATION) {
			m_population = population;
		}
		else {
			m_population = -1;
		}
	}
	//add population with overflow validation
	void City::addPopulation(int population)
	{
		if (population < POPULATION) {
			m_population += population;
			m_population > POPULATION ? m_population = POPULATION : m_population;
		}
	}
	//check if city objest is empty (in safe state)
	bool City::isEmpty()const
	{
		return (m_cityName[0] == '\0' || m_population < 0);
	}
	//city population getter
	int City::getPeople()const
	{
		return m_population;
	}
	//display all formatted city data
	void City::display()const
	{
		if (!isEmpty()) {
			cout << "|";
			cout.width(30);
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout << m_cityName;
			cout << " | ";
			cout.width(10);
			cout.setf(ios::right);
			cout << m_population << " | " << endl;
		}else cout << "invalid city" << endl;
	}
}