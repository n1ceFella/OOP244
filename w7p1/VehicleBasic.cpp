/*
Name: Volodymyr Labliuk
Email: vlabliuk@myseneca.ca
Student ID: 147302202
Data: 11.11.2021
Section: NBB
*/

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "VehicleBasic.h"
using namespace std;
namespace sdds
{
	VehicleBasic::VehicleBasic(const char* plateNum, int buildYear)
	{
		strcpy(m_plateNumber, plateNum);
		m_buildYear = buildYear;
		strcpy(m_address, "Factory");
	}
	void VehicleBasic::NewAddress(const char* address)
	{
		if (m_address != address) {
			cout.setf(ios::right);
			cout << "|";
			cout.width(8);
			cout << m_plateNumber;
			cout << "| |";
			cout.width(20);
			cout << m_address;
			cout << " ---> ";
			cout.unsetf(ios::right);
			cout.width(20);
			cout.setf(ios::left);
			cout << address;
			cout << "|" << endl;
			cout << "|" << endl;
			strcpy(m_address, address);
			cout.unsetf(ios::left);
		}
	}
	istream& VehicleBasic::read(istream& in)
	{
		cout << "Built year: ";
		in >> m_buildYear;
		cout << "License plate: ";
		in >> m_plateNumber;
		cout << "Current location: ";
		in >> m_address;
		return in;
	}

	ostream& VehicleBasic::write(ostream& os) const
	{
		os << "| " << m_buildYear << " | " << m_plateNumber << " | " << m_address;
		return os;
	}

	std::ostream& operator<<(std::ostream& ostr, const VehicleBasic& vehicle)
	{
		vehicle.write(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, VehicleBasic& vehicle)
	{
		vehicle.read(istr);
		return istr;
	}
	const char* VehicleBasic::plateNumber() const
	{
		return m_plateNumber;
	}
	const char* VehicleBasic::currentAddress() const
	{
		return m_address;
	}
	int VehicleBasic::buildYear() const
	{
		return m_buildYear;
	}
	void VehicleBasic::plateNumber(char* number)
	{
		strcpy(m_plateNumber, number);
	}
	void VehicleBasic::currentAddress(const char* address)
	{
		strcpy(m_address, address);
	}
	void VehicleBasic::buildYear(int buildYear)
	{
		m_buildYear = buildYear;
	}
}