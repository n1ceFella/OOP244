/*
Name: Volodymyr Labliuk
Email: vlabliuk@myseneca.ca
Student ID: 147302202
Data: 11.11.2021
Section: NBB
*/

#ifndef SDDS_Dumper_H
#define SDDS_Dumper_H
#include <iostream>
#include "VehicleBasic.h"
namespace sdds
{
	class Dumper : public VehicleBasic
	{
	public:
		Dumper(const char* plateNum, int buildYear, double capacity, const char* address);
		bool loaddCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
	private:
		double m_capacity;
		double m_currentLoad;

	};
}
#endif
