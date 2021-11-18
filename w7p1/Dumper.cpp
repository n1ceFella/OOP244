/*
Name: Volodymyr Labliuk
Email: vlabliuk@myseneca.ca
Student ID: 147302202
Data: 11.11.2021
Section: NBB
*/

#include<iostream>
#include "Dumper.h"
#include "VehicleBasic.h"
using namespace std;
namespace sdds
{
	Dumper::Dumper(const char* plateNum, int buildYear, double capacity, const char* address) : VehicleBasic(plateNum, buildYear)
	{
		m_capacity = capacity;
		m_currentLoad = 0;
		NewAddress(address);
	}
	bool Dumper::loaddCargo(double cargo) {
		if ((m_currentLoad + cargo) <= m_capacity) {
			m_currentLoad += cargo;
			return true;
		}
		else return false;
	}
	bool Dumper::unloadCargo()
	{
		if (m_currentLoad > 0) {
			m_currentLoad = 0;
			return true;
		}
		else return false;
	}
	ostream& Dumper::write(ostream& os) const
	{
		os << "| " << buildYear() << " | " << plateNumber() << " | " << currentAddress() << " | " << m_currentLoad << "/" << m_capacity;
		return os;
	}
	istream& Dumper::read(istream& in)
	{
		int year;
		char number[MAX_ADRESS_NUM];
		char address[MAX_ADRESS_NUM];
		cout << "Built year: ";
		in >> year;
		buildYear(year);
		cout << "License plate: ";
		in >> number;
		plateNumber(number);
		cout << "Current location: ";
		in >> address;
		currentAddress(address);
		cout << "Capacity: ";
		in >> m_capacity;
		cout << "Cargo: ";
		in >> m_currentLoad;
		return in;
	}
	
	
}
